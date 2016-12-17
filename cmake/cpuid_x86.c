/* * Copyright (c) 2014, 2015                                          Zhang Xianyi
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <string.h>

#ifdef COMPILER_MSVC
#include <intrin.h>
#endif

#define VENDOR_UNKNOWN       0
#define VENDOR_INTEL         1
#define VENDOR_AMD           2

#define CPUNAME_GENERIC      0
#define CPUNAME_SANDYBRIDGE  1
#define CPUNAME_HASWELL      2
//temp set to generic
#define CPUNAME_BULLDOZER    0
#define CPUNAME_PILEDRIVER   0

static char *cpuname[] = {
  "generic",
  "sandybridge",
  "haswell",
};

#define BITMASK(a, b, c) ((((a) >> (b)) & (c)))

static void cpuid(int op, int *eax, int *ebx, int *ecx, int *edx){
#ifdef COMPILER_MSVC
  int cpuinfo[4];
  __cpuid(cpuinfo, op);
  *eax=cpuinfo[0];
  *ebx=cpuinfo[1];
  *ecx=cpuinfo[2];
  *edx=cpuinfo[3];
#else
#if defined(__i386__) && defined(__PIC__)
  __asm__ __volatile__
    ("mov %%ebx, %%edi;"
     "cpuid;"
     "xchgl %%ebx, %%edi;"
     : "=a" (*eax), "=D" (*ebx), "=c" (*ecx), "=d" (*edx) : "a" (op) : "cc");
#else
  __asm__ __volatile__
    ("cpuid": "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx) : "a" (op) : "cc");
#endif
#endif
}

static int have_cpuid(void){
  int eax, ebx, ecx, edx;

  cpuid(0, &eax, &ebx, &ecx, &edx);
  return eax;
}


int get_vendor(void){
  int eax, ebx, ecx, edx;
  char vendor[13];

  cpuid(0, &eax, &ebx, &ecx, &edx);

  *(int *)(&vendor[0]) = ebx;
  *(int *)(&vendor[4]) = edx;
  *(int *)(&vendor[8]) = ecx;
  vendor[12] = (char)0;

  if (!strcmp(vendor, "GenuineIntel")) return VENDOR_INTEL;
  if (!strcmp(vendor, "AuthenticAMD")) return VENDOR_AMD;

  if ((eax == 0) || ((eax & 0x500) != 0)) return VENDOR_INTEL;

  return VENDOR_UNKNOWN;
}


static void xgetbv(int op, int * eax, int * edx){
#ifdef COMPILER_MSVC
  *eax=6; //Assume support for MSVC.
#else
  //Use binary code for xgetbv
  __asm__ __volatile__
    (".byte 0x0f, 0x01, 0xd0": "=a" (*eax), "=d" (*edx) : "c" (op) : "cc");
#endif
}

int support_avx(){
  int eax, ebx, ecx, edx;
  int ret=0;

  cpuid(1, &eax, &ebx, &ecx, &edx);
  if ((ecx & (1 << 28)) != 0 && (ecx & (1 << 27)) != 0 && (ecx & (1 << 26)) != 0){
    xgetbv(0, &eax, &edx);
    if((eax & 6) == 6){
      ret=1;  //OS support AVX
    }
  }
  return ret;
}



int cpu_detect()
{
  int eax, ebx, ecx, edx;
  int vendor, family, extend_family, model, extend_model;

  if (!have_cpuid()) return CPUNAME_GENERIC;

  vendor=get_vendor();

  cpuid(1, &eax, &ebx, &ecx, &edx);
  extend_family = BITMASK(eax, 20, 0xff);
  extend_model=BITMASK(eax, 16, 0x0f);
  family=BITMASK(eax,  8, 0x0f);
  model=BITMASK(eax,  4, 0x0f);

  if (vendor == VENDOR_INTEL){
  /*fprintf(stderr, "family %x exmodel %d  model %d\n",family,extend_model,model);*/
    switch (family) {
    case 0x6:
      switch (extend_model) {
      case 2:
	switch (model) {
	case 10:
	case 13:
	  if(support_avx()) {
	    return CPUNAME_SANDYBRIDGE;
	  }else{
	    return CPUNAME_GENERIC; //OS doesn't support AVX
	  }
	}
	break;
      case 3:
	switch (model) {
	case 10:
	case 14:
	  //Ivy Bridge
	  if(support_avx()) {
	    return CPUNAME_SANDYBRIDGE;
	  }else{
	    return CPUNAME_GENERIC; //OS doesn't support AVX
	  }
	case 12:
	case 15:
	  //Haswell. 
	  if(support_avx()) {
	    return CPUNAME_HASWELL;
	  }else{
	    return CPUNAME_GENERIC; //OS doesn't support AVX
	  }
	case 13:
	  //broadwell
	  if(support_avx()) {
	    return CPUNAME_HASWELL;
	  }else{
	    return CPUNAME_GENERIC; //OS doesn't support AVX
	  }
	}
	break;
      case 4:
        switch (model) {
        case 5:
	case 6:
	  //Haswell.
	  if(support_avx()) {
	    return CPUNAME_HASWELL;
	  }else{
	    return CPUNAME_GENERIC; //OS doesn't support AVX
	  }
	case 7:
	case 15:
	  //broadwell
	  if(support_avx()) {
	    return CPUNAME_HASWELL;
	  }else{
	    return CPUNAME_GENERIC; //OS doesn't support AVX
	  }
	case 14:
	  //skylake
	  if(support_avx()) {
	    return CPUNAME_HASWELL;
	  }else{
	    return CPUNAME_GENERIC; //OS doesn't support AVX
	  }
	}
        break;
      case 5:
	switch (model) {
	case 6:
	  //broadwell
	  if(support_avx()) {
	    return CPUNAME_HASWELL;
	  }else{
	    return CPUNAME_GENERIC; //OS doesn't support AVX
	  }
	case 5:
	case 14:
	  //skylake
	  if(support_avx()) {
	    return CPUNAME_HASWELL;
	  }else{
	    return CPUNAME_GENERIC; //OS doesn't support AVX
	  }
	}
	break;
      case 8: 
        switch (model) {
        case 14: // Kaby Lake
          if(support_avx())
            return CPUNAME_HASWELL;
          else
            return CPUNAME_GENERIC;
        }
        break;    
      }
      break;
    }
  }else if (vendor == VENDOR_AMD){
    switch (family) {
    case 0xf:
      switch (extend_family) {
      case 6:
	switch (model) {
	case 1:
	  if(support_avx())
	    return CPUNAME_BULLDOZER;
	  else
	    return CPUNAME_GENERIC; //OS don't support AVX.
	case 2:
	  if(support_avx())
	    return CPUNAME_PILEDRIVER;
	  else
	    return CPUNAME_GENERIC; //OS don't support AVX.
	case 0:
	  //Steamroller. Temp use Piledriver.
	  if(support_avx())
	    return CPUNAME_PILEDRIVER;
	  else
	    return CPUNAME_GENERIC; //OS don't support AVX.
	}
      }
      break;
    }
  }

  return CPUNAME_GENERIC;
}


int main()
{
  int cpuname_id;

  cpuname_id=cpu_detect();

  printf("%s", cpuname[cpuname_id]);
  return 0;
}

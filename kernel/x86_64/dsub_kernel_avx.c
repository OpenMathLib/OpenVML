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

#include "openvml_kernel.h"

#include <immintrin.h>

void KERNEL_NAME(VMLLONG n, VML_FLOAT * a, VML_FLOAT * b, VML_FLOAT * y, VML_FLOAT * z, VML_FLOAT * other_params) {
  VMLLONG loop_count=(COMPSIZE*n) >> 5;
  VMLLONG remain_count=(COMPSIZE*n) & 0x1f;

  int i=0;

  while(loop_count>0){

    __m256d av0=_mm256_loadu_pd(a);
    __m256d av1=_mm256_loadu_pd(a+4);
    __m256d av2=_mm256_loadu_pd(a+8);
    __m256d av3=_mm256_loadu_pd(a+12);

    __m256d av4=_mm256_loadu_pd(a+16);
    __m256d av5=_mm256_loadu_pd(a+20);
    __m256d av6=_mm256_loadu_pd(a+24);
    __m256d av7=_mm256_loadu_pd(a+28);


    __m256d bv0=_mm256_loadu_pd(b);
    __m256d bv1=_mm256_loadu_pd(b+4);
    __m256d bv2=_mm256_loadu_pd(b+8);
    __m256d bv3=_mm256_loadu_pd(b+12);

    __m256d bv4=_mm256_loadu_pd(b+16);
    __m256d bv5=_mm256_loadu_pd(b+20);
    __m256d bv6=_mm256_loadu_pd(b+24);
    __m256d bv7=_mm256_loadu_pd(b+28);




    __m256d yv0=_mm256_sub_pd(av0, bv0);
    __m256d yv1=_mm256_sub_pd(av1, bv1);
    __m256d yv2=_mm256_sub_pd(av2, bv2);
    __m256d yv3=_mm256_sub_pd(av3, bv3);

    __m256d yv4=_mm256_sub_pd(av4, bv4);
    __m256d yv5=_mm256_sub_pd(av5, bv5);
    __m256d yv6=_mm256_sub_pd(av6, bv6);
    __m256d yv7=_mm256_sub_pd(av7, bv7);

    _mm256_storeu_pd(y, yv0);
    _mm256_storeu_pd(y+4, yv1);
    _mm256_storeu_pd(y+8, yv2);
    _mm256_storeu_pd(y+12, yv3);

    _mm256_storeu_pd(y+16, yv4);
    _mm256_storeu_pd(y+20, yv5);
    _mm256_storeu_pd(y+24, yv6);
    _mm256_storeu_pd(y+28, yv7);

    a+=32;
    b+=32;
    y+=32;
    loop_count--;
  }

  for(i=0; i<remain_count; i++){
    y[i]=a[i]-b[i];
  }
}

#if 0
void KERNEL_NAME(VMLLONG n, VML_FLOAT * a, VML_FLOAT * b, VML_FLOAT * y, VML_FLOAT * z, VML_FLOAT * other_params) {

  //unroll 32
  VMLLONG loop_count=(COMPSIZE*n) >> 5;
  VMLLONG remain_count=(COMPSIZE*n) & 0x1f;

  __asm__ volatile 
  (
   "                                        \n\t"
   "                                        \n\t"
   "cmpq        $0, %3                      \n\t" //loop_count
   "je          Remain                      \n\t"
   "Mainloop:                               \n\t"
   "vmovupd     (%0),   %%ymm0              \n\t" //read a
   "vmovupd     32(%0), %%ymm1              \n\t"
   "vmovupd     64(%0), %%ymm2              \n\t"
   "vmovupd     96(%0), %%ymm3              \n\t"

   "vmovupd     128(%0), %%ymm4             \n\t"
   "vmovupd     160(%0), %%ymm5             \n\t"
   "vmovupd     192(%0), %%ymm6             \n\t"
   "vmovupd     224(%0), %%ymm7             \n\t"

   "vmovupd     (%1),   %%ymm8              \n\t" //read b
   "vmovupd     32(%1), %%ymm9              \n\t"
   "vmovupd     64(%1), %%ymm10              \n\t"
   "vmovupd     96(%1), %%ymm11              \n\t"

   "vmovupd     128(%1), %%ymm12             \n\t"
   "vmovupd     160(%1), %%ymm13             \n\t"
   "vmovupd     192(%1), %%ymm14             \n\t"
   "vmovupd     224(%1), %%ymm15             \n\t"


   "vsubpd      %%ymm8, %%ymm0,  %%ymm8      \n\t"
   "vsubpd      %%ymm9, %%ymm1,  %%ymm9      \n\t"
   "vsubpd      %%ymm10, %%ymm2, %%ymm10     \n\t"
   "vsubpd      %%ymm11, %%ymm3, %%ymm11     \n\t"

   "vsubpd      %%ymm12, %%ymm4, %%ymm12     \n\t"
   "vsubpd      %%ymm13, %%ymm5, %%ymm13     \n\t"
   "vsubpd      %%ymm14, %%ymm6, %%ymm14     \n\t"
   "vsubpd      %%ymm15, %%ymm7, %%ymm15     \n\t"

   "addq        $256,  %0                    \n\t"
   "addq        $256,  %1                    \n\t"

   "vmovupd     %%ymm8,  (%2)                \n\t"
   "vmovupd     %%ymm9,  32(%2)              \n\t"
   "vmovupd     %%ymm10, 64(%2)              \n\t"
   "vmovupd     %%ymm11, 96(%2)              \n\t"

   "vmovupd     %%ymm12, 128(%2)             \n\t"
   "vmovupd     %%ymm13, 160(%2)             \n\t"
   "vmovupd     %%ymm14, 192(%2)             \n\t"
   "vmovupd     %%ymm15, 224(%2)             \n\t"

   "addq        $256,  %2                    \n\t"
   "subq        $1,   %3                     \n\t"
   "jnz         Mainloop                     \n\t"

   "Remain:                                 \n\t"
   "cmpq        $0, %4                      \n\t"//remain_count
   "je          End                         \n\t"
   "Remainloop:                             \n\t"
   "vmovsd      (%0), %%xmm0                \n\t"
   "vmovsd      (%1), %%xmm1                \n\t"
   "vsubsd      %%xmm1, %%xmm0, %%xmm1      \n\t"
   "addq        $8,   %0                    \n\t"
   "addq        $8,   %1                    \n\t"
   "vmovsd      %%xmm1, (%2)                \n\t"
   "addq        $8,   %2                    \n\t"
   "subq        $1,   %4                    \n\t"
   "jnz         Remainloop                  \n\t"
   "End:                                    \n\t"
  ://output
  ://input 
   "r"(a), //0
   "r"(b), //1
   "r"(y), //2
   "r"(loop_count), //3
   "r"(remain_count) //4
  ://register clobber list
   "%xmm0", "%xmm1", "%xmm2","%xmm3", //for a
   "%xmm4", "%xmm5", "%xmm6","%xmm7", //
   "%xmm8", "%xmm9", "%xmm10","%xmm11", //for b
   "%xmm12", "%xmm13", "%xmm14","%xmm15", //
   "memory"
  );
}
#endif

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

    __m256 av0=_mm256_loadu_ps(a);
    __m256 av1=_mm256_loadu_ps(a+8);
    __m256 av2=_mm256_loadu_ps(a+16);
    __m256 av3=_mm256_loadu_ps(a+24);

    __m256 bv0=_mm256_loadu_ps(b);
    __m256 bv1=_mm256_loadu_ps(b+8);
    __m256 bv2=_mm256_loadu_ps(b+16);
    __m256 bv3=_mm256_loadu_ps(b+24);


    __m256 yv0=_mm256_sub_ps(av0, bv0);
    __m256 yv1=_mm256_sub_ps(av1, bv1);
    __m256 yv2=_mm256_sub_ps(av2, bv2);
    __m256 yv3=_mm256_sub_ps(av3, bv3);


    _mm256_storeu_ps(y, yv0);
    _mm256_storeu_ps(y+8, yv1);
    _mm256_storeu_ps(y+16, yv2);
    _mm256_storeu_ps(y+24, yv3);

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
   "vmovups     (%0),   %%ymm0              \n\t" //read a
   "vmovups     32(%0), %%ymm1              \n\t"
   "vmovups     64(%0), %%ymm2              \n\t"
   "vmovups     96(%0), %%ymm3              \n\t"

   "vmovups     (%1),   %%ymm8              \n\t" //read b
   "vmovups     32(%1), %%ymm9              \n\t"
   "vmovups     64(%1), %%ymm10              \n\t"
   "vmovups     96(%1), %%ymm11              \n\t"

   "vsubps      %%ymm8, %%ymm0,  %%ymm8      \n\t"
   "vsubps      %%ymm9, %%ymm1,  %%ymm9      \n\t"
   "vsubps      %%ymm10, %%ymm2, %%ymm10     \n\t"
   "vsubps      %%ymm11, %%ymm3, %%ymm11     \n\t"

   "addq        $128,  %0                    \n\t"
   "addq        $128,  %1                    \n\t"

   "vmovups     %%ymm8,  (%2)                \n\t"
   "vmovups     %%ymm9,  32(%2)              \n\t"
   "vmovups     %%ymm10, 64(%2)              \n\t"
   "vmovups     %%ymm11, 96(%2)              \n\t"

   "addq        $128,  %2                    \n\t"
   "subq        $1,   %3                     \n\t"
   "jnz         Mainloop                     \n\t"

   "Remain:                                 \n\t"
   "cmpq        $0, %4                      \n\t"//remain_count
   "je          End                         \n\t"
   "Remainloop:                             \n\t"
   "vmovss      (%0), %%xmm0                \n\t"
   "vmovss      (%1), %%xmm1                \n\t"
   "vsubss      %%xmm1, %%xmm0, %%xmm1      \n\t"
   "addq        $4,   %0                    \n\t"
   "addq        $4,   %1                    \n\t"
   "vmovss      %%xmm1, (%2)                \n\t"
   "addq        $4,   %2                    \n\t"
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
   //"%xmm4", "%xmm5", "%xmm6","%xmm7", 
   "%xmm8", "%xmm9", "%xmm10","%xmm11", //for b
   //"%xmm12", "%xmm13", "%xmm14","%xmm15",
   "memory"
  );
}
#endif

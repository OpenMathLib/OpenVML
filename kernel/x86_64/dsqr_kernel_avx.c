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


    __m256d yv0=_mm256_mul_pd(av0, av0);
    __m256d yv1=_mm256_mul_pd(av1, av1);
    __m256d yv2=_mm256_mul_pd(av2, av2);
    __m256d yv3=_mm256_mul_pd(av3, av3);

    __m256d yv4=_mm256_mul_pd(av4, av4);
    __m256d yv5=_mm256_mul_pd(av5, av5);
    __m256d yv6=_mm256_mul_pd(av6, av6);
    __m256d yv7=_mm256_mul_pd(av7, av7);

    _mm256_storeu_pd(y, yv0);
    _mm256_storeu_pd(y+4, yv1);
    _mm256_storeu_pd(y+8, yv2);
    _mm256_storeu_pd(y+12, yv3);

    _mm256_storeu_pd(y+16, yv4);
    _mm256_storeu_pd(y+20, yv5);
    _mm256_storeu_pd(y+24, yv6);
    _mm256_storeu_pd(y+28, yv7);

    a+=32;
    y+=32;
    loop_count--;
  }

  for(i=0; i<remain_count; i++){
    y[i]=a[i]*a[i];
  }
}


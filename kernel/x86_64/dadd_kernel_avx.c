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


   "vaddpd      %%ymm0, %%ymm8,  %%ymm8      \n\t"
   "vaddpd      %%ymm1, %%ymm9,  %%ymm9      \n\t"
   "vaddpd      %%ymm2, %%ymm10, %%ymm10     \n\t"
   "vaddpd      %%ymm3, %%ymm11, %%ymm11     \n\t"

   "vaddpd      %%ymm4, %%ymm12, %%ymm12     \n\t"
   "vaddpd      %%ymm5, %%ymm13, %%ymm13     \n\t"
   "vaddpd      %%ymm6, %%ymm14, %%ymm14     \n\t"
   "vaddpd      %%ymm7, %%ymm15, %%ymm15     \n\t"

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
   "vaddsd      %%xmm0, %%xmm1, %%xmm1      \n\t"
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

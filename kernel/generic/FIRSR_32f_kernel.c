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

int KERNEL_NAME(const float* pSrc, float* pDst, int numIters, FIRSpec_32f* pSpec, const float* pDlySrc, float* pDlyDst, unsigned char* pBuf)
{
    if (pSrc == NULL || pDst == NULL || pBuf == NULL)
    {
        return tsNULLPtrErr;
    }
    
    int index;
    double y;
    int j, k;
    float* pWorkBuf = (float*)pBuf;

    if (pDlySrc == NULL)
    {
        for (k = 0; k < pSpec->tapsLen - 1; k++)
        {
            pWorkBuf[k] = 0;
        }
    }
    else
    {
        for (k = 0; k < pSpec->tapsLen - 1; k++)
        {
            pWorkBuf[k] = pDlySrc[pSpec->tapsLen - 2 - k];
        }
    }

    index = pSpec->tapsLen - 2;
    for (int i = 0; i < numIters; i++)
    {
        y = pSpec->pTaps[0] * pSrc[i];
        for (j = index + 1; j < pSpec->tapsLen - 1; j++)
        {
            y += pSpec->pTaps[j - index] * pWorkBuf[j];
        }

        for (k = 0; k <= index; k++)
        {
            y += pSpec->pTaps[pSpec->tapsLen - 1 + k - index] * pWorkBuf[k];
        }

        pDst[i] = y;
        pWorkBuf[index] = pSrc[i];

        index = index == 0 ? pSpec->tapsLen - 2 : index - 1;
    }

    if (pDlyDst != NULL)
    {
        for (j = 0; j < pSpec->tapsLen - 1; j++)
        {
            pDlyDst[j] = pSrc[numIters - pSpec->tapsLen + 1 + j];
        }
    }

    return tsNoErr;
}

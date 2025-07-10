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

#ifndef _OPENVML_H_
#define _OPENVML_H_

#include "openvml_export.h"
#include "openvml_common.h"

#ifdef __cplusplus
extern "C" {
#endif

OPENVML_EXPORT char* OpenVML_FUNCNAME(openvml_get_config)();


OPENVML_EXPORT void OpenVML_FUNCNAME(vsAdd)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdAdd)(const VML_INT n, const double * a, const double * b, double * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vcAdd)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vzAdd)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsSub)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdSub)(const VML_INT n, const double * a, const double * b, double * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vcSub)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vzSub)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsSqr)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdSqr)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsPow)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdPow)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsPowx)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdPowx)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsPow2o3)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdPow2o3)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsPow3o2)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdPow3o2)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsExp)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdExp)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsExpm1)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdExpm1)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsLog10)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdLog10)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsLn)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdLn)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsLog1p)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdLog1p)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsTanh)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdTanh)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsFloor)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdFloor)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsSin)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdSin)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsCos)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdCos)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsSinCos)(const VML_INT n, const float * a, float * y, float * z);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdSinCos)(const VML_INT n, const double * a, double * y, double * z);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsTan)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdTan)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsAsin)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdAsin)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsAcos)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdAcos)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsAtan)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdAtan)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsAtan2)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdAtan2)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsFmax)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdFmax)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsFmin)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdFmin)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT double OpenVML_FUNCNAME(vsMean)(const VML_INT n, const float * a);
OPENVML_EXPORT double OpenVML_FUNCNAME(vdMean)(const VML_INT n, const double * a);

OPENVML_EXPORT double OpenVML_FUNCNAME(vsVariance)(const VML_INT n, const float * a);
OPENVML_EXPORT double OpenVML_FUNCNAME(vdVariance)(const VML_INT n, const double * a);

OPENVML_EXPORT int OpenVML_FUNCNAME(FIRSRGetSize)(const VML_INT n, const DataType tapsType, VML_INT * pSpecSize, VML_INT * pBufSize);

OPENVML_EXPORT int OpenVML_FUNCNAME(FIRSRInit_32f)(const float* pTaps, VML_INT tapsLen, AlgType algType, FIRSpec_32f* pSpec);

OPENVML_EXPORT int OpenVML_FUNCNAME(FIRSR_32f)(const float* pSrc, float* pDst, int numIters, FIRSpec_32f* pSpec, const float* pDlySrc, float* pDlyDst, unsigned char* pBuf);

#ifdef __cplusplus
}
#endif
#endif

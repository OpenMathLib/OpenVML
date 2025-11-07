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

#ifndef _OPENVML_REFERENCE_H_
#define _OPENVML_REFERENCE_H_

#include "openvml_export.h"
#include "openvml_common.h"

#define OpenVML_FUNCNAME_REF(x) x##_ref


#ifdef __cplusplus
extern "C" {
#endif

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsAdd)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdAdd)(const VML_INT n, const double * a, const double * b, double * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vcAdd)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vzAdd)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsSub)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdSub)(const VML_INT n, const double * a, const double * b, double * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vcSub)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vzSub)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsSqr)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdSqr)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsPow)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdPow)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsPowx)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdPowx)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsPow2o3)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdPow2o3)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsPow3o2)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdPow3o2)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsExp)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdExp)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsExp2)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdExp2)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsExp10)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdExp10)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsExpm1)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdExpm1)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsLog2)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdLog2)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsLog10)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdLog10)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsLn)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdLn)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsLog1p)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdLog1p)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsTanh)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdTanh)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsFloor)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdFloor)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsSin)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdSin)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsCos)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdCos)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsSinCos)(const VML_INT n, const float * a, float * y, float * z);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdSinCos)(const VML_INT n, const double * a, double * y, double * z);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsTan)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdTan)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsAsin)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdAsin)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsAcos)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdAcos)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsAtan)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdAtan)(const VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsAtan2)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdAtan2)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsFmax)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdFmax)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsFmin)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdFmin)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT double OpenVML_FUNCNAME_REF(vsMean)(const VML_INT n, const float * a);
OPENVML_EXPORT double OpenVML_FUNCNAME_REF(vdMean)(const VML_INT n, const double * a);

OPENVML_EXPORT double OpenVML_FUNCNAME_REF(vsVariance)(const VML_INT n, const float * a);
OPENVML_EXPORT double OpenVML_FUNCNAME_REF(vdVariance)(const VML_INT n, const double * a);

OPENVML_EXPORT int OpenVML_FUNCNAME_REF(FIRSRGetSize)(const VML_INT n, const DataType tapsType, VML_INT * pSpecSize, VML_INT * pBufSize);

OPENVML_EXPORT int OpenVML_FUNCNAME_REF(FIRSRInit_32f)(const float* pTaps, VML_INT tapsLen, AlgType algType, FIRSpec_32f* pSpec);

OPENVML_EXPORT int OpenVML_FUNCNAME_REF(FIRSR_32f)(const float* pSrc, float* pDst, int numIters, FIRSpec_32f* pSpec, const float* pDlySrc, float* pDlyDst, unsigned char* pBuf);

#ifdef __cplusplus
}
#endif

#endif

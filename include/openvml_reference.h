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

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsPow)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdPow)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsPowx)(const VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdPowx)(const VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vsExp)(const VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME_REF(vdExp)(const VML_INT n, const double * a, double * y);

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

#ifdef __cplusplus
}
#endif

#endif

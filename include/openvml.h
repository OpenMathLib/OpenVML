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


OPENVML_EXPORT void OpenVML_FUNCNAME(vsAdd)(VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdAdd)(VML_INT n, const double * a, const double * b, double * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vcAdd)(VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vzAdd)(VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsSub)(VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdSub)(VML_INT n, const double * a, const double * b, double * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vcSub)(VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vzSub)(VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsPow)(VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdPow)(VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsExp)(VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdExp)(VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsLog10)(VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdLog10)(VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsLn)(VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdLn)(VML_INT n, const double * a, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsTanh)(VML_INT n, const float * a, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdTanh)(VML_INT n, const double * a, double * y);


#ifdef __cplusplus
}
#endif
#endif

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

#ifndef _OPENVML_KERNEL_H_
#define _OPENVML_KERNEL_H_

#include "openvml_common.h"
#include "openvml_macros.h"
#include <stdlib.h>


void OpenVML_FUNCNAME(sadd_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dadd_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(cadd_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zadd_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(ssub_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dsub_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(csub_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zsub_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);


void OpenVML_FUNCNAME(spow_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dpow_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(cpow_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zpow_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);


void OpenVML_FUNCNAME(sexp_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dexp_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(cexp_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zexp_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);


void OpenVML_FUNCNAME(slog10_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dlog10_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(clog10_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zlog10_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);


void OpenVML_FUNCNAME(sln_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dln_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(cln_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zln_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);


void OpenVML_FUNCNAME(stanh_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dtanh_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(ctanh_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(ztanh_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

#endif

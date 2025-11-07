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

void OpenVML_FUNCNAME(ssqr_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(sdqr_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(spow_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dpow_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(cpow_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zpow_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(spowx_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dpowx_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(cpowx_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zpowx_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);


void OpenVML_FUNCNAME(sexp_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dexp_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(cexp_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zexp_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(sexp2_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dexp2_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(cexp2_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zexp2_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(sexp10_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dexp10_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(cexp10_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zexp10_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);



void OpenVML_FUNCNAME(sexpm1_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dexpm1_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(cexpm1_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zexpm1_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(slog2_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dlog2_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(clog2_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zlog2_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(slog10_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dlog10_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(clog10_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zlog10_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);


void OpenVML_FUNCNAME(sln_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dln_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(cln_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zln_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);


void OpenVML_FUNCNAME(slog1p_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dlog1p_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(clog1p_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zlog1p_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);


void OpenVML_FUNCNAME(stanh_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dtanh_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(ctanh_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(ztanh_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);


void OpenVML_FUNCNAME(sfloor_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dfloor_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(ssin_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dsin_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(csin_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zsin_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(scos_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dcos_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(ccos_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zcos_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(ssincos_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dsincos_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(csincos_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zsincos_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(stan_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dtan_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(ctan_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(ztan_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(sasin_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dasin_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(casin_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zasin_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(sacos_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dacos_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(cacos_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zacos_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(satan_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(datan_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);
void OpenVML_FUNCNAME(catan_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(zatan_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(satan2_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(datan2_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(sfmax_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dfmax_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

void OpenVML_FUNCNAME(sfmin_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
void OpenVML_FUNCNAME(dfmin_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

double OpenVML_FUNCNAME(smean_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
double OpenVML_FUNCNAME(dmean_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

double OpenVML_FUNCNAME(svariance_k)(VMLLONG n, float * a, float * b, float * y, float * z, float * other_params);
double OpenVML_FUNCNAME(dvariance_k)(VMLLONG n, double * a, double * b, double * y, double * z, double * other_params);

int FIRSRGetSize_k(const VML_INT n, const DataType tapsType, VML_INT * pSpecSize, VML_INT * pBufSize);

int FIRSRInit_32f_k(const float* pTaps, VML_INT tapsLen, AlgType algType, FIRSpec_32f* pSpec);

int FIRSR_32f_k(const float* pSrc, float* pDst, int numIters, FIRSpec_32f* pSpec, const float* pDlySrc, float* pDlyDst, unsigned char* pBuf);
#endif

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

#ifndef _OPENVML_MACROS_H_
#define _OPENVML_MACROS_H_

#ifndef COMPLEX
#define COMPSIZE  1
#else
#define COMPSIZE  2
#endif


#define SADD_K OpenVML_FUNCNAME(sadd_k)
#define DADD_K OpenVML_FUNCNAME(dadd_k)
#define CADD_K OpenVML_FUNCNAME(cadd_k)
#define ZADD_K OpenVML_FUNCNAME(zadd_k)

#define SSUB_K OpenVML_FUNCNAME(ssub_k)
#define DSUB_K OpenVML_FUNCNAME(dsub_k)
#define CSUB_K OpenVML_FUNCNAME(csub_k)
#define ZSUB_K OpenVML_FUNCNAME(zsub_k)

#define SSQR_K OpenVML_FUNCNAME(ssqr_k)
#define DSQR_K OpenVML_FUNCNAME(dsqr_k)

#define SPOW_K OpenVML_FUNCNAME(spow_k)
#define DPOW_K OpenVML_FUNCNAME(dpow_k)
#define CPOW_K OpenVML_FUNCNAME(cpow_k)
#define ZPOW_K OpenVML_FUNCNAME(zpow_k)

#define SPOWX_K OpenVML_FUNCNAME(spowx_k)
#define DPOWX_K OpenVML_FUNCNAME(dpowx_k)
#define CPOWX_K OpenVML_FUNCNAME(cpowx_k)
#define ZPOWX_K OpenVML_FUNCNAME(zpowx_k)

#define SEXP_K OpenVML_FUNCNAME(sexp_k)
#define DEXP_K OpenVML_FUNCNAME(dexp_k)
#define CEXP_K OpenVML_FUNCNAME(cexp_k)
#define ZEXP_K OpenVML_FUNCNAME(zexp_k)

#define SEXPM1_K OpenVML_FUNCNAME(sexpm1_k)
#define DEXPM1_K OpenVML_FUNCNAME(dexpm1_k)
#define CEXPM1_K OpenVML_FUNCNAME(cexpm1_k)
#define ZEXPM1_K OpenVML_FUNCNAME(zexpm1_k)

#define SLOG10_K OpenVML_FUNCNAME(slog10_k)
#define DLOG10_K OpenVML_FUNCNAME(dlog10_k)
#define CLOG10_K OpenVML_FUNCNAME(clog10_k)
#define ZLOG10_K OpenVML_FUNCNAME(zlog10_k)

#define SLN_K OpenVML_FUNCNAME(sln_k)
#define DLN_K OpenVML_FUNCNAME(dln_k)
#define CLN_K OpenVML_FUNCNAME(cln_k)
#define ZLN_K OpenVML_FUNCNAME(zln_k)

#define SLOG1P_K OpenVML_FUNCNAME(slog1p_k)
#define DLOG1P_K OpenVML_FUNCNAME(dlog1p_k)
#define CLOG1P_K OpenVML_FUNCNAME(clog1p_k)
#define ZLOG1P_K OpenVML_FUNCNAME(zlog1p_k)

#define STANH_K OpenVML_FUNCNAME(stanh_k)
#define DTANH_K OpenVML_FUNCNAME(dtanh_k)
#define CTANH_K OpenVML_FUNCNAME(ctanh_k)
#define ZTANH_K OpenVML_FUNCNAME(ztanh_k)

#define SFLOOR_K OpenVML_FUNCNAME(sfloor_k)
#define DFLOOR_K OpenVML_FUNCNAME(dfloor_k)

#define SFMAX_K OpenVML_FUNCNAME(sfmax_k)
#define DFMAX_K OpenVML_FUNCNAME(dfmax_k)

#define SFMIN_K OpenVML_FUNCNAME(sfmin_k)
#define DFMIN_K OpenVML_FUNCNAME(dfmin_k)

#define SMEAN_K OpenVML_FUNCNAME(smean_k)
#define DMEAN_K OpenVML_FUNCNAME(dmean_k)

#define SVARIANCE_K OpenVML_FUNCNAME(svariance_k)
#define DVARIANCE_K OpenVML_FUNCNAME(dvariance_k)

#define FIRSRGETSIZE_k OpenVML_FUNCNAME(FIRSRGetSize_k)

#define FIRSRINIT_32F_k OpenVML_FUNCNAME(FIRSRInit_32f_k)

#define FIRSR_32F_k OpenVML_FUNCNAME(FIRSR_32f_k)

#define SSIN_K OpenVML_FUNCNAME(ssin_k)
#define DSIN_K OpenVML_FUNCNAME(dsin_k)

#define SCOS_K OpenVML_FUNCNAME(scos_k)
#define DCOS_K OpenVML_FUNCNAME(dcos_k)

#define SSINCOS_K OpenVML_FUNCNAME(ssincos_k)
#define DSINCOS_K OpenVML_FUNCNAME(dsincos_k)

#define STAN_K OpenVML_FUNCNAME(stan_k)
#define DTAN_K OpenVML_FUNCNAME(dtan_k)

#define SASIN_K OpenVML_FUNCNAME(sasin_k)
#define DASIN_K OpenVML_FUNCNAME(dasin_k)

#define SACOS_K OpenVML_FUNCNAME(sacos_k)
#define DACOS_K OpenVML_FUNCNAME(dacos_k)

#define SATAN_K OpenVML_FUNCNAME(satan_k)
#define DATAN_K OpenVML_FUNCNAME(datan_k)

#define SATAN2_K OpenVML_FUNCNAME(satan2_k)
#define DATAN2_K OpenVML_FUNCNAME(datan2_k)

#ifndef COMPLEX
#ifndef DOUBLE
#define ADD_K SADD_K
#define SUB_K SSUB_K
#define SQR_K SSQR_K
#define POW_K SPOW_K
#define POWX_K SPOWX_K
#define EXP_K SEXP_K
#define EXPM1_K SEXPM1_K
#define LOG10_K SLOG10_K
#define LN_K SLN_K
#define LOG1P_K SLOG1P_K
#define TANH_K STANH_K
#define FLOOR_K SFLOOR_K
#define FMAX_K SFMAX_K
#define FMIN_K SFMIN_K
#define MEAN_K SMEAN_K
#define VARIANCE_K SVARIANCE_K
#define FIRSRGETSIZE_K FIRSRGETSIZE_k
#define FIRSRINIT_32F_K FIRSRINIT_32F_k
#define FIRSR_32F_K FIRSR_32F_k
#define SIN_K SSIN_K
#define COS_K SCOS_K
#define SINCOS_K SSINCOS_K
#define TAN_K STAN_K
#define ASIN_K SASIN_K
#define ACOS_K SACOS_K
#define ATAN_K SATAN_K
#define ATAN2_K SATAN2_K
#else
#define ADD_K DADD_K
#define SUB_K DSUB_K
#define SQR_K DSQR_K
#define POW_K DPOW_K
#define POWX_K DPOWX_K
#define EXP_K DEXP_K
#define EXPM1_K DEXPM1_K
#define LOG10_K DLOG10_K
#define LN_K DLN_K
#define LOG1P_K DLOG1P_K
#define TANH_K DTANH_K
#define FLOOR_K DFLOOR_K
#define FMAX_K DFMAX_K
#define FMIN_K DFMIN_K
#define MEAN_K DMEAN_K
#define VARIANCE_K DVARIANCE_K
#define FIRSRGETSIZE_K FIRSRGETSIZE_k
#define FIRSRINIT_32F_K FIRSRINIT_32F_k
#define FIRSR_32F_K FIRSR_32F_k
#define SIN_K DSIN_K
#define COS_K DCOS_K
#define SINCOS_K DSINCOS_K
#define TAN_K DTAN_K
#define ASIN_K DASIN_K
#define ACOS_K DACOS_K
#define ATAN_K DATAN_K
#define ATAN2_K DATAN2_K
#endif
#else
#ifndef DOUBLE
#define ADD_K CADD_K
#define SUB_K CSUB_K
#define POW_K CPOW_K
#define POWX_K CPOWX_K
#define EXP_K CEXP_K
#define EXPM1_K CEXPM1_K
#define LOG10_K CLOG10_K
#define LN_K CLN_K
#define LOG1P_K CLOG1P_K
#define TANH_K CTANH_K
#define SIN_K CSIN_K
#define COS_K CCOS_K
#define SINCOS_K CSINCOS_K
#define TAN_K CTAN_K
#define ASIN_K CASIN_K
#define ACOS_K CACOS_K
#define ATAN_K CATAN_K
#else
#define ADD_K ZADD_K
#define SUB_K ZSUB_K
#define POW_K ZPOW_K
#define POWX_K ZPOWX_K
#define EXP_K ZEXP_K
#define EXPM1_K ZEXPM1_K
#define LOG10_K ZLOG10_K
#define LN_K ZLN_K
#define LOG1P_K ZLOG1P_K
#define TANH_K ZTANH_K
#define SIN_K ZSIN_K
#define COS_K ZCOS_K
#define SINCOS_K ZSINCOS_K
#define TAN_K ZTAN_K
#define ASIN_K ZASIN_K
#define ACOS_K ZACOS_K
#define ATAN_K ZATAN_K
#endif
#endif

#endif

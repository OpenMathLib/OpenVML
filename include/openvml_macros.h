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

#define SPOW_K OpenVML_FUNCNAME(spow_k)
#define DPOW_K OpenVML_FUNCNAME(dpow_k)
#define CPOW_K OpenVML_FUNCNAME(cpow_k)
#define ZPOW_K OpenVML_FUNCNAME(zpow_k)

#define SEXP_K OpenVML_FUNCNAME(sexp_k)
#define DEXP_K OpenVML_FUNCNAME(dexp_k)
#define CEXP_K OpenVML_FUNCNAME(cexp_k)
#define ZEXP_K OpenVML_FUNCNAME(zexp_k)

#define SLOG10_K OpenVML_FUNCNAME(slog10_k)
#define DLOG10_K OpenVML_FUNCNAME(dlog10_k)
#define CLOG10_K OpenVML_FUNCNAME(clog10_k)
#define ZLOG10_K OpenVML_FUNCNAME(zlog10_k)


#define STANH_K OpenVML_FUNCNAME(stanh_k)
#define DTANH_K OpenVML_FUNCNAME(dtanh_k)
#define CTANH_K OpenVML_FUNCNAME(ctanh_k)
#define ZTANH_K OpenVML_FUNCNAME(ztanh_k)


#ifndef COMPLEX
#ifndef DOUBLE
#define ADD_K SADD_K
#define SUB_K SSUB_K
#define POW_K SPOW_K
#define EXP_K SEXP_K
#define LOG10_K SLOG10_K
#define TANH_K STANH_K
#else
#define ADD_K DADD_K
#define SUB_K DSUB_K
#define POW_K DPOW_K
#define EXP_K DEXP_K
#define LOG10_K DLOG10_K
#define TANH_K DTANH_K
#endif
#else
#ifndef DOUBLE
#define ADD_K CADD_K
#define SUB_K CSUB_K
#define POW_K CPOW_K
#define EXP_K CEXP_K
#define LOG10_K CLOG10_K
#define TANH_K CTANH_K
#else
#define ADD_K ZADD_K
#define SUB_K ZSUB_K
#define POW_K ZPOW_K
#define EXP_K ZEXP_K
#define LOG10_K ZLOG10_K
#define TANH_K ZTANH_K
#endif
#endif

#endif

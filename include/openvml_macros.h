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

#define SADD_K OpenVML_FUNCNAME(sadd_k)
#define DADD_K OpenVML_FUNCNAME(dadd_k)
//reuse 
#define CADD_K OpenVML_FUNCNAME(sadd_k)
#define ZADD_K OpenVML_FUNCNAME(dadd_k)


#define SSUB_K OpenVML_FUNCNAME(ssub_k)
#define DSUB_K OpenVML_FUNCNAME(dsub_k)
//reuse 
#define CSUB_K OpenVML_FUNCNAME(ssub_k)
#define ZSUB_K OpenVML_FUNCNAME(dsub_k)


#ifndef COMPLEX
#ifndef DOUBLE
#define ADD_K SADD_K
#define SUB_K SSUB_K
#else
#define ADD_K DADD_K
#define SUB_K DSUB_K
#endif
#else
#ifndef DOUBLE
#define ADD_K CADD_K
#define SUB_K CSUB_K
#else
#define ADD_K ZADD_K
#define SUB_K CSUB_K
#endif
#endif

#endif
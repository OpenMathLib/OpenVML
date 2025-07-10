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

#include "vml_test.h"
#include <stdio.h>
#include <string.h>
#include <openvml_reference.h>

static char* funcname[4]={"vsVariance", "vdVariance", NULL,NULL};
static double flop_per_elem[4]={0.0, 0.0, 0.0, 0.0};

static a_ret_func_t ref_vvariance[] = {
  (a_ret_func_t)OpenVML_FUNCNAME_REF(vsVariance),
  (a_ret_func_t)OpenVML_FUNCNAME_REF(vdVariance),
  NULL,
  NULL,
};

static a_ret_func_t test_vvariance[] = {
  (a_ret_func_t)OpenVML_FUNCNAME(vsVariance),
  (a_ret_func_t)OpenVML_FUNCNAME(vdVariance),
  NULL,
  NULL,
};


CTEST2(check_result_s, variance){
  run_test_a_ret(data->parameter, funcname, test_vvariance, ref_vvariance, flop_per_elem);
}

CTEST2(check_result_d, variance){
  run_test_a_ret(data->parameter, funcname, test_vvariance, ref_vvariance, flop_per_elem);
}

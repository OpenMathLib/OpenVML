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

static char* funcname[4]={"vsSub", "vdSub", NULL,NULL};
static double flop_per_elem[4]={0.0, 0.0, 0.0, 0.0};

static ab_y_func_t ref_vpow[] = {
  (ab_y_func_t)OpenVML_FUNCNAME_REF(vsPow),
  (ab_y_func_t)OpenVML_FUNCNAME_REF(vdPow),
  NULL,
  NULL,
};

static ab_y_func_t test_vpow[] = {
  (ab_y_func_t)OpenVML_FUNCNAME(vsPow),
  (ab_y_func_t)OpenVML_FUNCNAME(vdPow),
  NULL,
  NULL,
};


CTEST2(check_result_s, pow){
  run_test_ab_y(data->parameter, funcname, test_vpow, ref_vpow, flop_per_elem);
}

CTEST2(check_result_d, pow){
  run_test_ab_y(data->parameter, funcname, test_vpow, ref_vpow, flop_per_elem);
}

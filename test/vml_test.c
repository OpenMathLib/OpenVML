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

#include <stdio.h>
#define CTEST_MAIN
#include "vml_test.h"

CTEST_SETUP(check_result_s) {
  init_test_parameter(&(data->parameter), 0, 0);
}

CTEST_SETUP(check_result_d) {
  init_test_parameter(&(data->parameter), 0, 1);
}

CTEST_SETUP(check_result_c) {
  init_test_parameter(&(data->parameter), 1, 0);
}

CTEST_SETUP(check_result_z) {
  init_test_parameter(&(data->parameter), 1, 1);
}

CTEST_TEARDOWN(check_result_s) {
  free_test_parameter(&(data->parameter));
}

CTEST_TEARDOWN(check_result_d) {
  free_test_parameter(&(data->parameter));
}

CTEST_TEARDOWN(check_result_c) {
  free_test_parameter(&(data->parameter));
}

CTEST_TEARDOWN(check_result_z) {
  free_test_parameter(&(data->parameter));
}


int main(int argc, char ** argv){

  int ctest_argc=1;
  char * ctest_argv[3]={NULL,NULL,NULL};

  read_input_flags(argc, argv, &ctest_argc, ctest_argv);

  ctest_main(ctest_argc, (const char **)ctest_argv);

  return 0;
}

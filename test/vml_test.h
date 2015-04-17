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

#ifndef _VML_TEST_H_
#define _VML_TEST_H_

#include <stdlib.h>
#include <openvml.h>

#include "ctest.h"

#define STR_PASS "PASS"
#define STR_WARN "WARN"
#define STR_ERR  "ERROR"

typedef struct {
  double fail;
  double warn;
} eps_t;

typedef struct {
  void * a;
  void * b;
  void * y;
  void * ref_a;
  void * ref_b;
  void * ref_y;

  eps_t * eps;
  VML_INT start;
  VML_INT end;
  VML_INT step;

  int fp_type; //0 for real float, 1 for real double,
               //2 for complex float, 3 for complex double
  int element_size; //4 for float, 8 for double
  int compose_size; //1 for real, 2 for complex

  void * flushcache;
} perf_arg_t;


typedef struct{
  VML_INT start;
  VML_INT end;
  VML_INT step;
  char suitname[1024];
  char testname[1024];
} input_arg_t;

CTEST_DATA(check_result_s) {
  perf_arg_t * parameter;
};

CTEST_DATA(check_result_d) {
  perf_arg_t * parameter;
};

CTEST_DATA(check_result_c) {
  perf_arg_t * parameter;
};

CTEST_DATA(check_result_z) {
  perf_arg_t * parameter;
};

void * vml_test_memory_alloc(size_t size);
void vml_test_memory_free(void * ptr);
//input_arg_t * get_input_arg();

void init_test_parameter(perf_arg_t ** p, int iscomplex, int isdouble);
void free_test_parameter(perf_arg_t ** p);

int check_result(double ref, double test, eps_t* thres);

void init_rand(VML_INT n, void * a, int iscomplex, int isdouble);

typedef void (*ab_y_func_t)(VML_INT, const void *, const void *, void *);
void run_test_ab_y(perf_arg_t * para, char* funcname[], ab_y_func_t*test_func, ab_y_func_t* ref_func,
		   double * flop_per_elem);

typedef void (*a_y_func_t)(VML_INT, const void *, void *);
void run_test_a_y(perf_arg_t * para, char* funcname[], a_y_func_t*test_func, a_y_func_t* ref_func,
		   double * flop_per_elem);
#endif

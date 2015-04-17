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
input_arg_t * get_input_arg();

void init_test_parameter(perf_arg_t ** p, int iscomplex, int isdouble);
void free_test_parameter(perf_arg_t ** p);

int check_result(double ref, double test, eps_t* thres);

void init_rand(VML_INT n, void * a, int iscomplex, int isdouble);

typedef void (*ab_y_func_t)(VML_INT, const void *, const void *, void *);
void run_test_ab_y(perf_arg_t * para, char* funcname[], ab_y_func_t*test_func, ab_y_func_t* ref_func,
		   double * flop_per_elem);
#endif

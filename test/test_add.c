#include "vml_test.h"
#include <stdio.h>
#include <string.h>
#include <openvml_reference.h>

static char* funcname[4]={"vsAdd", "vdAdd", "vcAdd","vzAdd"};
static double flop_per_elem[4]={1.0, 1.0, 2.0, 2.0};

static ab_y_func_t ref_vadd[] = {
  (ab_y_func_t)OpenVML_FUNCNAME_REF(vsAdd),
  (ab_y_func_t)OpenVML_FUNCNAME_REF(vdAdd),
  (ab_y_func_t)OpenVML_FUNCNAME_REF(vcAdd),
  (ab_y_func_t)OpenVML_FUNCNAME_REF(vzAdd),
};

static ab_y_func_t test_vadd[] = {
  (ab_y_func_t)OpenVML_FUNCNAME(vsAdd),
  (ab_y_func_t)OpenVML_FUNCNAME(vdAdd),
  (ab_y_func_t)OpenVML_FUNCNAME(vcAdd),
  (ab_y_func_t)OpenVML_FUNCNAME(vzAdd),
};


CTEST2(check_result_s, add){
  run_test_ab_y(data->parameter, funcname, test_vadd, ref_vadd, flop_per_elem);
}

CTEST2(check_result_d, add){
  run_test_ab_y(data->parameter, funcname, test_vadd, ref_vadd, flop_per_elem);
}

CTEST2(check_result_c, add){
  run_test_ab_y(data->parameter, funcname, test_vadd, ref_vadd, flop_per_elem);
}

CTEST2(check_result_z, add){
  run_test_ab_y(data->parameter, funcname, test_vadd, ref_vadd, flop_per_elem);
}

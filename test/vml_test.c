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


  char * suitname=NULL;
  char * testname=NULL;

  read_input_flags(argc, argv, &suitname, &testname);

  ctest_main(suitname, testname);

  return 0;
}

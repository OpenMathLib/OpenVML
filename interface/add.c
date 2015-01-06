#include <openvml.h>
#include <openvml_kernel.h>
#include <stdio.h>

#ifndef DOUBLE
void vsAdd(VML_INT n, const float * a, const float * b, float * y) {
#else
void vdAdd(VML_INT n, const double * a, const double * b, double * y) {
#endif

  printf("%s", __func__);
}

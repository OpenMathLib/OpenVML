#include <openvml.h>
#include <openvml_kernel.h>

void CNAME(VML_INT n, const VML_FLOAT * a, const VML_FLOAT * b, VML_FLOAT * y) {

  if(n<=0) return;
  
  SUB_K(n, (VML_FLOAT*)a, (VML_FLOAT *)b, y);

}

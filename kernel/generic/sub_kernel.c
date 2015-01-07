#include "openvml_kernel.h"

void KERNEL_NAME(VMLLONG n, VML_FLOAT * a, VML_FLOAT * b, VML_FLOAT * y) {
  VMLLONG i=0;
  for(i=0; i<n; i++){
    y[i]=a[i]-b[i];
  }
}

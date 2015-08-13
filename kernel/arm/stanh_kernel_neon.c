#include <math.h>
#include <omp.h>
#include "openvml_kernel.h"
#include "simd_tanhs_neon.h"

void KERNEL_NAME(VMLLONG n, VML_FLOAT * a, VML_FLOAT * b, VML_FLOAT * y, VML_FLOAT * z, VML_FLOAT * other_params) 
{
    unsigned int m = n >> 2;
    unsigned int k = n & 3;
    unsigned int l = n & (~3);

    v4sf *src = (v4sf *) a;
    v4sf *dst = (v4sf *) y;

    #pragma omp parallel for
    for (unsigned int j = 0; j < m; j++) {
        v4sf tem = simd_tanh4f(src[j]);
        dst[j] = tem;
    }

    for (unsigned int j = l; j < k; j++) {
        y[j + l] = tanhf(a[j + l]);
    }
}

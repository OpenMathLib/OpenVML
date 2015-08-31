#include <math.h>
#include "openvml_kernel.h"
#include "simd_tanhs_neon.h"

void KERNEL_NAME(VMLLONG n, VML_FLOAT * a, VML_FLOAT * b, VML_FLOAT * y, VML_FLOAT * z, VML_FLOAT * other_params) 
{
    unsigned int m = n >> 2;
    unsigned int k = n & 3,j;
    unsigned int l = n & (~3);

    for (j = 0; j < m; j++) {
        v4sf src = vld1q_f32(a + j * 4); 
        v4sf tem = simd_tanh4f(src);
        vst1q_f32(y + j * 4, tem); 
    }

    for (j = 0; j < k; j++) {
        y[j + l] = tanhf(a[j + l]);
    }
}

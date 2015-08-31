#include <math.h>
#include "openvml_kernel.h"
#include "simd_lns_neon.h"

void KERNEL_NAME(VMLLONG n, VML_FLOAT * a, VML_FLOAT * b, VML_FLOAT * y, VML_FLOAT * z, VML_FLOAT * other_params) 
{
    unsigned int m = n >> 2;
    unsigned int k = n & 3, j;
    unsigned int l = n & (~3);

    for (j = 0; j < m; j++) {
        v4sf src = vld1q_f32(a + 4 * j);
        v4sf tem = simd_ln4f(src);
        vst1q_f32(y + 4 * j, tem);
    }

    for (j = 0; j < k; j++) {
        y[j + l] = logf(a[j + l]);
    }
}

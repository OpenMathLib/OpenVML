#include <math.h>
#include "openvml_kernel.h"
#include "simd_expd_avx.h"
#include "simd_function.h"

void KERNEL_NAME(VMLLONG n, VML_FLOAT * a, VML_FLOAT * b, VML_FLOAT * y, VML_FLOAT * z, VML_FLOAT * other_params) {
    unsigned int m = n >> 2;
    unsigned int k = n & 3;
    unsigned int l = n & (~3);

    for (j = 0; j < m; j++) {
        v4sd src = _mm256_loadu_pd(a + 4 * j);
        v4sd tem = simd_exp4d(src);
        _mm256_storeu_pd(y + 4 * j, tem);
    }

    for (j = 0; j < k; j++) {
        y[j + l] = exp(a[j + l]);
    }
}

#include <math.h>
#include "openvml_kernel.h"
#include "simd_pows_avx.h"

void KERNEL_NAME(VMLLONG n, VML_FLOAT * a, VML_FLOAT * b, VML_FLOAT * y, VML_FLOAT * z, VML_FLOAT * other_params) {
    unsigned int m = n >> 3;
    unsigned int k = n & 7;
    unsigned int l = n & (~7);

    for (unsigned int j = 0; j < m; j++) {
        v8sf aa = _mm256_loadu_ps(a + 8 * j);
        v8sf bb = _mm256_loadu_ps(b + 8 * j);
        v8sf tem = simd_pow8f(aa, bb);
        _mm256_storeu_ps(y + 8 * j, tem);
    }

    for (unsigned int j = 0; j < k; j++) {
        y[j + l] = powf(a[j + l], b[j + l]);
    }
}

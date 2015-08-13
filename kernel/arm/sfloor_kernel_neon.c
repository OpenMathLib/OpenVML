#include "openvml_function.h"
#include "openvml_map.h"
#include <math.h>
#include <omp.h>

void vs_floor(const unsigned int n, const float *a, float *b)
{
    unsigned int m = n >> 2;
    unsigned int k = n & 3;
    unsigned int l = n & (~3);

    v4sf *src = (v4sf *) a;
    v4sf *dest = (v4sf *) b;

    #pragma omp parallel for
    for (unsigned int j = 0; j < m; j++) {
        v4sf tem = simd_floors(src[j]);
        dest[j] = tem;
    }

    for (unsigned int j = l; j < k; j++) {
        b[j + l] = floorf(a[j + l]);
    }
}

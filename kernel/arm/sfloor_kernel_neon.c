#include <math.h>
#include "openvml_kernel.h"
#include "simd_map.h"

void KERNEL_NAME(VMLLONG n, VML_FLOAT * a, VML_FLOAT * b, VML_FLOAT * y, VML_FLOAT * z, VML_FLOAT * other_params)
{
    unsigned int m = n >> 2;
    unsigned int k = n & 3;
    unsigned int l = n & (~3);

    v4sf *src = (v4sf *) a;
    v4sf *dest = (v4sf *) y;

    for (unsigned int j = 0; j < m; j++) {
        v4sf tem = simd_floors(src[j]);
        dest[j] = tem;
    }

    for (unsigned int j = l; j < k; j++) {
        y[j + l] = floorf(a[j + l]);
    }
}

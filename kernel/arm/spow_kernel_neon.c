//#include <omp.h>
#include <math.h>
#include "openvml_kernel.h"
#include "simd_pows_neon.h"

void KERNEL_NAME(VMLLONG n, VML_FLOAT * a, VML_FLOAT * b, VML_FLOAT * y, VML_FLOAT * z, VML_FLOAT * other_params) 
{
    unsigned int m = n >> 2;
    unsigned int i, j;
    
    v4sf *pa = (v4sf *) a;
    v4sf *pb = (v4sf *) b;
    v4sf *pc = (v4sf *) y;

    unsigned int k = n & 3;
    unsigned int l = n & (~3);

    //	#pragma omp parallel for
    for (j = 0; j < m; j++) {
        v4sf aa = pa[j];
        v4sf bb = pb[j];
        pc[j] = simd_pow4f(aa, bb);
    }
    for (j = 0; j < k; j++) {
        y[l + j] = powf(a[l + j], b[l + j]);
    }
}

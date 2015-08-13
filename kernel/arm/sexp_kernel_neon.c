#include <math.h>
#include <omp.h>
#include "openvml_kernel.h"
#include "simd_exps_neon.h"

void KERNEL_NAME(VMLLONG n, VML_FLOAT * a, VML_FLOAT * b, VML_FLOAT * y, VML_FLOAT * z, VML_FLOAT * other_params) 
{
	unsigned int m = n >> 2;
	unsigned int j;
	unsigned int k = n & 3;
	unsigned int l = n & (~3);

	v4sf *src = (v4sf*)a;
	v4sf *dst = (v4sf*)y;

	#pragma omp parallel for	
	for (j=0; j<m; j++)
	{
		v4sf tem = simd_exp4f(src[j]);
		dst[j] = tem;
	}

	for (j=l; j<k; j++)
	{
		y[j+l] = expf(a[j+l]);
	}
}

#include <math.h>
//#include <omp.h>
#include "openvml_kernel.h"
#include "simd_exps_neon.h"

void KERNEL_NAME(VMLLONG n, VML_FLOAT * a, VML_FLOAT * b, VML_FLOAT * y, VML_FLOAT * z, VML_FLOAT * other_params) 
{
	unsigned int m = n >> 2;
	unsigned int j;
	unsigned int k = n & 3;
	unsigned int l = n & (~3);

	//	#pragma omp parallel for	
	for (j=0; j<m; j++)
	{
		v4sf src = vld1q_f32(a + j * 4);
		v4sf tem = simd_exp4f(src);
		vst1q_f32(y + j * 4, tem);
	}

	for (j=0; j<k; j++)
	{
		y[j+l] = expf(a[j+l]);
	}
}

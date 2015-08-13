/** Approximation of hyperbolic tangent from Lambert's (Gauss) continued fraction.
 * notes:
 *   - error starts to propagate near 5,6 or -5,-6 in the 0.00001 range
 *   - orders of 5/6 are used:
 *    tanh(x) = (21*x^5 + 1260*x^3 + 10395*x) / (x^6 + 210*x^4 + 4725*x^2 + 10395)
 *	  if(|x|>5.0) return sign(x) * 1.0
 **/
#ifndef _SIMD_TANH_KERNEL_H_
#define _SIMD_TANH_KERNEL_H_

#include "simd_const.h"
#include "simd_map.h"

_PS128_CONST(fast_tanh_5p0, 5.f);
_PS128_CONST(fast_tanh_p0, 21.f);
_PS128_CONST(fast_tanh_p1, 210.f);
_PS128_CONST(fast_tanh_p2, 1260.f);
_PS128_CONST(fast_tanh_p3, 4725.f);
_PS128_CONST(fast_tanh_p4, 10395.f);

/* portable fast c version */
static float fast_tanh(const float x)
{
	const float s = x*x;
	float d;
	if(x < -5.0)
		return - 1.0;
	else if (x > 5.0)
		return 1.0;
	d = (s*(s*(s + 210.f) + 4725.f) + 10395.f);
	return  (x *(s *(21.f * s + 1260.f) + 10395.f)) / d;
}

static inline v4sf simd_tanh4f(const v4sf x)
{
	v4sf y, s, d;
	v4sf a;
#ifdef _WITHOUT_DIV_	
	v4sf i_d;
#endif
	const v4sf mask = *(v4sf *) _ps128_sign_mask;
	const v4sf one = *(v4sf *) _ps128_1;
	const v4sf sign_bit = simd_ands(mask, x);
	v4sf tem = simd_fabs(x);

	/* if(|x| > 5.0) return sign(x) * 1.0 */
	v4sf conb = simd_cmplts(*(v4sf *) _ps128_fast_tanh_5p0, tem);
	v4sf val = simd_xors(sign_bit, one);
	
	s = simd_muls(x, x);

	/* denominator */
	/* d = (s*(s*(s + 210.f) + 4725.f) + 10395.f) */
	d = simd_adds(s, *(v4sf *) _ps128_fast_tanh_p1);
	d = simd_mas(d, s, *(v4sf *) _ps128_fast_tanh_p3);
	d = simd_mas(d, s, *(v4sf *) _ps128_fast_tanh_p4);

	/* numerator */
	/* y = (x *(s *(21.f * s + 1260.f) + 10395.f)) */
	y = simd_mas(s, *(v4sf *) _ps128_fast_tanh_p0, *(v4sf *) _ps128_fast_tanh_p2);
	y = simd_mas(y, s, *(v4sf *) _ps128_fast_tanh_p4);
	y = simd_muls(y, x);

#ifdef _WITHOUT_DIV_
    /* reciprocal of the denominator with one newton iteration */
    i_d = simd_rcps(d);
    i_d = simd_subs(simd_adds(i_d, i_d),simd_muls(d, simd_muls(i_d, i_d)));
    a = simd_muls(y, i_d);
#else
    a = simd_divs(y, d);
#endif

	d = simd_selects(conb, a, val);
	return d;
}

#endif /* _SIMD_TANH_KERNEL_H_ */

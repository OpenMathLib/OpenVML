#include "simd_const.h"
#include "simd_map.h"

_PI32_CONST256(cos_v0, 0);
_PI32_CONST256(cos_v1, 1);
_PI32_CONST256(cos_inv1, ~1);
_PI32_CONST256(cos_v4, 4);
_PI32_CONST256(cos_v2, 2);

_PS256_CONST(cos_minus_dp1, -0.78515625);
_PS256_CONST(cos_minus_dp2, -2.4187564849853515625e-4);
_PS256_CONST(cos_minus_dp3, -3.77489497744594108e-8);

_PS256_CONST(sincof_p0, -1.9515295891E-4);
_PS256_CONST(sincof_p1, 8.3321608736E-3);
_PS256_CONST(sincof_p2, -1.6666654611E-1);

_PS256_CONST(coscof_p0, 2.443315711809948E-005);
_PS256_CONST(coscof_p1, -1.388731625493765E-003);
_PS256_CONST(coscof_p2, 4.166664568298827E-002);
_PS256_CONST(cos_4div_pi, 1.27323954473516);
_PS256_CONST_TYPE(cos_abs_mask, int, ~0x80000000);

static inline v8sf simd_cos8f(const v8sf a)
{
    v8sf xmm1, xmm2 = _mm256_setzero_ps();
    v8sf xmm3, y, z, y2;
    v8si imm0, imm2;
    v8sf x = a;
    v8sf sign_bit, poly_mask;

    /* take the absolute value */
    x = simd_ands(x, *(v8sf *) _ps256_cos_abs_mask);

    /* scale by 4/Pi */
    y = simd_muls(x, *(v8sf *) _ps256_cos_4div_pi);

    /* store the integer part of y in mm0 */
    imm2 = simd_cvts_w(y);

    /* j=(j+1) & (~1) (see the cephes sources) */
    imm2 = simd_addw(imm2, *(v8si *) _pi32_256_cos_v1);
    imm2 = simd_andw(imm2, *(v8si *) _pi32_256_cos_inv1);

    y = simd_cvtw_s(imm2);
    imm2 = simd_subw(imm2, *(v8si *) _pi32_256_cos_v2);

    /* get the swap sign flag */
    imm0 = simd_andnotw(imm2, *(v8si *) _pi32_256_cos_v4);
    imm0 = simd_slliw(imm0, 29);

    /* get the polynom selection mask */
    imm2 = simd_andw(imm2, *(v8si *) _pi32_256_cos_v2);
    imm2 = simd_cmpeqw(imm2, *(v8si *) _pi32_256_cos_v0);

    sign_bit = simd_castw_s(imm0);
    poly_mask = simd_castw_s(imm2);

    /* The magic pass: "Extended precision modular arithmetic"
     * x = ((x - y * DP1) - y * DP2) - y * DP3; */
    xmm1 = *(v8sf *) _ps256_cos_minus_dp1;
    xmm2 = *(v8sf *) _ps256_cos_minus_dp2;
    xmm3 = *(v8sf *) _ps256_cos_minus_dp3;

    xmm1 = simd_muls(y, xmm1);
    xmm2 = simd_muls(y, xmm2);
    xmm3 = simd_muls(y, xmm3);

    x = simd_adds(x, xmm1);
    x = simd_adds(x, xmm2);
    x = simd_adds(x, xmm3);

    /* Evaluate the first polynom  (0 <= x <= Pi/4) */
    y = *(v8sf *) _ps256_coscof_p0;
    z = simd_muls(x, x);

    y = simd_mas(y, z, *(v8sf *) _ps256_coscof_p1);
    y = simd_mas(y, z, *(v8sf *) _ps256_coscof_p2);
    y = simd_muls(y, z);
    y = simd_muls(y, z);

    xmm1 = simd_muls(z, *(v8sf *) _ps256_0p5);
    y = simd_subs(y, xmm1);

    y = simd_adds(y, *(v8sf *) _ps256_1);

    /* Evaluate the second polynom  (Pi/4 <= x <= 0) */

    y2 = *(v8sf *) _ps256_sincof_p0;
    y2 = simd_muls(y2, z);
    y2 = simd_adds(y2, *(v8sf *) _ps256_sincof_p1);
    y2 = simd_muls(y2, z);
    y2 = simd_adds(y2, *(v8sf *) _ps256_sincof_p2);
    y2 = simd_muls(y2, z);
    y2 = simd_muls(y2, x);
    y2 = simd_adds(y2, x);

    /* select the correct result from the two polynoms */
    xmm3 = poly_mask;
    y2 = simd_ands(xmm3, y2);
    y = simd_andnots(xmm3, y);
    y = simd_adds(y, y2);

    /* update the sign */
    y = simd_xors(y, sign_bit);

    return y;
}

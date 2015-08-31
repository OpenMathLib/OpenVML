#include "simd_const.h"
#include "simd_map.h"
#include "simd_frexpd.h"
#include "simd_polevld.h"

static ALIGN32_BEG double exp_p[12] ALIGN32_END = {
    1.26177193074810590878E-4, 1.26177193074810590878E-4,
    1.26177193074810590878E-4, 1.26177193074810590878E-4,
    3.02994407707441961300E-2, 3.02994407707441961300E-2,
    3.02994407707441961300E-2, 3.02994407707441961300E-2,
    9.99999999999999999910E-1, 9.99999999999999999910E-1,
    9.99999999999999999910E-1, 9.99999999999999999910E-1
};

static ALIGN32_BEG double exp_q[16] ALIGN32_END = {
    3.00198505138664455042E-6, 3.00198505138664455042E-6,
    3.00198505138664455042E-6, 3.00198505138664455042E-6,
    2.52448340349684104192E-3, 2.52448340349684104192E-3,
    2.52448340349684104192E-3, 2.52448340349684104192E-3,
    2.27265548208155028766E-1, 2.27265548208155028766E-1,
    2.27265548208155028766E-1, 2.27265548208155028766E-1,
    2.00000000000000000009E0, 2.00000000000000000009E0,
    2.00000000000000000009E0, 2.00000000000000000009E0
};

static ALIGN32_BEG double exp_vc1[4] ALIGN32_END = {
    6.93145751953125E-1, 6.93145751953125E-1,
    6.93145751953125E-1, 6.93145751953125E-1
};

static ALIGN32_BEG double exp_vc2[4] ALIGN32_END = {
    1.42860682030941723212E-6, 1.42860682030941723212E-6,
    1.42860682030941723212E-6, 1.42860682030941723212E-6
};

static ALIGN32_BEG double expd_2p0[4] ALIGN32_END = { 2.0, 2.0, 2.0, 2.0 };
static ALIGN32_BEG double expd_0p5[4] ALIGN32_END = { 0.5, 0.5, 0.5, 0.5 };
static ALIGN32_BEG double expd_1p0[4] ALIGN32_END = { 1.0, 1.0, 1.0, 1.0 };

static ALIGN32_BEG double exp_log2a[4] ALIGN32_END = {
    0.44269504088896340736, 0.44269504088896340736,
    0.44269504088896340736, 0.44269504088896340736
};

static ALIGN32_BEG double exp_log2e[4] ALIGN32_END = {
    1.4426950408889634073599, 1.4426950408889634073599,
    1.4426950408889634073599, 1.4426950408889634073599
};

static ALIGN32_BEG double exp_max_log[4] ALIGN32_END = {
    7.08396418532264106224E2, 7.08396418532264106224E2,
    7.08396418532264106224E2, 7.08396418532264106224E2
};

static ALIGN32_BEG double exp_min_log[4] ALIGN32_END = {
    -7.08396418532264106224E2, -7.08396418532264106224E2,
    -7.08396418532264106224E2, -7.08396418532264106224E2
};

static ALIGN32_BEG unsigned short exp_vnan[16] ALIGN32_END = {
    0xffff, 0xffff, 0xffff, 0x7fff, 0xffff, 0xffff, 0xffff, 0x7fff,
    0xffff, 0xffff, 0xffff, 0x7fff, 0xffff, 0xffff, 0xffff, 0x7fff
};

static ALIGN32_BEG unsigned short exp_vinf[16] ALIGN32_END = {
    0x0, 0x0, 0x0, 0x7ff0, 0x00, 0x00, 0x0, 0x7ff0,
    0x0, 0x0, 0x0, 0x7ff0, 0x00, 0x00, 0x0, 0x7ff0
};


static inline v4sd simd_exp4d(const v4sd s256d)
{
    v4sd temp0d;
    v4sd temp1d;
    v4sd temp2d;
    v4sd temp3d;
    v4sd temp4d;
    v8si temp0i;
    v4sd tempsign;
    v4sd tempx;
    v4sd temppx;
    v8si tempn;
    v4si tempnx;
    v4sd tempxx;
    v4sd tempz;

    // if (isnan(x)) return(x);

    temp0d = simd_cmpeqd(s256d, s256d); //if true not nan, else is nan
    /*
     * if (x > MAXLOG) {
     * return (MAXNUM);
     * }
     * if (x < MINLOG) {
     * return (0.0);
     * }
     */

    temp1d = simd_cmpltd(*(v4sd *) exp_max_log, s256d);
    temp2d = simd_cmpltd(s256d, *(v4sd *) exp_min_log);

    /* px = floor(LOG2E * x + 0.5);
     * n = px;
     * x -= px * C1;
     * x -= px * C2;
     */
    temppx = simd_floord(simd_addd(simd_muld(*(v4sd *) exp_log2e, s256d), *(v4sd *) expd_0p5));

    /*
     *((int*)&tempn+1) = ((int)*((double*)&temppx));
     *((int*)&tempn+3) = ((int)*((double*)&temppx+1));
     *((int*)&tempn+5) = ((int)*((double*)&temppx+2));
     *((int*)&tempn+7) = ((int)*((double*)&temppx+3));
     */

    tempnx = simd_cvtd_w(temppx);

    // TODO: Using AVX
    ((int *) &tempn)[1] = ((int *) &tempnx)[0];
    ((int *) &tempn)[3] = ((int *) &tempnx)[1];
    ((int *) &tempn)[5] = ((int *) &tempnx)[2];
    ((int *) &tempn)[7] = ((int *) &tempnx)[3];

    tempx = simd_subd(s256d, simd_muld(temppx, *(v4sd *) exp_vc1));
    tempx = simd_subd(tempx, simd_muld(temppx, *(v4sd *) exp_vc2));

    /*
     * xx = x * x;
     * px = x * polevl(xx, exp_p, 2);
     * x = px / (polevl(xx, exp_q, 3) - px);
     * x = 1.0 + 2.0 * x;
     */

    tempxx = simd_muld(tempx, tempx);
    temppx = simd_muld(tempx, simd_polevld(tempxx, (v4sd *) exp_p, 2));
    tempx = simd_divd(temppx, simd_subd(simd_polevld(tempxx, (v4sd *) exp_q, 3), temppx));
    tempx = simd_addd(*(v4sd *) expd_1p0, simd_muld(*(v4sd *) expd_2p0, tempx));

    // x = ldexp(x, n);
    // return(x);
    tempx = simd_ldexpd(tempx, tempn);
    tempz = simd_ord(simd_andd(temp2d, simd_zerod), simd_andnotd(temp2d, tempx));
    tempz = simd_ord(simd_andd(temp1d, *(v4sd *) exp_vinf), simd_andnotd(temp1d, tempz));
    tempz = simd_ord(simd_andd(temp0d, tempz), simd_andnotd(temp0d, *(v4sd *) exp_vnan));
    
    // exp(0) = 1
    temp0d = simd_cmpeqd(s256d, simd_zerod); //if true not nan, else is nan
    tempz = simd_ord(simd_andd(temp0d, *(v4sd *) expd_1p0), simd_andnotd(temp0d, tempz));
    return tempz;
}

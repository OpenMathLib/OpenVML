#ifndef _SIMD_POWD_KERNEL_H_
#define _SIMD_POWD_KERNEL_H_

#include "simd_const.h"
#include "simd_map.h"
#include "simd_expd_avx.h"
#include "simd_lnd_avx.h"

static ALIGN32_BEG double powd_5p0[] ALIGN32_END = { 5.0, 5.0, 5.0, 5.0 };
static ALIGN32_BEG double powd_720[] ALIGN32_END = { 720.0, 720.0, 720.0, 720.0 };
static ALIGN32_BEG double powd_120[] ALIGN32_END = { 120.0, 120.0, 120.0, 120.0 };
static ALIGN32_BEG double powd_4p0[] ALIGN32_END = { 4.0, 4.0, 4.0, 4.0 };
static ALIGN32_BEG double powd_24[] ALIGN32_END = { 24.0, 24.0, 24.0, 24.0 };
static ALIGN32_BEG double powd_3p0[] ALIGN32_END = { 3.0, 3.0, 3.0, 3.0 };
static ALIGN32_BEG double powd_6p0[] ALIGN32_END = { 6.0, 6.0, 6.0, 6.0 };
static ALIGN32_BEG double powd_2p0[] ALIGN32_END = { 2.0, 2.0, 2.0, 2.0 };
static ALIGN32_BEG double powd_1p0[] ALIGN32_END = { 1.0, 1.0, 1.0, 1.0 };
static ALIGN32_BEG double powd_16p0[] ALIGN32_END = { 16.0, 16.0, 16.0, 16.0 };

static ALIGN32_BEG unsigned short bmask[] ALIGN32_END =
    { 0xffff, 0xfffe, 0xfffc, 0xfff8, 0xfff0, 0xffe0, 0xffc0, 0xff80, 0xff00, 0xfe00,
    0xfc00, 0xf800, 0xf000, 0xe000, 0xc000, 0x8000, 0x0000,
};

static ALIGN32_BEG double powd_p[] ALIGN32_END = {
    4.97778295871696322025E-1, 4.97778295871696322025E-1,
    4.97778295871696322025E-1, 4.97778295871696322025E-1,
    3.73336776063286838734E0, 3.73336776063286838734E0,
    3.73336776063286838734E0, 3.73336776063286838734E0,
    7.69994162726912503298E0, 7.69994162726912503298E0,
    7.69994162726912503298E0, 7.69994162726912503298E0,
    4.66651806774358464979E0, 4.66651806774358464979E0,
    4.66651806774358464979E0, 4.66651806774358464979E0
};

static ALIGN32_BEG double powd_q[] ALIGN32_END = {
    9.33340916416696166113E0, 9.33340916416696166113E0,
    9.33340916416696166113E0, 9.33340916416696166113E0,
    2.79999886606328401649E1, 2.79999886606328401649E1,
    2.79999886606328401649E1, 2.79999886606328401649E1,
    3.35994905342304405431E1, 3.35994905342304405431E1,
    3.35994905342304405431E1, 3.35994905342304405431E1,
    1.39995542032307539578E1, 1.39995542032307539578E1,
    1.39995542032307539578E1, 1.39995542032307539578E1
};

static double powd_a[] = {
    1.00000000000000000000E0, 9.57603280698573700036E-1, 9.17004043204671215328E-1,
    8.78126080186649726755E-1, 8.40896415253714502036E-1, 8.05245165974627141736E-1,
    7.71105412703970372057E-1, 7.38413072969749673113E-1, 7.07106781186547572737E-1,
    6.77127773468446325644E-1, 6.48419777325504820276E-1, 6.20928906036742001007E-1,
    5.94603557501360513449E-1, 5.69394317378345782288E-1, 5.45253866332628844837E-1,
    5.22136891213706877402E-1, 5.00000000000000000000E-1
};

static double powd_b[] = {
    0.00000000000000000000E0, 1.64155361212281360176E-17, 4.09950501029074826006E-17,
    3.97491740484881042808E-17, -4.83364665672645672553E-17, 1.26912513974441574796E-17,
    1.99100761573282305549E-17, -1.52339103990623557348E-17, 0.00000000000000000000E0
};

static ALIGN32_BEG double powd_r[] ALIGN32_END = {
    1.49664108433729301083E-5, 1.49664108433729301083E-5,
    1.49664108433729301083E-5, 1.49664108433729301083E-5,
    1.54010762792771901396E-4, 1.54010762792771901396E-4,
    1.54010762792771901396E-4, 1.54010762792771901396E-4,
    1.33335476964097721140E-3, 1.33335476964097721140E-3,
    1.33335476964097721140E-3, 1.33335476964097721140E-3,
    9.61812908476554225149E-3, 9.61812908476554225149E-3,
    9.61812908476554225149E-3, 9.61812908476554225149E-3,
    5.55041086645832347466E-2, 5.55041086645832347466E-2,
    5.55041086645832347466E-2, 5.55041086645832347466E-2,
    2.40226506959099779976E-1, 2.40226506959099779976E-1,
    2.40226506959099779976E-1, 2.40226506959099779976E-1,
    6.93147180559945308821E-1, 6.93147180559945308821E-1,
    6.93147180559945308821E-1, 6.93147180559945308821E-1
};


static ALIGN32_BEG double powd_stf[] ALIGN32_END = { 0.0625, 0.0625, 0.0625, 0.0625 };
static ALIGN32_BEG double powd_0p5[] ALIGN32_END = { 0.5, 0.5, 0.5, 0.5 };
static ALIGN32_BEG double powd_minus_0p0[] ALIGN32_END = { -0.0, -0.0, -0.0, -0.0 };
static ALIGN32_BEG int powd_zero[] ALIGN32_END = { 0, 0, 0, 0};
static ALIGN32_BEG int powd_one[] ALIGN32_END = { 1, 1, 1, 1, 1, 1, 1, 1 };
static ALIGN32_BEG double powd_mnexp[] ALIGN32_END = { -17183.0, -17183.0, -17183.0, -17183.0 };
static ALIGN32_BEG double powd_minus_1p0[] ALIGN32_END = { -1.0, -1.0, -1.0, -1.0 };

static ALIGN32_BEG unsigned short powd_nan[] ALIGN32_END = {
    0xffff, 0xffff, 0xffff, 0x7fff,
    0xffff, 0xffff, 0xffff, 0x7fff,
    0xffff, 0xffff, 0xffff, 0x7fff,
    0xffff, 0xffff, 0xffff, 0x7fff
};

static ALIGN32_BEG unsigned short powd_mnan[] ALIGN32_END = {
    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff
};

static ALIGN32_BEG unsigned short powd_inf[] ALIGN32_END = {
    0x00, 0x00, 0x0, 0x7ff0,
    0x00, 0x00, 0x0, 0x7ff0,
    0x00, 0x00, 0x0, 0x7ff0,
    0x00, 0x00, 0x0, 0x7ff0,
    0x00, 0x00, 0x0, 0x7ff0
};

static ALIGN32_BEG unsigned short powd_minf[] ALIGN32_END = {
    0x0, 0x0, 0x0, 0xfff0,
    0x0, 0x0, 0x0, 0xfff0,
    0x0, 0x0, 0x0, 0xfff0,
    0x0, 0x0, 0x0, 0xfff0,
    0x0, 0x0, 0x0, 0xfff0
};

static ALIGN32_BEG double powd_1em3[] ALIGN32_END = {1.0e-3,1.0e-3,1.0e-3,1.0e-3};

static ALIGN32_BEG double powd_const_lna[] ALIGN32_END = {
	0.44269504088896340736,0.44269504088896340736,
	0.44269504088896340736,0.44269504088896340736
};

static ALIGN32_BEG double powd_mexp[] ALIGN32_END = {16383.0,16383.0,16383.0,16383.0};

#define powd_reduce(mt, mx)						\
    mt = simd_muld(mx, *(v4sd *) powd_16p0);	\
	mt = simd_floord(mt);						\
	mt = simd_divd(mt, *(v4sd *) powd_16p0);


static inline v4sd simd_pow4d(v4sd sx256d, v4sd sy256d)
{
    v4sd tempw;
    v4sd tempz;
    v4sd tempW;
    v4sd tempWa;
    v4sd tempWb;
    v4sd tempya;
    v4sd tempyb;
    v4sd tempu;
    v4sd tempaw;
    v4sd tempay;
    v4sd tempwy;
    v4sd temp0d;
    v4sd temp1d;
    v4sd temp2d;
    v4sd temp3d;
    v4sd temp4d;
    v4sd temp5d;
    v4sd temp6d;
    v4sd temp7d;
    v4sd temp8d;
    v4sd temp9d;
    v4sd temp9d1;
    v4sd temp9d21;
    v4sd temp10d;
    v4sd temp11d;
    v4sd temp12d;
    v4sd temp13d;
    v4sd temp14d;
    v4sd temp15d;
    v4sd temp16d;
    v4sd temp17d;
    v4sd temp18d;
    v4sd temp19d;
    v4sd temp0dz;
    v4sd temp1dz;
    v4sd temp2dz;
    v4sd temp3dz;
    v4sd temp4dz;
    v4sd temp5dz;
    v4sd temp6dz;
    v4sd temp7dz;
    v4sd temp8dz;
    v4sd temp9dz;
    v4sd temp10dz;
    v4sd temp11dz;
    v4sd temp12dz;
    v4sd temp13dz;
    v4sd temp14dz;
    v4sd tempxsign;
    v4sd tempysign;

    v8si tempe;
    v4sd tempef;
    v8si tempi;
    v4sd tempnflg;
    v4sd tempiyflg;
    v4sd tempyoddint;
    v8si temp0i;
    v8si temp1i;
    v4sd sflr256d;
    int i;

    /* if (y == 0.0)
     * return(1.0);
     */
    temp0d = simd_cmpeqd(sy256d, simd_zerod);

    /* if (isnan(x))
     * return(x);
     */
    temp1d = simd_cmpeqd(sx256d, sx256d);

    /* if (isnan(y))
     * return(y);
     */
    temp2d = simd_cmpeqd(sy256d, sy256d);
    temp1d = simd_andd(temp1d, temp2d);

    /* if (y == 1.0)
     * return(x);
     */
    temp2d = simd_cmpeqd(sy256d, *(v4sd *) powd_1p0);
    temp2dz = sx256d;

    /*
     * if (!isfinite(y) && (x == 1.0 || x == -1.0))
     * {
     * return(NAN);
     * }
     */
    temp3d = simd_cmpeqd(sy256d, *(v4sd *) powd_inf);
    temp4d = simd_cmpeqd(sy256d, *(v4sd *) powd_minf);
    temp3d = simd_ord(temp3d, temp4d);
    temp4d = simd_cmpeqd(sx256d, *(v4sd *) powd_1p0);
    temp5d = simd_cmpeqd(sx256d, *(v4sd *) powd_minus_1p0);
    temp4d = simd_ord(temp4d, temp5d);
    temp3d = simd_andd(temp3d, temp4d);
    /*
     * if (x == 1.0)
     * return(1.0);
     */
    temp4d = simd_cmpeqd(sx256d, *(v4sd *) powd_1p0);

    /*
     * if (y >= MAXNUM)
     * {
     * if (x > 1.0)
     * return(INFINITY);
     * if (x > 0.0 && x < 1.0)
     * return(0.0);
     * if (x < -1.0)
     * {
     * return(INFINITY);
     * }
     * if (x > -1.0 && x < 0.0)
     * return(0.0);
     * }
     */

    temp5d = simd_cmpled(*(v4sd *) powd_inf, sy256d);
    temp6d = simd_cmpltd(*(v4sd *) powd_1p0, sx256d);   /* if (x > 1.0) */
    temp7d = simd_cmpltd(simd_zerod, sx256d);
    temp8d = simd_cmpltd(sx256d, *(v4sd *) powd_1p0);
    temp7d = simd_andd(temp7d, temp8d); /* if (x > 0.0 && x < 1.0) */
    temp8d = simd_cmpltd(sx256d, *(v4sd *) powd_minus_1p0);     /* if (x < -1.0) */
    temp5dz = simd_ord(simd_andd(temp8d, *(v4sd *) powd_inf), simd_andnotd(temp8d, simd_zerod));

    temp5dz = simd_ord(simd_andd(temp7d, simd_zerod), simd_andnotd(temp7d, temp5dz));
    temp5dz = simd_ord(simd_andd(temp6d, *(v4sd *) powd_inf), simd_andnotd(temp6d, temp5dz));

    /*
     * if (y <= -MAXNUM)
     * {
     * if (x > 1.0)
     * return(0.0);
     * if (x > 0.0 && x < 1.0)
     * return(INFINITY);
     * if (x < -1.0)
     * return(0.0);
     * if (x > -1.0 && x < 0.0)
     * return(INFINITY);
     * }
     */
    temp6d = simd_cmpled(sy256d, *(v4sd *) powd_minf);
    temp7d = simd_cmpltd(*(v4sd *) powd_1p0, sx256d);   /* if (x > 1.0) */
    temp8d = simd_cmpltd(simd_zerod, sx256d);
    temp9d = simd_cmpltd(sx256d, *(v4sd *) powd_1p0);
    temp8d = simd_andd(temp8d, temp9d); /* if (x > 0.0 && x < 1.0) */
    temp9d = simd_cmpltd(sx256d, *(v4sd *) powd_minus_1p0);     /* if (x < -1.0) */
    temp6dz = simd_ord(simd_andd(temp9d, simd_zerod), simd_andnotd(temp9d, *(v4sd *) powd_inf));

    temp6dz = simd_ord(simd_andd(temp8d, *(v4sd *) powd_inf), simd_andnotd(temp8d, temp6dz));
    temp6dz = simd_ord(simd_andd(temp7d, simd_zerod), simd_andnotd(temp7d, temp6dz));

    /*
     * if (x >= MAXNUM)
     * {
     * if (y > 0.0)
     * return(INFINITY);
     * return(0.0);
     * }
     */
    temp7d = simd_cmpled(*(v4sd *) powd_inf, sx256d);   /* if (x >= MAXNUM) */
    temp8d = simd_cmpltd(simd_zerod, sy256d);   /* if (y > 0.0) */
    temp7dz = simd_ord(simd_andd(temp8d, *(v4sd *) powd_inf), simd_andnotd(temp8d, simd_zerod));
    /*
     * iyflg = 0;
     * w = floor(y);
     * if (w == y)
     * iyflg = 1;
     *
     * yoddint = 0;
     * if (iyflg)
     * {
     * ya = fabs(y);
     * ya = floor(0.5 * ya);
     * yb = 0.5 * fabs(w);
     * if (ya != yb)
     * yoddint = 1;
     * }
     */
    tempw = simd_floord(sy256d);
    temp8d = simd_cmpeqd(tempw, sy256d);
    tempiyflg = simd_ord(simd_andd(temp8d, *(v4sd *) powd_2p0), simd_andnotd(temp8d, simd_zerod));
    tempya = simd_ord(simd_andd(simd_cmpltd(sy256d, simd_zerod),
                  simd_subd(simd_zerod, sy256d)), simd_andnotd(simd_cmpltd(sy256d, simd_zerod), sy256d));
    tempya = simd_floord(simd_muld(*(v4sd *) powd_0p5, tempya));
    tempyb = simd_ord(simd_andd(simd_cmpltd(tempw, simd_zerod),
                  simd_subd(simd_zerod, tempw)), simd_andnotd(simd_cmpltd(tempw, simd_zerod), tempw));
    tempyb = simd_muld(*(v4sd *) powd_0p5, tempyb);
    temp9d = simd_cmpeqd(tempya, tempyb);
    tempyoddint = simd_ord(simd_andd(temp9d, simd_zerod), simd_andnotd(temp9d, *(v4sd *) powd_2p0));
    tempyoddint = simd_ord(simd_andd(tempiyflg, tempyoddint), simd_andnotd(tempiyflg, simd_zerod));
    /*
     * if (x <= -MAXNUM)
     * {
     * if (y > 0.0)
     * {
     * if (yoddint)
     * return(-INFINITY);
     * return(INFINITY);
     * }
     * if (y < 0.0)
     * {
     * if (yoddint)
     * return(NEGZERO);
     * return(0.0);
     * }
     * }
     */
    temp8d = simd_cmpled(sx256d, *(v4sd *) powd_minf);  /* if (x <= -MAXNUM) */
    temp9d = simd_cmpltd(simd_zerod, sy256d);   /* if (y > 0.0) */
    temp10d = simd_cmpeqd(tempyoddint, simd_zerod);
    temp11d = simd_ord(simd_andd(temp10d, *(v4sd *) powd_inf), simd_andnotd(temp10d, *(v4sd *) powd_minf));

    /* if (y < 0.0) */
    temp13d = simd_ord(simd_andd(temp10d, simd_zerod), simd_andnotd(temp10d, *(v4sd *) powd_minus_0p0));
    temp8dz = simd_ord(simd_andd(temp9d, temp11d), simd_andnotd(temp9d, temp13d));

    /*
     * nflg = 0;
     * if (x <= 0.0)
     * {
     * if (x == 0.0)
     * {
     * if (y < 0.0)
     * {
     * if (signbit(x) && yoddint)
     * return(-INFINITY);
     * return(INFINITY);
     *
     * }
     * if (y > 0.0)
     * {
     * if (signbit(x) && yoddint)
     * return(NEGZERO);
     * return(0.0);
     * }
     * return(1.0);
     * }
     * else
     * {
     * if (iyflg == 0)
     * {
     * return(NAN);
     * }
     * nflg = 1;
     * }
     * }
     */

    tempxsign = simd_cmpltd(sx256d, simd_zerod);
    tempysign = simd_cmpltd(sy256d, simd_zerod);
    temp9d = simd_cmpled(sx256d, simd_zerod);
    temp9d1 = simd_cmpeqd(sx256d, simd_zerod);  /* if (x == 0.0) */
    temp11d = simd_cmpltd(sy256d, simd_zerod);  /* if (y < 0.0) */
    temp12d = simd_andd(tempxsign, tempyoddint); /* if (signbit(x) && yoddint) */
    temp13d = simd_ord(simd_andd(temp12d, *(v4sd *) powd_minus_0p0), simd_andnotd(temp12d, simd_zerod));
    temp14d = simd_cmpltd(simd_zerod, sy256d);  /* if (y > 0.0) */
    temp15d = simd_ord(simd_andd(temp12d, *(v4sd *) powd_minus_0p0), simd_andnotd(temp12d, simd_zerod));
    temp16d = simd_ord(simd_andd(temp14d, temp15d), simd_andnotd(temp14d, *(v4sd *) powd_1p0));
    temp9dz = simd_ord(simd_andd(temp11d, temp13d), simd_andnotd(temp11d, temp16d));
    temp9d21 = simd_cmpeqd(tempiyflg, simd_zerod); /* if (iyflg == 0) */
    tempnflg = simd_ord(simd_andd(temp10d, simd_zerod), simd_andnotd(temp10d, *(v4sd *) powd_2p0));
    tempnflg = simd_ord(simd_andd(temp9d, tempnflg), simd_andnotd(temp9d, simd_zerod));
    /*
     * if (iyflg)
     * {
     * i = w;
     * w = floor(x);
     * if ((w == x) && (fabs(y) < 32768.0))
     * {
     * w = powi(x, (int) y);
     * return(w);
     * }
     * }
     */
    /* that is useless */
    /*
     * if (nflg)
     * x = fabs(x);
     */
    temp11d = simd_ord(simd_andd(simd_cmpltd(sx256d, simd_zerod),
                  simd_subd(simd_zerod, sx256d)), simd_andnotd(simd_cmpltd(sx256d, simd_zerod), sx256d));
    sx256d = simd_ord(simd_andd(tempnflg, temp11d), simd_andnotd(tempnflg, sx256d));

    /*
     * w = x - 1.0;
     * aw = fabs(w);
     * ay = fabs(y);
     * wy = w * y;
     * ya = fabs(wy);
     */
    tempw = simd_subd(sx256d, *(v4sd *) powd_1p0);
    tempaw = simd_ord(simd_andd(simd_cmpltd(tempw, simd_zerod),
                  simd_subd(simd_zerod, tempw)), simd_andnotd(simd_cmpltd(tempw, simd_zerod), tempw));
    tempay = simd_ord(simd_andd(simd_cmpltd(sy256d, simd_zerod),
                  simd_subd(simd_zerod, sy256d)), simd_andnotd(simd_cmpltd(sy256d, simd_zerod), sy256d));
    tempwy = simd_muld(tempw, sy256d);
    tempya = simd_ord(simd_andd(simd_cmpltd(tempwy, simd_zerod),
                  simd_subd(simd_zerod, tempwy)), simd_andnotd(simd_cmpltd(tempwy, simd_zerod), tempwy));
    /*
     * if ((aw <= 1.0e-3 && ay <= 1.0)
     * || (ya <= 1.0e-3 && ay >= 1.0))
     * {
     * z = (((((w*(y-5.)/720. + 1./120.)*w*(y-4.) + 1./24.)*w*(y-3.)
     * + 1./6.)*w*(y-2.) + 0.5)*w*(y-1.))*wy + wy + 1.;
     * goto done;
     * }
     */
    temp10d = simd_cmpled(tempaw, *(v4sd *) powd_1em3);
    temp11d = simd_cmpled(tempay, *(v4sd *) powd_1p0);
    temp10d = simd_andd(temp10d, temp11d);
    temp11d = simd_cmpled(tempya, *(v4sd *) powd_1em3);
    temp12d = simd_cmpled(*(v4sd *) powd_1p0, tempay);
    temp11d = simd_andd(temp11d, temp12d);
    temp10d = simd_ord(temp10d, temp11d);
    temp12d = simd_divd(simd_muld(tempw, simd_subd(sy256d, *(v4sd *) powd_5p0)), *(v4sd *) powd_720);
    temp12d = simd_addd(temp12d, simd_divd(*(v4sd *) powd_1p0, *(v4sd *) powd_120));
    temp12d = simd_muld(simd_muld(temp12d, tempw), simd_subd(sy256d, *(v4sd *) powd_4p0));
    temp12d = simd_addd(temp12d, simd_divd(*(v4sd *) powd_1p0, *(v4sd *) powd_24));
    temp12d = simd_muld(simd_muld(tempw, temp12d), simd_subd(sy256d, *(v4sd *) powd_3p0));
    temp12d = simd_addd(temp12d, simd_divd(*(v4sd *) powd_1p0, *(v4sd *) powd_6p0));
    temp12d = simd_addd(simd_muld(simd_muld(temp12d, tempw), simd_subd(sy256d, *(v4sd *) powd_2p0)), *(v4sd *) powd_0p5);
    temp12d = simd_muld(simd_muld(temp12d, tempw), simd_subd(sy256d, *(v4sd *) powd_1p0));
    temp10dz = simd_addd(simd_muld(tempwy, temp12d), simd_addd(tempwy, *(v4sd *) powd_1p0));
    /*
     * x = frexp(x, &e);
     * i = 1;
     * if (x <= douba(9))
     * i = 9;
     * if (x <= douba(i+4))
     * i += 4;
     * if (x <= douba(i+2))
     * i += 2;
     * if (x >= douba(1))
     * i = -1;
     * i += 1;
     */
    sx256d = simd_frexpd(sx256d, &tempe);
    tempi = *(v8si *) powd_one;
    for (i = 0; i < 4; ++i) {
        if (((double *) &sx256d)[i] <= powd_a[9])
            ((int *) &tempi)[i] = 9;
        if (((double *) &sx256d)[i] <= powd_a[((int *) &tempi)[i] + 4])
            ((int *) &tempi)[i] += 4;
        if (((double *) &sx256d)[i] <= powd_a[((int *) &tempi)[i] + 2])
            ((int *) &tempi)[i] += 2;
        if (((double *) &sx256d)[i] >= powd_a[1])
            ((int *) &tempi)[i] = -1;
        ((int *) &tempi)[i] += 1;
    }
    /*
     * x -= douba(i);
     * x -= doubb(i/2);
     * x /= douba(i);
     */
    for (i = 0; i < 4; ++i) {
        ((double *) &temp11d)[i] = powd_a[((int *) &tempi)[i]];
        ((double *) &temp12d)[i] = powd_b[((int *) &tempi)[i] / 2];
    } 
	sx256d = simd_divd(simd_subd(simd_subd(sx256d, temp11d), temp12d), temp11d);

    /*
     * z = x*x;
     * w = x * (z * polevl(x, powd_p, 3) / p1evl(x, powd_q, 4));
     * w = w - ldexp(z, -1);
     */
    tempz = simd_muld(sx256d, sx256d);
    tempw =
        simd_muld(sx256d,
                  simd_divd(simd_muld(tempz, simd_polevld(sx256d, (v4sd *) powd_p, 3)),
                            simd_p1evld(sx256d, (v4sd *) powd_q, 4)));
    tempw = simd_subd(tempw, simd_divd(tempz, *(v4sd *) powd_2p0));
    /*
     * w = w + LOG2EA * w;
     * z = w + LOG2EA * x;
     * z = z + x;
     */
    tempw = simd_addd(tempw, simd_muld(tempw, *(v4sd *) powd_const_lna));
    tempz = simd_addd(tempw, simd_muld(*(v4sd *) powd_const_lna, sx256d));
    tempz = simd_addd(tempz, sx256d);
    /*
     * w = -i;
     * w = ldexp(w, -4);
     * w += e;
     */
	v4si itempw;  
    ((int *) &itempw)[0] = ((int *) &tempi)[0];
    ((int *) &itempw)[1] = ((int *) &tempi)[1];
    ((int *) &itempw)[2] = ((int *) &tempi)[2];
    ((int *) &itempw)[3] = ((int *) &tempi)[3];

    tempw = simd_subd(simd_zerod, simd_cvtw_d(itempw));

    tempw = simd_divd(tempw, *(v4sd *) powd_16p0);
    ((double *) &tempef)[0] = ((int *) &tempe)[1];
    ((double *) &tempef)[1] = ((int *) &tempe)[3];
    ((double *) &tempef)[2] = ((int *) &tempe)[5];
    ((double *) &tempef)[3] = ((int *) &tempe)[7];
    tempw = simd_addd(tempw, tempef);
    /*
     * ya = reduc(y);
     * yb = y - ya;
     */
    powd_reduce(tempya, sy256d);
    tempyb = simd_subd(sy256d, tempya);
    /*
     * F = z * y  +  w * yb;
     * Fa = reduc(F);
     * Fb = F - Fa;
     */
    tempW = simd_addd(simd_muld(tempz, sy256d), simd_muld(tempw, tempyb));
    powd_reduce(tempWa, tempW);
    tempWb = simd_subd(tempW, tempWa);
    /*
     * G = Fa + w * ya;
     * Ga = reduc(G);
     * Gb = G - Ga;
     */
    tempW = simd_addd(tempWa, simd_muld(tempw, tempya));
    powd_reduce(tempWa, tempW);
    tempu = simd_subd(tempW, tempWa);
    /*
     * H = Fb + Gb;
     * Ha = reduc(H);
     * w = ldexp(Ga+Ha, 4);
     */
    tempW = simd_addd(tempWb, tempu);
    powd_reduce(tempWb, tempW);
    tempw = simd_muld(simd_addd(tempWa, tempWb), *(v4sd *) powd_16p0);
    /*
     * if (w > MEXP)
     * {
     * if (nflg && yoddint)
     * return(-INFINITY);
     * return(INFINITY);
     * }
     */
    temp11d = simd_cmpltd(*(v4sd *) powd_mexp, tempw);
    temp13d = simd_andd(tempnflg, tempyoddint);
    temp11dz = simd_ord(simd_andd(temp13d, *(v4sd *) powd_minf), simd_andnotd(temp13d, *(v4sd *) powd_inf));
    /*
     * if (w < (MNEXP - 1))
     * {
     * if (nflg && yoddint)
     * return(NEGZERO);
     * return(0.0);
     * }
     */
    temp12d = simd_cmpltd(tempw, simd_subd(*(v4sd *) powd_mnexp, *(v4sd *) powd_1p0));
    temp12dz = simd_ord(simd_andd(temp13d, *(v4sd *) powd_minus_0p0), simd_andnotd(temp13d, simd_zerod));
    /*
     * e = w;
     * Hb = H - Ha;
     * if (Hb > 0.0)
     * {
     * e += 1;
     * Hb -= 0.0625;
     * }
     * z = Hb * polevl(Hb, powd_r, 6);
     */
    tempWb = simd_subd(tempW, tempWb);
    temp14d = simd_cmpltd(simd_zerod, tempWb);
    tempef = simd_ord(simd_andd(temp14d, simd_addd(tempw, *(v4sd *) powd_1p0)), simd_andnotd(temp14d, tempw));
    tempWb = simd_ord(simd_andd(temp14d, simd_subd(tempWb, *(v4sd *) powd_stf)), simd_andnotd(temp14d, tempWb));
    tempz = simd_muld(tempWb, simd_polevld(tempWb, (v4sd *) powd_r, 6));

    /*
     * if (e < 0)
     * i = 0;
     * else
     * i = 1;
     * i = e/16 + i;
     * e = 16*i - e;
     * w = douba(e);
     * z = w + w * z;
     * z = ldexp(z, i);
     */
    v4si itempe = simd_cvtd_w(tempef);
    v4si itemp0i = simd_cmpltu(itempe, *(v4si *) powd_zero);
    v4si itempi = simd_oru(simd_andu(itemp0i, *(v4si *) powd_zero), simd_andnotu(itemp0i, *(v4si *) powd_one));

    for (i = 0; i < 4; ++i) {
        ((int *) &itempi)[i] = ((int *) &itempe)[i] / 16 + ((int *) &itempi)[i];
        ((int *) &itempe)[i] = 16 * ((int *) &itempi)[i] - ((int *) &itempe)[i];
    } 

	((double *) &tempw)[0] = powd_a[((int *) &itempe)[0]];
    ((double *) &tempw)[1] = powd_a[((int *) &itempe)[1]];
	((double *) &tempw)[2] = powd_a[((int *) &itempe)[2]];
    ((double *) &tempw)[3] = powd_a[((int *) &itempe)[3]];

    tempz = simd_addd(tempw, simd_muld(tempw, tempz));

    ((int *) &tempi)[1] = ((int *) &itempi)[0];
    ((int *) &tempi)[3] = ((int *) &itempi)[1];
    ((int *) &tempi)[5] = ((int *) &itempi)[2];
    ((int *) &tempi)[7] = ((int *) &itempi)[3];

    tempz = simd_ldexpd(tempz, tempi);

    /*
     * done:
     *
     * if (nflg && yoddint)
     * {
     * if (z == 0.0)
     * z = NEGZERO;
     * else
     * z = -z;
     * }
     * return(z);
     */
    tempz = simd_ord(simd_andd(temp10d, temp10dz), simd_andnotd(temp10d, tempz));
    temp13d = simd_andd(tempnflg, tempyoddint);
    temp14d = simd_cmpeqd(tempz, simd_zerod);
    temp15d = simd_ord(simd_andd(temp14d, *(v4sd *) powd_minus_0p0),
                       simd_andnotd(temp14d, simd_subd(simd_zerod, tempz)));

    tempz = simd_ord(simd_andd(temp13d, temp15d), simd_andnotd(temp13d, tempz));
    temp13d = simd_ord(simd_andd(temp9d21, *(v4sd *) powd_mnan), simd_andnotd(temp9d21, tempz));
    temp9dz = simd_ord(simd_andd(temp9d1, temp9dz), simd_andnotd(temp9d1, temp13d));
    tempz = simd_ord(simd_andd(temp12d, temp12dz), simd_andnotd(temp12d, tempz));
    tempz = simd_ord(simd_andd(temp11d, temp11dz), simd_andnotd(temp11d, tempz));
    tempz = simd_ord(simd_andd(temp9d, temp9dz), simd_andnotd(temp9d, tempz));
    tempz = simd_ord(simd_andd(temp8d, temp8dz), simd_andnotd(temp8d, tempz));
    tempz = simd_ord(simd_andd(temp7d, temp7dz), simd_andnotd(temp7d, tempz));
    tempz = simd_ord(simd_andd(temp6d, temp6dz), simd_andnotd(temp6d, tempz));
    tempz = simd_ord(simd_andd(temp5d, temp5dz), simd_andnotd(temp5d, tempz));
    tempz = simd_ord(simd_andd(temp4d, *(v4sd *) powd_1p0), simd_andnotd(temp4d, tempz));
    tempz = simd_ord(simd_andd(temp3d, *(v4sd *) powd_nan), simd_andnotd(temp3d, tempz));
    tempz = simd_ord(simd_andd(temp2d, temp2dz), simd_andnotd(temp2d, tempz));
    tempz = simd_ord(simd_andd(temp1d, tempz), simd_andnotd(temp1d, *(v4sd *) powd_nan));
    tempz = simd_ord(simd_andd(temp0d, *(v4sd *) powd_1p0), simd_andnotd(temp0d, tempz));

    return tempz;
}

#endif

#include "simd_map.h"
#include "simd_const.h"
#include "simd_polevld.h"
#include "simd_frexpd.h"

static ALIGN32_BEG double ln_const1[4] ALIGN32_END = {
	2.121944400546905827679e-4, 2.121944400546905827679e-4,
	2.121944400546905827679e-4, 2.121944400546905827679e-4
};

static ALIGN32_BEG double ln_const2[4] ALIGN32_END = { 0.693359375, 0.693359375, 0.693359375, 0.693359375 };

static ALIGN32_BEG double ln_p[24] ALIGN32_END = { 
	1.01875663804580931796E-4, 1.01875663804580931796E-4, 1.01875663804580931796E-4, 1.01875663804580931796E-4, 
	4.97494994976747001425E-1, 4.97494994976747001425E-1, 4.97494994976747001425E-1, 4.97494994976747001425E-1,
	4.70579119878881725854E0, 4.70579119878881725854E0, 4.70579119878881725854E0, 4.70579119878881725854E0,
	1.44989225341610930846E1, 1.44989225341610930846E1, 1.44989225341610930846E1, 1.44989225341610930846E1,
	1.79368678507819816313E1, 1.79368678507819816313E1, 1.79368678507819816313E1, 1.79368678507819816313E1,
	7.70838733755885391666E0, 7.70838733755885391666E0, 7.70838733755885391666E0, 7.70838733755885391666E0
};

static ALIGN32_BEG double ln_q[20] ALIGN32_END = {
    1.12873587189167450590E1, 1.12873587189167450590E1, 1.12873587189167450590E1, 1.12873587189167450590E1, 
	4.52279145837532221105E1, 4.52279145837532221105E1, 4.52279145837532221105E1, 4.52279145837532221105E1,
	8.29875266912776603211E1, 8.29875266912776603211E1, 8.29875266912776603211E1, 8.29875266912776603211E1,
    7.11544750618563894466E1, 7.11544750618563894466E1, 7.11544750618563894466E1, 7.11544750618563894466E1, 
	2.31251620126765340583E1, 2.31251620126765340583E1, 2.31251620126765340583E1, 2.31251620126765340583E1
};

static ALIGN32_BEG double ln_r[12] ALIGN32_END = {
	-7.89580278884799154124E-1, -7.89580278884799154124E-1, -7.89580278884799154124E-1, -7.89580278884799154124E-1,
	1.63866645699558079767E1,1.63866645699558079767E1, 1.63866645699558079767E1,1.63866645699558079767E1,
    -6.41409952958715622951E1, -6.41409952958715622951E1, -6.41409952958715622951E1, -6.41409952958715622951E1
};

static ALIGN32_BEG double ln_s[12] ALIGN32_END = {
    -3.56722798256324312549E1, -3.56722798256324312549E1, -3.56722798256324312549E1, -3.56722798256324312549E1,
	3.12093766372244180303E2, 3.12093766372244180303E2, 3.12093766372244180303E2, 3.12093766372244180303E2,
	-7.69691943550460008604E2, -7.69691943550460008604E2, -7.69691943550460008604E2, -7.69691943550460008604E2
};

static ALIGN32_BEG unsigned short ln_vnan[16] ALIGN32_END = {
	0xffff,0xffff,0xffff,0x7fff,0xffff,0xffff,0xffff,0x7fff,
	0xffff,0xffff,0xffff,0x7fff,0xffff,0xffff,0xffff,0x7fff
};

static ALIGN32_BEG unsigned short ln_minus_inf[16] ALIGN32_END = {
	0x0,0x0,0x0,0xfff0,0x00,0x00,0x0,0xfff0,
	0x0,0x0,0x0,0xfff0,0x00,0x00,0x0,0xfff0
};

static ALIGN32_BEG double ln_sqrt[4] ALIGN32_END = {
	7.07106781186547524401E-1,7.07106781186547524401E-1,
	7.07106781186547524401E-1,7.07106781186547524401E-1
};

static ALIGN32_BEG unsigned short ln_inf[16] ALIGN32_END = {
	0x00,0x00,0x0,0x7ff0,0x00,0x00,0x0,0x7ff0,
	0x00,0x00,0x0,0x7ff0,0x00,0x00,0x0,0x7ff0
};

static ALIGN32_BEG double ln_2p0[4] ALIGN32_END = {2.0,2.0, 2.0, 2.0};
static ALIGN32_BEG double ln_minus_2p0[4] ALIGN32_END = {-2.0,-2.0,-2.0,-2.0};
static ALIGN32_BEG double ln_0p5[4] ALIGN32_END = {0.5, 0.5, 0.5, 0.5};
static ALIGN32_BEG double ln_1p0[4] ALIGN32_END = {1.0, 1.0, 1.0, 1.0};

static inline v4sd simd_ln4d(const v4sd a)
{
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
    v4sd tempef;
    v4sd tempz;
    v4sd tempz1;
    v4sd tempz2;
    v4sd tempx;
    v4sd tempy;
    v8si temp1i;
    v8si temp2i;
    v8si temp3i;
    v8si tempe;
    v8si tempq;
    v4sd temp0dz;
    v4sd temp1dz;
    v4sd temp2dz;
    v4sd temp3dz;
    v4sd temp4dz;
	v4sd src = a;
    /*if (isnan(x))
     * return(x);
     */
    temp0d = simd_cmpeqd(src, src); // if not nan return 2.0,else return 0.0

    /*if (x == INFINITY)
     * return(x);
     */

    temp1d = simd_cmpeqd(src, *(v4sd *) ln_inf);

    /*
     * if (x <= 0.0) {
     *   if (x == 0.0) {
     *     return (-INFINITY);
     *   } else {
     *     return (NAN);
     *   }
     * }
     */

    temp2d = simd_cmpled(src, simd_zerod);
    temp3d = simd_cmpeqd(src, simd_zerod);
    temp2dz = simd_ord(simd_andd(temp3d, *(v4sd *) ln_minus_inf), simd_andnotd(temp3d, *(v4sd *) ln_vnan));

    // x = frexp(x, &e);
    src = simd_frexpd(src, &tempe);
    ((double *) &tempef)[0] = ((int *) &tempe)[1];
    ((double *) &tempef)[1] = ((int *) &tempe)[3];
    ((double *) &tempef)[2] = ((int *) &tempe)[5];
    ((double *) &tempef)[3] = ((int *) &tempe)[7];

    /*
     * if ((e > 2) || (e < -2)) {
     * if (x < SQRTH) {
     * e -= 1;
     * z = x - 0.5;
     * y = 0.5 * z + 0.5;
     * }
     * else {
     * z = x - 0.5;
     * z -= 0.5;
     * y = 0.5 * x + 0.5;
     * }
     *
     * x = z / y;
     * z = x * x;
     * z = x * (z * polevl(z, ln_r, 2) / p1evl(z, ln_s, 3));
     * y = e;
     * z = z - y * 2.121944400546905827679e-4;
     * z = z + x;
     * z = z + e * 0.693359375;
     * goto ldone;
     * }
     */

    // e < -2 || e > 2
    temp3d = simd_ord(simd_cmpltd(*(v4sd *) ln_2p0, tempef),
                      simd_cmpltd(tempef, *(v4sd *) ln_minus_2p0));

    temp4d = simd_cmpltd(src, *(v4sd *) & ln_sqrt);
    temp5d = simd_subd(tempef, *(v4sd *) & ln_1p0);
    tempef = simd_ord(simd_andd(temp4d, temp5d), simd_andnotd(temp4d, tempef));
    temp5d = simd_subd(src, *(v4sd *) ln_0p5);
    temp6d = simd_subd(temp5d, *(v4sd *) ln_0p5);
    tempz1 = simd_ord(simd_andd(temp4d, temp5d), simd_andnotd(temp4d, temp6d));
    temp5d = simd_addd(simd_muld(*(v4sd *) ln_0p5, src), *(v4sd *) ln_0p5);
    temp6d = simd_addd(simd_muld(*(v4sd *) ln_0p5, tempz1), *(v4sd *) ln_0p5);

    tempy = simd_ord(simd_andd(temp4d, temp6d), simd_andnotd(temp4d, temp5d));
    tempx = simd_divd(tempz1, tempy);
    tempz1 = simd_muld(tempx, tempx);

    tempz1 = simd_muld(tempx, simd_divd(simd_muld(tempz1, simd_polevld(tempz1, (v4sd *) ln_r, 2)),
                                        simd_p1evld(tempz1, (v4sd *) ln_s, 3)));
    tempy = tempef;
    tempz1 = simd_subd(tempz1, simd_muld(tempy, *(v4sd *) ln_const1));
    tempz1 = simd_addd(tempz1, tempx);
    tempz1 = simd_addd(tempz1, simd_muld(tempef, *(v4sd *) ln_const2));

    /*
     * if (x < SQRTH) {
     * e -= 1;
     * x = ldexp(x, 1) - 1.0;
     * }
     * else {
     * x = x - 1.0;
     * }
     * z = x * x;
     * y = x * (z * polevl(x, ln_p, 5) / p1evl(x, ln_q, 5));
     *
     * if (e)
     * y = y - e * 2.121944400546905827679e-4;
     * y = y - ldexp(z, -1);
     * z = x + y;
     * if (e)
     * z = z + e * 0.693359375;
     *
     * ldone:
     * return (z);
     */

    tempx = simd_ord(simd_andd(temp4d, simd_subd(simd_muld(src, *(v4sd *) ln_2p0),
				*(v4sd *) ln_1p0)), simd_andnotd(temp4d, simd_subd(src, *(v4sd *)
				ln_1p0)));

    tempz2 = simd_muld(tempx, tempx);
    tempy = simd_muld(tempx, simd_divd(simd_muld(tempz2, simd_polevld(tempx, (v4sd *) ln_p, 5)),
				simd_p1evld(tempx, (v4sd *) ln_q, 5)));

    temp5d = simd_cmpeqd(tempef, simd_zerod);
    tempy = simd_ord(simd_andd(temp5d, tempy),
                 simd_andnotd(temp5d, simd_subd(tempy, simd_muld(tempef, *(v4sd *) ln_const1))));

    tempy = simd_subd(tempy, simd_muld(tempz2, *(v4sd *) ln_0p5));
    tempz2 = simd_addd(tempy, tempx);
    tempz2 = simd_ord(simd_andd(temp5d, tempz2),
                 simd_andnotd(temp5d, simd_addd(tempz2, simd_muld(tempef, *(v4sd *) ln_const2))));

    tempz = simd_ord(simd_andd(temp3d, tempz1), simd_andnotd(temp3d, tempz2));
    tempz = simd_ord(simd_andd(temp2d, temp2dz), simd_andnotd(temp2d, tempz));
    tempz = simd_ord(simd_andd(temp1d, src), simd_andnotd(temp1d, tempz));
    tempz = simd_ord(simd_andd(temp0d, tempz), simd_andnotd(temp0d, *(v4sd *) ln_vnan));

    return tempz;
}

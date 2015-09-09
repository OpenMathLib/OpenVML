#ifndef	_SIMD_MAP_H_
#define	_SIMD_MAP_H_

#include "simd_const.h"


// double 
#define simd_zerod			_mm256_setzero_pd()
#define simd_addd			_mm256_add_pd
#define simd_subd			_mm256_sub_pd

#define simd_muld			_mm256_mul_pd
#define simd_divd			_mm256_div_pd
#define simd_sqrtd			_mm256_sqrt_pd
#define simd_floord			_mm256_floor_pd

#define simd_maxd			_mm256_max_pd
#define simd_mind			_mm256_min_pd

#define simd_andd			_mm256_and_pd 	
#define simd_andnotd	        	_mm256_andnot_pd 		
#define simd_xord			_mm256_xor_pd 	
#define simd_ord			_mm256_or_pd 

#define simd_cmpltd(a,b)	        _mm256_cmp_pd(a, b, _CMP_LT_OS) 
#define simd_cmpled(a,b)	        _mm256_cmp_pd(a, b, _CMP_LE_OS)
#define simd_cmpged(a,b)	        _mm256_cmp_pd(a, b, _CMP_GE_OS)
#define simd_cmpeqd(a,b)	        _mm256_cmp_pd(a, b, _CMP_EQ_OS)

#define simd_mad(a,b,c)		        simd_addd(c, simd_muld(a,b)) // va*vb+vc
#define simd_nmad(a,b,c)	        simd_subd(c, simd_muld(a,b)) // vc-va*vb

#define simd_mind			_mm256_min_pd 
#define simd_maxd			_mm256_max_pd 

typedef union imm_xmm_union {
    v8si imm;
    v4si xmm[2];
} imm_xmm_union;

#define COPY_IMM_TO_XMM(imm_, xmm0_, xmm1_) {       \
    imm_xmm_union u __attribute__((aligned(32)));   \
    u.imm = imm_;                                   \
    xmm0_ = u.xmm[0];                               \
    xmm1_ = u.xmm[1];                               \
}

#define COPY_XMM_TO_IMM(xmm0_, xmm1_, imm_) {       \
    imm_xmm_union u __attribute__((aligned(32)));   \
    u.xmm[0]=xmm0_; u.xmm[1]=xmm1_; imm_ = u.imm;   \
}

// logical
#ifdef __AVX2__
	#define simd_andw		_mm256_and_si256
#else
	static inline v8si simd_andw(v8si x, v8si y)	\
	{						\
		v4si x1, x2;				\
		v4si y1, y2;				\
		v8si ret;				\
		COPY_IMM_TO_XMM(x, x1, x2);		\
		COPY_IMM_TO_XMM(y, y1, y2);		\
		x1 = _mm_and_si128(x1,y1);		\
		x2 = _mm_and_si128(x2,y2);		\
		COPY_XMM_TO_IMM(x1, x2, ret);		\
		return(ret);				\
	}
#endif

#ifdef __AVX2__
	#define simd_andnotw	_mm256_andnot_si256
#else
	static inline v8si simd_andnotw(v8si x, v8si y)	\
	{						\
		v4si x1, x2;				\
		v4si y1, y2;				\
		v8si ret;				\
		COPY_IMM_TO_XMM(x, x1, x2);		\
		COPY_IMM_TO_XMM(y, y1, y2);		\
		x1 = _mm_andnot_si128(x1,y1);		\
		x2 = _mm_andnot_si128(x2,y2);		\
		COPY_XMM_TO_IMM(x1, x2, ret);		\
		return(ret);				\
	}
#endif

#ifdef __AVX2__
	#define simd_orw		_mm256_or_si256 
#else
	static inline v8si simd_orw(v8si x, v8si y)	\
	{						\
		v4si x1, x2;				\
		v4si y1, y2;				\
		v8si ret;				\
		COPY_IMM_TO_XMM(x, x1, x2);		\
		COPY_IMM_TO_XMM(y, y1, y2);		\
		x1 = _mm_or_si128(x1,y1);		\
		x2 = _mm_or_si128(x2,y2);		\
		COPY_XMM_TO_IMM(x1, x2, ret);		\
		return(ret);				\
	}
#endif

// integer
#ifdef __AVX2__
	#define simd_subw		_mm256_sub_epi32 
#else
	static inline v8si simd_subw(v8si x, v8si y)	\
	{						\
		v4si x1, x2;				\
		v4si y1, y2;				\
		v8si ret;				\
		COPY_IMM_TO_XMM(x, x1, x2);		\
		COPY_IMM_TO_XMM(y, y1, y2);		\
		x1 = _mm_sub_epi32(x1,y1);		\
		x2 = _mm_sub_epi32(x2,y2);		\
		COPY_XMM_TO_IMM(x1, x2, ret);		\
		return(ret);				\
	}
#endif

#ifdef __AVX2__
	#define simd_addw		_mm256_add_epi32 
#else
	static inline v8si simd_addw(v8si x, v8si y)	\
	{						\
		v4si x1, x2;				\
		v4si y1, y2;				\
		v8si ret;				\
		COPY_IMM_TO_XMM(x, x1, x2);		\
		COPY_IMM_TO_XMM(y, y1, y2);		\
		x1 = _mm_add_epi32(x1,y1);		\
		x2 = _mm_add_epi32(x2,y2);		\
		COPY_XMM_TO_IMM(x1, x2, ret);		\
		return(ret);				\
	}
#endif

#ifdef __AVX2__
	#define simd_cmpeqw		_mm256_cmpeq_epi32 
#else
	static inline v8si simd_cmpeqw(v8si x, v8si y)	\
	{						\
		v4si x1, x2;				\
		v4si y1, y2;				\
		v8si ret;				\
		COPY_IMM_TO_XMM(x, x1, x2);		\
		COPY_IMM_TO_XMM(y, y1, y2);		\
		x1 = _mm_cmpeq_epi32(x1,y1);		\
		x2 = _mm_cmpeq_epi32(x2,y2);		\
		COPY_XMM_TO_IMM(x1, x2, ret);		\
		return(ret);				\
	}
#endif

#ifdef __AVX2__
	#define simd_xorw		_mm256_xor_si256 
#else
	static inline v8si simd_xorw(v8si x, v8si y)	\
	{						\
		v4si x1, x2;				\
		v4si y1, y2;				\
		v8si ret;				\
		COPY_IMM_TO_XMM(x, x1, x2);		\
		COPY_IMM_TO_XMM(y, y1, y2);		\
		x1 = _mm_xor_si128(x1,y1);		\
		x2 = _mm_xor_si128(x2,y2);		\
		COPY_XMM_TO_IMM(x1, x2, ret);		\
		return(ret);				\
	}
#endif


#ifdef __AVX2__
	#define simd_srliw		_mm256_srli_epi32 
#else
	static inline v8si simd_srliw(v8si x, int a)	\
	{						\
		v4si x1, x2;				\
		v8si ret;				\
		COPY_IMM_TO_XMM(x, x1, x2);		\
		x1 = _mm_srli_epi32(x1,a);		\
		x2 = _mm_srli_epi32(x2,a);		\
		COPY_XMM_TO_IMM(x1, x2, ret);		\
		return(ret);				\
	}
#endif

#ifdef __AVX2__
	#define simd_slliw		_mm256_slli_epi32 
#else
	static inline v8si simd_slliw(v8si x, int a)	\
	{						\
		v4si x1, x2;				\
		v8si ret;				\
		COPY_IMM_TO_XMM(x, x1, x2);		\
		x1 = _mm_slli_epi32(x1,a);		\
		x2 = _mm_slli_epi32(x2,a);		\
		COPY_XMM_TO_IMM(x1, x2, ret);		\
		return(ret);				\
	}
#endif

// floating point
#define simd_zeros		_mm256_setzero_ps()
#define simd_adds               _mm256_add_ps
#define simd_subs               _mm256_sub_ps
#define simd_muls               _mm256_mul_ps
#define simd_divs               _mm256_div_ps
#define simd_sqrts              _mm256_sqrt_ps
#define simd_ands               _mm256_and_ps
#define simd_andnots            _mm256_andnot_ps
#define simd_xors               _mm256_xor_ps
#define simd_ors		_mm256_or_ps
#define simd_floors             _mm256_floor_ps
#define simd_cmplts(a,b)        _mm256_cmp_ps(a, b, _CMP_LT_OS)
#define simd_cmples(a,b)        _mm256_cmp_ps(a, b, _CMP_LE_OS)
#define simd_cmpeqs(a,b)        _mm256_cmp_ps(a, b, _CMP_EQ_OS)
#define simd_cmpneqs(a,b)       _mm256_cmp_ps(a, b, _CMP_NEQ_OQ)

// if a is true and select c, else b
#define simd_selects(a,b,c)     _mm256_add_ps(_mm256_and_ps(a,c),_mm256_andnot_ps(a,b))

#define simd_mas(a,b,c)         _mm256_add_ps(_mm256_mul_ps(a,b),c)     // va*vb+vc
#define simd_nmas(a,b,c)        _mm256_sub_ps(c,_mm256_mul_ps(a,b))     // vc-va*vb

#define simd_cvts_w             _mm256_cvtps_epi32
#define simd_cvtw_s             _mm256_cvtepi32_ps
#define simd_cvtw_d		_mm256_cvtepi32_pd
#define simd_cvtd_w		_mm256_cvtpd_epi32

#define simd_castw_s            _mm256_castsi256_ps // cast int to float
#define simd_casts_w            _mm256_castps_si256 // cast float to int

#define simd_mins		_mm256_min_ps 
#define simd_maxs		_mm256_max_ps 

// for 128-bit integer
#define simd_andu		_mm_and_si128 
#define simd_cmpequ		_mm_cmpeq_epi32
#define simd_cmpltu		_mm_cmplt_epi32
#define simd_oru		_mm_or_si128
#define simd_andu		_mm_and_si128
#define simd_andnotu		_mm_andnot_si128


#endif /*_SIMD_MAP_H_ */

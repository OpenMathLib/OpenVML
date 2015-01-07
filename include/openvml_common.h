#ifndef _OPENVML_COMMON_H_
#define _OPENVML_COMMON_H_

#include "openvml_config.h"

#ifdef DOUBLE
typedef double VML_FLOAT;
#else
typedef float VML_FLOAT;
#endif

#if defined(OS_WINDOWS) && defined(__64BIT__)
typedef long long VMLLONG;
typedef unsigned long long VMLULONG;
#else
typedef long VMLLONG;
typedef unsigned long VMLULONG;
#endif

#ifdef USE64BITINT
typedef VMLLONG VML_INT;
#else
typedef int VML_INT;
#endif

#define OpenVML_FUNCNAME_3(pre,x,suf) pre##x##suf
#define OpenVML_FUNCNAME_2(pre,x,suf) OpenVML_FUNCNAME_3(pre, x, suf)
#define OpenVML_FUNCNAME_1(x) OpenVML_FUNCNAME_2(OPENVML_FUNC_PREFIX, x, OPENVML_FUNC_SUFFIX)
#define OpenVML_FUNCNAME(x) OpenVML_FUNCNAME_1(x)

#endif
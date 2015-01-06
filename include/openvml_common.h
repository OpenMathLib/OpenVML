#ifndef _OPENVML_COMMON_H_
#define _OPENVML_COMMON_H_

#include "openvml_config.h"

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

#endif
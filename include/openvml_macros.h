#ifndef _OPENVML_MACROS_H_
#define _OPENVML_MACROS_H_

#define SADD_K sadd_k


#define DADD_K dadd_k



#ifndef COMPLEX
#ifndef DOUBLE
#define ADD_K SADD_K
#else
#define ADD_K DADD_K
#endif
#else
#ifndef DOUBLE
#define ADD_K CADD_K
#else
#define ADD_K ZADD_K
#endif
#endif

#endif
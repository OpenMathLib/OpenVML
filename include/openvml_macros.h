#ifndef _OPENVML_MACROS_H_
#define _OPENVML_MACROS_H_

#define SADD_K OpenVML_FUNCNAME(sadd_k)
#define DADD_K OpenVML_FUNCNAME(dadd_k)
//reuse 
#define CADD_K OpenVML_FUNCNAME(sadd_k)
#define ZADD_K OpenVML_FUNCNAME(dadd_k)


#define SSUB_K OpenVML_FUNCNAME(ssub_k)
#define DSUB_K OpenVML_FUNCNAME(dsub_k)
//reuse 
#define CSUB_K OpenVML_FUNCNAME(ssub_k)
#define ZSUB_K OpenVML_FUNCNAME(dsub_k)


#ifndef COMPLEX
#ifndef DOUBLE
#define ADD_K SADD_K
#define SUB_K SSUB_K
#else
#define ADD_K DADD_K
#define SUB_K DSUB_K
#endif
#else
#ifndef DOUBLE
#define ADD_K CADD_K
#define SUB_K CSUB_K
#else
#define ADD_K ZADD_K
#define SUB_K CSUB_K
#endif
#endif

#endif
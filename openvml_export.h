
#ifndef OPENVML_EXPORT_H
#define OPENVML_EXPORT_H

#ifdef OPENVML_STATIC_DEFINE
#  define OPENVML_EXPORT
#  define OPENVML_NO_EXPORT
#else
#  ifndef OPENVML_EXPORT
#    ifdef openvml_EXPORTS
        /* We are building this library */
#      define OPENVML_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define OPENVML_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef OPENVML_NO_EXPORT
#    define OPENVML_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef OPENVML_DEPRECATED
#  define OPENVML_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef OPENVML_DEPRECATED_EXPORT
#  define OPENVML_DEPRECATED_EXPORT OPENVML_EXPORT OPENVML_DEPRECATED
#endif

#ifndef OPENVML_DEPRECATED_NO_EXPORT
#  define OPENVML_DEPRECATED_NO_EXPORT OPENVML_NO_EXPORT OPENVML_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define OPENVML_NO_DEPRECATED
#endif

#endif

set(OpenVML_LIBSRC_OTHER "")

if(NOT BUILD_SINGLE_THREAD)
set(OpenVML_LIBSRC_OTHER
    ${OpenVML_LIBSRC_OTHER}
    openvml_server.c
    )
endif()

add_library(openvml_driver_core OBJECT ${OpenVML_LIBSRC_OTHER})

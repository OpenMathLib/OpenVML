set(OpenVML_LIBSRC_OTHER "")

set(OpenVML_LIBSRC_OTHER
    ${OpenVML_LIBSRC_OTHER}
    openvml_util.c
    )

if(NOT BUILD_SINGLE_THREAD)
set(OpenVML_LIBSRC_OTHER
    ${OpenVML_LIBSRC_OTHER}
    openvml_server.c
    )
endif()

add_library(openvml_driver_core OBJECT ${OpenVML_LIBSRC_OTHER})

target_compile_definitions(openvml_driver_core PUBLIC openvml_EXPORTS)
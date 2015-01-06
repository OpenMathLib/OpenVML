############ Set LIBSRC #################

set(OpenVML_LIBSRC_S "")
set(OpenVML_LIBSRC_D "")
set(OpenVML_LIBSRC_C "")
set(OpenVML_LIBSRC_Z "")

set(REAL_INTERFACE_LIST add sub)
set(COMPLEX_INTERFACE_LIST add sub)

foreach(INTERFACE ${REAL_INTERFACE_LIST})

  set(OpenVML_LIBSRC_S
    ${OpenVML_LIBSRC_S}
    ${CMAKE_CURRENT_SOURCE_DIR}/${INTERFACE}.c
    )

  set(OpenVML_LIBSRC_D
    ${OpenVML_LIBSRC_D}
    ${CMAKE_CURRENT_BINARY_DIR}/${INTERFACE}_d.c
    )

  add_custom_command( OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${INTERFACE}_d.c
    DEPENDS ${INTERFACE}.c
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/${INTERFACE}.c   ${CMAKE_CURRENT_BINARY_DIR}/${INTERFACE}_d.c
    COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/${INTERFACE}_d.c)

  set_property(SOURCE ${CMAKE_CURRENT_BINARY_DIR}/${INTERFACE}_d.c
    APPEND 
    PROPERTY COMPILE_DEFINITIONS ${OpenVML_D_DEFINITIONS} ) 

endforeach(INTERFACE)

add_library(openvml_interface_core OBJECT ${OpenVML_LIBSRC_S} ${OpenVML_LIBSRC_D} ${OpenVML_LIBSRC_C} ${OpenVML_LIBSRC_Z} ${OpenVML_LIBSRC_OTHER})

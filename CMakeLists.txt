cmake_minimum_required(VERSION 2.8)

project(OpenVML C CXX)

set (OpenVML_LIBNAME openvml)

set (OpenVML_VERSION_MAJOR 0)
set (OpenVML_VERSION_MINOR 0)
set (OpenVML_VERSION_PATCH 1)

#set (OpenVML_ARCH "x86_64")
#set (OpenVML_CPU_CORENAME "haswell")

set (OpenVML_FUNC_PREFIX "")
set (OpenVML_FUNC_SUFFIX "")

option(BUILD_SINGLE_THREAD "Only build the single thread" ON)
option(AUTO_DETECT_CPU "Auto detect CPU architecture." ON)
option(BUILD_OpenVML_TEST "Build Test" ON)
option(BUILD_64BIT_INT "Build 64bit int interface(ilp64)" OFF)

#####################################################

if(AUTO_DETECT_CPU)
include(${PROJECT_SOURCE_DIR}/cmake/auto_detect_cpu.cmake)
endif()

if (NOT OpenVML_ARCH)
set (OpenVML_ARCH "generic")
endif(NOT OpenVML_ARCH)
if (NOT OpenVML_CPU_CORENAME)
set (OpenVML_CPU_CORENAME "generic")
endif(NOT OpenVML_CPU_CORENAME)

include_directories("${PROJECT_BINARY_DIR}") 
include_directories("${PROJECT_BINARY_DIR}/include") 
include_directories("${PROJECT_SOURCE_DIR}/include") 

#single thread
if(BUILD_SINGLE_THREAD)
  set(OPENVML_SINGLE_THREAD 1)
endif(BUILD_SINGLE_THREAD)

#32-bit or 64-bit target
include(${PROJECT_SOURCE_DIR}/cmake/detect_32or64bit.cmake)
detect_32_64_bit(OpenVML_BINARY)
if("${OpenVML_BINARY}" STREQUAL "32")
  set(__32BIT__ 1)
elseif("${OpenVML_BINARY}" STREQUAL "64")
  set(__64BIT__ 1)
endif()

#32-bit or 64-bit int
if(BUILD_64BIT_INT)
  set(USE64BITINT 1)
endif()

if(WIN32)
  set(OS_WINDOWS 1)
endif()

configure_file (
  "${PROJECT_SOURCE_DIR}/include/openvml_config.h.in"
  "${PROJECT_BINARY_DIR}/include/openvml_config.h"
)


SET(CMAKE_POSITION_INDEPENDENT_CODE ON) 

set(OpenVML_LIBSRC_S "")
set(OpenVML_LIBSRC_D "")
set(OpenVML_LIBSRC_C "")
set(OpenVML_LIBSRC_Z "")
set(OpenVML_LIBSRC_OTHER "")

#define -DDOUBLE for double precision
set(OpenVML_S_DEFINITIONS "")
set(OpenVML_D_DEFINITIONS DOUBLE)
set(OpenVML_C_DEFINITIONS COMPLEX)
set(OpenVML_Z_DEFINITIONS COMPLEX DOUBLE)



##########################################################
# For RPATH http://www.cmake.org/Wiki/CMake_RPATH_handling
#
set(CMAKE_MACOSX_RPATH 1)
# use, i.e. don't skip the full RPATH for the build tree
SET(CMAKE_SKIP_BUILD_RPATH  FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 
SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


# the RPATH to be used when installing, but only if it's not a system directory
LIST(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
IF("${isSystemDir}" STREQUAL "-1")
   SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
ENDIF("${isSystemDir}" STREQUAL "-1")
##########################################################


add_subdirectory(interface)
add_subdirectory(driver)
add_subdirectory(kernel)

set(CORE_LIB_LISTS $<TARGET_OBJECTS:openvml_interface_core> $<TARGET_OBJECTS:openvml_driver_core> $<TARGET_OBJECTS:openvml_kernel_${OpenVML_ARCH}_${OpenVML_CPU_CORENAME}_core>)

add_library(${OpenVML_LIBNAME} SHARED ${CORE_LIB_LISTS})
#only build shared library for MSVC
if(NOT MSVC)
add_library(${OpenVML_LIBNAME}_static STATIC ${CORE_LIB_LISTS})

set_target_properties(${OpenVML_LIBNAME}_static PROPERTIES OUTPUT_NAME ${OpenVML_LIBNAME})
set_target_properties(${OpenVML_LIBNAME}_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
endif()

set_target_properties(${OpenVML_LIBNAME} PROPERTIES CLEAN_DIRECT_OUTPUT 1)

if(NOT MSVC)
target_link_libraries(${OpenVML_LIBNAME} m)
target_link_libraries(${OpenVML_LIBNAME}_static m)
endif()

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set_target_properties(${OpenVML_LIBNAME} PROPERTIES 
  VERSION ${OpenVML_VERSION_MAJOR}.${OpenVML_VERSION_MINOR}
  SOVERSION ${OpenVML_VERSION_MAJOR}
)

include (GenerateExportHeader)
generate_export_header(${OpenVML_LIBNAME})

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE )
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

#install
if(NOT MSVC)
install(TARGETS ${OpenVML_LIBNAME} ${OpenVML_LIBNAME}_static
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
else()
install(TARGETS ${OpenVML_LIBNAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
endif()

install(FILES ${PROJECT_BINARY_DIR}/openvml_export.h DESTINATION include)
install(FILES ${PROJECT_BINARY_DIR}/include/openvml_config.h DESTINATION include)
install(FILES ${PROJECT_SOURCE_DIR}/include/openvml.h DESTINATION include)
install(FILES ${PROJECT_SOURCE_DIR}/include/openvml_common.h DESTINATION include)


#test
if(BUILD_OpenVML_TEST)
add_subdirectory(reference)

enable_testing()
add_subdirectory(test)
endif(BUILD_OpenVML_TEST)

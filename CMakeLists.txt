cmake_minimum_required(VERSION 3.24)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{VCPKG_ROOT})
    string(STRIP "$ENV{VCPKG_ROOT}" _blackline_vcpkg_root)
    set(_blackline_vcpkg_toolchain "${_blackline_vcpkg_root}/scripts/buildsystems/vcpkg.cmake")
    if(EXISTS "${_blackline_vcpkg_toolchain}")
        set(CMAKE_TOOLCHAIN_FILE "${_blackline_vcpkg_toolchain}" CACHE FILEPATH "vcpkg toolchain file")
    endif()
endif()

project(
    blackline
    VERSION 0.0.1
    DESCRIPTION "BLACKLINE competitive FPS and purpose-built engine"
    LANGUAGES CXX
)

include(cmake/BlacklineProjectOptions.cmake)

enable_testing()

add_subdirectory(engine/core)
add_subdirectory(apps/bootstrap)
add_subdirectory(tests)

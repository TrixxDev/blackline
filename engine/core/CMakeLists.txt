add_library(bl_core STATIC)

add_library(blackline::core ALIAS bl_core)

target_sources(
    bl_core
    PRIVATE src/version.cpp
)

target_include_directories(
    bl_core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(bl_core PUBLIC cxx_std_23)

blackline_apply_project_warnings(bl_core)
blackline_apply_version_definitions(bl_core)

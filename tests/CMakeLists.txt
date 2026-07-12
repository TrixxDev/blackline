find_package(Catch2 CONFIG REQUIRED)

add_executable(bl_core_tests core_version_test.cpp)

target_link_libraries(
    bl_core_tests
    PRIVATE blackline::core Catch2::Catch2WithMain
)

target_compile_features(bl_core_tests PRIVATE cxx_std_23)

blackline_apply_project_warnings(bl_core_tests)

include(CTest)
include(Catch)

catch_discover_tests(bl_core_tests)

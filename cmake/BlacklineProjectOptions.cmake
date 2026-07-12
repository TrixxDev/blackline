set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

function(blackline_apply_project_warnings target)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /WX /permissive-)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic -Werror)
    endif()
endfunction()

function(blackline_apply_version_definitions target)
    if(CMAKE_BUILD_TYPE)
        set(_blackline_build_config "${CMAKE_BUILD_TYPE}")
    else()
        set(_blackline_build_config "MultiConfig")
    endif()

    target_compile_definitions(
        ${target}
        PUBLIC BLACKLINE_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
               BLACKLINE_VERSION_MINOR=${PROJECT_VERSION_MINOR}
               BLACKLINE_VERSION_PATCH=${PROJECT_VERSION_PATCH}
               BLACKLINE_BUILD_CONFIG="${_blackline_build_config}"
               BLACKLINE_COMPILER_ID="${CMAKE_CXX_COMPILER_ID}"
    )
endfunction()

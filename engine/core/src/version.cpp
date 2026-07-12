#include <bl/core/version.hpp>

#include <format>
#include <string>

#ifndef BLACKLINE_VERSION_MAJOR
#define BLACKLINE_VERSION_MAJOR 0
#endif
#ifndef BLACKLINE_VERSION_MINOR
#define BLACKLINE_VERSION_MINOR 0
#endif
#ifndef BLACKLINE_VERSION_PATCH
#define BLACKLINE_VERSION_PATCH 0
#endif
#ifndef BLACKLINE_BUILD_CONFIG
#define BLACKLINE_BUILD_CONFIG "unknown"
#endif
#ifndef BLACKLINE_COMPILER_ID
#define BLACKLINE_COMPILER_ID "unknown"
#endif

namespace bl::core {
namespace {

constexpr SemanticVersion kVersion{
    static_cast<std::uint32_t>(BLACKLINE_VERSION_MAJOR),
    static_cast<std::uint32_t>(BLACKLINE_VERSION_MINOR),
    static_cast<std::uint32_t>(BLACKLINE_VERSION_PATCH),
};

} // namespace

SemanticVersion version() noexcept {
    return kVersion;
}

const char* versionString() noexcept {
    static const std::string formatted =
        std::format("{}.{}.{}", kVersion.major, kVersion.minor, kVersion.patch);
    return formatted.c_str();
}

BuildInfo buildInfo() noexcept {
    return BuildInfo{
        .version = kVersion,
        .configuration = BLACKLINE_BUILD_CONFIG,
        .compilerId = BLACKLINE_COMPILER_ID,
    };
}

std::string formatBuildReport() {
    const BuildInfo info = buildInfo();
    return std::format(
        "BLACKLINE bootstrap\n"
        "  product: blackline\n"
        "  version: {}.{}.{}\n"
        "  configuration: {}\n"
        "  compiler: {}\n",
        info.version.major,
        info.version.minor,
        info.version.patch,
        info.configuration,
        info.compilerId);
}

} // namespace bl::core

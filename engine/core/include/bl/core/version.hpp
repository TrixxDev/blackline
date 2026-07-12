#pragma once

#include <cstdint>
#include <string>

namespace bl::core {

struct SemanticVersion {
    std::uint32_t major{};
    std::uint32_t minor{};
    std::uint32_t patch{};
};

[[nodiscard]] SemanticVersion version() noexcept;
[[nodiscard]] const char* versionString() noexcept;

struct BuildInfo {
    SemanticVersion version{};
    const char* configuration{};
    const char* compilerId{};
};

[[nodiscard]] BuildInfo buildInfo() noexcept;
[[nodiscard]] std::string formatBuildReport();

} // namespace bl::core

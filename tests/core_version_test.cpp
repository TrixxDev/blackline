#include <bl/core/version.hpp>

#include <catch2/catch_test_macros.hpp>

#include <string>
#include <string_view>

TEST_CASE("version exposes semantic components", "[core][version]") {
    const bl::core::SemanticVersion version = bl::core::version();

    REQUIRE(version.major == 0);
    REQUIRE(version.minor == 0);
    REQUIRE(version.patch == 1);
}

TEST_CASE("versionString matches semantic version", "[core][version]") {
    REQUIRE(std::string_view{bl::core::versionString()} == "0.0.1");
}

TEST_CASE("buildInfo includes configuration and compiler metadata", "[core][version]") {
    const bl::core::BuildInfo info = bl::core::buildInfo();

    REQUIRE(info.version.major == 0);
    REQUIRE(info.version.minor == 0);
    REQUIRE(info.version.patch == 1);
    REQUIRE(std::string_view{info.configuration}.length() > 0);
    REQUIRE(std::string_view{info.compilerId}.length() > 0);
}

TEST_CASE("formatBuildReport includes product and version lines", "[core][version]") {
    const std::string report = bl::core::formatBuildReport();

    REQUIRE(report.find("BLACKLINE bootstrap") != std::string::npos);
    REQUIRE(report.find("version: 0.0.1") != std::string::npos);
}

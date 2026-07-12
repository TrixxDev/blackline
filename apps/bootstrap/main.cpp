#include <bl/core/version.hpp>

#include <iostream>

int main() {
    std::cout << bl::core::formatBuildReport();
    return 0;
}

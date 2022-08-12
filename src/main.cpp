#include "table.hpp"
#include "color.hpp"
#include "ansi_codes.hpp"
#include <iostream>

int main() {
    std::cout << ANSI::ColorRGBFG(66, 245, 182) << ANSI::ColorRGBBG(224, 130, 179) << "Testing colors" << ANSI::GraphicsResetAllModes() << "\n";
}

#include "table.hpp"
#include "color.hpp"
#include "ansi_codes.hpp"
#include <iostream>

int main() {
    std::cout << ANSI::ColorRgbFG(66, 245, 182) << ANSI::ColorRgbBG(224, 130, 179) << "Testing colors" << ANSI::GraphicsResetAllModes() << "\n";
}

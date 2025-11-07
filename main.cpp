#include <iostream>
#include <cmath>
#include <vector>
#include "LogicFunctions.h"

using namespace std;

struct Color { int r, g, b; };

void printPixel(const Color &c) {
    // set background color (48;2;r;g;b), print two spaces as the "pixel", then reset
    std::cout << "\x1b[48;2;" << c.r << ";" << c.g << ";" << c.b << "m" << "  " << "\x1b[0m";
}

void drawGrid(int width, int height, const vector<Color> &grid) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            printPixel(grid[y * width + x]);
        }
        std::cout << '\n';
    }
}

int main() {
    const int width = 40;
    const int height = 20;
    vector<Color> grid(width * height);

    // Fill with a simple gradient
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y * width + x] = {
                (x * 255) / (width - 1),      // red gradient across X
                (y * 255) / (height - 1),     // green gradient across Y
                128                           // constant blue
            };
        }
    }

    drawGrid(width, height, grid);
    return 0;
}
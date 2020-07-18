#include <iostream>
#include "Fuel/fuel.h"
#include "Intcode/intcode.h"
#include "ReadFile/readFile.h"
#include "Wires/wires.h"
#include <algorithm>
#include <keypad.h>


int main() {

    range puzzleRange;
    puzzleRange.max = 676461;
    puzzleRange.min = 178416;
//    if (testNumForValidity(112233)) {
//        std::cout << "hello" << std::endl;
//    }
    std::cout << possiblePasscodes(puzzleRange) << std::endl;

    return 0;
}

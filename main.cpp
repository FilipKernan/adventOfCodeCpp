#include <iostream>
#include "Fuel/fuel.h"
#include "Intcode/intcode.h"
#include "ReadFile/readFile.h"
#include "Wires/wires.h"
#include <algorithm>
#include <keypad.h>


int main() {

    std::string input =  fileToString("../PuzzleInput.txt");
    compute(constructArray(input));
    return 0;
}

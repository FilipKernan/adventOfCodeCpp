#include <iostream>
#include "Fuel/fuel.h"
#include "Intcode/intcode.h"
#include "ReadFile/readFile.h"

int main() {


//        std::cout << compute(constructArray("1,1,1,4,99,5,6,0,99")) << std::endl;
    std::string input =  fileToString("../PuzzleInput.txt");

for (int i = 0; i <= 99; i++){
    for (int j = 0; j <= 99; j++){
        std::string workingString;
        workingString = input.substr(0, 2) + std::to_string(i) + "," + std::to_string(j) + input.substr(5);

        if (compute(constructArray(workingString)) == 19690720) {
            std::cout << std::to_string((100 * i) + j) << std::endl;
        }

    }
}

    return 0;
}

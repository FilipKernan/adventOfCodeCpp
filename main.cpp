#include <iostream>
#include "Fuel/fuel.h"
#include "Intcode/intcode.h"
#include "ReadFile/readFile.h"
#include "Wires/wires.h"
#include <algorithm>


int main() {

    int SIZE = 15000;
//        std::cout << compute(constructArray("1,1,1,4,99,5,6,0,99")) << std::endl;
    std::string input =  fileToString("../PuzzleInput.txt");
    std::vector<intersection> intersections = findIntersections(input, SIZE, SIZE);
    intersection nearest = findClosestManhatten(intersections);
    //intersection nearest = findClosestWireDistance(intersections);

    std::cout << abs(nearest.x - SIZE/2) + abs(nearest.y - SIZE/2) << std::endl;
    //std::cout << nearest.xSteps + nearest.ySteps << std::endl;
    return 0;
}

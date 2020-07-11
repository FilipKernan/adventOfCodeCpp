//
// Created by filip on 7/7/20.
//
#include "wires.h"


std::vector<intersection> findIntersections(std::string string,int &height,int &width){
    // creates an array for the wires to exist on
    long** wireArray = new long *[height];
    for (int l = 0; l < height; ++l) {
        wireArray[l] = new long[width];
    }
    fill(wireArray, height, width);
    // splits the puzzle input
    std::size_t found = string.find("\n", 1);
    std::string stringArray[2] = {string.substr(1, found), string.substr(found + 1)};
    // creates a log of intersections
    std::vector<intersection> intersections;

    // loops though each wire
    for (int i = 0; i < 2; ++i) {
        int x = height/2, y = width/2;
        int size = 0;
        // splits wire instructions appart
        std::vector<std::string> stringVector = split(stringArray[i], size);
        long pastLength = 0;

        for (int j = 0; j < size; ++j) {
            // parsing the wire instructions
            std::string currentInstruction = stringVector[j];
            char direction = currentInstruction[0];
            int lenght = std::stoi(currentInstruction.substr(1));

            for (int k = 0; k < lenght; ++k) {
                if (wireArray[y][x] > 0 && i == 1) { // logs any intersections that are detected
                    intersection section;
                    section.x = x;
                    section.y = y;
                    section.xSteps = pastLength + k;
                    section.ySteps = wireArray[y][x];
                    intersections.push_back(section);
                } else {
                    if (i <= 0 && wireArray[y][x] == 0) {
                        wireArray[y][x] = pastLength + k;
                    }
                }
                switch (direction) {
                    case 'U':

                        y++;
                        break;
                    case 'D':

                        y--;
                        break;
                    case 'R':
                        x++;
                        break;
                    case 'L':

                        x--;
                        break;
                }
            }
            pastLength += lenght ;
        }
    }
    return intersections;
}




// splits appart a string of instuctions to individual instuctions
std::vector<std::string> split(std::string string, int& size){
    size = std::count(string.begin(), string.end(), ',') + 1;
    std::vector<std::string> turnList;
    int lastTurn = 0;
    for (int j = 0; j < size; ++j) {
        turnList.push_back( string.substr(lastTurn, string.find(",", lastTurn + 1) - (lastTurn)));
        lastTurn = string.find(",", lastTurn + 1) + 1;
    }
    return turnList;
}




intersection findClosestManhatten(std::vector<intersection> intersections){
    std::sort(intersections.begin(), intersections.end(), compareManhattenDistance);
    return intersections[0];
}
intersection findClosestWireDistance(std::vector<intersection> intersections){
    std::sort(intersections.begin(), intersections.end(), compareWireDistance);
    return intersections[0];
}

// fills an array with 0s
void fill(long** wireArray, int height, int width) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            wireArray[i][j] = 0;
        }
    }
}

bool compareManhattenDistance( intersection &a,  intersection &b){
    return (abs(a.x - (ARRAY_SIZE/2)) + abs(a.y - (ARRAY_SIZE/2))) < (abs(b.x - (ARRAY_SIZE/2)) + abs(b.y - (ARRAY_SIZE/2)));
}

bool compareWireDistance( intersection &a,  intersection &b) {
    return a.xSteps + a.ySteps < b.xSteps + b.ySteps;
}
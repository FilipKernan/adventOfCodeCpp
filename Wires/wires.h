//
// Created by filip on 7/7/20.
//
#include <string>
#include <algorithm>
#include <vector>
#ifndef ADVENTOFCODE_WIRES_H
#define ADVENTOFCODE_WIRES_H

#define ARRAY_SIZE 15000

struct intersection {
    int x;
    int y;
    long xSteps;
    long ySteps;
};


std::vector<intersection> findIntersections(std::string string,int &height,int &width);


intersection findClosestManhatten(std::vector<intersection> intersections);

intersection findClosestWireDistance(std::vector<intersection> intersections);

std::vector<std::string> split(std::string, int&);

void fill(long** wireArray, int height, int width);

bool compareManhattenDistance(intersection &a, intersection &b);

bool compareWireDistance( intersection &a,  intersection &b);

#endif //ADVENTOFCODE_WIRES_H

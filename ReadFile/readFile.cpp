//
// Created by filip on 7/6/20.
//
#include "readFile.h"

std::string fileToString(std::string address){
    std::ifstream read(address);
    std::string output, endString;
    while(getline(read, output)) {
        endString += "\n" + output;
    }
    return endString;
}

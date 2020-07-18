//
// Created by filip on 7/11/20.
//

#ifndef ADVENTOFCODE_KEYPAD_H
#define ADVENTOFCODE_KEYPAD_H

#include <vector>

struct range {
    unsigned long min;
    unsigned long max;
};

int possiblePasscodes(range);
bool testNumForValidity(int num);

std::vector<int> splitNum(int);



#endif //ADVENTOFCODE_KEYPAD_H

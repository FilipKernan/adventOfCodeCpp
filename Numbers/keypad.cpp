//
// Created by filip on 7/11/20.
//
#include <cmath>
#include "keypad.h"

int possiblePasscodes(range range) {
    int possiblePasscodes = 0;
    for (int i = range.min; i <= range.max; ++i) {


        if (testNumForValidity(i)) {
            possiblePasscodes++;
        }

    }
    return possiblePasscodes;
}

bool testNumForValidity(int num) {
    bool neverDecreases = true, doubles = false, lastNumWasDouble = false, validDouble = false;
    std::vector<int> testNum = splitNum(num);
    for (int j = 0; j < testNum.size(); j++) {// I know this is not best practice for vectors
        if (j +1 < testNum.size()) {
            if (doubles) {
                lastNumWasDouble = true;
            }
            if (testNum[j] == testNum[j+1]) {
                if (lastNumWasDouble) {
                    doubles = false;
                } else {
                    doubles = true;
                }
            } else {
                lastNumWasDouble = false;
                if (doubles)  {
                    validDouble = true;
                }
            }

            if (j + 2 == testNum.size() && doubles && !lastNumWasDouble) validDouble = true;

            if (testNum[j] > testNum[j+1]) {
                neverDecreases = false;
            }
        }
    }
    return neverDecreases && validDouble;
}

std::vector<int> splitNum(int num) {// might be better to use array but I needed more practice with vectors
    std::vector<int> numVector;
    for (int i = 0; num * (pow(0.1, i)) > 1; ++i) {
        int val = num * (pow(0.1, i));
        val %= 10;
        numVector.insert(numVector.begin(), val);
    }
    return numVector;
}


/*
 * create vector of digits
 *  we know that it is 6 digits
 *      number* (0.1 * i) -> %10
 *      do 6 times  use insert(0, val)
 * once vector is created, create flags for the requirements
 *  never decresses
 *  has one double
 *  no tripples
 */
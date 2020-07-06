//
// Created by filip on 7/5/20.
//
#include "intcode.h"

long* constructArray(std::string in){
    long incodes[200];
    int indexOfLastComa = -1, incodeCount = 0;
    for (int i =0; i < in.length(); i++) {
        if (in[i] == ',') {
            incodes[incodeCount] = std::stoi(in.substr((indexOfLastComa + 1),(i - (indexOfLastComa + 1))));//substinf index of last coma and
            indexOfLastComa = i;
            incodeCount++;
        }
    }
    long* ptr = incodes;
    return ptr;
}

long compute(long* intcodes) {
    int index = 0;
    while (validOpcode(*(intcodes + index))){
        long code[4];

        std::copy(intcodes + index, intcodes + index +4, code);
        switch (*(intcodes + index)) {
            case 1:
                opcode1(code, intcodes);
                break;
            case 2:
                opcode2(code, intcodes);
                break;
        }
        index += 4;
    }
    return  *intcodes;
}

void opcode1(long code[], long* intcodes){
    long result = *(intcodes + code[1]) + *(intcodes + code[2]);
    *(intcodes + code[3]) = result;
}

void opcode2(long code[], long* intcodes){
    long result = *(intcodes + code[1]) * *(intcodes + code[2]);
    *(intcodes + code[3]) = result;
}


bool validOpcode(long opcode) {
    return 1 == opcode || 2 == opcode;
}
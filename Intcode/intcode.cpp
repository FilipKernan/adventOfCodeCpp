//
// Created by filip on 7/5/20.
//
#include "intcode.h"

void compute(int* intcodes) {
    int index = 0;
    while (validOpcode(*(intcodes + index))){
        int code[4];

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
}

int opcode1(int code[], int* intcodes);

int opcode2(int code[], int* intcodes);


bool validOpcode(int opcode) {
    return 1 == opcode || 2 == opcode;
}
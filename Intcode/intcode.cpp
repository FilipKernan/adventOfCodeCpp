//
// Created by filip on 7/5/20.
//
#include "intcode.h"

long* constructArray(std::string in){
    long incodes[1000];
    int indexOfLastComa = -1, incodeCount = 0;
    for (int i =0; i < in.length(); i++) {
        if (in[i] == ',') {
            incodes[incodeCount] = std::stoi(in.substr((indexOfLastComa + 1),(i - (indexOfLastComa + 1))));//substinf index of last coma and
            indexOfLastComa = i;
            incodeCount++;
        }
        if (i +1 == in.length()) {
            incodes[incodeCount] = std::stoi(in.substr(in.find_last_of(',', in.length() -1) + 1));//substinf index of last coma and
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
        switch ((*(intcodes + index)) % 10) {
            case 1:
                opcode1(code, intcodes, index);
                break;
            case 2:
                opcode2(code, intcodes, index);
                break;
            case 3:
                opcode3(code, intcodes, index);
                break;
            case 4:
                opcode4(code, intcodes, index);
                break;
            case 5:
                opcode5(code, intcodes, index);
                break;
            case 6:
                opcode6(code, intcodes, index);
                break;
            case 7:
                opcode7(code, intcodes, index);
                break;
            case 8:
                opcode8(code, intcodes, index);
                break;
        }

    }
    return  *intcodes;
}

void opcode1(long code[], long* intcodes, int &index){
    int param1, param2;
    if ((code[0]/100) % 10 == 1) {
        param1 = code[1];
    } else {
        param1 = *(intcodes + code[1]);
    }

    if ((code[0]/1000)  == 1) {
        param2 = code[2];
    } else {
        param2 = *(intcodes + code[2]);
    }
    long result = param1 + param2;
    *(intcodes + code[3]) = result;
    index += 4;

}

void opcode2(long code[], long* intcodes, int &index){
    int param1, param2;
    if ((code[0]/100) % 10 == 1) {
        param1 = code[1];
    } else {
        param1 = *(intcodes + code[1]);
    }

    if ((code[0]/1000)  == 1) {
        param2 = code[2];
    } else {
        param2 = *(intcodes + code[2]);
    }
    long result = param1 * param2;
    *(intcodes + code[3]) = result;
    index += 4;

}

void opcode3(long code[], long* intcodes, int &index){
    long result;
    std::cout <<  "enter an input" << std::endl;
    std::cin >> result;
    *(intcodes + code[1]) = result;
    index += 2;

}

void opcode4(long code[], long* intcodes, int &index){
    if (code[0] / 100 == 1) {
        std::cout <<  code[1] << std::endl;
    } else {
        std::cout << *(intcodes + code[1]) << std::endl;
    }
    index += 2;

}

void opcode5(long code[], long* intcodes, int &index) {
    int param1, param2;
    if ((code[0]/100) % 10 == 1) {
        param1 = code[1];
    } else {
        param1 = *(intcodes + code[1]);
    }

    if ((code[0]/1000)  == 1) {
        param2 = code[2];
    } else {
        param2 = *(intcodes + code[2]);
    }
    if (param1 != 0) {
        index = param2;
    } else {
        index += 3;
    }
}

void opcode6(long code[], long* intcodes, int &index) {
    int param1, param2;
    if ((code[0]/100) % 10 == 1) {
        param1 = code[1];
    } else {
        param1 = intcodes[code[1]];
    }

    if ((code[0]/1000)  == 1) {
        param2 = code[2];
    } else {
        param2 = intcodes[code[2]];
    }
    if (param1 == 0) {
        index = param2;
    } else {
        index += 3;
    }
}

void opcode7(long code[], long* intcodes, int &index) {
    int param1, param2;
    if ((code[0]/100) % 10 == 1) {
        param1 = code[1];
    } else {
        param1 = *(intcodes + code[1]);
    }

    if ((code[0]/1000)  == 1) {
        param2 = code[2];
    } else {
        param2 = *(intcodes + code[2]);
    }
    if  (param1 < param2) {
        *(intcodes + code[3]) = 1;
    } else {
        *(intcodes + code[3]) = 0;
    }

    index += 4;
}

void opcode8(long code[], long* intcodes, int &index) {
    int param1, param2;
    if ((code[0]/100) % 10 == 1) {
        param1 = code[1];
    } else {
        param1 = *(intcodes + code[1]);
    }

    if ((code[0]/1000)  == 1) {
        param2 = code[2];
    } else {
        param2 = *(intcodes + code[2]);
    }
    if  (param1 == param2) {
        *(intcodes + code[3]) = 1;
    } else {
        *(intcodes + code[3]) = 0;
    }

    index += 4;
}


bool validOpcode(long opcode) {
    opcode %= 10;
    return 1 == opcode || 2 == opcode || 3 == opcode || 4 == opcode || 5 == opcode ||
        6 == opcode || 7 == opcode || 8 == opcode;
}
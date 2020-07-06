//
// Created by filip on 7/5/20.
//
#include <string>

#ifndef ADVENTOFCODE_INTCODE_H
#define ADVENTOFCODE_INTCODE_H
long * constructArray(std::string);

long compute(long[]);

void opcode1(long[], long*);

void opcode2(long[], long*);

bool validOpcode(long);
#endif //ADVENTOFCODE_INTCODE_H

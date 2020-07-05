//
// Created by filip on 7/5/20.
//
#include <string>

#ifndef ADVENTOFCODE_INTCODE_H
#define ADVENTOFCODE_INTCODE_H
int* constructArray(std::string);

void compute(int[]);

int opcode1(int[], int*);

int opcode2(int[], int*);

bool validOpcode(int);
#endif //ADVENTOFCODE_INTCODE_H

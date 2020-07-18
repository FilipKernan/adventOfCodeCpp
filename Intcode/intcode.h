//
// Created by filip on 7/5/20.
//
#include <string>
#include <iostream>


#ifndef ADVENTOFCODE_INTCODE_H
#define ADVENTOFCODE_INTCODE_H
long * constructArray(std::string);

long compute(long[]);

void opcode1(long[], long*, int &);

void opcode2(long[], long*, int &);

void opcode3(long[], long*, int &);

void opcode4(long[], long*, int &);

void opcode5(long[], long*, int &);

void opcode6(long[], long*, int &);

void opcode7(long[], long*, int &);

void opcode8(long[], long*, int &);



bool validOpcode(long);
#endif //ADVENTOFCODE_INTCODE_H

//
// Created by filip on 7/18/20.
//

#ifndef ADVENTOFCODE_ORBITS_H
#define ADVENTOFCODE_ORBITS_H

#include <string>
#include <vector>
using namespace std;

struct body {

    string name;
    body* parent = NULL;
    vector<body*> children;

};



vector<body*> createTreeOfBodies(vector<string>);


unsigned long computeTotalOrbits(vector<body*>);

int countParents(body*);

vector<string> orbits(string);

int findBody(vector<body *>, string);

unsigned long transversesToSanta(body*, body*);

int validPaths(body*);
/*
 * create struct with name and vector of bodies orbiting  check
 * also create a master vector of all bodies
 * walk though list and search for body name
 *  walk up the tree and count how many steps until reached COM
 *  increment counter
 */
#endif //ADVENTOFCODE_ORBITS_H

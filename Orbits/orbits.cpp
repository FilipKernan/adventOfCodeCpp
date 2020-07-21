//
// Created by filip on 7/18/20.
//
#include <algorithm>
#include <iostream>
#include "orbits.h"



/*
 * need to create dynamic var to have it be put on the heap
 * https://stackoverflow.com/questions/23444844/c-error-terminate-called-after-throwing-an-instance-of-stdbad-alloc
 * possubly need to write custom find
 */

vector<body*> createTreeOfBodies(vector<string> in) {
    vector<body *> bodies;
    for (int i = 0; i < in.size(); ++i) {
        // if parent does exists exists
        int foundParent = findBody(bodies, in[i].substr(0, 3));
        if( foundParent >= 0) {
            int parentIndex = foundParent;
            body * childBody = new body();

            int foundChild = findBody(bodies, in[i].substr(4));
            if( foundChild >= 0) {
                int index = foundChild;

                bodies[index]->parent = bodies[parentIndex];
                bodies[parentIndex]->children.push_back(bodies[index]);


            } else { // if child does not exists
                bodies.push_back(childBody);
                int childIndex = bodies.size() - 1;
                bodies[childIndex]->name = in[i].substr(4);
                bodies[childIndex]->parent = bodies[parentIndex];
                bodies[parentIndex]->children.push_back(childBody);


            }
        }else {
            body *parentBody = new body(), *childBody = new body();
            bodies.push_back(parentBody);
            int parentIndex = bodies.size() -1;
            bodies[parentIndex]->name = in[i].substr(0, 3);
            // if child already exists
            int foundChild = findBody(bodies, in[i].substr(4));

            if( foundChild >= 0) {
                int index = foundChild;
                bodies[index]->parent = bodies[parentIndex];
                bodies[parentIndex]->children.push_back(bodies[index]);

            } else { // if child does not exists
                bodies.push_back(childBody);
                int childIndex = bodies.size() - 1;
                bodies[childIndex]->name = in[i].substr(4);
                bodies[childIndex]->parent = bodies[parentIndex];
                bodies[parentIndex]->children.push_back(bodies[childIndex]);

            }







        }
    }
    int COM = findBody(bodies, "COM");
    int END = findBody(bodies, "W94");
    int OTHEREND = findBody(bodies, "XQQ");

    return bodies;
}

unsigned long computeTotalOrbits(vector<body*> bodies) {
    unsigned long totalOrbits = 0;
    for (int i = 0; i < bodies.size(); ++i) {
        totalOrbits += countParents(bodies[i]);
    }
    return totalOrbits;
}

int countParents(body* mass) {
    int parents = 0;
    if (mass->parent != NULL) {
        parents = 1;

        parents += countParents(mass->parent);
    }
    return parents;
}
vector<string> orbits(string in){
    vector<string> orbits;
    int index = 0;
    while (index + 3 < in.length()) {
        int enterIndex = in.find_first_of('\n', index);
        string orbitString = in.substr(index, enterIndex - index);
        orbits.push_back(orbitString);
        index = enterIndex + 1;
    }
    return orbits;
}


int findBody(vector<body *> bodies, string name) {
    int retVal = -1;
    for (int i = 0; i < bodies.size(); ++i) {
        if (retVal == -1 && bodies[i]->name == name) {
            retVal = i;
        }
    }

    return retVal;
}


unsigned long transversesToSanta(body* currentNodePtr, body* lastNodePtr) {
    vector<unsigned long> transverses;
    if (currentNodePtr->name == "SAN") {
        return 1;
    } else if (validPaths(currentNodePtr) <= 0  && lastNodePtr != NULL) {
        return 1000000000;
    } else {
        if (currentNodePtr->parent != NULL && currentNodePtr->parent != lastNodePtr) {
            if (lastNodePtr == NULL) {
                transverses.push_back(transversesToSanta(currentNodePtr->parent, currentNodePtr));

            } else {
                transverses.push_back(1 + transversesToSanta(currentNodePtr->parent, currentNodePtr));

            }
        }
        for (int i = 0; i < currentNodePtr->children.size(); ++i) {
            if (currentNodePtr->children[i] != lastNodePtr) {
                unsigned long pathCount = transversesToSanta(currentNodePtr->children[i], currentNodePtr);
                if (pathCount == 1) {
                    transverses.push_back(1);
                } else transverses.push_back(pathCount + 1);
            }
        }
        sort(transverses.begin(), transverses.end());
        return transverses.front();
    }
}

int validPaths(body* currentNodePtr) {
    int retVal = 0;
    if (currentNodePtr->parent != NULL) {
        retVal++;
    }
    retVal += currentNodePtr->children.size();
    retVal--;
    return retVal;
}

/*
 * find min transfers to Santa
 * depth first search, stop at nulls
 *
 * count transverses, for each connection, that is not your own  count is unsigned long
 *  min 1, needs to have protection against climbing back up, have root node param
 *  each transvers count will be added to a vector, helper function to return min
 *  returns 1 if node name is Santa, return 100000 if all children && parents are null
 *
 *
 */

#include <iostream>
#include "Fuel/fuel.h"
#include "Intcode/intcode.h"
#include "ReadFile/readFile.h"
#include "Wires/wires.h"
#include <algorithm>
#include <keypad.h>
#include "Orbits/orbits.h"

using namespace std;
int main() {

    string input =  fileToString("../PuzzleInput.txt");
    vector<string> orbitVector =  orbits(input);

    vector<body*> tree = createTreeOfBodies(orbitVector);
    int myIndex = findBody(tree, "YOU");
    /*
     * refactor to just get the number of steps
     * then have transvers also take in a target
     * manualy find your index and santa's index
     * pass the parents into the transverse funcion.
     */
    unsigned long toSanta = transversesToSanta(tree[myIndex], NULL);

    cout << toSanta << endl;

    return 0;
}

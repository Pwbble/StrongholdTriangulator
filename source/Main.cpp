/**
 * Name: Main.cpp
 * Description: Main class
 * Created: Dec 23, 2022
 */

#include <cmath>
#include <iostream>
#include "Location.h"

using std::cin;
using std::cout;

using std::endl;
using std::string;

Location triangulate(Location& pos1, Location& pos2) {
    float x1 = pos1.getX(); // x1
    float z1 = pos1.getZ(); // z1
    float x2 = pos2.getX(); // x2
    float z2 = pos2.getZ(); // z2
    float m1 = tan(pos1.getYawRad()); // Slope 1
    float m2 = tan(pos2.getYawRad()); // Slope 2
    float sx = (z1 - z2 + (m2 * x2) - (m1 * x1)) / (m2 - m1); // Stronghold x pos
    float sz = (m1 * (sx - x1)) + z1;                         // Stronghold z pos
    return {sx, sz, 0}; // Stronghold location
}

Location getLocation(int id) {
    float x, z, yaw;
    // Get location
    cout << "Enter x" << id << ": ";
    cin >> x;
    cout << "Enter z" << id << ": ";
    cin >> z;
    // Get yaw
    do {
        cout << "Enter yaw" << id << ": ";
        cin >> yaw;
    } while (!Location::isYawGood(yaw));
    return {x, z, yaw};
}

void run() {
    Location pos1 = getLocation(1), pos2 = getLocation(2), stronghold = triangulate(pos1, pos2);

    cout << "Approximate Stronghold Location: (" << stronghold.getX() << ", ~, " << stronghold.getZ() << ")." << endl << endl;
    cout << "(If this location is off, perhaps your input data was wrong.)" << endl;
}

int main() {
    run();
    return 0;
}
/**
 * Name: Location.cpp
 * Description: Location class
 * Created: Dec 23, 2022
 */

#include "Location.h"

Location::Location(const float x, const float z, const float yaw) : x(x),
                                                                    z(z),
                                                                    yaw(yaw),
                                                                    yawRad(degToRad(mcDegToDeg(yaw))) {}

#ifndef COORDINATE_HPP_
#define COORDINATE_HPP_

#include <iostream>
#include <cmath>

struct coordinate {
    double x;
    double y;
    double z;
    coordinate () {}
    coordinate (double x, double y, double z);
    void print () const;
    double distance (const coordinate& other) const;
};

#endif // COORDINATE_HPP_

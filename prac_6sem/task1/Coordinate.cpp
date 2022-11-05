
#include "Coordinate.hpp"

coordinate::coordinate(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void coordinate::print () const {
    std::cout << x << " " << y << " " << z << std::endl;
}

double coordinate::distance (const coordinate& other) const {
    return sqrt(pow(x-other.x, 2)+pow(y-other.y, 2)+pow(z-other.z, 2));
}

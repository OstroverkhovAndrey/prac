
#ifndef STACKSTATE_HPP_
#define STACKSTATE_HPP_

#include "Coordinate.hpp"

class StackState {
private:
    struct state {
        coordinate begin;
        coordinate end;
        coordinate next;
        double length;
        double angle;
        state* prev;
    };
    state* currentState;
public:
    StackState () {currentState = 0;}
    void push (const coordinate& begin, const coordinate& end, const coordinate& next, const double& length, const double& angle);
    void pop (coordinate& begin, coordinate& end, coordinate& next, double& length, double& angle);
    ~StackState();
};

#endif // STACKSTATE_HPP_


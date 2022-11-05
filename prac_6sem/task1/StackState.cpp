
#include "StackState.hpp"

void StackState::push (const coordinate& begin, const coordinate& end, const coordinate& next, const double& length, const double& angle) {
    state* temp = new state;
    temp->begin = begin;
    temp->end = end;
    temp->next = next;
    temp->length = length;
    temp->angle = angle;
    temp->prev = currentState;
    currentState = temp;
}

void StackState::pop (coordinate& begin, coordinate& end, coordinate& next, double& length, double& angle) {
    begin = currentState->begin;
    end = currentState->end;
    next = currentState->next;
    length = currentState->length;
    angle = currentState->angle;
    state *temp = currentState;
    currentState = currentState->prev;
    delete temp;
}

StackState::~StackState () {
    while (currentState) {
        state* temp = currentState;
        currentState = currentState -> prev;
        delete temp;
    }
}

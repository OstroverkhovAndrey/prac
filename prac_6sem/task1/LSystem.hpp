
#ifndef LSYSTEM_HPP_
#define LSYSTEM_HPP_

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Coordinate.hpp"
#include "StackState.hpp"
#include <GL/glut.h>
#include <cmath>

class LSystem {
private:
    std::string initialString;
    std::string currentString;
    double lengthBranch;
    double angleBranch;
    double scaleLengthCoefficient;
    double scaleAngleCoefficient;
    struct rule {
        char before;
        std::string after;
        double probabilityOfApplication;
    };
    int numRules;
    rule* rules;
    coordinate calculationNextPoint (const coordinate& point1, const coordinate& point2, const double& len);
    coordinate turn3d (const coordinate& point1, const coordinate& point2, const coordinate& point3, double angle, bool f, char axis);
    coordinate turn2d (const coordinate& point1, const coordinate& point2, const coordinate& point3, double angle, bool f);
    void drawLine (const coordinate& point1, const coordinate& coint2);

public:
    LSystem ();

    void setLengthBranch (float len) {lengthBranch = len;}
    void setAngleBranch (float angle) {angleBranch = angle;}
    void setScaleLengthCoefficient (float coef) {scaleLengthCoefficient = coef;}
    void setScaleAngleCoefficient (float coef) {scaleAngleCoefficient = coef;}

    const std::string& getCurrentString () const {return currentString;}

    void addRule (char c, std::string str, double prob = 1.0);
    void buildSystem (int numIterations);
    void printRules ();
    void draw ();
};

#endif // LSYSTEM_HPP_


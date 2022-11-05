
#include "LSystem.hpp"

LSystem::LSystem() {
    initialString = "F";
    currentString = "";
    lengthBranch = 1;
    angleBranch = 30;
    scaleLengthCoefficient = 1;
    scaleAngleCoefficient = 1;
    numRules = 0;
    rules = new rule[numRules];
}

void LSystem::addRule(char c, std::string str, double prob) {
    for (int i = 0; i < numRules; ++i) {
        if (c == rules[i].before) {
            rules[i].after = str;
            rules[i].probabilityOfApplication = prob;
            return;
        }
    }
    numRules++;
    rule* temp = new rule[numRules];
    for (int i = 0; i < numRules-1; ++i) {
        temp[i] = rules[i];
    }
    temp[numRules-1].before = c;
    temp[numRules-1].after = str;
    temp[numRules-1].probabilityOfApplication = prob;
    delete [] rules;
    rules = temp;
}

void LSystem::buildSystem(int numIterations) {
    srand(time(0));
    std::string temp = initialString;
    for (int i = 0; i < numIterations; ++i) {
        currentString = "";
        for (std::string::iterator it = temp.begin(); it != temp.end(); ++it) {
            bool inRules = false;
            for (int k = 0; k < numRules; ++k) {
                if (*it == rules[k].before) {
                    if (1.0*rand()/RAND_MAX < rules[k].probabilityOfApplication) {
                        currentString += rules[k].after;
                        k = numRules;
                        inRules = true;
                    }
                }
            }
            if (!inRules) {
                currentString += *it;
            }
        }
        temp = currentString;
    }
}

void LSystem::printRules() {
    for (int i = 0; i < numRules; ++i) {
        std::cout << rules[i].before << " " << rules[i].after << " " << rules[i].probabilityOfApplication << std::endl;
    }
}

void LSystem::drawLine (const coordinate& point1, const coordinate& point2) {
    glBegin(GL_LINES);
    glVertex3f(point1.x, point1.y, point1.z);
    glVertex3f(point2.x, point2.y, point2.z);
    glEnd();
}

void LSystem::draw() {

    lengthBranch = 1.0;

    coordinate prevPoint(0.0, -1.0, 0.0);
    coordinate currentPoint(0.0, 0.0, 0.0);
    coordinate nextPoint(0.0, lengthBranch, 0.0);

    StackState stackState;

    for (std::string::iterator it = currentString.begin(); it != currentString.end(); ++it) {
        switch (*it) {
            case 'F':
                drawLine(currentPoint, nextPoint);
                prevPoint = currentPoint;
                currentPoint = nextPoint;
                lengthBranch = lengthBranch * scaleLengthCoefficient;
                angleBranch = angleBranch * scaleAngleCoefficient;
                nextPoint = calculationNextPoint(prevPoint, currentPoint, lengthBranch);
                break;
            case 'f':
                prevPoint = currentPoint;
                currentPoint = nextPoint;
                lengthBranch = lengthBranch * scaleLengthCoefficient;
                angleBranch = angleBranch * scaleAngleCoefficient;
                nextPoint = calculationNextPoint(prevPoint, currentPoint, lengthBranch);
                break;
            case '+':
                nextPoint = turn3d(prevPoint, currentPoint, nextPoint, angleBranch, 0, 'z');
                break;
            case '-':
                nextPoint = turn3d(prevPoint, currentPoint, nextPoint, angleBranch, 1, 'z');
                break;
            case '[':
                stackState.push(prevPoint, currentPoint, nextPoint, lengthBranch, angleBranch);
                break;
            case ']':
                stackState.pop(prevPoint, currentPoint, nextPoint, lengthBranch, angleBranch);
                break;
            case '&':
                nextPoint = turn3d(prevPoint, currentPoint, nextPoint, angleBranch, 0, 'x');
                break;
            case '^':
                nextPoint = turn3d(prevPoint, currentPoint, nextPoint, angleBranch, 1, 'x');
                break;
            case '<':
                nextPoint = turn3d(prevPoint, currentPoint, nextPoint, angleBranch, 0, 'y');
                break;
            case '>':
                nextPoint = turn3d(prevPoint, currentPoint, nextPoint, angleBranch, 1, 'y');
                break;
            default:
                break;
        }
    }
    // glBegin(GL_LINES);
    // glVertex3f(0.0, 0.0, 0.0);
    // glVertex3f(1.0, 0.0, 0.0);
    // glVertex3f(0.0, 0.0, 0.0);
    // glVertex3f(0.0, 1.0, 0.0);
    // glEnd();
}

coordinate LSystem::calculationNextPoint (const coordinate& point1, const coordinate& point2, const double& len) {
    double prevLen = point1.distance(point2);
    coordinate point3;
    point3.x = point2.x + (point2.x - point1.x) * (len / prevLen);
    point3.y = point2.y + (point2.y - point1.y) * (len / prevLen);
    point3.z = point2.z + (point2.z - point1.z) * (len / prevLen);
    return point3;
}


coordinate LSystem::turn3d (const coordinate& point1, const coordinate& point2, const coordinate& point3, const double angle, bool f, char axis) {
    coordinate point;
    coordinate newPoint1;
    coordinate newPoint2;
    coordinate newPoint3;
    switch (axis) {
        case 'x':
            newPoint1 = coordinate(point1.z, point1.y, point1.x);
            newPoint2 = coordinate(point2.z, point2.y, point2.x);
            newPoint3 = coordinate(point3.z, point3.y, point3.x);
            point = turn2d(newPoint1, newPoint2, newPoint3, angle, f);
            point = coordinate(point.z, point.y, point.x);
            break;
        case 'y':
            newPoint1 = coordinate(point1.x, point1.z, point1.y);
            newPoint2 = coordinate(point2.x, point2.z, point2.y);
            newPoint3 = coordinate(point3.x, point3.z, point3.y);
            point = turn2d(newPoint1, newPoint2, newPoint3, angle, f);
            point = coordinate(point.x, point.z, point.y);
            break;
        case 'z':
            newPoint1 = coordinate(point1.x, point1.y, point1.z);
            newPoint2 = coordinate(point2.x, point2.y, point2.z);
            newPoint3 = coordinate(point3.x, point3.y, point3.z);
            point = turn2d(newPoint1, newPoint2, newPoint3, angle, f);
            point = coordinate(point.x, point.y, point.z);
            break;
        default:
            break;
    }
    return point;
}

coordinate LSystem::turn2d (const coordinate& point1, const coordinate& point2, const coordinate& point3, double angle, bool f) {

    double len = sqrt(pow(point2.x-point3.x, 2)+pow(point2.y-point3.y, 2));
    double a = point1.x - point2.x;
    double b = point1.y - point2.y;
    double k = cos((180 - angle)*3.14159265/180.0) * len * sqrt(a*a+b*b);

    double q1 = a*a+b*b;
    double q2 = -2*k*a;
    double q3 = k*k - len*len*b*b;
    double D = sqrt(q2*q2-4*q1*q3);
    double c1 = (-q2 - D)/(2*q1);
    double c2 = (-q2 + D)/(2*q1);
    double c = 0.0;
    if (f) {
        if (0 <= c1 && c1 <= len) {
            c = c1;
        } else {
            c = c2;
        }
    } else {
        if (-1 <= c1 && c1 <= 0) {
            c = c1;
        } else {
            c = c2;
        }
    }
    double d = sqrt(len*len-c*c);
    coordinate point;
    point.x = c + point2.x;
    point.y = d + point2.y;
    point.z = point3.z;
    return point;
}

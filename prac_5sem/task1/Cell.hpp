
#ifndef CELL_HPP_
#define CELL_HPP_

#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>

class Cell {
    friend class Field;
private:
    int n; //порядковый номер клетки
    Cell * up; // верхний сосед
    Cell * right; // правый сосед
    Cell * down; // нижний сосед
    Cell * left; // левый сосед
    Cell * upRight; //верхний правый сосед
    Cell * downRight; //нижний правый сосед
    Cell * downLeft; // нижний левый сосед
    Cell * upLeft; //верхний левый сосед
    char color = 'c'; // clear, red, green, blue, цвет клетки
    char nextColor = 'c'; //цвет после очередного цикла
    int x, y; // координаты в матрице
    int size; // размер ячейки

public:
    Cell(int, int, int, int);

    void print(); //вывести цвет клетки
    void draw(sf::RenderWindow & window); //нарисовать клетку
    void updataColor();  // обновление цвета, next_color станет цветом в следующую итерацию
    void changeColor(); // смена цвета
    void randomColor(); //задать рандомный цвет клетке
    void clear(); // очистить цвет клетки
    void setColor(); // установить случайный цвет клетки

    void setColor(char color) {this->color = color;}
    void setUp(Cell * up) {this->up = up;}
    void setRight(Cell * right) {this->right = right;}
    void setDown(Cell * down) {this->down = down;}
    void setLeft(Cell * left) {this->left = left;}
    void setUpRight(Cell * upRight) {this->upRight = upRight;}
    void setDownRight(Cell * downRight) {this->downRight = downRight;}
    void setDownLeft(Cell * downLeft) {this->downLeft = downLeft;}
    void setUpLeft(Cell * upLeft) {this->upLeft = upLeft;}

    char getColor() {return color;}
    Cell * getUp() {return up;}
    Cell * getRight() {return right;}
    Cell * getDown() {return down;}
    Cell * getLeft() {return left;}
    Cell * getUpRight() {return upRight;}
    Cell * getDownRight() {return downRight;}
    Cell * getDownLeft() {return downLeft;}
    Cell * getUpLeft() {return upLeft;}

};

#endif //CELL_HPP_

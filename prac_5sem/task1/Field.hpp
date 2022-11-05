
#ifndef FIELD_H_
#define FIELD_H_

#include "Cell.hpp"
#include <cstdlib>
#include <SFML/Graphics.hpp>

class Field {
private:
    Cell ** field;  //поле игры
    int n, m;       //размеры поля
    int sizeCell;  //размер ячейки
public:
    Field (int, int, int);
    ~Field();
    void print ();  //вывести поле
    void randomColor(); //заполнить поле рандомными цветами
    void updataField(); //обновить поле, произвести очередную итерацию
    void clear(); // очистить поле
    void draw(sf::RenderWindow &); //нарисовать поле
    void setColorCell(int, int); // установить цвет определенной ячейки
};


#endif //FIELD_H_

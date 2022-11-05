
#include "Field.hpp"

Field::Field(int n, int m, int sizeCell) {
    this->sizeCell = sizeCell;
    this->n = n;
    this->m = m;
    this->field = (Cell**)calloc(n, sizeof (Cell*));
    for (int i = 0; i < n; ++i) {
        field[i] = (Cell*)calloc(m, sizeof (Cell));
        for (int j = 0; j < m; ++j) {
            Cell temp = Cell(0, i, j, sizeCell);
            field[i][j] = temp;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            this->field[i][j].setUp(&this->field[(i - 1 + n) % n][(j + m) % m]);
            this->field[i][j].setUpRight(&this->field[(i - 1 + n) % n][(j + 1 + m) % m]);
            this->field[i][j].setRight(&this->field[(i + n) % n][(j + 1 + m) % m]);
            this->field[i][j].setDownRight(&this->field[(i + 1 + n) % n][(j + 1 + m) % m]);
            this->field[i][j].setDown(&this->field[(i + 1 + n) % n][(j + m) % m]);
            this->field[i][j].setDownLeft(&this->field[(i + 1 + n) % n][(j - 1 + m) % m]);
            this->field[i][j].setLeft(&this->field[(i + n) % n][(j - 1 + m) % m]);
            this->field[i][j].setUpLeft(&this->field[(i - 1 + n) % n][(j - 1 + m) % m]);
        }
    }
}

Field::~Field() {
    for (int i = 0; i < n; ++i) {
        free(field[i]);
    }
    free(field);
}

void Field::print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            field[i][j].print();
        }
        std::cout << std::endl;
    }
}

void Field::randomColor() {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            this->field[i][j].randomColor();
        }
    }
}

void Field::updataField(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            this->field[i][j].updataColor();
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            this->field[i][j].changeColor();
        }
    }
}

void Field::clear() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            this->field[i][j].clear();
        }
    }
}

void Field::draw(sf::RenderWindow & window) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            this->field[i][j].draw(window);
        }
    }
}

void Field::setColorCell(int x, int y) {
    field[x][y].setColor();
}


#include "Cell.hpp"

Cell::Cell(int n, int x, int y, int sizeCell) {
    this->n = n;
    this->x = x;
    this->y = y;
    this->size = sizeCell;
}

void Cell::print() {
    if (this->color != 'c') {
        std::cout << this->color << " ";
    } else {
        std::cout << "  ";
    }
}

void Cell::updataColor() {
    int countRed = 0;
    int countGreen = 0;
    int countBlue = 0;
    if (this->up->color == 'r') {
        countRed++;
    } else if (this->up->color == 'g') {
        countGreen++;
    } else if (this->up->color == 'b') {
        countBlue++;
    }
    if (this->upRight->color == 'r') {
        countRed++;
    } else if (this->upRight->color == 'g') {
        countGreen++;
    } else if (this->upRight->color == 'b') {
        countBlue++;
    }
    if (this->right->color == 'r') {
        countRed++;
    } else if (this->right->color == 'g') {
        countGreen++;
    } else if (this->right->color == 'b') {
        countBlue++;
    }
    if (this->downRight->color == 'r') {
        countRed++;
    } else if (this->downRight->color == 'g') {
        countGreen++;
    } else if (this->downRight->color == 'b') {
        countBlue++;
    }
    if (this->down->color == 'r') {
        countRed++;
    } else if (this->down->color == 'g') {
        countGreen++;
    } else if (this->down->color == 'b') {
        countBlue++;
    }
    if (this->downLeft->color == 'r') {
        countRed++;
    } else if (this->downLeft->color == 'g') {
        countGreen++;
    } else if (this->downLeft->color == 'b') {
        countBlue++;
    }
    if (this->left->color == 'r') {
        countRed++;
    } else if (this->left->color == 'g') {
        countGreen++;
    } else if (this->left->color == 'b') {
        countBlue++;
    }
    if (this->upLeft->color == 'r') {
        countRed++;
    } else if (this->upLeft->color == 'g') {
        countGreen++;
    } else if (this->upLeft->color == 'b') {
        countBlue++;
    }

    if (countRed > 3 || countGreen > 3 || countBlue > 3) {
        this->nextColor = 'c';
    } else if (this->color == 'c') {
        if (countRed == 3 && countGreen == 3 && countBlue == 2) {
            this->nextColor = 'b';
        } else if (countRed == 3 && countGreen == 2 && countBlue == 3) {
            this->nextColor = 'g';
        } else if (countRed == 2 && countGreen == 3 && countBlue == 3) {
            this->nextColor = 'r';
        } else if (countRed == 3) {
            this->nextColor = 'r';
        } else if (countGreen == 3) {
            this->nextColor = 'g';
        } else if (countBlue == 3) {
            this->nextColor = 'b';
        }
    } else if (this->color == 'r') {
        if (countRed == 3) {
            this->nextColor = 'r';
        } else if (countGreen == 3 && countBlue != 3) {
            this->nextColor = 'g';
        } else if (countGreen != 3 && countBlue == 3) {
            this->nextColor = 'b';
        } else {
            this->nextColor = 'c';
        }
    } else if (this->color == 'g') {
        if (countGreen == 3) {
            this->nextColor = 'g';
        } else if (countRed == 3 && countBlue != 3) {
            this->nextColor = 'r';
        } else if (countRed != 3 && countBlue == 3) {
            this->nextColor = 'b';
        } else {
            this->nextColor = 'c';
        }
    } else if (this->color == 'b') {
        if (countBlue == 3) {
            this->nextColor = 'b';
        } else if (countRed == 3 && countGreen != 3) {
            this->nextColor = 'r';
        } else if (countRed != 3 && countGreen == 3) {
            this->nextColor = 'g';
        } else {
            this->nextColor = 'c';
        }
    }
}

void Cell::changeColor() {
    this->color = this->nextColor;
}

void Cell::randomColor() {
    int c = rand() % 4;
    if (c == 0) {
        this->color = 'c';
    } else if (c == 1) {
        this->color = 'r';
    } else if (c == 2) {
        this->color = 'g';
    } else {
        this->color = 'b';
    }
}

void Cell::clear() {
    this->color = 'c';
    this->nextColor = 'c';
}

void Cell::draw(sf::RenderWindow & window) {
    sf::CircleShape shape;
    shape.setRadius(float (size / 2));
    shape.setPosition(size * x, size * y);
    if (color == 'c') {
        shape.setFillColor(sf::Color::Black);
    } else if (color == 'r') {
        shape.setFillColor(sf::Color::Red);
    } else if (color == 'g') {
        shape.setFillColor(sf::Color::Green);
    } else if (color == 'b') {
        shape.setFillColor(sf::Color::Blue);
    }
    window.draw(shape);
}

void Cell::setColor() {
    if (color == 'c') {
        color = 'r';
    } else if (color == 'r') {
        color = 'g';
    } else if (color == 'g') {
        color = 'b';
    } else if (color == 'b') {
        color = 'c';
    }
}

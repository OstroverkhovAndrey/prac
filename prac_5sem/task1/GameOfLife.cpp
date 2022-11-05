/*
 * скомпилировать и запустить make
 * скомпилировать make compile
 * запустить make run
 *
 * есть два состояния: работа клеточного автомата и редактирование поля
 * переключение между ними осуществляется клавишей p, изначально режим редактирования
 * в состоянии работы клеточный автомат работает пока не зациклится или поле не очистится
 * в состоянии редактирования можно очистить поле (клавиша c), задать рандомный цвет ячеек (клавиша r)
 * также можно задать цвета в ручную, в состоянии редактирования перейти в режим рисования (клавиша d)
 * она же отвечает за выход из режима рисования
 */


#include "Field.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

    srand(time(NULL));

    // флаги отвечающие за интрефейс
    bool pauseFlag = true;
    bool drawFlag = false;
    bool randomFlag = false;
    bool clearFlag = false;

    // задаем параметры окна и открываем его
    int sizeWindowX = 800, sizeWindowY = 800;
    sf::RenderWindow window;
    window.create(sf::VideoMode(sizeWindowX, sizeWindowY), "GameGfLife", sf::Style::Titlebar | sf::Style::Close);
    window.clear(sf::Color::Black);
    window.setPosition(sf::Vector2i(700, 100));

    // создаем поле игры
    int sizeCell = 20; // размер ячейки
    Field field(sizeWindowX / sizeCell, sizeWindowY / sizeCell, sizeCell);
    field.randomColor();

    // устанавливаем время между итерациями и устанавливаем таймер
    sf::Time t = sf::seconds(0.5f);
    sf::Clock clock;
    clock.restart();

    // запускаем главный цикл игры
    while (window.isOpen()) {
        sf::Event event;
        // запускаем цикл обработки событий
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyReleased) {
                switch (event.key.code) {
                    case sf::Keyboard::P:
                        pauseFlag = !pauseFlag;
                        if (!pauseFlag) {
                            drawFlag = false;
                        }
                        break;
                    case sf::Keyboard::D:
                        if (pauseFlag) {
                            drawFlag = !drawFlag;
                        }
                        break;
                    case sf::Keyboard::R:
                        if (pauseFlag) {
                            field.randomColor();
                        }
                        randomFlag = !randomFlag;
                        break;
                    case sf::Keyboard::C:
                        if (pauseFlag) {
                            field.clear();
                        }
                        clearFlag = !clearFlag;
                        break;
                    default:
                        break;
                }
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (pauseFlag && drawFlag) {
                        field.setColorCell(event.mouseButton.x / sizeCell, event.mouseButton.y / sizeCell);
                    }
                }
            }
        }
        // обновляем поле
        if (clock.getElapsedTime() > t) {
            clock.restart();
            if (!pauseFlag) {
                field.updataField();
            }
        }

        // очищаем и рисуем изображение
        window.clear(sf::Color::Black);
        field.draw(window);
        window.display();
    }

    return 0;
}

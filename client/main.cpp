/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** main
*/

#include <iostream>
// #include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    std::cout << "This is the client main." << std::endl;
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}
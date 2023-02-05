
#include "game.hpp"

void setupPlayButton(game **gm)
{
    (*gm)->playBut.position = sf::Vector2f(860, 775);
    (*gm)->playBut.initButtonRectangleShape((*gm)->playBut.position,
        sf::Color::Black, 4, sf::Color::White, sf::Vector2f(200, 70));

    createText(&(*gm)->playBut.text, &(*gm)->playBut.font, "./assets/fonts/arial.ttf",
        "PLAY", 50, sf::Vector2f((*gm)->playBut.position.x + 43, (*gm)->playBut.position.y + 5), sf::Color::White);
    return;
}
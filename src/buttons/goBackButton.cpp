/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** goBackButton
*/

#include "game.hpp"

void setupGoBackButton(game **gm)
{
    (*gm)->goBackBut.position = sf::Vector2f(40, 40);
    (*gm)->goBackBut.initButtonRectangleShape((*gm)->goBackBut.position,
        sf::Color::Black, 4, sf::Color::White, sf::Vector2f(200, 70));

    createText(&(*gm)->goBackBut.text, &(*gm)->goBackBut.font, "./assets/fonts/arial.ttf",
        "RETOUR", 50, sf::Vector2f((*gm)->goBackBut.position.x + 27, (*gm)->goBackBut.position.y + 5), sf::Color::White);
    return;
}

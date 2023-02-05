/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** goBackButton
*/

#include "game.hpp"

void setupSubmitButton(game **gm)
{
    (*gm)->submitBut.position = (sf::Vector2f){1650, 600};
    (*gm)->submitBut.initButtonRectangleShape((*gm)->submitBut.position,
        sf::Color::Black, 4, sf::Color::White, (sf::Vector2f){200, 70});

    createText(&(*gm)->submitBut.text, &(*gm)->submitBut.font, "./assets/fonts/arial.ttf",
        "VALIDER", 50, (sf::Vector2f){(*gm)->submitBut.position.x + 27, (*gm)->submitBut.position.y + 5}, sf::Color::White);
    return;
}

void setupGoBackButton(game **gm)
{
    (*gm)->goBackBut.position = (sf::Vector2f){40, 40};
    (*gm)->goBackBut.initButtonRectangleShape((*gm)->goBackBut.position,
        sf::Color::Black, 4, sf::Color::White, (sf::Vector2f){200, 70});

    createText(&(*gm)->goBackBut.text, &(*gm)->goBackBut.font, "./assets/fonts/arial.ttf",
        "RETOUR", 50, (sf::Vector2f){(*gm)->goBackBut.position.x + 27, (*gm)->goBackBut.position.y + 5}, sf::Color::White);
    return;
}

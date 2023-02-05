/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** treeButton
*/

#include "game.hpp"

void setupTreeButton(game **gm)
{
    (*gm)->treeBut.position = (sf::Vector2f){1440, 40};
    (*gm)->treeBut.initButtonRectangleShape((*gm)->treeBut.position,
        sf::Color::Black, 4, sf::Color::White, (sf::Vector2f){200, 70});

    createText(&(*gm)->treeBut.text, &(*gm)->treeBut.font, "./assets/fonts/arial.ttf",
        "ARBRE", 50, (sf::Vector2f){(*gm)->treeBut.position.x + 43, (*gm)->treeBut.position.y + 5}, sf::Color::White);
    return;
}
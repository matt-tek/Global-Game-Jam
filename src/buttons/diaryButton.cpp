/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** diaryButton
*/

#include "game.hpp"

void setupDiaryButton(game **gm)
{
    (*gm)->diaryBut.position = sf::Vector2f(1680, 40);
    (*gm)->diaryBut.initButtonRectangleShape((*gm)->diaryBut.position,
        sf::Color::Black, 4, sf::Color::White, sf::Vector2f(200, 70));

    createText(&(*gm)->diaryBut.text, &(*gm)->diaryBut.font, "./assets/fonts/arial.ttf",
        "JOURNAL", 50, sf::Vector2f((*gm)->diaryBut.position.x + 15, (*gm)->diaryBut.position.y + 5), sf::Color::White);
    return;
}
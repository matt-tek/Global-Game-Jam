/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** initRectangleShape
*/

#include "game.hpp"

sf::RectangleShape initRectangleShape(sf::Vector2f position,
    sf::Color fillColor, float outlineThickness, sf::Color outlineColor,
    sf::Vector2f size)
{
    sf::RectangleShape rect;

    rect.setPosition(position);
    rect.setFillColor(fillColor);
    rect.setOutlineThickness(outlineThickness);
    rect.setOutlineColor(outlineColor);
    rect.setSize(size);
    return rect;
}
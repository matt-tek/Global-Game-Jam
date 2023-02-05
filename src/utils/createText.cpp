/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** createText
*/

#include "game.hpp"

void createText(sf::Text *text, sf::Font *font, string fontPath,
    string content, float charSize, sf::Vector2f position, sf::Color fillColor)
{
    font->loadFromFile(fontPath);
    text->setFont((*font));
    text->setFillColor(fillColor);
    text->setCharacterSize(charSize);
    text->setString(s2ws(content));
    text->setPosition(position);
    return;
}
/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** window
*/

#include "window.hpp"

void windowClass::createWindow(int width, int height, std::string window_name)
{
    mode.width = width;
    mode.height = height;
    window.create(sf::VideoMode::getDesktopMode(), window_name);
    return;
}

sf::RenderWindow *windowClass::getWindow(void)
{
    return &this->window;
}
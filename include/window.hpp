/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** window
*/

#include "include.hpp"

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

class windowClass {
    public:
    void createWindow(int width, int height, std::string window_name)
    {
        mode.width = width;
        mode.height = height;
        window.create(mode, window_name);
        return;
    }

    sf::RenderWindow *getWindow(void)
    {
        return &this->window;
    }

    private:
    sf::VideoMode mode;
    sf::RenderWindow window;
};

#endif /* !WINDOW_HPP_ */

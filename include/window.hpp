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
    void createWindow(int width, int height, std::string window_name);

    sf::RenderWindow *getWindow(void);

    private:
    sf::VideoMode mode;
    sf::RenderWindow window;
};

#endif /* !WINDOW_HPP_ */

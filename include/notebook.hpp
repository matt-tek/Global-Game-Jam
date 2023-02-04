


#pragma once

#include <json/json.h>
#include <iostream>
#include <fstream>
#include "notebooktext.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"



class notebook : public sf::Drawable
{
    public:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Font font;
        sf::Text parole;
        int value = 0;
        notebook();
        ~notebook();
        void update();
        bool loadNotebook(std::string path);
        std::vector<std::shared_ptr<notebooktext>> text;
};

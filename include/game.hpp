

#include "include.hpp"
#include "window.hpp"
#include "Animation.hpp"

#pragma once

using namespace std;

class game
{
    private:
        windowClass win;
    public:
        static game *instance;
        std::vector<std::shared_ptr<player>> players;
        vector<sf::Text> dialog;
        sf::RectangleShape dialogPannel;
        sf::Font font;
        Animation *Anim;
        
        game();
        ~game();

        windowClass *getWindow(void)
        {
            return &win;
        }

        static game *getInstance();

        player &getPlayer(std::string name);

        bool loadPlayers(std::string pl);
};

void dialog(game **gm, int person);
sf::RectangleShape initRectangleShape(sf::Vector2f position,
    sf::Color fillColor, float outlineThickness, sf::Color outlineColor,
    sf::Vector2f size);
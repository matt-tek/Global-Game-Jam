

#include "include.hpp"
#include "window.hpp"
#include <functional>

#pragma once

using namespace std;

class button {
    private:
    public:
    virtual void effect(void) = 0;

};

class diaryButton : public button {
    public:
    void effect() override {
        cout << "Hello\n";
    }

    void initButtonRectangleShape(sf::Vector2f position,
        sf::Color fillColor, float outlineThickness, sf::Color outlineColor,
        sf::Vector2f size)
    {
        rect.setPosition(position);
        rect.setFillColor(fillColor);
        rect.setOutlineThickness(outlineThickness);
        rect.setOutlineColor(outlineColor);
        rect.setSize(size);

        hitBox.width = size.x;
        hitBox.height = size.y;
        hitBox.top = position.y;
        hitBox.left = position.x;
        return;
    }

    void drawButton(sf::RenderWindow *window)
    {
        window->draw(rect);
        window->draw(text);
    }

    int isMouseOnButton(sf::Vector2f mousePos)
    {
        if (hitBox.contains(mousePos) == true &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left) == true &&
            isMouseClicked == true) {
                return 0;
            this->effect();
            isMouseClicked = true;
            return 1;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false)
            isMouseClicked = false;
        return 0;
    }

    bool isMouseClicked = false;
    sf::FloatRect hitBox;
    sf::Vector2f position;
    sf::Font font;
    sf::Text text;
    sf::RectangleShape rect;
};

class treeButton : public button {
    public:
    void effect () override {
        cout << "Tree\n";
    }

    void initButtonRectangleShape(sf::Vector2f position,
        sf::Color fillColor, float outlineThickness, sf::Color outlineColor,
        sf::Vector2f size)
    {
        rect.setPosition(position);
        rect.setFillColor(fillColor);
        rect.setOutlineThickness(outlineThickness);
        rect.setOutlineColor(outlineColor);
        rect.setSize(size);

        hitBox.width = size.x;
        hitBox.height = size.y;
        hitBox.top = position.y;
        hitBox.left = position.x;
        return;
    }

    void drawButton(sf::RenderWindow *window)
    {
        window->draw(rect);
        window->draw(text);
    }

    int isMouseOnButton(sf::Vector2f mousePos)
    {
        if (hitBox.contains(mousePos) == true &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left) == true &&
            isMouseClicked == false) {
            effect();
            isMouseClicked = true;
            return 1;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false)
            isMouseClicked = false;
        return 0;
    }

    bool isMouseClicked = false;
    sf::FloatRect hitBox;
    sf::Vector2f position;
    sf::Font font;
    sf::Text text;
    sf::RectangleShape rect;
};

class game
{
    private:
        windowClass win;
    public:
        static game *instance;
        diaryButton diaryBut;
        treeButton treeBut;
        std::vector<std::shared_ptr<player>> players;
        vector<sf::Text> dialog;
        sf::RectangleShape dialogPannel;

        sf::Font font;
        
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
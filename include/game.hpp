

#include "include.hpp"
#include "window.hpp"
#include <functional>

#pragma once

using namespace std;

typedef enum screens_s {
    main_menu,
    dialog_screen,
    diary_screen,
    tree_screen
} screens;

extern screens currentScreen;

class button {
    private:
    public:
    virtual void effect(void) = 0;
};

class goBackButton : public button {
    public:
    void effect(void) override {
        currentScreen = dialog_screen;
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
            sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == true &&
            isMouseClicked == false) {
            this->effect();
            isMouseClicked = true;
            return 1;
        }
        return 0;
    }

    bool isMouseClicked = false;
    sf::FloatRect hitBox;
    sf::Vector2f position;
    sf::Font font;
    sf::Text text;
    sf::RectangleShape rect;
};

class diaryButton : public button {
    public:
    void effect(void) override {
        currentScreen = diary_screen;
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
            sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == true &&
            isMouseClicked == false) {
            this->effect();
            isMouseClicked = true;
            return 1;
        }
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
        currentScreen = tree_screen;
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

class clickWord {
    public:
    bool isClickable;
    sf::RectangleShape rect;
    sf::FloatRect hitbox;
    bool collected;
    string str;
    private:
};

class diaryScreenClass {
    public:
    vector<vector<sf::Text>> text;
    vector<vector<sf::RectangleShape>> hide;
    sf::Font font;
};

class game
{
    private:
        windowClass win;
    public:
        int currentDiary = 0;
        diaryScreenClass diary;
        vector<string> collectedWords;
        static game *instance;
        goBackButton goBackBut;
        diaryButton diaryBut;
        treeButton treeBut;
        map<std::string, int> playerId;
        std::vector<std::shared_ptr<player>> players;
        vector<sf::Text> dialog;
        vector<clickWord> texts;
        sf::RectangleShape dialogPannel;
        int currentScene = 0;
        int person = 0;

        sf::Font font;
        
        void displayCharacter(string character)
        {
            if (this->playerId[character] != 0) {
                getWindow()->getWindow()->draw(players[this->playerId[character]]->sprite.sprite);
                getWindow()->getWindow()->draw(players[this->playerId[character]]->profilePic.sprite);
            }
        }

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

string dialog(game **gm);
sf::RectangleShape initRectangleShape(sf::Vector2f position,
    sf::Color fillColor, float outlineThickness, sf::Color outlineColor,
    sf::Vector2f size);
void setupDiaryButton(game **gm);
void setupTreeButton(game **gm);
void createText(sf::Text *text, sf::Font *font, string fontPath,
    string content, float charSize, sf::Vector2f position, sf::Color fillColor);
void setupGoBackButton(game **gm);
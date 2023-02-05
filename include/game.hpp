

#include "include.hpp"
#include "window.hpp"
#include <functional>

#pragma once

using namespace std;

void createText(sf::Text *text, sf::Font *font, string fontPath,
    string content, float charSize, sf::Vector2f position, sf::Color fillColor);

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
        if (hitBox.contains(mousePos)) {
            this->text.setFillColor(sf::Color::Red);
        } else {
            this->text.setFillColor(sf::Color::White);
        }
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
        if (hitBox.contains(mousePos)) {
            this->text.setFillColor(sf::Color::Red);
        } else {
            this->text.setFillColor(sf::Color::White);
        }
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
        if (hitBox.contains(mousePos)) {
            this->text.setFillColor(sf::Color::Red);
        } else {
            this->text.setFillColor(sf::Color::White);
        }
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

class PlayButton : public button {
    public:
    void effect(void) override {
        currentScreen = main_menu;
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
        if (hitBox.contains(mousePos)) {
            this->text.setFillColor(sf::Color::Red);
        } else {
            this->text.setFillColor(sf::Color::White);
        }
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

class clickWord {
    public:
    bool isClickable;
    sf::RectangleShape rect;
    sf::FloatRect hitbox;
    bool collected;
    string str;
    private:
};

class submitButton : public button {
    public:
    void effect () override {
        cout << "Hello" << endl;
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

    vector<sf::Text> isMouseOnButton(sf::Vector2f mousePos, vector<string> s,
        vector<sf::Text> copy)
    {
        bool correct = true;

//        cout << copy.size() << "+" << s.size() << endl;
        if (copy.size() > s.size()) {
            copy.clear();
            return copy;
        }
        if (hitBox.contains(mousePos) == true &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left) == true &&
            isMouseClicked == false && copy.size() == s.size()) {
            for (size_t i = 0; i < copy.size(); i++) {
                string str = copy[i].getString();
                if (str.compare(s[i]) != 0) {
                    correct = false;
                    break;
                }
            }
            if (correct == true) {
                currentScreen = dialog_screen;
                isMouseClicked = false;
            } else
                copy.clear();
            effect();
            isMouseClicked = true;
            return copy;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false)
            isMouseClicked = false;
        return copy;
    }

    bool isMouseClicked = false;
    sf::FloatRect hitBox;
    sf::Vector2f position;
    sf::Font font;
    sf::Text text;
    sf::RectangleShape rect;
};

class diaryScreenClass {
    public:

    void check(sf::RenderWindow *window, std::vector<string> ansswer,
        int currentDiary)
    {
        sf::Vector2i mouse = sf::Mouse::getPosition((*window));
        sf::Text t;

        sf::Vector2f pos;
        pos.x = mouse.x;
        pos.y = mouse.y;
        for (size_t i = 0; i < wordsTagsHitbox.size(); i++) {
            if (wordsTagsHitbox[i].contains(pos) == true ||
                i == selected) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    selected = i;
                wordTags[i].setFillColor(sf::Color::Black);
                wordTagsRect[i].setFillColor(sf::Color::White);
            } else {
                wordTags[i].setFillColor(sf::Color::White);
                wordTagsRect[i].setFillColor(sf::Color::Black);
            }
        }
        if (selected == -1)
            return;
        if (filled == 1) {
            for (size_t i = 0; i < copy.size(); i++)
                window->draw(copy[i]);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == false)
            up = 0;
        for (size_t i = 0; i < hideHitbox[currentDiary].size(); i++) {
            if (hideHitbox[currentDiary][i].contains(pos)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
                    up == 0) {
                    up = 1;
                    filled = 1;
                    createText(&t, &font, "./assets/fonts/arial.ttf",
                        wordTags[selected].getString(), 80,
                        sf::Vector2f(hideHitbox[currentDiary][i].left,
                        hideHitbox[currentDiary][i].top),
                        sf::Color::White);
                    copy.push_back(t);
                    cout << "pushing_back_copy" << endl;
                    hide[currentDiary][i].setOutlineThickness(0);
                }
                hide[currentDiary][i].setFillColor(sf::Color::White);
            } else {
                hide[currentDiary][i].setFillColor(sf::Color::Black);
            }
        }
        return;
    }
    int up = 0;
    vector<sf::Text> copy;
    int filled = 0;
    int selected = -1;
    vector<vector<sf::Text>> text;
    vector<vector<sf::RectangleShape>> hide;
    vector<vector<sf::FloatRect>> hideHitbox;
    sf::Font font;
    sf::RectangleShape wordPannel;
    vector<sf::Text> wordTags;
    vector<sf::RectangleShape> wordTagsRect;
    vector<sf::Vector2f> wordsTagsPos;
    vector<sf::FloatRect> wordsTagsHitbox;
};

class game
{
    private:
        windowClass win;
    public:
        int currentDiary = 0;
        diaryScreenClass diary;
        vector<string> collectedWords;
        int offset = 50;
        int y = 730;
        static game *instance;

        submitButton submitBut;
        goBackButton goBackBut;
        diaryButton diaryBut;
        treeButton treeBut;
        PlayButton playBut;
        map<std::string, int> playerId;
        std::vector<std::shared_ptr<player>> players;
        vector<sf::Text> dialog;
        vector<clickWord> texts;
        sf::RectangleShape dialogPannel;
        sf::Texture bgMenu;
        sf::Sprite bgMenuSprite;
        std::vector<std::shared_ptr<sf::Texture>> perso_tex;
        std::vector<std::shared_ptr<sf::Sprite>> person_spr;
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
/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** dialogScreen
*/

#include "game.hpp"

extern vector<vector<string>> str;
vector<string> split(const string& str, const string& delimiters);

extern vector<string> bgs;

    /* gm->texture.loadFromFile("./assets/sprites/salon.jpg");
    gm->bg.setTexture(gm->texture);
    gm->bg.setScale(sf::Vector2f(1.71, 1.71)); */

int diaryScreen(game *gm)
{
    sf::Vector2i mouse = sf::Mouse::getPosition((*gm->getWindow()->getWindow()));
    sf::Vector2f pos;
    int offset = 50;

    /* gm->diary.wordTags[0].setPosition((sf::Vector2f){(float)mouse.x,
        (float)mouse.y}); */

    gm->goBackBut.drawButton(gm->getWindow()->getWindow());
    if (gm->goBackBut.isMouseOnButton(sf::Vector2f((float)mouse.x, (float)mouse.y)) == 1) {
        gm->diaryBut.isMouseClicked = false;
        gm->goBackBut.isMouseClicked = false;
    }
    gm->getWindow()->getWindow()->draw(gm->diary.wordPannel);
    for (size_t i = 0; i < gm->diary.wordTags.size(); i++) {
        pos = gm->diary.wordTags[i].getPosition();
        gm->getWindow()->getWindow()->draw(gm->diary.wordTagsRect[i]);
        gm->getWindow()->getWindow()->draw(gm->diary.wordTags[i]);
    }
    for (size_t i = 0; i < gm->diary.text[gm->currentDiary].size(); i++)
        gm->getWindow()->getWindow()->draw(gm->diary.text[gm->currentDiary][i]);
    for (size_t i = 0; i < gm->diary.hide[gm->currentDiary].size(); i++)
        gm->getWindow()->getWindow()->draw(gm->diary.hide[gm->currentDiary][i]);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if (gm->goBackBut.isMouseOnButton(sf::Vector2f((float)mouse.x, (float)mouse.y)) == 1) {
            gm->diaryBut.isMouseClicked = false;
            gm->goBackBut.isMouseClicked = false;
        }
    }
    gm->diary.check(gm->getWindow()->getWindow(), str[0], gm->currentDiary);
    gm->submitBut.drawButton(gm->getWindow()->getWindow());
    gm->diary.copy = gm->submitBut.isMouseOnButton((sf::Vector2f){(float)mouse.x, (float)mouse.y},
        split(str[gm->currentDiary][1], " "), gm->diary.copy, &gm->correct);
    if (currentScreen == dialog_screen && gm->correct == true) {
        gm->diaryBut.isMouseClicked = 0;
        gm->currentDiary += 1;
        gm->diary.copy.clear();

        gm->texture.loadFromFile("./assets/sprites/salon.jpg");
        gm->bg.setTexture(gm->texture);
        gm->bg.setScale(sf::Vector2f(1.71, 1.71));
    }
    return 0;
}

int treeScreen(game *gm)
{
    sf::Vector2i mouse = sf::Mouse::getPosition((*gm->getWindow()->getWindow()));

    gm->goBackBut.drawButton(gm->getWindow()->getWindow());
    if (gm->goBackBut.isMouseOnButton(sf::Vector2f((float)mouse.x, (float)mouse.y)) == 1) {
        gm->goBackBut.isMouseClicked = false;
        gm->treeBut.isMouseClicked = false;
    }
    return 0;
}

int menuScreen(game *gm)
{
    sf::Vector2i mouse = sf::Mouse::getPosition((*gm->getWindow()->getWindow()));

    gm->getWindow()->getWindow()->draw(gm->bgMenuSprite);
    for (auto &it: gm->person_spr) {
        gm->getWindow()->getWindow()->draw(*it);
    }
    gm->playBut.drawButton(gm->getWindow()->getWindow());
    
    if (gm->playBut.isMouseOnButton(sf::Vector2f((float)mouse.x, (float)mouse.y)) == 1) {
        gm->playBut.isMouseClicked = false;
        currentScreen = screens::dialog_screen;
        return 1;
    }
    return (0);
}

string dialogScreen(game *gm, string character, int *isPressed, bool *clicked)
{
    sf::Vector2i mouse;
    sf::Text t;
    sf::RectangleShape r;
    sf::FloatRect hitbox;
    
    gm->getWindow()->getWindow()->draw(gm->bg);;
    gm->displayCharacter(character);
    gm->getWindow()->getWindow()->draw(gm->dialogPannel);
    gm->diaryBut.drawButton(gm->getWindow()->getWindow());
    gm->treeBut.drawButton(gm->getWindow()->getWindow());
    mouse = sf::Mouse::getPosition((*gm->getWindow()->getWindow()));

    gm->diaryBut.isMouseOnButton(sf::Vector2f((float)mouse.x, (float)mouse.y));
    gm->treeBut.isMouseOnButton(sf::Vector2f((float)mouse.x, (float)mouse.y));
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false)
        *clicked = false;
    for (size_t i = 0; i < gm->dialog.size(); i++) {
        if (character.compare("Transition") != 0)
            gm->getWindow()->getWindow()->draw(gm->dialog[i]);
        if (gm->texts[i].isClickable == true) {
            //gm->getWindow()->getWindow()->draw(gm->texts[i].rect);
            if (gm->texts[i].hitbox.contains(sf::Vector2f(mouse.x, mouse.y)) == true &&
                gm->texts[i].collected == false) {
                if (gm->offset > 1700) {
                    gm->offset = 40;
                    gm->y += 150;
                }
                gm->collectedWords.push_back(gm->texts[i].str);
                for (size_t y = 0; y < gm->collectedWords.size(); y++)
                    cout << "[" << gm->collectedWords[y] << "], ";
                cout << endl;
                gm->texts[i].collected = true;
                createText(&t, &gm->diary.font, "./assets/fonts/arial.ttf",
                    gm->collectedWords[gm->collectedWords.size() - 1], 80, sf::Vector2f(gm->offset, gm->y),
                    sf::Color::White);
                r = initRectangleShape(sf::Vector2f(gm->offset - 5.0f, gm->y), sf::Color(0, 0, 0, 0),
                    3, sf::Color::White, sf::Vector2f(t.getGlobalBounds().width + 10.0f, 105));
                gm->diary.wordTagsRect.push_back(r);
                gm->diary.wordTags.push_back(t);
                hitbox.height = 105;
                hitbox.width = t.getLocalBounds().width + 10.0f;
                hitbox.top = gm->y;
                hitbox.left = gm->offset - 5.0f;
                gm->offset += t.getLocalBounds().width + 30.0f;
                gm->diary.wordsTagsHitbox.push_back(hitbox);
                cout << "Clicked a word" << endl;
                break;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == true && (*isPressed) == 0) {
        gm->texts.clear();
        (*isPressed) = 1;
        gm->person += 1;
        character = dialog(&gm);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == false)
        (*isPressed) = 0;
    return character;
}
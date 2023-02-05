/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** dialogScreen
*/

#include "game.hpp"

int diaryScreen(game *gm)
{
    sf::Vector2i mouse = sf::Mouse::getPosition((*gm->getWindow()->getWindow()));

    gm->goBackBut.drawButton(gm->getWindow()->getWindow());
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if (gm->goBackBut.isMouseOnButton((sf::Vector2f){(float)mouse.x, (float)mouse.y}) == 1) {
            gm->diaryBut.isMouseClicked = false;
            gm->goBackBut.isMouseClicked = false;
        }
    }
    return 0;
}

int treeScreen(game *gm)
{
    sf::Vector2i mouse = sf::Mouse::getPosition((*gm->getWindow()->getWindow()));

    gm->goBackBut.drawButton(gm->getWindow()->getWindow());
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if (gm->goBackBut.isMouseOnButton((sf::Vector2f){(float)mouse.x, (float)mouse.y}) == 1) {
            gm->goBackBut.isMouseClicked = false;
            gm->treeBut.isMouseClicked = false;
        }
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
    
    if (gm->playBut.isMouseOnButton((sf::Vector2f){(float)mouse.x, (float)mouse.y}) == 1) {
        gm->playBut.isMouseClicked = false;
        currentScreen = screens::dialog_screen;
        return 1;
    }
    return (0);
}

string dialogScreen(game *gm, string character, int *isPressed, bool *clicked)
{
    sf::Vector2i mouse;

    gm->displayCharacter(character);
    gm->getWindow()->getWindow()->draw(gm->dialogPannel);
    gm->diaryBut.drawButton(gm->getWindow()->getWindow());
    gm->treeBut.drawButton(gm->getWindow()->getWindow());
    mouse = sf::Mouse::getPosition((*gm->getWindow()->getWindow()));
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        gm->diaryBut.isMouseOnButton((sf::Vector2f){(float)mouse.x, (float)mouse.y});
        gm->treeBut.isMouseOnButton((sf::Vector2f){(float)mouse.x, (float)mouse.y});
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false)
        *clicked = false;
    for (size_t i = 0; i < gm->dialog.size(); i++) {
        if (character.compare("Transition") != 0)
            gm->getWindow()->getWindow()->draw(gm->dialog[i]);
        if (gm->texts[i].isClickable == true) {
            //gm->getWindow()->getWindow()->draw(gm->texts[i].rect);
            if (gm->texts[i].hitbox.contains(sf::Vector2f(mouse.x, mouse.y)) == true &&
                gm->texts[i].collected == false) {
                gm->collectedWords.push_back(gm->texts[i].str);
                for (size_t y = 0; y < gm->collectedWords.size(); y++)
                    cout << "[" << gm->collectedWords[y] << "], ";
                cout << endl;
                gm->texts[i].collected = true;
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
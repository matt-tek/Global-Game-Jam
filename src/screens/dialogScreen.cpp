/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** dialogScreen
*/

#include "game.hpp"

int dialogScreen(game *gm, string character)
{
    sf::Vector2i mouse;
    bool clicked = false;
    sf::Event event;
    int isPressed = 0;

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
        clicked = false;
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
    while (gm->getWindow()->getWindow()->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            gm->getWindow()->getWindow()->close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == true && isPressed == 0) {
        gm->texts.clear();
        isPressed = 1;
        gm->person += 1;
        character = dialog(&gm);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == false)
        isPressed = 0;
    return 0;
}
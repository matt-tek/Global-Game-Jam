#include "game.hpp"

int main(void)
{
    game *gm = game::getInstance();
    sf::Event event;
    int person = 0;
    int isPressed = 0;
    sf::Vector2i mouse;
    bool clicked = false;

    gm->loadPlayers("./ressources/characters.json");
    gm->getWindow()->createWindow(1920, 1080, "name");
    string character;
    character = dialog(&gm, person);

    setupDiaryButton(&gm);
    setupTreeButton(&gm);

    gm->dialogPannel = initRectangleShape((sf::Vector2f){4, 707},
        sf::Color(0, 0, 0, 0), 4, sf::Color::White, (sf::Vector2f){1910, 300});

    while (gm->getWindow()->getWindow()->isOpen()) {
        gm->getWindow()->getWindow()->clear();
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
        gm->getWindow()->getWindow()->display();
        while (gm->getWindow()->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                gm->getWindow()->getWindow()->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == true && isPressed == 0) {
            gm->texts.clear();
            isPressed = 1;
            person += 1;
            character = dialog(&gm, person);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == false)
            isPressed = 0;
    }
    return (0);
}

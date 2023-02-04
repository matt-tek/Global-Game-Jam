#include "game.hpp"

int main(void)
{
    game *gm = game::getInstance();
    sf::Event event;
    int person = 0;
    int isPressed = 0;

    gm->loadPlayers("./ressources/characters.json");
    gm->getWindow()->createWindow(1920, 1080, "name");
    dialog(&gm, person);
    gm->Anim->setAnimClock(0.1f);

    gm->dialogPannel = initRectangleShape((sf::Vector2f){4, 707},
        sf::Color::Black, 4, sf::Color::White, (sf::Vector2f){1910, 300});

    while (gm->getWindow()->getWindow()->isOpen()) {
        gm->getWindow()->getWindow()->clear();
        // gm->Anim->getTime() = gm->_clock.getElapsedTime();
        std::cout << "time : " << gm->Anim->getTime().asSeconds() << std::endl;
        if (gm->Anim->getTime().asSeconds() == gm->Anim->getAnimClock()) {
            gm->getWindow()->getWindow()->draw(gm->dialogPannel);
            for (size_t i = 0; i < gm->dialog.size(); i++)
                gm->getWindow()->getWindow()->draw(gm->dialog[i]);
            gm->Anim->_clock.restart();
        }
        gm->getWindow()->getWindow()->display();
        while (gm->getWindow()->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                gm->getWindow()->getWindow()->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == true && isPressed == 0) {
            isPressed = 1;
            person += 1;
            dialog(&gm, person);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == false)
            isPressed = 0;
    }
    return (0);
}

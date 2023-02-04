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

    gm->dialogPannel = initRectangleShape((sf::Vector2f){4, 1007},
        sf::Color::Black, 4, sf::Color::White, (sf::Vector2f){1910, 300});

    while (gm->getWindow()->getWindow()->isOpen()) {
        gm->getWindow()->getWindow()->clear();
        gm->getWindow()->getWindow()->draw(gm->dialogPannel);
        // std::cout << "x = " << gm->dialogPannel.getSize().x << " --- y = " << gm->dialogPannel.getSize().y << std::endl;
        gm->Anim->automoveUp(sf::Vector2f{4, 707}, 5.0f, gm->dialogPannel);
        std::cout << " POS x = " << gm->dialogPannel.getPosition().x << " --- y = " << gm->dialogPannel.getPosition().y << std::endl;

        for (size_t i = 0; i < gm->dialog.size(); i++)
            gm->getWindow()->getWindow()->draw(gm->dialog[i]);
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

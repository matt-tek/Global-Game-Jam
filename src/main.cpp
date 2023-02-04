#include "game.hpp"
#include "TextBox.hpp"

int main(void)
{
    game *gm = game::getInstance();
    TextBox *tb = new TextBox();
    sf::Event event;
    int person = 0;
    int isPressed = 0;

    gm->loadPlayers("./ressources/characters.json");
    gm->getWindow()->createWindow(1920, 1080, "name");
    dialog(&gm, person);
    while (gm->getWindow()->getWindow()->isOpen()) {
        gm->getWindow()->getWindow()->clear();
        for (size_t i = 0; i < gm->dialog.size(); i++) {
            gm->getWindow()->getWindow()->draw(gm->dialog[i]);
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
        // gm->getWindow()->getWindow()->draw(tb->getShape());
        // gm->getWindow()->getWindow()->display();
    }
    return (0);
}

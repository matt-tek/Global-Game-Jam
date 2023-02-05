

#include "game.hpp"

int menuScreen(game *gm)
{
    sf::Vector2i mouse = sf::Mouse::getPosition((*gm->getWindow()->getWindow()));

    gm->playBut.drawButton(gm->getWindow()->getWindow());
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if (gm->playBut.isMouseOnButton((sf::Vector2f){(float)mouse.x, (float)mouse.y}) == 1) {
            gm->playBut.isMouseClicked = false;
            currentScreen = screens::dialog_screen;
            return 1;
        }
    }
}
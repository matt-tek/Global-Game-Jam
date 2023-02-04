#include "game.hpp"

int dialogScreen(game *gm, string character);

int main(void)
{
    game *gm = game::getInstance();
    sf::Event event;
    int isPressed = 0;
    sf::Vector2i mouse;
    bool clicked = false;

    gm->loadPlayers("./ressources/characters.json");
    gm->getWindow()->createWindow(1920, 1080, "name");
    string character;
    character = dialog(&gm);

    setupDiaryButton(&gm);
    setupTreeButton(&gm);

    gm->dialogPannel = initRectangleShape((sf::Vector2f){4, 707},
        sf::Color(0, 0, 0, 0), 4, sf::Color::White, (sf::Vector2f){1910, 300});

    while (gm->getWindow()->getWindow()->isOpen()) {
        gm->getWindow()->getWindow()->clear();
        if (gm->currentScreen == dialog_screen) {
            dialogScreen(gm, character);
        }
        gm->getWindow()->getWindow()->display();
    }
    return (0);
}

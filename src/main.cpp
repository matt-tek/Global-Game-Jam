#include "game.hpp"

string dialogScreen(game *gm, string character, int *isPressed, bool *clicked);
int diaryScreen(game *gm);
int treeScreen(game *gm);
int menuScreen(game *gm);
void setupPlayButton(game **gm);
screens currentScreen = screens::main_menu;

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
    setupGoBackButton(&gm);
    setupPlayButton(&gm);

    gm->dialogPannel = initRectangleShape((sf::Vector2f){4, 707},
        sf::Color(0, 0, 0, 0), 4, sf::Color::White, (sf::Vector2f){1910, 300});

    while (gm->getWindow()->getWindow()->isOpen()) {
        gm->getWindow()->getWindow()->clear();
        while (gm->getWindow()->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                gm->getWindow()->getWindow()->close();
        }
        if (currentScreen == dialog_screen)
            character = dialogScreen(gm, character, &isPressed, &clicked);
        else if (currentScreen == screens::diary_screen)
            diaryScreen(gm);
        else if (currentScreen == screens::tree_screen)
            treeScreen(gm);
        else if (currentScreen == screens::main_menu)
            menuScreen(gm);
        gm->getWindow()->getWindow()->display();
    }
    return (0);
}

#include <json/json.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <map>

#include "game.hpp"

int main(void)
{
    game *gm = game::getInstance();

    gm->loadPlayers("./ressources/characters.json");

    gm->getPlayer("Nadia").talk();
    gm->getPlayer("Nadia").talk();
    gm->getPlayer("Louis").talk();
    gm->getPlayer("Louis").talk();
    gm->getPlayer("Louis").talk();
    
    gm->getWindow()->createWindow(800, 600, "name");
    while (gm->getWindow()->getWindow()->isOpen()) {

    }
    return (0);
}




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

    gm->loadPlayers("characters.json");


    gm->getPlayer("Nadia").talk();
    gm->getPlayer("Nadia").talk();
    gm->getPlayer("Louis").talk();
    gm->getPlayer("Louis").talk();
    gm->getPlayer("Louis").talk();


    return (0);
}




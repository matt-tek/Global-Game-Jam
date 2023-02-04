

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "player.hpp"
#include <json/json.h>

class game
{
    private:
        game();
    public:
        static game *instance;
        std::vector<std::shared_ptr<player>> players;
        
        ~game();

        static game *getInstance();

        player &getPlayer(std::string name);

        bool loadPlayers(std::string pl);
};

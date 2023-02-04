

#include "include.hpp"
#include "window.hpp"

#pragma once

using namespace std;

class game
{
    private:
        windowClass win;
    public:
        static game *instance;
        std::vector<std::shared_ptr<player>> players;
        
        game();
        ~game();

        windowClass *getWindow(void)
        {
            return &win;
        }

        static game *getInstance();

        player &getPlayer(std::string name);

        bool loadPlayers(std::string pl);
};

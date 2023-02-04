
#pragma once

#include "include.hpp"
#include "text.hpp"

#include <json/json.h>

class game;

class player
{
public:
    player(std::string name, game *gam);
    ~player();
    std::string name;
    int value;
    game *gm;
    std::map<int, std::shared_ptr<text>> parole;
    std::vector<std::vector<std::string>> clickableWords;

    std::string &getName();

    void setTextDep(int value, std::shared_ptr<text> data);

    std::shared_ptr<text> getTextDep(int value);

    void setName(std::string name);

    bool loadjson(std::string file);

    void talk(game **gm);
};
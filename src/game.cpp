
#include "game.hpp"

game *game::instance = nullptr;

game *game::getInstance() {
    if (instance == nullptr) {
        instance = new game();
    }
    return instance;
}

game::game()
{
    this->Anim = new Animation;
}

game::~game()
{

}

player &game::getPlayer(std::string name) {
    for (auto &it : this->players) {
        if (it.get()->getName() == name) {
            return *it;
        }
    }
    return *this->players[0];
}

bool game::loadPlayers(std::string pl) {
    std::ifstream ifs(pl);
    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(ifs, root)) {
        return false;
    }
    std::cout << "Loading players" << std::endl;
    for (auto &it : root["caracters"]) {
        this->players.push_back(std::shared_ptr<player>(new player(it["name"].asString(), this)));
    }
    std::cout << "Loading players files" << std::endl;
    for (auto &it : root["caracters"]) {
        this->getPlayer(it["name"].asString()).loadjson(it["file"].asString());
    }
    std::cout << "Loading players files done" << std::endl;
    return true;
}
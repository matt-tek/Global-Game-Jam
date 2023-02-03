#include <json/json.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>


class player;

class game
{
    public:
        std::vector<std::shared_ptr<player>> players;
        game() {

        }
        ~game() {

        }

        player &getPlayer(std::string name) {
            for (auto &it : this->players) {
                if (it->getName() == name) {
                    return it;
                }
            }
            return nullptr;
        }

        bool loadPlayers(std::string player) {
            std::ifstream ifs(player);
            Json::Reader reader;
            Json::Value root;
            if (!reader.parse(ifs, root)) {
                return false;
            }
            for (auto &it : root["caracters"]) {
                this->players.push_back(std::make_shared<player>(it.asString()));
            }
            std::cout << this->players.size() << std::endl;
            return true;
        }
};

class player
{
public:
    player(std::string name) {}
    ~player() {}
    std::string name;

    std::string &getName() {
        return name;
    }
    void setName(std::string name) {
        this->name = name;
        return;
    }
    bool loadjson(std::string file) {
        std::ifstream ifs(file);
        Json::Reader reader;
        Json::Value root;
        if (!reader.parse(ifs, root)) {
            return false;
        }
        std::cout << root["caracters"].asString() << std::endl;
        return true;
    }
};




int main(void)
{
    game *gm = new game();

    gm->loadPlayers("characters.json");

    return (0);
}




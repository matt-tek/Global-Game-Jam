#include <json/json.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <map>


class text 
{
    public:
        text() : validate(false) {}
        ~text() {}
        std::vector<std::shared_ptr<text>> deps;
        std::string parole;
        bool validate;
        bool isNext(void) {
            int count = 0;
            for (auto &it: this->deps) {
                if (it->validate == true) {
                    count++;
                }
            }
            return (count == this->deps.size() ? true : false);
        }
};


class player
{
public:
    player(std::string name) {}
    ~player() {}
    std::string name;
    int value;
    std::map<int, std::shared_ptr<text>> parole;

    std::string &getName() {
        return name;
    }

    void setTextDep(int value, std::shared_ptr<text> data) {
        if (this->parole[value] != nullptr) {
            this->parole[value]->deps.push_back(data);
        } else {
            this->parole[value] = std::shared_ptr<text>(new text());
            this->parole[value]->deps.push_back(data);
        }
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

class game
{
    private:
        game() {

        }
    public:
        static game *instance;
        std::vector<std::shared_ptr<player>> players;
        
        ~game() {

        }

        player &getPlayer(std::string name) {
            for (auto &it : this->players) {
                if (it.get()->getName() == name) {
                    return *it;
                }
            }
        }

        bool loadPlayers(std::string pl) {
            std::ifstream ifs(pl);
            Json::Reader reader;
            Json::Value root;
            if (!reader.parse(ifs, root)) {
                return false;
            }
            for (auto &it : root["caracters"]) {
                this->players.push_back(std::shared_ptr<player>(new player(it["name"].asString())));
            }
            std::cout << this->players.size() << std::endl;
            return true;
        }
};




int main(void)
{
    game *gm = new game();

    gm->loadPlayers("characters.json");

    return (0);
}




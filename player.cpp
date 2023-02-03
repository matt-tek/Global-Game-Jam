
#include "player.hpp"
#include "game.hpp"

player::player(std::string name, game *gam) : name(name), gm(gam), value(1)
{

}
    
    
player::~player()
{

}

std::string &player::getName() {
    return this->name;
}

void player::setTextDep(int value, std::shared_ptr<text> data) {
    if (this->parole[value] != nullptr) {
        this->parole[value]->deps.push_back(data);
    } else {
        this->parole[value] = std::shared_ptr<text>(new text());
        this->parole[value]->deps.push_back(data);
    }
}

std::shared_ptr<text> player::getTextDep(int value) {
    if (this->parole[value] != nullptr) {
        return this->parole[value];
    } else {
        this->parole[value] = std::shared_ptr<text>(new text());
    }
    return this->parole[value];
}

void player::setName(std::string name) {
    this->name = name;
    return;
}

bool player::loadjson(std::string file) {
    std::ifstream ifs(file);
    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(ifs, root)) {
        return false;
    }
    
    std::cout << "Loading player " << this->name << std::endl;
    Json::Value tex = root["text"];
    for (auto &it : tex) {
        std::cout << "Loading text " << it["id"].asInt() << std::endl;
        if (this->parole[it["id"].asInt()] != nullptr) {
            this->parole[it["id"].asInt()]->parole = it["text"].asString();
        } else {
            std::shared_ptr<text> data = std::shared_ptr<text>(new text());
            data->parole = it["text"].asString();
            this->parole[it["id"].asInt()] = data;
        }
        for (auto &it2 : it["dependsOn"]) {
            std::string str = it2.asString();
            std::string name = str.substr(0, str.find(":"));
            int index = std::stoi(str.substr(str.find(":") + 1, str.size()));
            this->parole[it["id"].asInt()]->deps.push_back(this->gm->getPlayer(name).getTextDep(index));
        }
    }
    return true;
}

void player::talk(void) {
    std::cout << this->parole[this->value]->parole << std::endl;
    this->parole[this->value]->validate = true;
    if (this->parole[value]->isNext() && this->parole.size() != this->value) {
        this->value += 1;
    }
}
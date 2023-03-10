
#include "game.hpp"

game *game::instance = nullptr;

int load(std::string path, std::vector<std::shared_ptr<sf::Sprite>> &spr, std::vector<std::shared_ptr<sf::Texture>> &tex, sf::Vector2f pos)
{
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();
    if (!texture->loadFromFile(path))
        return 84;
    sprite->setTexture(*texture);
    sprite->setPosition(pos);
    tex.push_back(texture);
    spr.push_back(sprite);

    return 0;
}

game *game::getInstance() {
    if (instance == nullptr) {
        instance = new game();
    }
    return instance;
}

game::game()
{
    this->bgMenu.loadFromFile("./assets/sprites/salon.jpg");
    this->bgMenuSprite.setTexture(this->bgMenu);
    this->bgMenuSprite.setScale(sf::Vector2f(2.5, 3));
    load("./assets/sprites/Julia_1.png", this->person_spr, this->perso_tex, sf::Vector2f(0, 130));
    load("./assets/sprites/Victor_1.png", this->person_spr, this->perso_tex, sf::Vector2f(1000, 130));
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
}

void createSprite(sf::Sprite *sprite, sf::Texture *texture, std::string path,
    sf::Vector2f scale, sf::Vector2f position)
{
    texture->loadFromFile(path);
    sprite->setTexture((*texture));
    sprite->setScale(scale);
    sprite->setPosition(position);
}

bool game::loadPlayers(std::string pl) {
    std::ifstream ifs(pl);
    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(ifs, root)) {
        return false;
    }
    //std::cout << "Loading players" << std::endl;
    for (auto &it : root["caracters"]) {
        this->players.push_back(std::shared_ptr<player>(new player(it["name"].asString(), this)));
    }
    //std::cout << "Loading players files" << std::endl;
    int i = 0;
    for (auto &it : root["caracters"]) {
        this->getPlayer(it["name"].asString()).loadjson(it["file"].asString());
        createSprite(&this->players[i]->sprite.sprite, &this->players[i]->sprite.texture,
            it["sprite"].asString(), sf::Vector2f(0.7, 0.7), sf::Vector2f(250, 4));
        createSprite(&this->players[i]->profilePic.sprite, &this->players[i]->profilePic.texture,
            it["profile_picture"].asString(), sf::Vector2f(0.3, 0.3), sf::Vector2f(0, 708));
        this->playerId.insert(make_pair(it["name"].asString(), i));
        i++;
    }
    std::cout << "Loading players files done" << std::endl;
    return true;
}
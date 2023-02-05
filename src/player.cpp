
#include "player.hpp"
#include "game.hpp"

vector<string> split(const string& str, const string& delimiters);

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
    std::vector<std::string> words;

    if (!reader.parse(ifs, root))
        return false;
    this->clickableWords.push_back(words);
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
        words.clear();
        for (auto &it3 : it["clickable_words"]) {
            std::string str = it3.asString();
            words.push_back(str);
        }
        this->clickableWords.push_back(words);            
    }
    return true;
}

int isWordClickable(game **gm, sf::Text *text, std::vector<string> words, string str,
    int x, int y)
{
    clickWord click;

    for (size_t i = 0; i < words.size(); i++) {
        if (words[i].compare(str) == 0) {
            text->setFillColor(sf::Color::Green);
            click.isClickable = true;
            click.rect = initRectangleShape(sf::Vector2f(x, y), sf::Color(0, 0, 0, 0),
                2, sf::Color::White, sf::Vector2f(text->getLocalBounds().width, 70));
            click.hitbox.left = x;
            click.hitbox.top = y;
            click.hitbox.width = text->getLocalBounds().width;
            click.hitbox.height = text->getLocalBounds().height;
            click.collected = false;
            click.str = text->getString();
            (*gm)->texts.push_back(click);
            return 1;
        }
    }
    click.isClickable = false;
    (*gm)->texts.push_back(click);
    text->setFillColor(sf::Color::White);
    return 0;
}

int isSingleChar(std::string str)
{
    if (str.compare(".") == 0 || str.compare("!") == 0 ||
            str.compare(",") == 0 || str.compare("?") == 0)
        return 1;
    return 0;
}

void player::talk(game **gm) {
    sf::Text text;
    float offset = 350;
    float y = 740;
    vector<string> vec;

    std::cout << this->parole[this->value]->parole << std::endl;
    this->parole[this->value]->validate = true;
    vec = split(this->parole[this->value]->parole.c_str(), " ");
    (*gm)->font.loadFromFile("./assets/fonts/arial.ttf");
    (*gm)->dialog.clear();
    text.setFont((*gm)->font);
    for (size_t i = 0; i < vec.size(); i++) {
        if (offset >= 1700) {
            offset = 350;
            y += 80;
        }
        text.setCharacterSize(50);
        text.setString(vec[i]);
        isWordClickable(gm, &text, this->clickableWords[this->value], vec[i], offset, y);
        text.setPosition(sf::Vector2f(offset, y));
        if (isSingleChar(vec[i])) {
            text.setPosition(sf::Vector2f(offset - 15.0f, y));
            offset += 10.0f;
        } else
            offset += text.getLocalBounds().width + 20.0f;
        (*gm)->dialog.push_back(text);
    }
    if (this->parole[value]->isNext() && this->parole.size() != this->value) {
        this->value += 1;
    }
}
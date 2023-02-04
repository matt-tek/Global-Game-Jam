

#include "notebook.hpp"


notebook::notebook()
{
    this->texture.loadFromFile("./assets/notebook.png");
    this->sprite.setTexture(texture);
    this->sprite.setScale(4, 4);
    loadNotebook("./ressources/notebook.json");
    this->font.loadFromFile("./assets/fonts/arial.ttf");
    this->parole.setFont(this->font);
    this->parole.setString(this->text[this->value]->text);
    this->parole.setCharacterSize(50);
    this->parole.setPosition((sf::Vector2f){20, 20});
    this->parole.setFillColor(sf::Color::Black);
}

notebook::~notebook()
{
}

void notebook::update()
{
    this->parole.setString(this->text[this->value]->text);
}

bool notebook::loadNotebook(std::string path)
{
    try {
        std::ifstream file(path);
        Json::Reader reader;
        Json::Value root;

        if (!reader.parse(file, root)) {
            return (false);
        }
        for (auto &it : root["notebook"]) {
            this->text.push_back(std::shared_ptr<notebooktext>(new notebooktext()));
            this->text.back()->loadText(it);
        }
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (false);
    }
    return (true);
}

void notebook::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->sprite);
    target.draw(this->parole);
}
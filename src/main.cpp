#include "game.hpp"
#include <wchar.h>

string dialogScreen(game *gm, string character, int *isPressed, bool *clicked);
int diaryScreen(game *gm);
int treeScreen(game *gm);

int menuScreen(game *gm);
void setupPlayButton(game **gm);
screens currentScreen = screens::main_menu;
vector<string> split(const string& str, const string& delimiters);
void setupSubmitButton(game **gm);

vector<vector<string>> str = {{"My name is James 4 years old", "James 4"},
    {"Je suis mort", "mort"}};

int initDiary(game *gm)
{
    sf::Text text;
    vector<sf::Text> t;
    vector<sf::RectangleShape> r;
    vector<sf::FloatRect> h;
    sf::RectangleShape rect;
    sf::FloatRect hitbox;
    int y = 0;
    setlocale(LC_ALL, "");

    for (size_t j = 0; j < str.size(); j++) {
        int offset = 650;
        vector<string> vec = split(str[j][0], " ");
        vector<string> hidden = split(str[j][1], " ");
        gm->diary.text.push_back(t);
        gm->diary.hide.push_back(r);
        gm->diary.hideHitbox.push_back(h);
        for (size_t i = 0; i < vec.size(); i++) {
            createText(&text, &gm->diary.font, "./assets/fonts/arial.ttf",
                vec[i], 80, sf::Vector2f(offset, 440), sf::Color::White);
            for (size_t y = 0; y < hidden.size(); y++) {
                if (hidden[y].compare(vec[i]) == 0) {
                    rect = initRectangleShape(sf::Vector2f(offset, 440), sf::Color::Black, 2,
                        sf::Color::White, sf::Vector2f(text.getLocalBounds().width, 100));
                    gm->diary.hide[j].push_back(rect);
                    hitbox.top = 440;
                    hitbox.left = offset;
                    hitbox.width = text.getLocalBounds().width;
                    hitbox.height = 100;
                    gm->diary.hideHitbox[j].push_back(hitbox);
                }
            }
            gm->diary.text[j].push_back(text);
            offset += text.getLocalBounds().width + 25.0f;
        }
    }
    gm->diary.wordPannel = initRectangleShape(sf::Vector2f(4, 707),
        sf::Color(0, 0, 0, 0), 4, sf::Color::White, sf::Vector2f(1910, 300));
    return 0;
}

int main(void)
{
    game *gm = game::getInstance();
    sf::Event event;
    int isPressed = 0;
    sf::Vector2i mouse;
    bool clicked = false;

    gm->loadPlayers("./ressources/characters.json");
    gm->getWindow()->createWindow(1920, 1080, "name");
    string character;
    character = dialog(&gm);

    gm->texture.loadFromFile("./assets/sprites/salon.jpg");
    gm->bg.setTexture(gm->texture);
    gm->bg.setScale(sf::Vector2f(1.71, 1.71));

    initDiary(gm);
    setupDiaryButton(&gm);
    setupTreeButton(&gm);
    setupGoBackButton(&gm);
    setupSubmitButton(&gm);
    setupPlayButton(&gm);

    gm->dialogPannel = initRectangleShape(sf::Vector2f(4, 707),
        sf::Color(0, 0, 0, 0), 4, sf::Color::White, sf::Vector2f(1910, 300));

    while (gm->getWindow()->getWindow()->isOpen()) {
        gm->getWindow()->getWindow()->clear();
        while (gm->getWindow()->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                gm->getWindow()->getWindow()->close();
        }
        if (currentScreen == dialog_screen)
            character = dialogScreen(gm, character, &isPressed, &clicked);
        else if (currentScreen == screens::diary_screen)
            diaryScreen(gm);
        else if (currentScreen == screens::tree_screen)
            treeScreen(gm);
        else if (currentScreen == screens::main_menu)
            menuScreen(gm);
        gm->getWindow()->getWindow()->display();
    }
    return (0);
}

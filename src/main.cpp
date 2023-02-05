#include "game.hpp"

string dialogScreen(game *gm, string character, int *isPressed, bool *clicked);
int diaryScreen(game *gm);
int treeScreen(game *gm);
vector<string> split(const string& str, const string& delimiters);

vector<vector<string>> str = {{"My name is James", "James"},
    {"I'm dead", "dead"}};

int initDiary(game *gm)
{
    sf::Text text;
    vector<sf::Text> t;
    vector<sf::RectangleShape> r;
    sf::RectangleShape rect;
    vector<string> vec = split(str[0][0], " ");
    vector<string> hidden = split(str[0][1], " ");
    int offset = 650;
    int y = 0;

    for (size_t j = 0; j < str.size(); j++) {
        gm->diary.text.push_back(t);
        gm->diary.hide.push_back(r);
        for (size_t i = 0; i < vec.size(); i++) {
            createText(&text, &gm->diary.font, "./assets/fonts/arial.ttf",
                vec[i], 80, sf::Vector2f(offset, 440), sf::Color::White);
            for (size_t y = 0; y < hidden.size(); y++) {
                if (hidden[y].compare(vec[i]) == 0) {
                    rect = initRectangleShape(sf::Vector2f(offset, 440), sf::Color::Black, 2,
                        sf::Color::White, sf::Vector2f(text.getLocalBounds().width, 100));
                    gm->diary.hide[j].push_back(rect);
                }
            }
            gm->diary.text[j].push_back(text);
            offset += text.getLocalBounds().width + 25.0f;
        }
    }
    return 0;
}
screens currentScreen = screens::dialog_screen;

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

    setupDiaryButton(&gm);
    setupTreeButton(&gm);
    setupGoBackButton(&gm);

    initDiary(gm);

    gm->dialogPannel = initRectangleShape((sf::Vector2f){4, 707},
        sf::Color(0, 0, 0, 0), 4, sf::Color::White, (sf::Vector2f){1910, 300});

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
        gm->getWindow()->getWindow()->display();
    }
    return (0);
}

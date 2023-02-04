#include "game.hpp"

void setText(sf::Text *text, sf::Font *font, string fontPath,
    string content, float charSize, sf::Vector2f position, sf::Color fillColor)
{
    font->loadFromFile(fontPath);
    text->setFont((*font));
    text->setFillColor(fillColor);
    text->setCharacterSize(charSize);
    text->setString(content);
    text->setPosition(position);
    return;
}

void setupDiaryButton(game **gm)
{
    (*gm)->diaryBut.position = (sf::Vector2f){1680, 40};
    (*gm)->diaryBut.initButtonRectangleShape((*gm)->diaryBut.position,
        sf::Color::Black, 4, sf::Color::White, (sf::Vector2f){200, 70});

    setText(&(*gm)->diaryBut.text, &(*gm)->diaryBut.font, "./assets/fonts/arial.ttf",
        "DIARY", 50, (sf::Vector2f){(*gm)->diaryBut.position.x + 50, (*gm)->diaryBut.position.y + 5}, sf::Color::White);
    return;
}

void setupTreeButton(game **gm)
{
    (*gm)->treeBut.position = (sf::Vector2f){1440, 40};
    (*gm)->treeBut.initButtonRectangleShape((*gm)->treeBut.position,
        sf::Color::Black, 4, sf::Color::White, (sf::Vector2f){200, 70});

    setText(&(*gm)->treeBut.text, &(*gm)->treeBut.font, "./assets/fonts/arial.ttf",
        "TREE", 50, (sf::Vector2f){(*gm)->treeBut.position.x + 50, (*gm)->treeBut.position.y + 5}, sf::Color::White);
    return;
}

int main(void)
{
    game *gm = game::getInstance();
    sf::Event event;
    int person = 0;
    int isPressed = 0;
    sf::Vector2i mouse;

    gm->loadPlayers("./ressources/characters.json");
    gm->getWindow()->createWindow(1920, 1080, "name");
    dialog(&gm, person);

    setupDiaryButton(&gm);
    setupTreeButton(&gm);

    gm->dialogPannel = initRectangleShape((sf::Vector2f){4, 707},
        sf::Color::Black, 4, sf::Color::White, (sf::Vector2f){1910, 300});

    while (gm->getWindow()->getWindow()->isOpen()) {
        gm->getWindow()->getWindow()->clear();
        gm->getWindow()->getWindow()->draw(gm->dialogPannel);
        gm->diaryBut.drawButton(gm->getWindow()->getWindow());
        gm->treeBut.drawButton(gm->getWindow()->getWindow());
        mouse = sf::Mouse::getPosition((*gm->getWindow()->getWindow()));
        gm->diaryBut.isMouseOnButton((sf::Vector2f){(float)mouse.x, (float)mouse.y});
        gm->treeBut.isMouseOnButton((sf::Vector2f){(float)mouse.x, (float)mouse.y});
        for (size_t i = 0; i < gm->dialog.size(); i++)
            gm->getWindow()->getWindow()->draw(gm->dialog[i]);
        gm->getWindow()->getWindow()->display();
        while (gm->getWindow()->getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                gm->getWindow()->getWindow()->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == true && isPressed == 0) {
            isPressed = 1;
            person += 1;
            dialog(&gm, person);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == false)
            isPressed = 0;
    }
    return (0);
}

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class TextBox
{
private:
    sf::Color _textBoxColor;
    sf::Sprite _textBoxSprite;
    sf::RectangleShape _boxShape;
    sf::Texture _textBoxTexture;
    sf::Font _font;
    float _animClock = 0.0f;
    bool _isVisible;
public:
    TextBox();
    TextBox(const std::string &spritePath, const std::string &fontPath);
    ~TextBox();
    void setFont(const std::string &fontPath);
    void setTexture(const std::string &spritePath);
    void updateAnimClock(void);
    void resetAnimclock(void);
    void drawTextBox(void);
    float getAnimTime(void) const { return _animClock; };
    sf::Sprite getSprite(void) const { return _textBoxSprite; };
    sf::RectangleShape getShape(void) const { return _boxShape; };
};
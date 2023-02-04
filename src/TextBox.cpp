#include "../include/TextBox.hpp"
#include <iostream>

TextBox::TextBox() {
    this->_textBoxColor = sf::Color(255, 0, 0, 255);
    this->_boxShape.setSize(sf::Vector2f(120, 50));
    this->_boxShape.setFillColor(this->_textBoxColor);
    std::cout << "sprite init" << std::endl;
    std::cout << "color :" << this->_textBoxColor.r << std::endl;
}

TextBox::TextBox(const std::string &spritePath, const std::string &fontPath) {
    this->_textBoxTexture.loadFromFile(spritePath);
    this->_textBoxSprite.setTexture(this->_textBoxTexture);
}

void TextBox::drawTextBox() {
    
}
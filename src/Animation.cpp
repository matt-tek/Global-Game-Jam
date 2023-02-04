#include "../include/Animation.hpp"

Animation::Animation() {
    this->_time = this->_clock.restart();
}
Animation::~Animation() {}

void Animation::setAnimClock(const float &animClock) {
    this->_animClock = animClock;
}

void Animation::resetAnimClock(void) {
    this->_animClock = 0.0f;
}

void Animation::updateAnimClock(void) {
    this->_animClock += this->_time.asSeconds();
}

void Animation::automoveUp(sf::Vector2f targetPos, float velocity, sf::RectangleShape &pannel) {
    sf::Vector2f pos;

    if (pannel.getPosition().y >= 707) {
        while (pos.y <= targetPos.y) {
            pos = pannel.getPosition();
            pos.y = pos.y - velocity;
            pannel.setPosition(pos);
        }
    }
}

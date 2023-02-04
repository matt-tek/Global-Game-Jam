#include "../include/Animation.hpp"

Animation::Animation() {}
Animation::~Animation() {}

void Animation::setAnimClock(const float &animClock) {
    this->_animClock = animClock;
}

void Animation::resetAnimClock(void) {
    this->_animClock = 0;
}

void Animation::updateAnimClock(void) {
    this->_animClock += this->_time.asSeconds();
}

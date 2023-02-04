#pragma once

#include <SFML/Graphics.hpp>

class Animation {
    public:
        Animation();
        ~Animation();
        void setAnimClock(const float &animClock);
        void resetAnimClock(void);
        float getAnimClock(void) const { return _animClock; };
        void updateAnimClock(void);
        sf::Time getTime(void) const { return _time; };
        sf::Clock _clock;
    protected:
    private:
        sf::Time _time = sf::Time::Zero;
        float _animClock = 0.0f;
};


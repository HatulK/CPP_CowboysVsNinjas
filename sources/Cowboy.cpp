#include "Cowboy.hpp"

#include <utility>

using namespace ariel;


Cowboy::Cowboy(std::string name,Point location) :
        Character(std::move(name), location, maxCowboyHP, typeCowboy),
        bullets(maxBullets) {}

bool Cowboy::shoot(Character *enemy) {
    return false;
}

bool Cowboy::hasboolets() const {
    return bullets > 0;
}

void Cowboy::reload() {
    if (bullets == 6) throw std::logic_error("Magazine is at full capacity.\n");
    bullets = 6;
}

int Cowboy::getBullets() const {
    return this->bullets;
}




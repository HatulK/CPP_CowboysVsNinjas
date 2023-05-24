#include "Cowboy.hpp"

#include <utility>

using namespace ariel;


Cowboy::Cowboy(std::string name, Point location) :
        Character(std::move(name), std::move(location),110, typeCowboy),
        bullets(6) {}

void Cowboy::shoot(Character *enemy) {
    if(enemy== this)throw std::runtime_error("A character can't attack himself\n");
    if (!enemy->isAlive()) throw std::runtime_error("Its not smart to attack dead characters.\n");
    if (!this->isAlive()) throw std::runtime_error("Dead cowboys cannot shoot.\n");
if(!this->hasboolets()){
    printf("Cannot shoot this turn, instead im reloading.\n");
    this->reload();
    return;
}
//Cowboy damage is 10.
enemy->hit(10);
    bullets--;
}

bool Cowboy::hasboolets() const {
    return bullets > 0;
}

void Cowboy::reload() {
    if(!this->isAlive()) throw std::runtime_error("A dead cowboy can't reload.\n");
    bullets = 6;
}

int Cowboy::getBullets() const {
    return this->bullets;
}

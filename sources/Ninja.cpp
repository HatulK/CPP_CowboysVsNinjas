#include "Ninja.hpp"

#include <utility>

using namespace ariel;

Ninja::Ninja(std::string name,Point location, int hp, int speed, enum characterType type):Character(std::move(name),location,hp,type),speed(speed){

}


int Ninja::move(Character *enemy) {
    return this->speed;
}

void Ninja::slash(Character *enemy) {

}

int Ninja::getSpeed() const {
    return speed;
}


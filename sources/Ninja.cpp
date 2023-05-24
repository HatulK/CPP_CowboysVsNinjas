#include "Ninja.hpp"

#include <utility>

using namespace ariel;

Ninja::Ninja(std::string name, Point location, int healthpoint, int speed, enum characterType type) :
        Character(std::move(name),std::move(location), healthpoint,type),speed(speed) {}


void Ninja::move(Character *enemy) {
    if(enemy== nullptr) throw std::runtime_error("The enemy provided is null pointer\n");
    if (!this->isAlive()) throw std::runtime_error("This ninja is dead and cannot be moved.\n");
    if (!enemy->isAlive()) throw std::runtime_error("The enemy is dead. Character doesnt move.\n");
    this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed));
}

void Ninja::slash(Character *enemy) {
    if(enemy== nullptr) throw std::runtime_error("The enemy provided is null pointer\n");
    if(enemy== this)throw std::runtime_error("A ninja can't attack it self.\n");
    if (!isAlive()) throw std::runtime_error("This ninja is dead\n");
    if (distance(enemy) > 1) {
        move(enemy); //If the enemy is farther than 1 then move towards him.
    }
    else enemy->hit(40);
}

int Ninja::getSpeed() const {
    return speed;
}


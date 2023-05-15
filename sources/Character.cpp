#include "Character.hpp"

#include <utility>

using namespace ariel;

Character::Character(std::string name, Point location, int hp,
                     enum characterType type) : location(location),
                                                healthpoints(hp),
                                                name(std::move(name)),
                                                type(type) {}

Character::Character() : location(0, 0), healthpoints(0), type(noType) {}

bool Character::isAlive() {
    return false;
}

double Character::distance(Character *otherChar) {
    return 0;
}

void Character::hit(int damage) {

}

std::string Character::print() const {
    return "";
}

const Point &Character::getLocation() const {
    return location;
}

int Character::gethealthpoints() const {
    return healthpoints;
}

const std::string &Character::getName() const {
    return name;
}

characterType Character::getType() const {
    return type;
}

// Copy constructor
Character::Character(const Character &other)
        : location(other.location),
          healthpoints(other.healthpoints),
          name(other.name),
          type(other.type) {}

// Move constructor
Character::Character(Character &&other) noexcept
        : location(other.location),
          healthpoints(other.healthpoints),
          name(std::move(other.name)),
          type(other.type) {}

// Copy assignment operator
Character &Character::operator=(const Character &other) {
    return *this;
}

// Move assignment operator
Character &Character::operator=(Character &&other) noexcept {
    if (this != &other) {
        location = other.location;
        healthpoints = other.healthpoints;
        name = std::move(other.name);
        type = other.type;
    }
    return *this;
}

Character::~Character() = default;

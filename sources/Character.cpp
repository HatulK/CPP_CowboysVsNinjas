#include "Character.hpp"
#include <utility>

using namespace ariel;

// Constructor
Character::Character(std::string name, Point location, int hp,
                     enum characterType type) : location(std::move(location)),
                                                healthpoints(hp), inteam(false),
                                                name(std::move(name)),
                                                type(type) {}

//Empty Constructor
Character::Character() : location(0, 0), healthpoints(0), inteam(false), type(noType) {}

//Returning if the player is alive
bool Character::isAlive() const {
    return healthpoints > 0;
}

//Returns the distance from this to other
double Character::distance(Character *other) {
    double ans = this->location.distance(other->getLocation());
    return ans;
}

//Set the player HP after being attacked
void Character::hit(int damage) {
    if (damage < 0) throw std::invalid_argument("Damage should be a natural number.\n");
    this->healthpoints -= damage;
}

//toString
std::string Character::print() const {
    return "";
}

//Returns this current HP
int Character::gethealthpoints() const {
    return healthpoints;
}

//Returns players name
const std::string &Character::getName() const {
    return name;
}

//Returns player types (Cowboy or ninja[old,young,trained])
characterType Character::getType() const {
    return type;
}

// Copy constructor
Character::Character(const Character &other) = default;

// Move constructor
Character::Character(Character &&other) noexcept
        : location(other.location),
          healthpoints(other.healthpoints),
          name(std::move(other.name)), inteam(other.inteam),
          type(other.type) {
    other.location = Point(0, 0);
    other.healthpoints=0;
    other.inteam= false;
    other.name="";
    other.type=noType;
}

// Copy assignment operator
Character &Character::operator=(const Character &other) {
    if (this == &other) {
        return *this;
    }
    name = other.name;
    location = other.location;
    healthpoints = other.healthpoints;
    inteam = other.inteam;
    type = other.type;
    return *this;
}

// Move assignment operator
Character &Character::operator=(Character &&other) noexcept {
    if (this != &other) {
        name = other.name;
        location = other.location;
        healthpoints = other.healthpoints;
        inteam = other.inteam;
        type = other.type;
    }
    return *this;
}

//Change this player location
void Character::setLocation(const Point &newLocation) {
location=newLocation;
}

const Point &Character::getLocation() const {
    return location;
}

bool Character::isInTeam() const {
    return this->inteam;
}

void Character::setTeam() {
    inteam = true;
}

//Destructor
Character::~Character() = default;

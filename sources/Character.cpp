#include "Character.hpp"
#include "Team.hpp"

#include <utility>
#include <valarray>
#include <limits>

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
    if (damage < 0) throw std::logic_error("Damage should be a natural number.\n");
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

//Returns this player location
Point Character::getLocation() {
    return location;
}

//Change this player location
void Character::setLocation(const Point &newLocation) {
location=newLocation;
}

bool Character::isInTeam() const {
    return this->inteam;
}

void Character::setTeam() {
    inteam = true;
}

Character *Character::findNearestCharacter(Team *team) {
    Character *answer = nullptr;
    double temp;
    double minDistance = std::numeric_limits<double>::max();
    for (int i = 0; i < team->getTeamsize(); ++i) {
        if (team->getCharacters().at(i) != nullptr && team->getCharacters().at(i)->isAlive()&&this!=team->getCharacters().at(i)) {
            temp = this->distance(team->getCharacters().at(i));
            if (temp < minDistance) {
                minDistance = temp;
                answer = team->getCharacters().at(i);
            }
        }
    }
    return answer;
}
//Destructor
Character::~Character() = default;

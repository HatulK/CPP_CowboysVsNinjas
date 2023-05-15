#include "Team.hpp"

using namespace ariel;

Team::Team(Character *leader) : leader(leader) {

}

Team::~Team() {


}

void Team::add(Character *character) {

}

void Team::attack(Team *enemyTeam) {

}

int Team::stillAlive() {
    return 0;
}

void Team::print() {

}

const std::array<Character, maxCharacters> &Team::getCharacters() const {
    return characters;
}

Character *Team::getLeader() const {
    return leader;
}


// Copy constructor
Team::Team(const Team &other)
        : characters(other.characters),
          leader(new Character(*(other.leader))) {}

// Move constructor
Team::Team(Team &&other) noexcept
        : characters(std::move(other.characters)),
          leader(other.leader) {
    other.leader = nullptr;
}

// Copy assignment operator
Team &Team::operator=(const Team &other) {
    if (this != &other) {
        characters = other.characters;
        delete leader;
        leader = new Character(*(other.leader));
    }
    return *this;
}

// Move assignment operator
Team &Team::operator=(Team &&other) noexcept {
    if (this != &other) {
        characters = std::move(other.characters);
        delete leader;
        leader = other.leader;
        other.leader = nullptr;
    }
    return *this;
}
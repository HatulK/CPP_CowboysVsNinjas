#include "Team.hpp"

using namespace ariel;

Team::Team(Character *leader) : leader(leader) {
    if (leader->isInTeam()) throw std::runtime_error("The leader is already associated with a different team.\n");
    if (!leader->isAlive()) throw std::runtime_error("Cannot place a dead character as a team leader\n");
    this->leader = leader;
    characters.at(0) = *this->leader;
    teamsize = 1;
}

// Copy constructor
Team::Team(const Team &other)
        : characters(other.characters),
          leader(new Character(*(other.leader))), teamsize(other.teamsize) {}

// Move constructor
Team::Team(Team &&other) noexcept
        : characters(other.characters), teamsize(0),
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

Team::~Team() = default; ////TBD


void Team::add(Character *character) {
    if (character == nullptr) throw std::invalid_argument("Null pointer\n");
    if (character->isInTeam()) throw std::runtime_error("This member already in a team.\n");
    if (!character->isAlive()) throw std::runtime_error("Cannot add a dead character to a team.\n");
    if (characters.size() == 10) throw std::runtime_error("Max character capacity reached.\n");
    character->setTeam();
    characters.at(teamsize) = *character;
    teamsize++;
}

int Team::stillAlive() {
    int num = 0;
    for (int i = 0; i < teamsize; ++i) {
        if (characters.at(i).isAlive()) {
            num++;
        }
    }
    return num;
}

std::array<Character, 10> Team::getCharacters() const {
    return characters;
}

Character *Team::getLeader() const {
    return leader;
}

int Team::getTeamsize() const {
    return teamsize;
}

void Team::setLeader(Character *newLeader) {
    Team::leader = newLeader;
}

void Team::swapLeader(){} ////TBD

Character *Team::findNearestEnemy(Team *team){} ////TBD

void Team::print() {} ////TBD

void Team::attack(Team *enemyTeam) { ////TBD
    if (enemyTeam == nullptr) throw std::runtime_error("Enemy team is null\n");
    if (0 == enemyTeam->stillAlive()) throw std::runtime_error("The other team is already dead.\n");

}

////Ninja/Cowboy attacking??
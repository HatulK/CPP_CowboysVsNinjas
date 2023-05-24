#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Character *leader) : Team(leader) {}

void Team2::attack(ariel::Team *enemyTeam) {
    if (enemyTeam == nullptr) throw std::invalid_argument("Enemy team is null\n");
    if (0 == enemyTeam->stillAlive()) throw std::runtime_error("The other team is already dead.\n");
    if (!getLeader()->isAlive()) swapLeader();
    auto toAttack = findNearestCharacter(enemyTeam);
    //first for loop is for cowboys to attack first
    for (size_t i = 0; i < this->getTeamsize(); ++i) {
        auto *attacker = getCharacters().at(i);
        if (attacker != nullptr && attacker->getType() == typeCowboy && attacker->isAlive()) {
            if (toAttack == nullptr || !toAttack->isAlive()) toAttack = findNearestCharacter(enemyTeam);
            if (toAttack != nullptr && toAttack->isAlive()) dynamic_cast<Cowboy *>(attacker)->shoot(toAttack);
        }
        if (attacker != nullptr && (attacker->getType() == typeTrainedNinja || attacker->getType() == typeOldNinja ||
                                    attacker->getType() == typeYoungNinja) && attacker->isAlive()) {
            if (toAttack == nullptr || !toAttack->isAlive()) toAttack = findNearestCharacter(enemyTeam);
            if (toAttack != nullptr && toAttack->isAlive() && attacker->isAlive()) {
                if (attacker->distance(toAttack) <= 1) dynamic_cast<Ninja *>(attacker)->slash(toAttack);
                else dynamic_cast<Ninja *>(attacker)->move(toAttack);
            }
        }
    }
}

void Team2::print() {}



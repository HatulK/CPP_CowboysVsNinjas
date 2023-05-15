
#include "Team2.hpp"

ariel::Team2::Team2(Character *leader) : Team(leader) {

}

void ariel::Team2::attack(ariel::Team *enemyTeam) {
    Team::attack(enemyTeam);
}

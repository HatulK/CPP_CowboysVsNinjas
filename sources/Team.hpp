#ifndef SYSTEMSEX4A_TEAM_H
#define SYSTEMSEX4A_TEAM_H

#include "Character.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"
#include "array"

namespace ariel {
    

    class Team {
    private:
        std::array<Character, 10> characters;
        Character *leader;
        int teamsize;
    public:
        int getTeamsize() const;

    public:
        explicit Team(Character *leader);

        Team(const Team& other);

        void setLeader(Character *newLeader);

        Team(Team&& other) noexcept;

        Team &operator=(Team &&other) noexcept;

        Team &operator=(const Team &other);

        void add(Character *character);

        virtual void attack(Team *enemyTeam);

        int stillAlive();

        void print();

        virtual ~Team();

        std::array<Character, 10> getCharacters() const;

        Character *getLeader() const;

        void swapLeader();

        Character *findNearestEnemy(Team *team);
    };
}

#endif //SYSTEMSEX4A_TEAM_H

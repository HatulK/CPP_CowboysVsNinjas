#ifndef SYSTEMSEX4A_TEAM_H
#define SYSTEMSEX4A_TEAM_H

#include "Character.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"
#include "array"

namespace ariel {
const int maxSize = 10;

    class Team {
    private:
        std::array<Character *, maxSize> characters{};
        Character *leader;
        int teamsize;
    public:

        explicit Team(Character* leader);

        Team(const Team &other);

        Team(Team &&other) noexcept;

        Team &operator=(Team &&other) noexcept;

        Team &operator=(const Team &other);

        void add(Character *character);

        virtual void attack(Team *enemyTeam);

        int stillAlive();

        virtual void print();

        virtual ~Team();

        const std::array<Character *, maxSize> &getCharacters() const;

        int getTeamsize() const;

        Character *getLeader() const;

        Character *findNearestCharacter(Team *team);

        void setLeader(Character *newLeader);

        void swapLeader();
    };
}

#endif

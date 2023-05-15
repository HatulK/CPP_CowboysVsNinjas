#ifndef SYSTEMSEX4A_TEAM_H
#define SYSTEMSEX4A_TEAM_H

#include "Character.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"
#include "array"

namespace ariel {
    const int maxCharacters = 10;

    class Team {
    private:
        std::array<Character, maxCharacters> characters;
        Character *leader;
    public:
        explicit Team(Character *leader);

        Team(const Team& other);

        Team(Team&& other) noexcept;

        Team &operator=(Team &&other) noexcept;

        Team &operator=(const Team &other);

        void add(Character *character);

        virtual void attack(Team *enemyTeam);

        int stillAlive();

        void print();

        virtual ~Team();

        const std::array<Character, maxCharacters> &getCharacters() const;

        Character *getLeader() const;
    };
}

#endif //SYSTEMSEX4A_TEAM_H

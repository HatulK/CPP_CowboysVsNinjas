#ifndef SYSTEMSEX4A_CHARACTER_healthpointsP
#define SYSTEMSEX4A_CHARACTER_healthpointsP

#include <iostream>
#include "Point.hpp"
#include "Team.hpp"
//#include "Team.hpp"

namespace ariel {
    enum characterType {
        noType = 0, typeYoungNinja = 1, typeTrainedNinja = 2, typeOldNinja = 3, typeCowboy = 4
    };

    class Character {
    private:
        Point location;
        int healthpoints;
        bool inteam;
        std::string name;

        enum characterType type;

    public:
        Character(std::string name,Point location, int healthpoints,enum characterType type);

        virtual ~Character();

        bool isInTeam() const;

        void setTeam();

        Character();

        bool isAlive() const;

        double distance(Character *other);

        void hit(int damage);

        Point getLocation();

        virtual std::string print() const;

        int gethealthpoints() const;

        const std::string &getName() const;

        characterType getType() const;

        Character& operator=(Character&& other) noexcept;

         Character(const Character& other);

        Character &operator=(const Character &other);

        Character(Character &&other) noexcept;

        void setLocation(const Point &newLocation);

    };
}


#endif

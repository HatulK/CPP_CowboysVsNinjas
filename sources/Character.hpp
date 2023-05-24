#ifndef SYSTEMSEX4A_CHARACTER_HPP
#define SYSTEMSEX4A_CHARACTER_HPP

#include "Point.hpp"
#include <iostream>

namespace ariel {
    enum characterType {
        noType = 0, typeYoungNinja = 1, typeTrainedNinja = 2, typeOldNinja = 3, typeCowboy = 4
    };

    class Character {
    private:
        std::string name;
        int healthpoints;
        Point location;
        enum characterType type;
        bool inteam;

    public:
        Character(std::string name, Point location, int hitPoints, enum characterType type);

        Character();

        Character &operator=(const Character &other);

        Character(const Character &other);

        Character(Character &&other) noexcept;

        Character &operator=(Character &&other) noexcept;

        virtual ~Character();

        bool isAlive() const;

        double distance(Character *otherChar);

        void hit(int damage);

        virtual std::string print() const;

        const Point &getLocation() const;

        void setLocation(const Point &location);

        int gethealthpoints() const;

        const std::string &getName() const;

        characterType getType() const;

        bool isInTeam() const;

        void setTeam();

    };
}


#endif //SYSTEMSEX4A_CHARACTER_HPP
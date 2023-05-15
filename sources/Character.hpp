#ifndef SYSTEMSEX4A_CHARACTER_healthpointsP
#define SYSTEMSEX4A_CHARACTER_healthpointsP

#include <iostream>
#include "Point.hpp"

namespace ariel {
    enum characterType {
        noType = 0, typeNinja = 1, typeYoungNinja = 2, typeTrainedNinja = 3, typeOldNinja = 4, typeCowboy = 5
    };

    class Character {
    private:
        Point location;
        int healthpoints;
        std::string name;

        enum characterType type;

    public:
        Character(std::string name,Point location, int healthpoints, enum characterType type);

        virtual ~Character();

        Character();

        static bool isAlive();

        static double distance(Character *otherChar);

        void hit(int damage);

        virtual std::string print() const;

        const Point &getLocation() const;

        int gethealthpoints() const;

        const std::string &getName() const;

        characterType getType() const;

        Character& operator=(Character&& other) noexcept;

         Character(const Character& other);

        Character& operator=(const Character& other);

        Character(Character &&other) noexcept;

    };
}


#endif //SYSTEMSEX4A_CHARACTER_healthpointsP

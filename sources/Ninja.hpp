#ifndef SYSTEMSEX4A_NINJA_healthpointsP
#define SYSTEMSEX4A_NINJA_healthpointsP

#include "Character.hpp"

namespace ariel {
    const int youngNinjaSpeed = 14;
    const int trainedNinjaSpeed = 12;
    const int oldNinjaSpeed = 8;
    const int youngNinjaHP = 100;
    const int trainedNinjaHP = 120;
    const int oldNinjaHP = 150;

    class Ninja : public Character {
    private:
        int speed{};
    protected:
        Ninja(std::string name,Point location, int healthpoints,
              int speed, enum characterType type);

    public:
        int move(Character *enemy);

        void slash(Character *enemy);

        int getSpeed() const;
    };
}

#endif

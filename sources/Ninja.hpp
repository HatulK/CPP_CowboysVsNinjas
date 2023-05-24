#ifndef SYSTEMSEX4A_NINJA_healthpointsP
#define SYSTEMSEX4A_NINJA_healthpointsP

#include "Character.hpp"

namespace ariel {

    class Ninja : public Character {
    private:
        const int speed{};
    protected:
        Ninja(std::string name,Point location, int healthpoints,
              int speed, enum characterType type);

    public:
        void move(Character *enemy);

        void slash(Character *enemy);

        int getSpeed() const;
    };
}

#endif

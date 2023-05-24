#include "doctest.h"
#include "sources/Point.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"

using namespace ariel;

TEST_CASE("point") {
    ariel::Point point1(0, 0);
    ariel::Point point2(3, 4);
    ariel::Point point3(-3, -4);
    CHECK_EQ(point1.getX(), 0);
    CHECK_EQ(point1.getY(), 0);
    CHECK_EQ(point1.distance(point2), 5);
    CHECK_EQ(point1.distance(point3), 5);
    CHECK_EQ(point1.print(), "(0,0)");
}

TEST_CASE("character creation") {
    Point point(0, 0);
    auto *oldNinja = new OldNinja("oldNinja", point);
    auto *youngNinja = new YoungNinja("youngNinja", {0, 1});
    auto *trainedNinja = new TrainedNinja("trainedNinja", {0, 2});
    auto *cowboy = new Cowboy("cowboy", point);
    CHECK_EQ(oldNinja->getName(), "oldNinja");
    CHECK_EQ(youngNinja->getName(), "youngNinja");
    CHECK_EQ(trainedNinja->getName(), "trainedNinja");
    CHECK_EQ(cowboy->getName(), "cowboy");
    CHECK(cowboy->hasboolets());
    CHECK_EQ(cowboy->gethealthpoints(), maxCowboyHP);
    CHECK_EQ(trainedNinja->gethealthpoints(), trainedNinjaHP);
    CHECK_EQ(youngNinja->gethealthpoints(), youngNinjaHP);
    CHECK_EQ(oldNinja->gethealthpoints(), oldNinjaHP);
    CHECK_EQ(trainedNinja->getSpeed(), trainedNinjaSpeed);
    CHECK_EQ(youngNinja->getSpeed(), youngNinjaSpeed);
    CHECK_EQ(oldNinja->getSpeed(), oldNinjaSpeed);
}

TEST_CASE("attacking") {
    Point p(0, 0);
    auto *oldNinja = new OldNinja("oldNinja", p);
    auto *youngNinja = new YoungNinja("youngNinja", p);
    auto *cowboy = new Cowboy("cowboy", p);
    while (ariel::YoungNinja::isAlive()) {
        oldNinja->slash(youngNinja);

    }
    CHECK_THROWS(cowboy->reload());
    CHECK_THROWS(oldNinja->slash(youngNinja));
    CHECK_THROWS(cowboy->shoot(youngNinja));
    CHECK_EQ(cowboy->getBullets(), 6);
    CHECK_EQ(youngNinja->gethealthpoints(), 0);
    CHECK_FALSE(youngNinja->isAlive());
    int hp = oldNinjaHP;
    for (int i = 0; i < 6; ++i) {
        ariel::Cowboy::shoot(oldNinja);
        CHECK_EQ(oldNinja->gethealthpoints(), hp - ((i + 1) * 10));
    }
    CHECK_EQ(cowboy->getBullets(), 0);
    CHECK_FALSE(cowboy->hasboolets());
    CHECK(oldNinja->isAlive());
    CHECK_THROWS(cowboy->shoot(oldNinja));
    CHECK_NOTHROW(cowboy->reload());
}

TEST_CASE("dead character") {

}

TEST_CASE("team") {
    auto LeaderNinja = new YoungNinja(("LeaderNinja"), {0, 0});
    auto ninja1 = new YoungNinja(("Ninja1"), {0, 0});
    auto ninja2 = new YoungNinja(("Ninja2"), {0, 0});
    auto ninja3 = new YoungNinja(("Ninja3"), {0, 0});
    auto ninja4 = new YoungNinja(("Ninja4"), {0, 0});
    auto ninja5 = new YoungNinja(("Ninja5"), {0, 0});
    auto ninja6 = new YoungNinja(("Ninja6"), {0, 0});
    auto ninja7 = new YoungNinja(("Ninja7"), {0, 0});
    auto ninja8 = new YoungNinja(("Ninja8"), {0, 0});
    auto ninja9 = new YoungNinja(("Ninja9"), {0, 0});
    auto ninja10 = new YoungNinja(("Ninja10"), {0, 0});
    auto team1 = new Team(LeaderNinja); //1
    team1.add(ninja1); //2
    CHECK_THROWS(team1.add(ninja1)); // Cannot add the same character twice.
    team1.add(ninja2); //3
    team1.add(ninja3); //4
    team1.add(ninja4); //5
    team1.add(ninja5); //6
    team1.add(ninja6); //7
    team1.add(ninja7); //8
    team1.add(ninja8); //9
    team1.add(ninja9); //10
    CHECK_THROWS(team1.add(ninja10)); // Cant add more than 10 characters
    CHECK(((team1.getLeader())==(LeaderNinja)));
    CHECK_NOTHROW(team1.getCharacters());

}

TEST_CASE("move") {
    Point point1(0, 0);
    Point point2(3, 4);
    auto *youngNinja = new YoungNinja("oldNinja", point1);
    auto *cowboy = new Cowboy("cowboy", point2);
    double dist = ariel::YoungNinja::distance(cowboy);
    youngNinja->move(cowboy);
    CHECK_EQ(dist - youngNinja->getSpeed(), youngNinja->distance(cowboy));
}

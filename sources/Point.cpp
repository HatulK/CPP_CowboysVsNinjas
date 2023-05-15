#include <iostream>
#include <complex>
#include "Point.hpp"


using namespace ariel;

ariel::Point::Point(double x, double y) : xpoint(x), ypoint(y) {}

ariel::Point::Point() : xpoint(0), ypoint(0) {}

double ariel::Point::getX() const {
    return xpoint;
}

double ariel::Point::getY() const {
    return ypoint;
}

double ariel::Point::distance(const Point &point) const {
    double xDiff = this->xpoint - point.xpoint;
    double yDiff = this->ypoint - point.ypoint;
    return std::sqrt(xDiff * xDiff + yDiff * yDiff);
}

std::string ariel::Point::print() const {
    return "(" + std::to_string(this->xpoint) + "," + std::to_string(this->ypoint) + ")";
}

Point ariel::moveTowards(Point &source, Point &dest, double distance) {
    return {0, 0};
}

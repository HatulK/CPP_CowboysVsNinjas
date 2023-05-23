#include <complex>
#include "Point.hpp"


using namespace ariel;

ariel::Point::Point(double x, double y) : xpoint(x), ypoint(y) {}

ariel::Point::Point() : xpoint(0), ypoint(0) {}

Point::~Point() = default;

Point &Point::operator=(const Point &other) = default;

Point::Point(const Point &other) = default;

Point::Point(Point &&other) noexcept {
    xpoint = other.xpoint;
    ypoint = other.ypoint;
}

Point &Point::operator=(Point &&other) noexcept {
    if (this != &other) {
        xpoint = other.xpoint;
        ypoint = other.ypoint;
    }
    return *this;
}

double ariel::Point::getX() const {
    return xpoint;
}

double ariel::Point::getY() const {
    return ypoint;
}

double ariel::Point::distance(const Point &other) const {
    double num1 = this->ypoint - other.ypoint;
    double num2 = this->xpoint - other.xpoint;
    return std::sqrt(num2 * num2 + num1 * num1);
}

std::string ariel::Point::print() const {
    return "(" + std::to_string(this->xpoint) + "," + std::to_string(this->ypoint) + ")\n";
}

Point Point::moveTowards(const Point &source, const Point &dest, double distance) {
    if(distance<0) throw std::invalid_argument("Distance should be greater or equal to 0.\n");
    double deltax = dest.xpoint - source.xpoint;
    double deltay = dest.ypoint - source.ypoint;
    double magnitude = sqrt(deltax * deltax + deltay * deltay);
    if (magnitude <= distance) {
        // The destination is within or at the given distance
        return dest;
    } else {
        double ratio = distance / magnitude;
        double newX = source.xpoint + (deltax * ratio);
        double newY = source.ypoint + (deltay * ratio);
        return {newX, newY};
    }
}



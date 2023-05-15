#ifndef EX4_POINT_HPP
#define EX4_POINT_HPP

#include "string"
namespace ariel {
    class Point {
    private:
        double xpoint;
        double ypoint;

    public:
        Point(double xpoint, double ypoint);
        Point();

        double distance(const Point &point) const;

        friend Point moveTowards(Point &source, Point &dest, double distance);

        double getX() const;

        double getY() const;

        std::string print() const;

        static Point moveTowards(Point &src,Point &dest, double distance);

    };
}


#endif

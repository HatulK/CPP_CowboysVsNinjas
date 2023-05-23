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

        Point &operator=(const Point &other);

        Point(const Point &other);

        Point(Point &&other) noexcept;

        Point &operator=(Point &&other) noexcept;

        ~Point();

        double distance(const Point &point) const;

        double getX() const;

        double getY() const;

        std::string print() const;

        static Point moveTowards(const Point &src, const Point &dest, double distance);

    };
}


#endif

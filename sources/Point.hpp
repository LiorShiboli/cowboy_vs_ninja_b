#pragma once
#include <string>
namespace ariel
{
    


    class Point
    {
    private:
        double x_pos;
        double y_pos;

    public:
        Point(double, double );
        double get_y();
        double get_x();
        void set_y(double);
        void set_x(double);
        double distance(Point other);
        std::string print();
        static Point moveTowards(Point from, Point torwards, double distance);
    };

 }// namespace ariel

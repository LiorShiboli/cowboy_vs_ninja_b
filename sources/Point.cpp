#include "Point.hpp"
#include "cmath"
#include <stdexcept>
namespace ariel
{
        Point::Point(double xCoordinate, double yCoordinate):x_pos(xCoordinate),y_pos(yCoordinate){}
        double Point::get_x(){return x_pos;}
        double Point::get_y(){return y_pos;}
        void Point::set_x(double new_x){this->x_pos=new_x;}
        void Point::set_y(double new_y){this->y_pos = new_y;}
        double Point::distance(Point other){
                double delta_x = this->get_x() - other.get_x();
                double delta_y = this->get_y() -  other.get_y(); 
                return std::sqrt(delta_x*delta_x+delta_y*delta_y);}
        std::string Point::print(){return "("+std::to_string(x_pos)+","+std::to_string(y_pos)+")";}
        Point Point::moveTowards(Point from, Point torwards, double distance){
                if (distance<0){
                        throw std::invalid_argument("no getting away you coward(negative distance)");
                }
                double delta_x = torwards.get_x() - from.get_x();
                double delta_y = torwards.get_y() -  from.get_y(); 
                double currentDistance = (std::sqrt(delta_x*delta_x+delta_y*delta_y));
                delta_x = delta_x/currentDistance;
                delta_y = delta_y/currentDistance;
                return Point(from.get_x()+delta_x*distance,from.get_y()+delta_y*distance);}
} // namespace ariel

#pragma once
#include <string>
using namespace std;
#include "Point.hpp"
namespace ariel
{
    class Character
    {
    private:
        string name;
        int hitpoints;
        Point location;
        bool isMember;
    protected:
        void setLocation(Point);
    public:
        void addToTeam();
        bool isInTeam();
        Character(int hitPoints,string name,Point coordinate);
        bool isAlive();
        virtual void hit(int damage);
        string getName();
        Point getLocation();
        virtual string print();
        int get_HP();
        double distance(Character*);
    };
    
} // namespace ariel

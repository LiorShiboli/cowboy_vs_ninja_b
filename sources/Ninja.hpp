#pragma once
#include <string>
using namespace std;
#include "Character.hpp"
namespace ariel
{
    class Ninja:public Character
    {
    private:
     int speed;
    public:
        Ninja(int speed,int hitpoints,string name,Point coordinate);
        virtual void move(Character* enemy);
        void slash(Character* enemy);
        string print();
    };
    
} // namespace ariel

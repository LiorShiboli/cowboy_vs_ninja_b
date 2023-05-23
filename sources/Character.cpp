#include "Character.hpp"
namespace ariel
{
    


    Character::Character(int hitPoints,string name,Point coordinate){}
    bool Character::isAlive(){return true;}
    void Character::hit(int damage){}
    string Character::getName(){return "";}
    Point Character::getLocation(){
        return Point(0,0);
    }
    string Character::print(){
        return "";
    }
    int Character::get_HP(){return 0;}
    double Character::distance(Character*){return 0;}
    } // namespace ariel
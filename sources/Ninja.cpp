#include "Ninja.hpp"
#include <stdexcept>
#include <iostream>
namespace ariel
{
    


    Ninja::Ninja(int speed ,int hitPoints,string name,Point coordinate):Character(hitPoints,name,coordinate),speed(speed){}
    void Ninja::move(Character* enemy){
        this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),speed));
    }
    void Ninja::slash(Character* enemy){
        if (!this->isAlive())
        {
            throw runtime_error("cannot attack while dead (dead man slash no man)" );
        }
        if (!enemy->isAlive())
        {
            throw runtime_error("cannot attack dead character");
        }
        if(this==enemy){
            throw runtime_error("13 throws why(dont harm yourself)");
        }
        if(this->distance(enemy)<1){
            enemy->hit(40);
        }
    }
    string Ninja::print(){
        return "N"+Character::print();
    }
} // namespace ariel
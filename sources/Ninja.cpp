#include "Ninja.hpp"
namespace ariel
{
    


    Ninja::Ninja(int hitPoints,string name,Point coordinate):Character(hitPoints,name,coordinate){}
    void Ninja::move(Character* enemy){
        this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),0));
    }
    void Ninja::slash(Character* enemy){
        if(this->distance(enemy)<1){
            enemy->hit(40);
        }
        }
    } // namespace ariel
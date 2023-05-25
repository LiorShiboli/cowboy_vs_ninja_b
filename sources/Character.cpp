#include "Character.hpp"
#include <stdexcept>
namespace ariel
{
    Character::Character(int hitPoints,string name,Point coordinate):hitpoints(hitPoints),name(name),location(coordinate),isMember(false){}
    void Character::addToTeam(){this->isMember = true;}
    bool Character::isInTeam(){return this->isMember;}
    bool Character::isAlive(){return (hitpoints>0);}
    void Character::hit(int damage)
    { 
        if(damage<0){
            throw invalid_argument("no healing");
        }
        this->hitpoints = max(hitpoints-damage,0);
    }
    string Character::getName(){return this->name;}
    Point Character::getLocation(){
        return location;
    }
    string Character::print(){
        if (this->isAlive()){
        return "name: "+this->getName()+" hitpoints:"+to_string(hitpoints)+" location:"+location.print();
        }
        return  "name: "+this->getName()+" location:"+location.print();
    }
    int Character::get_HP(){return this->hitpoints;}
    double Character::distance(Character* other){return this->getLocation().distance(other->getLocation());}
    void Character::setLocation(Point newLocation){this->location = newLocation;}
    } // namespace ariel
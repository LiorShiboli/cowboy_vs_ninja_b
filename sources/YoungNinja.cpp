#include "YoungNinja.hpp"
namespace ariel
{
    YoungNinja::YoungNinja( string name,Point coordinate):Ninja(100,name,coordinate){}
    void YoungNinja::move(Character* enemy){
        this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),14));
    }
    
} // namespace ariel

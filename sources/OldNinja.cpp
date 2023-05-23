#include "OldNinja.hpp"
namespace ariel
{
    OldNinja::OldNinja( string name,Point coordinate):Ninja(150,name,coordinate){}
    void OldNinja::move(Character* enemy){
        this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),8));
        }
} // namespace ariel

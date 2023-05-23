#include "TrainedNinja.hpp"
namespace ariel
{
    TrainedNinja::TrainedNinja( string name,Point coordinate):Ninja(120,name,coordinate){}
    void TrainedNinja::move(Character* enemy){
        this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),12));
    }
} // namespace ariel

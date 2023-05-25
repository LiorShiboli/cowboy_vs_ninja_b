#include "Cowboy.hpp"
#include <stdexcept>
#include <iostream>
namespace ariel
{
    Cowboy::Cowboy(string name, Point coordinate):Character(110,name,coordinate),bullets(6){}
    void Cowboy::shoot(Character* enemy){
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
        if (this->hasboolets())
        {
        this->bullets= this->bullets-1;
        enemy->hit(10);
        }
    }
    string Cowboy::print(){
        return "C"+Character::print();
    }
    bool Cowboy::hasboolets(){return this->bullets>0;}
    void Cowboy::reload(){
        if (!this->isAlive())
        {
            throw runtime_error("cannot reload from the grave" );
        }
        this->bullets=6;
    }
} // namespace ariel

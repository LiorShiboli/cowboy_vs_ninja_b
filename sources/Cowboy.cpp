#include "Cowboy.hpp"
namespace ariel
{
    Cowboy::Cowboy(string name, Point coordinate):Character(110,name,coordinate),bullets(6){}
    void Cowboy::shoot(Character* enemy){
        enemy->hit(10);
    }
    string Cowboy::print(){return "";}
    bool Cowboy::hasboolets(){return true;}
    void Cowboy::reload(){}
} // namespace ariel

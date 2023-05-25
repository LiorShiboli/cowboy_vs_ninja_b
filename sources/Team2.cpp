#include "Team2.hpp"
#include <stdexcept>
#include <limits>
namespace ariel
{
    Team2::Team2(Character* leader ):Team(leader){}
    void  Team2::attack(Team* enemyTeam){
        if (enemyTeam==nullptr)
        {
            throw invalid_argument("cannot attack no team(you have no enemies)");
        }
        if (!this->getLeader()->isAlive())
        {
            this->switchLeader();
            if (this->getLeader()==nullptr)
            {
                throw runtime_error("team is dead");
            }
            
        }
        
        
        Character* target = this->NearestToLeader(enemyTeam);
        if (target==nullptr)
        {
            throw runtime_error("overkill(atacking a deadd team)");
        }
        
        //cover cowboys
      
        
        for (Character* attacker :this->getMembers())
        {
            if (attacker->isAlive())
            {
                if (dynamic_cast<Cowboy*>(attacker)!=nullptr)
                { 
                    
                    Cowboy* shooter = dynamic_cast<Cowboy*>(attacker);
                    
                    if (target!=nullptr&&!target->isAlive())
                    {
                        target = this->NearestToLeader(enemyTeam);
                    }
                    if (!shooter->hasboolets())
                    {
                        shooter->reload();
                    }
                    else if (target!=nullptr)
                    {
                        shooter->shoot(target);
                    }
                } 
            
        
                if (dynamic_cast<Ninja*>(attacker)!=nullptr)
                { 
                    Ninja* slasher = dynamic_cast<Ninja*>(attacker);
                
                    if (target!=nullptr&&!target->isAlive())
                    {
                        target = this->NearestToLeader(enemyTeam);
                    }
                    if (target!=nullptr)
                    {
                        if (slasher->distance(target)>1)
                        {
                            slasher->move(target);
                        }
                        else
                        {
                            slasher->slash(target);
                        }
                    }
                }
            }  
        }
        
    }
    string  Team2::print(){
        string print ="";
         for (Character* teammate : this->getMembers()){
            print+= teammate->print();
        }
        return print;
         
    }
    int Team2::stillAlive(){
        int counter=0;
        for (Character* teammate: this->getMembers())
        {
            if (teammate->isAlive())
            {
                 counter++;
            }
            
           
        }
        return counter;
    }
} // namespace ariel

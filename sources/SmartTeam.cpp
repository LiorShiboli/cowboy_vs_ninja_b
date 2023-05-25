#include "SmartTeam.hpp"
#include <stdexcept>
#include <limits>
namespace ariel
{


    Character* findCowboyTarget(vector<Character*> targets){
        Character* target =nullptr;
        int minHP= std::numeric_limits<int>::max();
        for (Character* option :targets)
        {
            if (option->isAlive()&&option->get_HP()<minHP)
            {
                minHP =option->get_HP();
                target=option;
            }
            
        }
        return target;
        
    }
    Character* findNinjaTarget(Ninja* slasher, vector<Character*> targets){
        Character* target =nullptr;
        int minHP= std::numeric_limits<int>::max();
        for (Character* option :targets)
        {
            if (option->isAlive()&& option->distance(slasher)<slasher->getSpeed()+1&&option->get_HP()<minHP)
            {
                minHP =option->get_HP();
                target=option;
            }
            
        }
        if (target==nullptr)
        {
            for (Character* option :targets)
        {
            if (option->isAlive()&&option->get_HP()<minHP)
            {
                minHP =option->get_HP();
                target=option;
            }
            
        }
        }
        
        return target;
        
    }
    void SmartTeam::attack(Team* enemyTeam){
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
        
        
        //cover cowboys
      
        
        for (Cowboy* shooter :this->getShooters())
        {
            if (shooter->isAlive())
            {
                    if (!shooter->hasboolets())
                    {
                        shooter->reload();
                    }
                    else 
                    {
                        Character* target =findCowboyTarget(enemyTeam->getMembers());
                        if (target!=nullptr)
                        {
                        
                        shooter->shoot(target);
                        }
                    }
            }
        }
        //go through ninjas
        for (Ninja* slasher :this->getSlashers())
        {
            if (slasher->isAlive())
            {
                Character* target = findNinjaTarget(slasher,enemyTeam->getMembers());
                if (target!=nullptr)
                {
                    if (slasher->distance(target)>1)
                    {
                        slasher->move(target);
                    }
                    else{
                        slasher->slash(target);}
                    
                }
            }  
        }
        
        
    }
} // namespace ariel

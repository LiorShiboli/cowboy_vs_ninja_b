#include "Team.hpp"
#include <stdexcept>
#include <limits>
namespace ariel
{
    Team::Team(Character* leader ):teamLeader(leader),size(0)
    {
        this->add(leader);
    }
    Team::~Team(){
        for (Character* teammate : characters)
        {
            free(teammate);
        }
        
    }
    vector<Character*> Team::getMembers(){return this->characters;}
    Character* Team::getLeader(){ return teamLeader;}
    void Team::switchLeader()
    {
        this->teamLeader = this->NearestToLeader(this);
    }
    void Team::add(Character* teammate){
        if (teammate->isInTeam())
        {
            throw runtime_error("already in team");
        }
        if (size>=10)
        {
            throw runtime_error("this team isnt big enough for the 11 of us");
        }
        this->size++;
        teammate->addToTeam();
        characters.push_back(teammate);
        
    }
    int  Team::stillAlive(){
        int counter =0;
        for (Character* teammate : characters){
            if (teammate->isAlive())
            {
                counter++;
            }
            
        }
        return counter;
    }
    void  Team::attack(Team* enemyTeam){
        if (enemyTeam==nullptr)
        {
            throw invalid_argument("cannot attack no team(you have no enemies)");
        }
        if (!this->teamLeader->isAlive())
        {
            this->teamLeader =this->NearestToLeader(this);
            if (this->teamLeader==nullptr)
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
      
        
        for (Character* attacker :this->characters)
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
            }
        }
        //go through ninjas
        for (Character* attacker :this->characters)
        {
            if (attacker->isAlive())
            {
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
                        else{
                            slasher->slash(target);}
                        
                    }
                }
            }  
        }
        
    }
    Character* Team::NearestToLeader(Team* otherTeam){
        
        Character* target = nullptr;
        double minDistance = std::numeric_limits<double>::max();
        for (Character* other: otherTeam->getMembers())
        {
            if (other->isAlive()&&other->distance(this->teamLeader)<minDistance )
            {
                minDistance = other->distance(this->teamLeader);
                target = other;
            }
            
        }
        return target;
        
    }
    string  Team::print(){
        string print ="";
         for (Character* teammate : characters){
            print+= teammate->print();
        }
        return print;
         
    }
} // namespace ariel

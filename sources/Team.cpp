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
        for (Character* teammate : slashers)
        {
            free(teammate);
        }
         for (Character* teammate : shooters)
        {
            free(teammate);
        }
        
    }
    vector<Character*> Team::getMembers(){
        vector<Character*> members;
        for (Character* teammate : slashers)
        {
            members.push_back(teammate);
        }
        for (Character* teammate : shooters)
        {
            members.push_back(teammate);
        }
        
        return members;
        }
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
        if (dynamic_cast<Cowboy*>(teammate)!=nullptr)
        {
            shooters.push_back(dynamic_cast<Cowboy*>(teammate));
        }
        if (dynamic_cast<Ninja*>(teammate)!=nullptr)
        {
            slashers.push_back(dynamic_cast<Ninja*>(teammate));
        } 
        
    }
    int  Team::stillAlive(){
        int counter =0;
         for (Character* teammate : slashers)
        {
            if (teammate->isAlive())
            {
                counter++;
            }
        }
        for (Character* teammate : shooters)
        {
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
      
        
        for (Cowboy* shooter :this->shooters)
        {
            if (shooter->isAlive())
            {
                    
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
        //go through ninjas
        for (Ninja* slasher :this->slashers)
        {
            if (slasher->isAlive())
            {
                
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
    Character* Team::NearestToLeader(Team* otherTeam){
        
        Character* target = nullptr;
        double minDistance = std::numeric_limits<double>::max();
        for (Character* attacker :otherTeam->getMembers())
        {
                if (dynamic_cast<Cowboy*>(attacker)!=nullptr)
                {
                    Cowboy* other = dynamic_cast<Cowboy*>(attacker);
                    if (other->isAlive()&&other->distance(this->teamLeader)<minDistance )
                    {
                        minDistance = other->distance(this->teamLeader);
                        target = other;
                    }
                } 
            
        }
        //go through ninjas
        for (Character* attacker :otherTeam->getMembers())
        {
             if (dynamic_cast<Ninja*>(attacker)!=nullptr)
                {
                    Ninja* other = dynamic_cast<Ninja*>(attacker);
                    if (other->isAlive()&&other->distance(this->teamLeader)<minDistance )
                    {
                        minDistance = other->distance(this->teamLeader);
                        target = other;
                    }
                }   
        }
        return target;
        
    }
    string  Team::print(){
        string print ="";
        for (Character* teammate : slashers)
        {
            print+=teammate->print();
        }
        for (Character* teammate : shooters)
        {
            print+=teammate->print();
        }
        
        return print;
         
    }
} // namespace ariel

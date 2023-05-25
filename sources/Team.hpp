#pragma once
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"
#include "Point.hpp"
#include <vector>
namespace ariel
{
    class Team
    {
    private:
       int size;
       Character* teamLeader;
       vector<Cowboy*> shooters;
       vector<Ninja*> slashers;
    protected:
    vector<Cowboy*> getShooters();
    vector<Ninja*> getSlashers();
    
    Character* getLeader();
    void switchLeader();
    public:
        vector<Character*> getMembers();
        Team(Character* );
        ~Team();
        virtual void add(Character*);
        virtual int stillAlive();
        virtual void attack(Team*);
        Character* NearestToLeader(Team* enemyTeam);
        virtual string print();
    };
    
} // namespace ariel

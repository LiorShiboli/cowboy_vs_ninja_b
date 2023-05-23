#pragma once
#include "Team.hpp"
namespace ariel
{
    class Team2:public Team
    {
    private:
        int x;
        int y;
    public:
        Team2(Character* );
        ~Team2();
        virtual void add(Character*);
        virtual int stillAlive();
        virtual void attack(Team*);
        virtual string print();
    };
    
}
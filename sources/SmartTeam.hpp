#include "Team2.hpp"
namespace ariel
{
    class SmartTeam:public Team
    {
    private:
    public:
        SmartTeam(Character* );
        virtual void attack(Team*);
    };
    
}
#pragma once
#include <string>
using namespace std;
#include "Ninja.hpp"
namespace ariel
{
    class TrainedNinja:public Ninja
    {
    private:
        /* data */
    public:
        TrainedNinja( string name,Point coordinate);
        void move(Character*);
    };
    
} // namespace ariel

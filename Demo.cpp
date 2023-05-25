/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


#include <random>
#include <chrono>
#include <iostream>

double random_float(double min = -100, double max = 100) {
    std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::uniform_real_distribution<double> distribution(min, max);

    return distribution(generator);
}
auto create_yninja = [](double x = random_float(), double y = random_float()) {
    return new YoungNinja{"boruto", Point{x, y}};
};

auto create_tninja = [](double x = random_float(), double y = random_float()) {
    return new TrainedNinja{"kakashi", Point{x, y}};
};

auto create_oninja = [](double x = random_float(), double y = random_float()) {
    return new OldNinja{"oldie", Point{x, y}};
};

auto create_cowboy = [](double x = random_float(), double y = random_float()) {
    return new Cowboy{"Bob", Point{x, y}};
};

auto random_char(double x = random_float(), double y = random_float()) -> Character * {
    int flag = static_cast<int>(random_float()) % 4;

    if (flag == 0) return create_cowboy(x, y);

    if (flag == 1) return create_yninja(x, y);

    if (flag == 2) return create_tninja(x, y);

    return create_oninja(x, y);
}

auto simulate_battle = [](Team &team, Team &team2) {
    int i = 0;
    while (team.stillAlive() && team2.stillAlive()) {
        if (i % 2 == 0) {
            team.attack(&team2);
        } else {
            team2.attack(&team);
        }
        i++;
    }
};
//<-------------------------------------------------->

const int MAX_TEAM = 10;
auto multi_attack = [](int n, Team &attacker, Team &defender) {
        for (int i = 0; i < n; i++) {
            if (defender.stillAlive()) {
                attacker.attack(&defender);
            }
        }
    };

int main(){
    Team team{create_cowboy(-1, -1)};
    team.add(create_yninja(0, 0));
    team.add(create_oninja(-0.5, -0.5));
    team.add(create_tninja(0.5, 0.5));
    team.add(create_cowboy());

    cout<<team.stillAlive()<<endl;

    auto young_ninja = create_yninja(0, 0);
    auto trained_ninja = create_tninja(1, 1);
    auto old_ninja = create_oninja(2, 2);
    auto young_ninja2 = create_yninja(3, 3);
    auto cowboy = create_cowboy(-6, -6);
    auto cowboy2 = create_cowboy(-7, -7);
    auto cowboy3 = create_cowboy(-8, -8);
    Team team2{young_ninja};
    team2.add(trained_ninja);
    team2.add(old_ninja);
    team2.add(young_ninja2);
    team2.add(cowboy);
    team2.add(cowboy2);
    team2.add(cowboy3);

    multi_attack(2, team, team2);
    
    team.attack(&team2);
    multi_attack(2, team, team2);
    cout<<!old_ninja->isAlive() << young_ninja2->isAlive()<<endl;
    cout<<team.print()<<endl;
    
    multi_attack(4, team, team2);
    cout<<old_ninja->isAlive()<<endl; // Old ninja should be dead
    cout<<team.print()<<endl;
    cout<<team2.print()<<endl;
    multi_attack(2, team, team2);
    team.attack(&team2); // The entire enemy team will be dead before every cowboy shoots, the attack should stop and not throw an exception
    cout<<young_ninja2->isAlive()<<endl; // Young ninja should be dead

   return 0;
}
/*
int main() {
   Point a(32.3,44),b(1.3,3.5);
   assert(a.distance(b) == b.distance(a));
   Cowboy *tom = new Cowboy("Tom", a);
   OldNinja *sushi = new OldNinja("sushi", b);
   tom->shoot(sushi);
   cout << tom->print() <<endl;

   sushi->move(tom);
   sushi->slash(tom);

   Team team_A(tom); 
   team_A.add(new YoungNinja("Yogi", Point(64,57)));

   // Team b(tom); should throw tom is already in team a

   Team team_B(sushi);
   team_B.add(new TrainedNinja("Hikari", Point(12,81)));


   while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
      team_A.attack(&team_B);
      team_B.attack(&team_A);
      team_A.print();
      team_B.print();
   }

   if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
   else cout << "winner is team_B" << endl;

   return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
*/

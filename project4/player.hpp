#ifndef PLAYER
#define PLAYER

#include "stack.hpp"
#include "queue.hpp"

class Player
{
private:
        Queue * lineup;
        Stack * fainted;
        int wins;
        int losses;
        int points;
        void update_points();

public:
        Queue * get_lineup();
        Stack * get_fainted();
        void display_stats();
        int get_points();

        void won();
        void lost();

        Player();
        ~Player();
};

#endif

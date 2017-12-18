#ifndef GUY_HPP
#define GUY_HPP
#include <string>
#include "pack.hpp"
#include "space.hpp"
#include "creature.hpp"
class Item;

class Player : public Creature
{
private:
        Pack * backpack;
        Item * hand;
        void maybe_move();
public:
        void pick_up(Item *);

        virtual void turn();
        Player(string n = "Ben", int a = 100, int b = 100 , int c = 100, Space * curr = NULL);
        virtual ~Player();
};

#endif

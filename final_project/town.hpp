#ifndef TOWN_HPP
#define TOWN_HPP

#include "space.hpp"

class Town : public Space
{
private:
        friend class World;
        Space * first;
        Space * second;
        Space * third;
        Space * fourth;
        Space * fifth;
        Space * sixth;
public:
        Town(string n = "Town");
        ~Town();
};
#endif

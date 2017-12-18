/*********************************************************************
** Program Filename: floor.hpp
** Author: brian palmer
** Date: 11.28.16
** Description: Conveyor_Belt class template
** Input: none
** Output: none
*********************************************************************/

#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "space.hpp"
#include "water.hpp"
#include "stack.hpp"
#include "conveyor_belt.hpp"


class Floor : public Space
{
        Conveyor_Belt * conveyor_belt;
public:
        Floor(string n = "Floor");
        ~Floor();

        void check_conveyor_belt(Stack *);
        virtual bool inspect(Stack *);
};

#endif

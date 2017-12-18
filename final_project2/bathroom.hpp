/*********************************************************************
** Program Filename: bathroom.hpp
** Author: brian palmer
** Date: 11.28.16
** Description: Bathroom header
** Input: none
** Output: none
*********************************************************************/

#ifndef BATHROOM_HPP
#define BATHROOM_HPP

#include "space.hpp"
#include "water.hpp"
#include "stack.hpp"
#include "key.hpp"


class Bathroom : public Space
{
private:
        bool stall;
        Item * locker;
public:
        virtual bool inspect(Stack *);

        Bathroom(string n = "Bathroom");
        virtual ~Bathroom();

        void check_right_stall();
        Item * check_locker();
        void check_left_stall();

        Item * get_locker();
};

#endif

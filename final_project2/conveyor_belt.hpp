/*********************************************************************
** Program Filename: conveyor_belt.hpp
** Author: brian palmer
** Date: 11.28.16
** Description: Conveyor_Belt class
** Input: none
** Output: none
*********************************************************************/

#ifndef CONVEYOR_BELT_HPP
#define CONVEYOR_BELT_HPP

#include "machine.hpp"
#include "node.hpp"
#include "water.hpp"
#include "soda.hpp"

class Conveyor_Belt : public Machine
{
private:
        Node * front;
        Node * rear;
        bool is_empty();

        void rotate();
public:
        Conveyor_Belt(string type = "Conveyor Belt");
        ~Conveyor_Belt();

        void push(Item *);
        Item * check(); // front
        Item * get_item(); // pop
        virtual void start(Stack *);

};

#endif

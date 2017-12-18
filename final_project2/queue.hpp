/*********************************************************************
** Program Filename: Queue.hpp
** Author: brian palmer
** Date: 11.5.16
** Description: Queue class
** Input: none
** Output: none
*********************************************************************/

#ifndef QUEUE
#define QUEUE

#include "node.hpp"

class Queue
{
private:
        Node * front;
        Node * rear;
public:
        Queue();
        ~Queue();

        void push(Item *);
        Item * pop();
        bool is_empty();
        // void display();
        // Creature * peek();
};

#endif

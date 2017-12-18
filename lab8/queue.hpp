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
#include <string>
#include <iostream>

using std::cout;
using std::string;

class Queue
{
private:
        Node * front;
        Node * back;

        bool is_empty();
public:
        Queue();
        ~Queue();

        void add_back(int);
        int get_front();
        int remove_front();
        void display();

};

#endif

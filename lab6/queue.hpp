/*****************
* brian palmer
* 11.3.16
* palmebri@oregonstate.edu
*************/

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

        void push(int);
        int pop();
        bool is_empty();
};

#endif

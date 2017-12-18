/***************
* brian palmer
* palmebri@oregonstate.edu
**************/

#include "queue.hpp"

void Queue::push(int i)
{
        if (is_empty() == true)
        {
                front = new Node(i);
                rear = front;
        }
        else
        {
                rear->next = new Node(i);
                rear = rear->next;
        }
}

int Queue::pop()
{
        if (is_empty() == true)
        {
                return 0;
        }
        else
        {
                int output = front->value;
                Node * temp = front;
                front = front->next;
                delete temp;
                return output;
        }
}

Queue::Queue()
{
        front = NULL;
        rear = NULL;
}

Queue::~Queue()
{
        while (is_empty() == false)
        {
                pop();
        }
}

bool Queue::is_empty()
{
        if (front == NULL)
                return true;
        else
                return false;
}

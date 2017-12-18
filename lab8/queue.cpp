/*********************************************************************
** Program Filename: queue.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: queue implementation
** Input: none
** Output: none
*********************************************************************/

#include "queue.hpp"

void Queue::add_back(int i)
{
        if (front == NULL && back == NULL)
        {
                Node * node = new Node;
                node->prev = back;
                node->next = front;
                node->value = i;

                front = node;
                back = front;
        }
        else
        {
                Node * iter = front;
                if (iter->value == -1)
                {
                        iter->value = i;
                }
                else if (iter->next == NULL)
                {
                        Node * node = new Node;

                        node->prev = back;
                        back->next = node;
                        back = node;

                        node->next = front;
                        front->prev = back;
                        node->value = i;
                }
                else
                {
                        iter = iter->next;
                        while (iter->value != -1 && iter != front)
                                iter = iter->next;
                        if (iter != front)
                                iter->value = i;
                        else
                        {
                                Node * node = new Node;

                                node->prev = back;
                                back->next = node;
                                back = node;

                                node->next = front;
                                front->prev = back;
                                node->value = i;
                        }
                }
        }
}

/*********************************************************************
** Function: pop
** Description: removes and returns first integer in queue
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: integer
*********************************************************************/

int Queue::remove_front()
{
        if (is_empty() == true)
                return -1;
        else
        {
                int output = front->value;
                front->value = -1;
                if (front->next != NULL)
                {
                        back = front;
                        front = front->next;
                }
                return output;
        }
}

int Queue::get_front()
{
        if (is_empty() == true)
                return -1;
        else
                return front->value;
}

void Queue::display()
{
        if (is_empty() == true)
                cout << "There is nothing in the queue!\n";
        else
        {
                Node * iter = front;
                while (iter != back)
                {
                        cout << iter->value << " ";
                        iter = iter->next;
                }
                cout << iter->value << " ";
        }
}

/*********************************************************************
** Function: Queue constructor
** Description: creates stack
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Queue::Queue()
{
        front = NULL;
        back = NULL;
}

/*********************************************************************
** Function: Stack destructor
** Description: destroys stack
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Queue::~Queue()
{
        cout << "erasing queue..";
        int counter = 1;
        while (front != back)
        {
                cout << ".." << counter << "..";
                Node * temp = front;
                front = front->next;
                delete temp;
                counter++;
        }
        cout << ".." << counter << "..";
        Node * temp = front;
        front = front->next;
        delete temp;

        cout << "..done!\n";

}

/*********************************************************************
** Function: is empty()
** Description: returns true if stack equals null
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: bool
*********************************************************************/

bool Queue::is_empty()
{
        if (front == NULL)
        {
                cout << "queue is empty!\n";
                return true;
        }
        else
                return false;
}

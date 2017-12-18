/*********************************************************************
** Program Filename: queue.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: queue implementation
** Input: none
** Output: none
*********************************************************************/

#include "queue.hpp"

/*********************************************************************
** Function: display()
** Description: displays creatures in queue
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Queue::display()
{
        Node * temp = front;
        if (temp == NULL)
        {
                cout << "*** EMPTY ***";
        }
        else
        {
                while (temp->next != NULL)
                {
                        cout << temp->creature->get_type() << ", " << temp->creature->get_str_pts() << " || ";
                        temp = temp->next;
                }
                cout << temp->creature->get_type() << ", " << temp->creature->get_str_pts();
        }
}

// Creature * Queue::peek()
// {
//         if (front == NULL)
//                 return NULL;
//         else
//                 return front->creature;
// }

void Queue::push(Creature * i)
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

/*********************************************************************
** Function: pop
** Description: removes and returns first integer in queue
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: integer
*********************************************************************/

Creature * Queue::pop()
{
        if (is_empty() == true)
        {
                Creature * temp = NULL;
                return temp;
        }
        else
        {
                Creature * output = front->creature;
                Node * temp = front;
                temp->creature = NULL;
                front = front->next;
                delete temp;
                return output;
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
        rear = NULL;
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
        while (front != NULL)
        {
                Node * temp = front;
                front = front->next;
                delete temp;
        }
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
                return true;
        else
                return false;
}

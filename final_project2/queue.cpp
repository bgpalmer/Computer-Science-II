/*********************************************************************
** Program Filename: queue.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: queue implementation
** Input: none
** Output: none
*********************************************************************/

#include "queue.hpp"


// Dont Need
// /*********************************************************************
// ** Function: display()
// ** Description: displays creatures in queue
// ** Parameters: none
// ** Pre-Conditions: none
// ** Post-Conditions: none
// ** Return: none
// *********************************************************************/
//
// void Queue::display()
// {
//         Node * temp = front;
//         if (temp == NULL)
//         {
//                 cout << "*** EMPTY ***";
//         }
//         else
//         {
//                 while (temp->next != NULL)
//                 {
//                         cout << temp->item->get_type() <
//                         temp = temp->next;
//                 }
//                 cout << temp->creature->get_type() << ", " << temp->creature->get_str_pts();
//         }
// }

// Creature * Queue::peek()
// {
//         if (front == NULL)
//                 return NULL;
//         else
//                 return front->creature;
// }

/*********************************************************************
** Function: push
** Description: creates new node and adds to the back of the queue. Node
takes only the item parameter, and it's next member is assigned the default
parameter value NULL by the constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Queue::push(Item * i)
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
** Description: if queue is not empty, returns first item, else NULL
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: Item pointer
*********************************************************************/

Item * Queue::pop()
{
        if (is_empty() == true)
        {
                return NULL;
        }
        else
        {
                Item * output = front->item;
                Node * temp = front;
                temp->item = NULL;
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
** Description: returns true if front member equals null
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

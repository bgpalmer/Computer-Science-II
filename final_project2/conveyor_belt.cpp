/*********************************************************************
** Program Filename: conveyor_belt.cpp
** Author: brian palmer
** Date: 11.28.16
** Description: Conveyor_Belt function definitions
** Input: none
** Output: none
*********************************************************************/

#include "conveyor_belt.hpp"

/*********************************************************************
** Function: conveyor belt
** Description: conveyor_belt constructor
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Conveyor_Belt::Conveyor_Belt(string type) : Machine(type)
{
        front = NULL;
        rear = NULL;

        push(NULL);
        push(NULL);
        push(new Water);
        push(NULL);
        push(new Soda);
        push(NULL);
}

/*********************************************************************
** Function: conveyor belt
** Description: conveyor_belt Destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Conveyor_Belt::~Conveyor_Belt()
{
        while (front != rear)
        {
                Node * temp = front;
                front = front->next;
                delete temp;
        }
        Node * temp = front;
        front = front->next;
        delete temp;

}

/*********************************************************************
** Function: check
** Description: rotates circular queue then returns pointer to the first item
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: Do not delete the pointer! Set null if desired.
** Return: none
*********************************************************************/

Item * Conveyor_Belt::check()
{
        rotate();
        return front->item;
}

/*********************************************************************
** Function: get item
** Description: creates a pointer to the front nodes item, sets node item pointer to NULL,
than returns item pointer
** Parameters: string
** Pre-Conditions: should use after checking that the first node isn't empty(use check())
** Post-Conditions: none
** Return: none
*********************************************************************/

Item * Conveyor_Belt::get_item()
{
        Item * temp = front->item;
        front->item = NULL;
        return temp;
}

/*********************************************************************
** Function: rotate
** Description: rotates the circular queue. the front item is sent to the rear.
** Parameters: none
** Pre-Conditions: should use after checking that the first node isn't empty(use check())
** Post-Conditions: none
** Return: none
*********************************************************************/

void Conveyor_Belt::rotate()
{
        Node * temp = front;
        front = front->next;
        rear = temp;
}


// Not needed!
// /*********************************************************************
// ** Function: is_empty
// ** Description: checks if the queue empty
// ** Parameters: none
// ** Pre-Conditions: none
// ** Post-Conditions: none
// ** Return: bool
// *********************************************************************/
//
// bool Conveyor_Belt::is_empty()
// {
//         if (front == NULL)
//                 return true;
//         else
//                 return false;
// }

/*********************************************************************
** Function: push
** Description: creates a node, assigns the nodes item member to the passed item
pointer, then adds the node to the back
** Parameters: item pointer
** Pre-Conditions: should be used when constructing the game
** Post-Conditions: none
** Return: none
*********************************************************************/

void Conveyor_Belt::push(Item * obj)
{
        Node * iter = front;
        if (iter == NULL)
        {
                rear = new Node(obj, rear);
                front = rear;
        }
        else
        {
                Node * temp = rear;
                rear = new Node(obj, front);
                temp->next = rear;
        }
}

/*********************************************************************
** Function: start
** Description: starts the conveyor belt
** Parameters: stack pointer
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Conveyor_Belt::start(Stack * pack)
{
        if (state == false)
        {
                cout << "The conveyor belt is off. ";
                cout << "Turn on?\n";
                char c = facilitateYNresponse();
                switch (c)
                {
                        case 'Y':
                                change_state();
                                break;
                        case 'N':
                                cout << "Left it alone.\n";
                                break;
                }
        }
        else
        {
                Item * item = check();
                if (item == NULL)
                {
                        cout << "Nothing there right now";
                        cout << " but it is moving!\n";
                }
                else
                {
                        cout << "You found a " << item->get_type() <<"!\n";
                        if (pack->maybe_add(item) == true)
                                pack->add(get_item());
                        item = NULL;
                }
        }
}

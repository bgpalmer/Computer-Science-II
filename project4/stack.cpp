/*********************************************************************
** Program Filename: stack.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: stack implementation
** Input: none
** Output: none
*********************************************************************/

#include "stack.hpp"

/*********************************************************************
** Function: display
** Description: displays creatues in stack
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Stack::display()
{
        Node * temp = top;
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

// Creature * Stack::peek()
// {
//         if (top == NULL)
//                 return NULL;
//         else
//                 return top->creature;
// }

bool Stack::is_empty()
{
        if (top == NULL)
                return true;
        else
                return false;
}

/*********************************************************************
** Function: pop
** Description: removes the top node in the stack and returns the value
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: integer
*********************************************************************/

Creature * Stack::pop()
{
        if (is_empty() == true)
        {
                Creature * temp = NULL;
                return temp;
        }
        else
        {
                Creature * output = top->creature;
                Node * temp = top;
                top = top->next;
                delete temp;

                return output;
        }
}

/*********************************************************************
** Function: push(int)
** Description: adds an integer to the front of the list
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: should return user to stack menu
** Return: none
*********************************************************************/

void Stack::push(Creature * v)
{
        top = new Node(v, top);
}

/*********************************************************************
** Function: Stack constructor
** Description: creates stack
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Stack::Stack()
{
        top = NULL;
}

/*********************************************************************
** Function: Stack destructor
** Description: destroys stack
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: no dangling pointers
** Return: none
*********************************************************************/

Stack::~Stack()
{
        while (top != NULL)
        {
                Node * temp = top;
                top = top->next;
                delete temp;
        }
}

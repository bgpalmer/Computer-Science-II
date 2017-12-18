/*********************************************************************
** Program Filename: node.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: node implementation
** Input: none
** Output: none
*********************************************************************/

#include "node.hpp"

/*********************************************************************
** Function: Node constructor
** Description: Nodes are used in the Queue, Stack, and Conveyor_Belt
classes. They can be used to create doubly linked lists. They also have
a branch member, which allows doubly linked lists to be created off nodes
pre-existing nodes
** Parameters:  Item pointer, Node pointer
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Node::Node(Item * v, Node * n)
{
        branch = NULL;
        item = v;
        next = n;
        if (n != NULL)
                next->prev = this;
        prev = NULL;
        quantity = 0;
        type_weight = 0.00;
}

/*********************************************************************
** Function: Node destructor
** Description: removes node list from branch first, then deletes item pointer
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Node::~Node()
{
        while (branch != NULL)
        {
                Node * temp = branch;
                branch = branch->next;
                delete temp;
        }
        if (item != NULL)
                delete item;
}

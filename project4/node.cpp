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
** Description: creates Node
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Node::Node(Creature * v, Node * n)
{
        creature = v;
        next = n;
}

/*********************************************************************
** Function: Node destructor
** Description: removes node
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Node::~Node()
{
        delete creature;
}

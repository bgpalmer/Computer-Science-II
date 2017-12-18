/*********************************************************************
** Program Filename: node.hpp
** Author: brian palmer
** Date: 11.5.16
** Description: Node class
** Input: none
** Output: none
*********************************************************************/


#ifndef NODE
#define NODE
#include <string>
#include <iostream>
#include "creature.hpp"
#include "vampire.hpp"
#include "medusa.hpp"
#include "harry_potter.hpp"
#include "blue_men.hpp"
#include "barbarian.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Queue;
class Stack;

class Node
{
private:
        friend class Queue;
        friend class Stack;
        Creature * creature;
        Node * next;
public:
        Node(Creature * v, Node * n = NULL);
        ~Node();
};

#endif

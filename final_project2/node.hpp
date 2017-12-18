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
#include "item.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::string;

class Node
{
private:
        friend class Conveyor_Belt;
        friend class Stack;
        friend class Queue;
        Item * item;
        Node * next;
        Node * branch;
        Node * prev;
        int quantity;
        float type_weight;
public:
        Node(Item * v = NULL, Node * n = NULL);
        ~Node();

        //Node * operator[] (int);
};

#endif

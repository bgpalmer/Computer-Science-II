#ifndef NODE
#define NODE
#include <string>
#include <iostream>

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
        int value;
        Node * next;
public:
        Node(int v, Node * n = NULL);
        ~Node();
};

#endif

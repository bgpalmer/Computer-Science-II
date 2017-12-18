#include "node.hpp"

Node::Node(int v, Node * n)
{
        value = v;
        next = n;
}

Node::~Node()
{
        
}

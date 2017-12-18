#include "stack.hpp"

bool Stack::is_empty()
{
        if (top == NULL)
                return true;
        else
                return false;
}

int Stack::pop()
{
        if (is_empty() == true)
        {
                return 0;
        }
        else
        {
                int output = top->value;
                Node * temp = top;
                top = top->next;
                delete temp;

                return output;
        }
}

void Stack::push(int v)
{
        top = new Node(v, top);
}

Stack::Stack()
{
        top = NULL;
}

Stack::~Stack()
{
        while (top != NULL)
        {
                Node * temp = top;
                top = top->next;
                delete temp;
        }
}

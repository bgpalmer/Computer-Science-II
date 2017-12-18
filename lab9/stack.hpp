#ifndef STACK
#define STACK

#include "menu.hpp"
#include <string>
#include <stack>

using std::string;
using std::stack;

class Stack : public Menu
{
private:
        string user_string;

        void set_user_string();
        void create_palindrome();
public:
        void start();

        Stack();
        ~Stack();
};

#endif

/*************
* brian palmebr
* 10.20.16
* palmebri@oregonstate.edu
* implementation of reverse_string function
******************/

#include "reverse_string.hpp"

void reverse_string(string str)
{
        const char * c_str = str.c_str();
        if (c_str[0] == '\0') // base case
                return;

        else
        {
                string copy, output, character;
                character = c_str[0];
                for (int i = 1; i < str.size(); i++)
                {
                        copy += c_str[i];
                }
                reverse_string(copy);
                cout << character;
        }
}

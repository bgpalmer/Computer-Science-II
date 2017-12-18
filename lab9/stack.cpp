#include "stack.hpp"

void Stack::set_user_string()
{
        cout << "Enter a string that you would like a palindrome made from.\n";
        user_string = facilitateNameInput();
}

void Stack::create_palindrome()
{
        stack <char> reverser;
        const char * c_str = user_string.data();
        int i = 0;
        while (c_str[i] != '\0')
        {
                reverser.push(c_str[i]);
                i++;
        }

        while (reverser.empty() == false)
        {
                user_string += reverser.top();
                reverser.pop();
        }
}

void Stack::start()
{
        set_user_string();
        create_palindrome();
        cout << "PALINDROME: " << user_string << "\n\n";
}

Stack::Stack()
{
        // intentionally blank

}

Stack::~Stack()
{
        // intentionally blank
}

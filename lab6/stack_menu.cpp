#include "stack_menu.hpp"

void Stack_Menu::set_choice()
{
	cout <<"\n\t:::Integer Stack:::\n\n";

	cout << "1) Push\n";
	cout << "2) Pop\n";
	cout << "3) Quit\n";

	choice = facilitateIntInput(1,4);
}

void Stack_Menu::run_chosen_operation()
{
        int input;
	switch (choice)
	{
		case 1:
			if (no_stack() == true)
			{
				stack = new Stack;
			}
			cout << "Enter an integer between 0 - 30000.\n";
			input = facilitateIntInput(0,30001);
			stack->push(input);
			break;
		case 2:
			if (no_stack())
			{
				cout << "No stack has been built yet, use Push function to get started.\n";
			}
			else
			{
				if (stack->is_empty() == true)
					cout << "The queue is empty!" << endl;
				else
					cout << " >>>>> " << stack->pop() << endl;
			}
			break;
	}
}
Stack_Menu::Stack_Menu() : Menu()
{
	stack = NULL;
}

Stack_Menu::~Stack_Menu()
{
	delete stack;
}

bool Stack_Menu::no_stack()
{
        if (stack == NULL)
                return true;
        else
                return false;
}

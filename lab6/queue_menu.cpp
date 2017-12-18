#include "queue_menu.hpp"

void Queue_Menu::set_choice()
{
	cout <<"\n\t:::Integer Queue:::\n\n";

	cout << "1) Push\n";
	cout << "2) Pop\n";
	cout << "3) Quit\n";

	choice = facilitateIntInput(1,4);
}

void Queue_Menu::run_chosen_operation()
{
	int input;
	switch (choice)
	{
		case 1:
			if (no_queue())
			{
				queue = new Queue;
			}
			cout << "Enter an integer between 0 - 30000.\n";
			input = facilitateIntInput(0,30001);
			queue->push(input);
			break;
		case 2:
			if (no_queue())
			{
				cout << "No queue has been built yet, use Push function to get started.\n";
			}
			else
			{
				if (queue->is_empty() == true)
					cout << "The queue is empty!" << endl;
				else
					cout << " >>>>> " << queue->pop() << endl;
			}
			break;
	}
}

Queue_Menu::Queue_Menu() : Menu()
{
        queue = NULL;
}

Queue_Menu::~Queue_Menu()
{
        delete queue;
}

bool Queue_Menu::no_queue()
{
        if (queue == NULL)
                return true;
        else
                return false;
}

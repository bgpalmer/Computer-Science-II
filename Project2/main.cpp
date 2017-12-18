/*********************************************************************
** Program Filename: main.cpp
** Author: brian palmer
** Date: 10.22.16
** Description: Main Program
** Input: "helper_functions.hpp", "item.hpp", "list.hpp"
** Output: zero
*********************************************************************/

#include "helper_functions.hpp"
#include "item.hpp"
#include "list.hpp"
int main()
{
	List grocery;
	int choice;

	cout << "Your grocery list is ready!" << endl;

	do
	{
		choice = integer_menu();
		switch (choice)
		{
			case 1:
				grocery.addItem();
				break;
			case 2:
				grocery.removeItem();
				break;
			case 3:
				grocery.print();
				break;
		}
	} while (choice != 4);
	cout << "Goodbye!" << endl;
	return 0;
}

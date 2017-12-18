#include "main_menu.hpp"

void Main_Menu::set_choice()
{
	cout <<"\n\t:::Main:::\n\n";

	cout << "1) Stack\n";
	cout << "2) Queue\n";
	cout << "3) Quit\n";

	choice = facilitateIntInput(1,4);
}

void Main_Menu::run_chosen_operation()
{
        switch(choice)
        {

                case 1:
                        sub_menu = new Stack_Menu;
                        sub_menu->start();
			delete sub_menu;
			sub_menu = NULL;
                        break;


                case 2:
                        sub_menu = new Queue_Menu;
                        sub_menu->start();
			delete sub_menu;
			sub_menu = NULL;
                        break;

        }
}

Main_Menu::Main_Menu() : Menu()
{
	sub_menu = NULL;
}

Main_Menu::~Main_Menu()
{
        // left blank intentionally
}

#include "menu.hpp"

void Menu::start()
{
        do
        {
                set_choice();
                run_chosen_operation();
        } while (choice != 3);
}

Menu::Menu()
{
        choice = -1;
}

Menu::~Menu()
{
        // intentionally blank
}

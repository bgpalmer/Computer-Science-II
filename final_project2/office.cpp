/*********************************************************************
** Program Filename: office.cpp
** Author: brian palmer
** Date: 12.01.16
** Description: office class definitions
** Input: none
** Output: none
*********************************************************************/

#include "office.hpp"

// office constructor
Office::Office(string n) : Space(n)
{
        desk = new Water;
}

// office destructor
Office::~Office()
{
        if (desk != NULL)
                delete desk;
}

/*********************************************************************
** Function: inspect
** Description: provides user list of objects to inspect and access
to their backpack
** Parameters: Stack pointer
** Pre-Conditions: none
** Post-Conditions: none
** Return: always returns false
*********************************************************************/
bool Office::inspect(Stack * pack)
{
        Item * item = NULL;
        bool done = false;
        do
        {
                cout << "\t:::Inspect Office Space:::\n\n";
                cout << "1) Desk\n";
                cout << "2) Open Backpack\n";
                cout << "3) Exit\n";
                int choice = facilitateIntInput(1,4);
                switch(choice)
                {
                        case 1:
                                // maybe_add_to_bag(check_desk());
                                item = check_desk();
                                inspect_item(item);
                                if (item != NULL && pack->maybe_add(item) == true)
                                        pack->add(get_desk());
                                item = NULL;
                                break;

                        case 2:
                                pack->open();
                                break;

                        case 3:
                                done = true;
                                break;
                }

        }
        while (done == false);
        // return item;
        return false;
}

// desk accessor

Item * Office::check_desk()
{
        return desk;
}

/*********************************************************************
** Function: get desk
** Description: returns pointer to item and sets desk to NULL
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: Item pointer
*********************************************************************/

Item * Office::get_desk()
{
        Item * temp = desk;
        desk = NULL;
        return temp;
}

/*********************************************************************
** Program Filename: bathroom.cpp
** Author: brian palmer
** Date: 11.28.16
** Description: Barbarian function definitions
** Input: none
** Output: none
*********************************************************************/

#include "bathroom.hpp"

/*********************************************************************
** Function: Bathroom constructor
** Description: Bathroom constructor
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Bathroom::Bathroom(string n) : Space(n)
{
        stall = false;
        locker = new Key;
}

/*********************************************************************
** Function: Bathroom Destructor
** Description: Bathroom Destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: if bathroom has item, delete
** Return: none
*********************************************************************/

Bathroom::~Bathroom()
{
        if (locker != NULL)
                delete locker;
}

/*********************************************************************
** Function: check_right_stall
** Description: displays text to screen depending on member
** Parameters: string, int, int, int, int, int, int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Bathroom::check_right_stall()
{
        if (stall == false)
        {
                cout << " *BLEH* Someone didn't flush and left the seat up!\n";
                stall = true;
        }
        else
                cout << "No way I'm going back in there!\n";

}

/*********************************************************************
** Function: check_left_stall
** Description: displays randomly 1 of 5 possible messages to screen
** Parameters: string, int, int, int, int, int, int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Bathroom::check_left_stall()
{
        int r = getRandomPosInt(5);
        switch(r)
        {
                case 0:
                        cout << "\'HEY! I'm IN here!\'\n";
                        break;
                case 1:
                        cout << "\'Don't come in!\'\n";
                        break;
                case 2:
                        cout << "\'OCCUPIED!\'\n";
                        break;
                case 3:
                        cout << "\'Don't you knock?!\'\n";
                        break;
                case 4:
                        cout << "\'Get lost, I'm in here!\'\n";
                        break;
        }
}

/*********************************************************************
** Function: check_locker
** Description: returns the item currently hidden or NULL
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: Item pointer
*********************************************************************/

Item * Bathroom::check_locker()
{
        return locker;
}

/*********************************************************************
** Function: get_locker
** Description: sets locker to NULL and returns pointer to item
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: Item pointer
*********************************************************************/

Item * Bathroom::get_locker()
{
        Item * temp = locker;
        locker = NULL;
        return temp;
}

/*********************************************************************
** Function: inspect
** Description: virtual function with menu to let user choose what to do. always returns false.
** Parameters: Stack pointer
** Pre-Conditions: none
** Post-Conditions: none
** Return: bool
*********************************************************************/

bool Bathroom::inspect(Stack * pack)
{
        Item * item = NULL;
        bool done = false;
        do
        {
                cout << "\t:::Inspecting Bathroom:::\n\n";
                cout << "1) Check the Left Stall\n";
                cout << "2) Check the Right Stall\n";
                cout << "3) Check the Lockers\n";
                cout << "4) Open Backpack\n";
                cout << "5) Exit\n";

                // in case 3, the user first checks to see if an object
                // is hiding an item. If so, the user decides whether to add
                // the item. If they want to add it, the item is retrieved
                // and added to the bag.
                //
                // After checking for the item, there are two pointers pointing
                // to the item. The first pointer is used for inspecting the item.
                // The second is used for transferring the item to the users pack.
                // At the end of the case, the first pointer is NULLED so that only
                // one pointer points to the item.

                int c = facilitateIntInput(1,6);
                switch(c)
                {
                        case 1:
                                check_left_stall();
                                break;
                        case 2:
                                check_right_stall();
                                break;
                        case 3:
                                item = check_locker();
                                inspect_item(item);
                                if (item != NULL && pack->maybe_add(item))
                                        pack->add(get_locker());
                                item = NULL;
                                break;
                        case 4:
                                pack->open();
                                break;
                        case 5:
                                done = true;
                                break;
                }
        }
        while (done == false);
        return false;
}

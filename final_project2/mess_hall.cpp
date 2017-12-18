/*********************************************************************
** Program Filename: mess_hall.cpp
** Author: brian palmer
** Date: 11.28.16
** Description: Mess hall function definitions
** Input: none
** Output: none
*********************************************************************/

#include "mess_hall.hpp"

// constructor

Mess_Hall::Mess_Hall(string n) : Space(n)
{
        table = new Water;
        ceiling_fan = new Water;
        refridgerator = new Water;
        soda_machine = new Soda_Machine;
}

// destructor
// if items have not been collected, they are deleted here (instead of the bag)
Mess_Hall::~Mess_Hall()
{
        if (table != NULL)
                delete table;
        if (ceiling_fan != NULL)
                delete ceiling_fan;
        if (ceiling_fan != NULL)
                delete refridgerator;
        delete soda_machine;
}


// table accessor
Item * Mess_Hall::check_table()
{
        return table;
}

// refridgerator accessor
Item * Mess_Hall::check_refridgerator()
{
        return refridgerator;
}

// ceiling fan accessor
Item * Mess_Hall::check_ceiling_fan()
{
        return ceiling_fan;
}

/*********************************************************************
** Function: check soda machine
** Description: if power switch is true and soda machine is on,
user can get sodas from the machine. If the bag is full or user
does not want, user must throw away soda. There are 3 sodas in the machine
** Parameters: Stack pointer
** Pre-Conditions: none
** Post-Conditions: If sodas are removed, the machine should not add new ones
** Return: none
*********************************************************************/
void Mess_Hall::check_soda_machine(Stack * pack)
{
        if (power_switch == false)
        {
                cout << "The machine is plugged in but won't turn on. Maybe\n";
                cout << "the lights control the plugs? Hate that...\n";
        }
        else if (soda_machine->get_state() == false)
        {
                cout << "The Soda Machine is off and is plugged in.\n";
                cout << "Turn on?\n";
                char c = facilitateYNresponse();
                switch(c)
                {
                        case 'Y':
                                soda_machine->change_state();
                                cout << "The machine is on.\n";
                                break;
                        case 'N':
                                cout << "Machine remains off." << endl;
                                break;
                }
        }
        if (power_switch == true && soda_machine->get_state() && true)
        {
                cout << "The soda machine is rattling! Is it enough to\n";
                cout << "kick out a soda?\n";
                soda_machine->start(pack);
        }
}

/*********************************************************************
** Function: get table
** Description: returns pointer to item and sets table to NULL
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Item * Mess_Hall::get_table()
{
        Item * temp = table;
        table = NULL;
        return temp;
}

/*********************************************************************
** Function: get ceiling fan
** Description: returns pointer to item and sets ceiling fan to NULL
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Item * Mess_Hall::get_ceiling_fan()
{
        Item * temp = ceiling_fan;
        ceiling_fan = NULL;
        return temp;
}

/*********************************************************************
** Function: get table
** Description: returns pointer to item and sets refridgerator to NULL
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Item * Mess_Hall::get_refridgerator()
{
        Item * temp = refridgerator;
        refridgerator = NULL;
        return temp;
}

/*********************************************************************
** Function: inspect
** Description: provides user with list of objects to interact with
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: always returns false
*********************************************************************/

bool Mess_Hall::inspect(Stack * pack)
{
        Item * item = NULL;
        bool done = false;
        do
        {
                cout << "\t:::Mess Hall:::\n\n";
                cout << "1) Ceiling Fan\n";
                cout << "2) Table\n";
                cout << "3) Refridgerator\n";
                cout << "4) Soda Machine\n";
                cout << "5) Open Backpack\n";
                cout << "6) Flip Switch\n";
                cout << "7) Exit\n";
                int choice = facilitateIntInput(1,8);

                // in case 1-3, the user first checks to see if an object
                // is hiding an item. If so, the user decides whether to add
                // the item. If they want to add it, the item is retrieved
                // and added to the bag.
                //
                // After checking for the item, there are two pointers pointing
                // to the item. The first pointer is used for inspecting the item.
                // The second is used for transferring the item to the users pack.
                // At the end of the case, the first pointer is NULLED so that only
                // one pointer points to the item.
                switch(choice)
                {
                        case 1:
                                item = check_ceiling_fan();
                                inspect_item(item);
                                if (item != NULL && pack->maybe_add(item))
                                        pack->add(get_ceiling_fan());
                                item = NULL;
                                break;
                        case 2:
                                item = check_table();
                                inspect_item(item);
                                if (item != NULL && pack->maybe_add(item))
                                        pack->add(get_table());
                                item = NULL;
                                break;
                        case 3:
                                item = check_refridgerator();
                                inspect_item(item);
                                if (item != NULL && pack->maybe_add(item))
                                        pack->add(get_refridgerator());
                                item = NULL;
                                break;
                        case 4:
                                check_soda_machine(pack);
                                item = NULL;
                                break;
                        case 5:
                                pack->open();
                                break;
                        case 6:
                                flip_switch();
                                break;
                        case 7:
                                done = true;
                                break;
                }

        }
        while (done == false);
        // return item;
        return false;
}

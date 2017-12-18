/*********************************************************************
** Program Filename: loading_bay.cpp
** Author: brian palmer
** Date: 11.30.16
** Description: Conveyor_Belt function definitions
** Input: none
** Output: none
*********************************************************************/

#include "loading_bay.hpp"

// constructor
Loading_Bay::Loading_Bay(string n) : Space(n)
{
        door = false;
        //truck = new Truck;
}

// destructor
Loading_Bay::~Loading_Bay()
{
        // Intentionally blank
}

/*********************************************************************
** Function: inspect
** Description: inspect
** Parameters: Stack pointer
** Pre-Conditions: users curr space member should be assigned to loading bay
** Post-Conditions: none
** Return: True or False; true if user turns on car with key and drives away.
This ends the game
*********************************************************************/

bool Loading_Bay::inspect(Stack * pack)
{
        bool gameover = false;
        bool done = false;
        do
        {
                cout << "\t:::Inspecting Loading Bay:::\n\n";
                cout << "1) Check Truck\n";
                cout << "2) Check Door\n";
                cout << "3) Exit\n";
                int i = facilitateIntInput(1,4);
                switch(i)
                {
                        case 1:
                                gameover = check_truck(pack);
                                break;
                        case 2:
                                check_door();
                                break;
                        case 3:
                                done = true;
                                break;
                }
        }
        while (done == false && gameover == false);
        return gameover;
}

/*********************************************************************
** Function: check door
** Description: user checks whether door is open or not, and can open or close it
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Loading_Bay::check_door()
{
        if (door == false)
        {
                cout << "The garage door is closed. Open it?\n";
                char c = facilitateYNresponse();
                switch(c)
                {
                        case 'Y':
                                door = true;
                                cout << "The garage door is open.\n";
                                break;
                        case 'N':
                                cout << "The garage door remains closed\n";\
                                break;
                }
        }
        else
        {
                cout << "The garage door is open. Close it?\n";
                char c = facilitateYNresponse();
                switch(c)
                {
                        case 'Y':
                                door = false;
                                cout << "The garage door is closed.\n";
                                break;
                        case 'N':
                                cout << "The garage door remains open\n";\
                                break;
                }
        }


}

/*********************************************************************
** Function: is_door_open
** Description: essentially an accessor for the door member
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: bool
*********************************************************************/

bool Loading_Bay::is_door_open()
{
        if (door == false)
                return false;
        else
                return true;
}

/*********************************************************************
** Function: check truck
** Description: if user has the key item and the door is down, and the user starts
the car, the user wins the game and the function passes true back. If those reqs
are not met, passes back false
** Parameters: Stack pointer
** Pre-Conditions: none
** Post-Conditions: if user meets above conditions, game should end and user should win
** Return: bool
*********************************************************************/

bool Loading_Bay::check_truck(Stack * pack)
{
        bool gameover = false;
        cout << "Turn the car on?\n";
        char c = facilitateYNresponse();
        switch(c)
        {
                case 'Y':
                        if (pack->find("Key") == false)
                        {
                                cout << "\n * I need a \'Key\'! *\n\n";
                        }
                        else if (is_door_open() == false)
                        {
                                cout << "The car is on but the garage door is down, open\n";
                                cout << "the garage door first\n";
                        }
                        else
                        {
                                cout << "You turned the car on and drove away!\n";
                                gameover = true;
                        }
                        break;
                case 'N':
                        cout << "Never mind then!" << endl;
                        break;
        }
        return gameover;
}

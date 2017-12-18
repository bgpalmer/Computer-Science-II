/*********************************************************************
** Program Filename: floor.cpp
** Author: brian palmer
** Date: 11.28.16
** Description: floor function definitions
** Input: none
** Output: none
*********************************************************************/

#include "floor.hpp"

/*********************************************************************
** Function: floor
** Description: constructor
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Floor::Floor(string n) : Space(n)
{
        conveyor_belt = new Conveyor_Belt;
}

/*********************************************************************
** Function: floor destructor
** Description: floor destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Floor::~Floor()
{
        delete conveyor_belt;
}

/*********************************************************************
** Function: inspect
** Description: provides user with objects to interact with
** Parameters: item pointer
** Pre-Conditions: user should be in the floor
** Post-Conditions: none
** Return: none
*********************************************************************/

bool Floor::inspect(Stack * pack)
{
        bool done = false;
        do
        {
                cout << "\t:::Inspect Floor:::\n\n";
                cout << "1) Check \'Circular\' Conveyor Belt\n";
                cout << "2) Flip Lightswitch\n";
                cout << "3) Open Backpack\n";
                cout << "4) Exit\n";
                int c = facilitateIntInput(1,5);
                switch(c)
                {
                        case 1:
                                conveyor_belt->start(pack);
                                break;
                        case 2:
                                flip_switch();
                                break;
                        case 3:
                                pack->open();
                                break;
                        case 4:
                                done = true;
                                break;
                }
        }
        while (done == false);

        return false;
}

/*********************************************************************
** Function: check_conveyor_belt
** Description: starts conveyor_belt options
** Parameters: Stack pointer
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Floor::check_conveyor_belt(Stack * pack)
{
        conveyor_belt->start(pack);
}

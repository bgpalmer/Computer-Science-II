/*********************************************************************
** Program Filename: mess_hall.hpp
** Author: brian palmer
** Date: 11.30.16
** Description: Conveyor_Belt function definitions
** Input: none
** Output: none
*********************************************************************/

#ifndef MESS_HALL_HPP
#define MESS_HALL_HPP

#include "space.hpp"
#include "stack.hpp"
// #include "battery.hpp"
#include "soda_machine.hpp"
#include "water.hpp"

class Item;

class Mess_Hall : public Space
{
private:
        Item * table;
        Item * ceiling_fan;
        Item * refridgerator;
        Machine * soda_machine;

public:
        Mess_Hall(string n = "Mess Hall");
        virtual ~Mess_Hall();

        Item * check_table();
        Item * check_ceiling_fan();
        Item * check_refridgerator();
        void check_soda_machine(Stack *);

        Item * get_table();
        Item * get_ceiling_fan();
        Item * get_refridgerator();


        virtual bool inspect(Stack *);


};

#endif

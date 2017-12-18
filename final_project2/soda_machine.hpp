/*********************************************************************
** Program Filename: soda_machine.hpp
** Author: brian palmer
** Date: 12.01.16
** Description: sodad machine header
** Input: none
** Output: none
*********************************************************************/

#ifndef SODA_MACHINE_HPP
#define SODA_MACHINE_HPP

#include "machine.hpp"
#include "queue.hpp"
#include "soda.hpp"
#include "stack.hpp"

class Soda_Machine : public Machine
{
private:
        Queue * contents;
public:
        Soda_Machine(string t = "Soda Machine");
        virtual ~Soda_Machine();
        virtual void start(Stack *);

};

#endif

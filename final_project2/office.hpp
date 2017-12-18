/*********************************************************************
** Program Filename: office.hpp
** Author: brian palmer
** Date: 12.01.16
** Description: office class template
** Input: none
** Output: none
*********************************************************************/

#ifndef OFFICE_HPP
#define OFFICE_HPP

#include "space.hpp"
#include "water.hpp"

class Office : public Space
{
private:
        Item * desk;
        Item * check_desk();
        Item * get_desk();
public:
        virtual bool inspect(Stack *);

        Office(string n = "Office");
        virtual ~Office();
};

#endif

/*********************************************************************
** Program Filename: loading_bay.hpp
** Author: brian palmer
** Date: 11.28.16
** Description: Loading bay class template
** Input: none
** Output: none
*********************************************************************/

#ifndef LOADING_BAY
#define LOADING_BAY

#include "space.hpp"
// #include "truck.hpp"
#include "stack.hpp"

class Loading_Bay : public Space
{
private:
        bool door;

public:
        Loading_Bay(string n = "Loading Bay");
        ~Loading_Bay();
        bool is_door_open();
        void check_door();
        bool check_truck (Stack *);

        virtual bool inspect(Stack *);

};

#endif

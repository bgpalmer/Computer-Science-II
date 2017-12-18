#include "lake.hpp"

Lake::Lake(string l) : Space(l)
{
        // intentionally blank
}

Lake::~Lake()
{
        // intentionally blank
}

void Lake::set_choice()
{
        cout << "\t:::LAKE:::\n\n";
        cout << "1) Fish\n";
        cout << "2) Quit\n";
        choice = facilitateIntInput(1,4);
}

Item * Lake::run_operation()
{
        Item * thing = NULL;
        switch(choice)
        {
                case 1:
                        //thing = fish();
                        break;
                case 2:
                        light_campfire();
                        break;
        }
        return thing;
}

bool Lake::is_frozen()
{
        if (frozen == true)
                return true;
        else
                return false;
}

// Item * Lake::fish()
// {
//         return new Fish;
// }

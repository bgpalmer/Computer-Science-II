#include "field.hpp"

Field::Field(string f) : Space(f)
{
        garden = NULL;
}

Field::~Field()
{
        delete garden;
}

bool Field::seed()
{
        if (garden->plant(new Plant) == true)
                return true;
        else
                return false;
}

Plant * Field::harvest()
{
        return garden->remove();
}

void Field::set_choice()
{
        cout << "\t:::GARDEN:::\n\n";
        cout << "1) Plant\n";
        cout << "2) Harvest\n";
        cout << "3) Quit\n";
        choice = facilitateIntInput(1,4);
}

Item * Field::run_operation()
{
        Item * thing = NULL;
        switch(choice)
        {
                case 1:
                        seed();
                        break;
                case 2:
                        thing = harvest();
                        break;
        }
        return thing;
}

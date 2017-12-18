/*********************************************************************
** Program Filename: space.cpp
** Author: brian palmer
** Date: 12.01.16
** Description: space class template
** Input: none
** Output: none
*********************************************************************/

#include "space.hpp"

// Space constructor

Space::Space(string t)
{
        type = t;
        power_switch = false;

        up = NULL;
        down = NULL;
        left = NULL;
        right = NULL;
}

// Space destructor

Space::~Space()
{
        up = NULL;
        down = NULL;
        left = NULL;
        right = NULL;
}

/*********************************************************************
** Function: inspect_item
** Description: tells user what item they found
** Parameters: Item pointer
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Space::inspect_item(Item * obj)
{
        if (obj == NULL)
                cout << "There was nothing there!" << endl;
        else
                cout << "You found a " << obj->get_type() << endl;
}

/*********************************************************************
** Function: flip switch
** Description: switches bool value of power_switch
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Space::flip_switch()
{
        if (power_switch == true)
        {
                power_switch = false;
                cout << "Lightswitch is now OFF\n";
        }
        else
        {
                power_switch = true;
                cout << "Lightswitch is now ON.\n";
        }
}

// type accessor
string Space::get_type()
{
        return type;
}

// up accessor
Space * Space::get_up()
{
        return up;
}

// down accessor
Space * Space::get_down()
{
        return down;
}

// left accessor
Space * Space::get_left()
{
        return left;
}

// right accessor
Space * Space::get_right()
{
        return right;
}

// right mutator
void Space::set_right(Space * r)
{
        right = r;
}

// left mutator
void Space::set_left(Space * l)
{
        left = l;
}

// up mutator
void Space::set_up(Space * u)
{
        up = u;
}

// down mutator
void Space::set_down(Space * d)
{
        down = d;
}

/*********************************************************************
** Function: set orthogs
** Description: takes space triple pointer and sets appropriate up,down,left,right
members for a particular space
** Parameters: Space triple pointer, int (outer loop), int (inner loop)
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void Space::set_orthogs(Space *** s, int r, int c)
{
        if (r - 1 < 0)
                s[r][c]->up = NULL;
        else
                s[r][c]->up = s[r-1][c];
        if (r + 1 >= 2)
                s[r][c]->down = NULL;
        else
                s[r][c]->down = s[r+1][c];
        if (c - 1 < 0)
                s[r][c]->left = NULL;
        else
                s[r][c]->left = s[r][c-1];
        if (c + 1 >= 3)
                s[r][c]->right = NULL;
        else
                s[r][c]->right = s[r][c+1];

        // cout << "UP: " << s[r][c]->up << "\n";
        // cout << "DOWN: " << s[r][c]->down << "\n";
        // cout << "RIGHT: " << s[r][c]->right << "\n";
        // cout << "LEFT: " << s[r][c]->left << "\n\n";
}

/*********************************************************************
** Program Filename: search.cpp
** Author: Brian Palmer
** Date: 11.12.16
** Description: search functions implementations
** Input: None
** Output: None
*********************************************************************/

#include "search.hpp"

/*********************************************************************
** Function: binary search
** Description: performs a binary search on a list of integers
** Parameters: integer pointer, int, int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

int binary_search(int * data, int size, int value)
{
        int     first = 0,
                last = size,
                middle = 0,
                position = -1;

        bool    found = false;

        while (found == false && first <= last)
        {
                middle = (first + last)/2;
                if (data[middle] == value)
                {
                        found = true;
                        position = middle + 1;
                }
                else if (data[middle] > value)
                        last = middle - 1;
                else
                        first = middle + 1;
        }
        return position;
}

/*********************************************************************
** Function: Linear_Search
** Description: performs linear search on list of integers
** Parameters: integer pointer, int, int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

int linear_search(int * data, int size, int value)
{
        int index = 0;
        int position = -1;
        bool found = false;

        while (index < size && found == false)
        {
                if (value == data[index])
                {
                        found = true;
                        position = index + 1;
                }
                index++;
        }
        return position;
}

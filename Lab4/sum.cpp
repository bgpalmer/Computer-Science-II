/*************
* brian palmer
* 10.20.16
* palmebri@oregonstate.edu
* sum implementation
**************/

#include "sum.hpp"

int sum(int arr[], int size)
{
        if (0 >= size) // base case
                return arr[size];
        else
        {
                int s = sum(arr, size - 1) + arr[size];
                return s;
        }
}

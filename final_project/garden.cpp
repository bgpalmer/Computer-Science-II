/*****************
* brian palmer
* 11.29.16
* palmebri@oregonstate.edu
******************/

#include "garden.hpp"

Garden::Garden()
{
        size = 0;
        for (int i = 0; i < 10; i++)
                garden[i] = NULL;
}

Garden::~Garden()
{
        for (int i = 0; i < size; i++)
        {
                delete garden[i];
                garden[i] = NULL;
        }
}

bool Garden::plant(Plant * seed)
{
        if (size == 10)
                return false;
        else
        {
                garden[size] = seed;
                size++;
                return true;
        }
}

Plant * Garden::remove()
{
        if (size == 0)
                return NULL;
        else
        {
                Plant * front = garden[0];
                garden[0] = garden[1];
                for (int i = 1; i < size - 1; i++)
                        garden[i] = garden[i+1];
                size--;
                garden[size+1] = NULL;
                return front;
        }
}

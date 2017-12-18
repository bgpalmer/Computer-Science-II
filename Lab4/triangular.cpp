/**************
* brian palmer
* 10.20.16
* palmebri@oregonstate.edu
* triangular funciton implementation
****************/

#include "triangular.hpp"

int triangular(int N)
{
        if (N <= 1)
                return 1;
        else
                return N + triangular(N - 1);
}

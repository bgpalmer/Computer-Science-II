#include "pack.hpp"

Pack::Pack()
{
        size = 0;
        weight = 0.00;
        top = NULL;
}

Pack::~Pack()
{
        delete top;
}

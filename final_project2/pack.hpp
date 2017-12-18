#ifndef PACK_HPP
#define PACK_HPP

#include "stack.hpp"

class Pack
{
private:
        int size;
        float weight;
        Stack * top;
public:
        Pack();
        ~Pack();
};

#endif

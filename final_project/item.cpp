#include "item.hpp"

Item::Item(string n)
{
        name = n;
}

Item::~Item()
{
        // intentionally blank
}

string Item::get_name()
{
        return name;
}

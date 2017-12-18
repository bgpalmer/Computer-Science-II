#include "campfire.hpp"

Campfire::Campfire()
{
        lit = false;
}

Campfire::~Campfire()
{
        // intentionally blank
}

bool Campfire::is_lit()
{
        return lit;
}

bool Campfire::light()
{
        if (is_lit())
                return false;
        else
                return true;
}

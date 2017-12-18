#ifndef LAKE_HPP
#define LAKE_HPP
#include "space.hpp"
#include "fish.hpp"

class Lake : public Space
{
private:
        //Item * fish();
        bool frozen;

public:
        virtual void set_choice();
        virtual Item * run_operation();

        bool is_frozen();
        // Lake(string l = "Lake", Space * a = NULL, Space * b = NULL, Space * c = NULL, Space * d = NULL);
        Lake(string l = "Lake");
        ~Lake();
};

#endif

#ifndef FIELD_HPP
#define FIELD_HPP
#include "space.hpp"
#include "garden.hpp"

class Field : public Space
{
private:
        bool seed();
        Plant * harvest();
        Garden * garden;

public:
        virtual void set_choice();
        virtual Item * run_operation();
        //Field(string f = "Garden", Space * a = NULL, Space * b = NULL, Space * c = NULL , Space * d = NULL);
        Field(string f = "Garden");
        ~Field();
};

#endif

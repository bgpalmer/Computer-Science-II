#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
using std::string;

class Item
{
private:
        string name;
public:
        string get_name();

        Item(string m);
        ~Item();
};

#endif

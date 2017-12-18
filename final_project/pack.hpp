#ifndef PACK_HPP
#define PACK_HPP
#include <string>
#include <map>
#include <iostream>
#include <iomanip>

using std::string;
using std::map;
using std::pair;
using std::cout;
using std::make_pair;
using std::setw;


class Item;

class Pack
{
private:
        const int MAX_NUM_ITEMS = 10;
        map<string, int> items;
        string type;

public:
        bool is_full();
        Pack();
        ~Pack();

        bool add_item(string, int);
        bool remove_item(string, int);
        void print_contents();
        string get_type();
};

#endif

#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <queue>
#include <iostream>
#include <fstream>
#include "menu_functions.hpp"
#include "menu.hpp"

using std::queue;
using std::cout;

class Deque_Menu : public Menu
{
private:
        int round_counter;
        int num_rounds;
        int chance_added;
        int chance_removed;
        int run_ttl;

        queue<int> buffer;

        void set_num_rounds();
        void set_chance_added();
        void set_chance_removed();

        void get_average();
        void maybe_add_num();
        void maybe_remove_num();
        //void write();

public:
        void start();

        Deque_Menu();
        ~Deque_Menu();
};

#endif

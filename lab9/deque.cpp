#include "deque.hpp"

Deque_Menu::Deque_Menu()
{
        round_counter = 1;
        num_rounds = 1;
        chance_added = -1;
        chance_removed = -1;
        run_ttl = 0;
}

Deque_Menu::~Deque_Menu()
{
        // left blank intentionally
}

void Deque_Menu::start()
{
        set_num_rounds();
        set_chance_added();
        set_chance_removed();
        do
        {
                maybe_add_num();
                maybe_remove_num();
                get_average();
                round_counter++;
        }
        while (round_counter <= num_rounds);
}

void Deque_Menu::set_num_rounds()
{
        cout << "How many rounds should this simulation run for? (5 - 100)\n";
        num_rounds = facilitateIntInput(5, 101);
}

void Deque_Menu::set_chance_added()
{
        cout << "What is the chance a random integer will be added to the buffer?\n";
        chance_added = facilitateIntInput(0,101);
}

void Deque_Menu::set_chance_removed()
{
        cout << "What is the chance a random integer will be removed from the buffer?\n";
        chance_removed = facilitateIntInput(0,101);
}

void Deque_Menu::maybe_add_num()
{
        int random = getRandomPosInt(101);
        if (random <= chance_added)
        {
                int rdm = getRandomPosInt(101);
                buffer.push_back(rdm);
        }
}

void Deque_Menu::maybe_remove_num()
{
        int random = getRandomPosInt(101);
        if (random <= chance_removed)
        {
                if (buffer.size() != 0)
                        buffer.pop_back();
        }
}

void Deque_Menu::get_average()
{
        run_ttl += buffer.size();
        cout << "Round " << round_counter << ":\n";
        cout << "Current size: " << buffer.size() << "\n";
        cout << "Average size: " << (double)run_ttl/round_counter << "\n";
        cout << "Currently in buffer: ";
        if (buffer.size() == 0)
                cout << "*** EMPTY ***";
        else
        {
                for (deque<int>::iterator iter = buffer.begin(); iter != buffer.end(); iter++)
                        cout << *iter << " ";
        }
        cout << "\n\n";
}

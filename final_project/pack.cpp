#include "pack.hpp"

Pack::Pack()
{
        // intentionally blank
}

Pack::~Pack()
{
        // intentionally blank
}

bool Pack::add_item(string name, int num)
{
        if (is_full() == false)
        {
                pair <map<string,int>::iterator,bool> iter;
                pair <string,int> pr;
                pr = make_pair(name,num);
                iter = items.insert(pr);
                if (iter.second == false)
                        (*(iter.first)).second += num;
                return true;
        }
        else
                return false;
}

bool Pack::remove_item(string name, int num)
{
        if (items.empty() == true)
                return false;
        else
        {
                map<string,int>::iterator iter;
                iter = items.find(name);
                if (iter == items.end())
                        return false;
                else
                {
                        iter->second -= num;
                        if (iter->second <= 0)
                                items.erase(name);
                        return true;
                }
        }
}

void Pack::print_contents()
{
        if (items.empty() == false)
        {
                cout << "\t:::BAG:::\n\n";
                cout << setw(10) << "Item" << setw(10) << "Qty" << "\n";
                cout << "===============================\n\n";
                for (map<string,int>::iterator i = items.begin(); i != items.end(); i++)
                {
                        cout << setw(10) << i->first;
                        cout << setw(10) << i->second;
                        cout << "\n";
                }
        }
        else
                cout << "The Pack is empty!\n\n";
}

bool Pack::is_full()
{
        if (items.size() > MAX_NUM_ITEMS)
                return true;
        else
                return false;
}

string Pack::get_type()
{
        return type;
}

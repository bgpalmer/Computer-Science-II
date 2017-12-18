/*********************************************************************
** Program Filename: selection_sort.hpp
** Author: Brian Palmer
** Date: 11.12.16
** Description: selection sort implementation
** Input: None
** Output: None
*********************************************************************/

#include "selection_sort.hpp"

/*********************************************************************
** Function:  sort
** Description: Reads a file with a list of integers, sorts the intgers (calls
the Selection sort function), and then writes the sorted and unsorted list to
a user-named textfile
** Parameters: integer pointer, integer
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void sort(int * data, int size)
{


        // First write the numbers passed in before sorting

        ofstream out;
        string name;

        cout << "What would you like your file to be called?" << endl;
        cin >> name;

        cout << "\n\nwriting....";

        out.open(name.c_str());
        out << "Pre-Sorted: \n\n\n";
        for (int i = 0; i < size; i++)
        {
                if (i % 20 == 0)
                        out << "\n";
                out << data[i] << " ";
        }


        // Sorts and writes to file

        selection_sort(data, size);

        // write
        out << "\n\n\n\n\nPost-Sorted:\n\n\n";
        for (int i = 0; i < size; i++)
        {
                if (i % 20 == 0)
                        out << "\n";
                out << data[i] << " ";
        }

        cout << "..done!\n";

}

/*********************************************************************
** Function: selection sort
** Description: performs a selection sort on a list of data
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void selection_sort(int * data, int size)
{
        int     start_scan,
                min_index,
                min_value;

        for (start_scan = 0; start_scan < size; start_scan++)
        {
                min_index = start_scan;
                min_value = data[start_scan];

                for (int index = start_scan + 1; index < size; index++)
                {
                        if (data[index] < min_value)
                        {
                                min_value = data[index];
                                min_index = index;
                        }
                }
                data[min_index] = data[start_scan];
                data[start_scan] = min_value;

        }
}

/*********************************************************************
** Function: display_sort
** Description: displays the contents of an integer list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void display_sort(int * data, int size)
{
        cout << "\n\nDisplaying sorted:\n\n";

        for (int i = 0; i < size; i++)
        {
                cout << data[i] << " ";
        }
        cout << "\n";
}

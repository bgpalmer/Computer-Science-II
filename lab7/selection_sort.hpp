/*********************************************************************
** Program Filename: selection.hpp
** Author: Brian Palmer
** Date: 11.12.16
** Description: Binary Menu submenu
** Input: None
** Output: None
*********************************************************************/

#ifndef SELECTION
#define SELECTION

#include <fstream>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;

void sort(int * data, int size);
void selection_sort(int * data, int size);
void display_sort(int * data, int size);

#endif

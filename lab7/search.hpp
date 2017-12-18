/*********************************************************************
** Program Filename: search.hpp
** Author: Brian Palmer
** Date: 11.12.16
** Description: Search function declarations
** Input: None
** Output: None
*********************************************************************/

#ifndef SEARCH
#define SEARCH

#include <iostream>
#include <string>
#include <fstream>
using std::ifstream;
using std::string;
using std::cout;


int linear_search(int * data, int size, int value);
int binary_search(int * data, int size, int value);

// helpers

string get_textfile_data(ifstream &in, string filename);

#endif

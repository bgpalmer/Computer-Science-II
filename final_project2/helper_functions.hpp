/*********************************************************************
** Program Filename: helper_functions.hpp
** Author: brian palmer
** Date: 10.22.16
** Description: helper_functions declarations
** Input: iostream, iomanip, cstdlib, string, "validation.hpp"
** Output: none
*********************************************************************/

#ifndef _HELP_
#define _HELP_

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "validation.hpp"

using std::string;
using std::atoi;
using std::atof;
using std::cin;
using std::cout;
using std::endl;
using std::setw;

string facilitateValidUnitInput();
char facilitateYNresponse();
int facilitateIntInput(int start, int end);
double facilitateMoneyInput(double min, double max);
string facilitateNameInput(string);
int integer_menu();

#endif

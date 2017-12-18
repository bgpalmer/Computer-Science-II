/*****************
* brian palmer
* 10.12.16
* palmebri@oregonstate.edu
* menu helper functions
*****************/

#ifndef _MENU_
#define _MENU_

#include <iostream>
#include "validation.hpp"

using std::cin;
using std::cout;
using std::endl;

char facilitateYNresponse();
int facilitateIntInput(int start, int end);
double facilitateMoneyInput(int min, int max);
string facilitateNameInput();
string sumFunctionHelper(); // slight change of facilitateNameInput()
int integer_menu();

#endif

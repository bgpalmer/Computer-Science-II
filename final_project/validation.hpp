/*********************************************************************
** Program Filename: validation.hpp
** Author: brian palmer
** Date: 10.22.16
** Description: validation functions declarations
** Input: iostream, cstdlib, ctime, string, iomanip
** Output: none
*********************************************************************/

#ifndef _VALID_
#define _VALID_
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
using std::string;
using std::srand;
using std::rand;
using std::time;
using std::cout;
using std::endl;

bool validateYNresponse(string);
bool checkIfInt(string);
bool checkIfIntInRange(int value, int begin, int end);
bool checkIfIntAndInRange(string, int, int);

char convertYNtoUpper(string);

int getRandomPosInt();
int getRandomPosInt(int);

bool cmpString(string, string);
bool cmpInteger(int, int);
bool cmpDouble(double, double);
bool cmpCharArray(const char *, const char *);


bool checkCharacters(const char *, const char *);

string capitalize(string);

#endif

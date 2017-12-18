/***********
* Brian Palmer
* 10.3.16
* palmebri@oregonstate.edu
* This file declares all of the validation functions
***************/

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

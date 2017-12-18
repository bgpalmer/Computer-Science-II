/***********
* Brian Palmer
* 10.3.16
* palmebri@oregonstate.edu
* This file declares all of the validation functions
***************/

#ifndef _VALID_
#define _VALID_

#include <cstdlib>
#include <ctime>
#include <string>
using std::string;
using std::srand;
using std::rand;
using std::time;


bool validateYNresponse(string);
bool checkIfInt(string);
bool checkIfIntInRange(int value, int begin, int end);
bool checkIfIntAndInRange(string, int, int);

char convertYNtoUpper(string);

int getRandomPosInt();
int getRandomPosInt(int);


#endif

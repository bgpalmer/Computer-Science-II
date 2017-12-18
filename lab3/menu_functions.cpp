/***************
* brian palmer
* 10.12.16
* palmebri@oregonstate.edu
* menu function implementations
******************/

#include "menu_functions.hpp"

/******************
* facilitateYNresponse
* preReq: none
* parameters: none
* post: returns uppercase Y or N
* description: uses validation functions to ensure user enters Y/y or N/n
*********************/

char facilitateYNresponse()
{
	bool validResp;
	string input;
	do
        {
                cout << "[Y or N]: ";
                cin >> input;
                validResp = validateYNresponse(input);
                if (!validResp)
                {
                        cout << "Can only accept a Y or N answer, please try again" << endl;
                }
        } while (!validResp);

	char YN = convertYNtoUpper(input);

	return YN;

}


/*******************
* facilitateIntInput
* preReq: none
* parameters: none
* post: returns integer
* description: uses validation functions to ensure user enters integer
******************/

int facilitateIntInput(int start, int end)
{
	string input;
	bool checkIntAndInRange;
	do
	{
		cout << " >> ";
		cin >> input;
        	checkIntAndInRange = checkIfIntAndInRange(input, start, end);
		if (!checkIntAndInRange)
		{
			cout << "Bad Input, please try again. Must be an integer between " << start << "-" << end-1 << "." << endl;
		}
        } while (!checkIntAndInRange);

        int integer = atoi(input.c_str());
	return integer;
}


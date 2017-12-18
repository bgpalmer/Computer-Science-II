/*********************************************************************
** Program Filename: helper_functions.cpp
** Author: brian palmer
** Date: 10.22.16
** Description: helper_functions implementations
** Input: "helper_functions.hpp"
** Output: none
*********************************************************************/

#include "helper_functions.hpp"

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
                std::getline(cin, input);
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
		std::getline(cin, input);
        	checkIntAndInRange = checkIfIntAndInRange(input, start, end);
		if (!checkIntAndInRange)
		{
			cout << "Bad Input, please try again. Must be an integer between " << start << " - " << end - 1 << "." << endl;
		}
        } while (!checkIntAndInRange);

        int integer = atoi(input.c_str());
	return integer;
}




/*************
* facilitateMoneyInput
* preReq: none
* parameters: int, int
* post: none
* description: faciliates money input
***************/

double facilitateMoneyInput(double min, double max)
{
	double output;
	string v_chars, input;
	v_chars += "1234567890.";
	const char * v_chars_ptr = v_chars.c_str();
	bool checkChars = false, checkRange = false, period = false, checkDecimals = false;
	int places = 0;
	do
	{
		places = 0;
		period = false;
		checkRange = false;
		checkChars = false;
		checkDecimals = true;
		cout << " >> $";
		std::getline(cin, input);
		const char * c_input = input.c_str();
		/* checking for valid characters */
		checkChars = checkCharacters(c_input, v_chars_ptr);

		if (checkChars)
		{
			/* checking range */
			output = atof(input.c_str());
			if (output >= min && output < max)
			{
				checkRange = true;
				/* checking decimal positions */
				for (int i = 0; c_input[i] != '\0'; i++)
				{
					if(c_input[i] == '.' && !period)
					{
						checkDecimals = false;
						/* checking number of decimal places */
						for (int j = i + 1; c_input[j] != '\0'; j++)
							places++;

						/* checking to be sure only one decimal was added */
						if (places < 3)
						{
							int k = 0;
							for (int j = i + 1; c_input[j] != '.' && k < places; k++, j++)
							{
								k++;
								j++;
							}
							if (k == places)
								checkDecimals = true;
						}
						period = true;
					}
				}
				if (!checkDecimals)
					cout << "Bad input! (NNN.NN)" << endl;
			}
			else
				cout << "Out of Range! (" << min <<"," << max-.01 << ")" << endl;
		}
		else
		{
			cout << "\nBad input. Please enter try again\n";
		}
	} while (!checkChars || !checkRange || !checkDecimals);

	return output;
}


/*************
* facilitate string input
* preReq: none
* parameters: none
* post: none
* description: removes all special characters from string
***************/

string facilitateNameInput()
{
	string v_letters;
	v_letters += " ";
	v_letters += "abcdefghijklmnopqrstuvwxyz";
	v_letters += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	v_letters += "\0";
	const char * v_letters_arr = v_letters.c_str();

	string input;
	bool check = false;
	do
	{
		cout << " >> ";
		std::getline(cin, input);
		const char * inp = input.c_str();
		check = checkCharacters(inp, v_letters_arr);
		if (!check)
		{
			cout << "\nThere was an invalid character!\n";
			cout << "Valid Characters: \n -> a - z \n -> <space>" << endl;
			cout << endl;
		}
	} while (!check);
	input = capitalize(input);

	return input;
}

string facilitateValidUnitInput()
{
	const int SIZE = 4;
	string units[SIZE] = {"CAN", "OUNCE", "POUND", "BOX"};

	string input;
	bool check = false;

	cout <<"\nWhat are the items units?" << endl;
	do
	{
		cout << "Available units: CAN, OUNCE, POUND, BOX" << endl;
		cout << " >> ";
		std::getline(cin, input);
		input = capitalize(input);
		for (int i = 0; i < SIZE; i++)
		{
			if (input == units[i])
				check = true;
		}
		if (!check)
		{
			cout << "\nBad input, please try again.\n" << endl;
		}
	} while (!check);

	return input;
}

/****************
* integer_menu
* menu function
**************/

int integer_menu()
{
	cout << "\n	::MENU::\n\n";

	cout << "1) Add Item\n";
	cout << "2) Remove Item\n";
	cout << "3) Print List\n";
	cout << "4) Quit\n";

	return facilitateIntInput(1,5);
}

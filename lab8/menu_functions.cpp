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
/*
double facilitateMoneyInput(int min, int max)
{
	string v_chars, input;
	v_chars += "1234567890.";
	const char * v_chars_ptr = v_chars.c_str();

	bool check;
	cout << " >> $";
	do
	{
		std::getline(cin, input);
		const char * c_input = input.c_str();
		check = checkCharacters(c_input, v_chars_ptr);
		if (!check)
		{
			cout << "\nBad input. Please enter try again\n";
		}
	} while (!check);
	return stod(input);
}
*/

/*************
* facilitate string input
* preReq: none
* parameters: none
* post: none
* description: removes all special characters from string
***************/

char facilitateCharacterInput()
{
	string v_letters;
	v_letters += "ABCDX";
	v_letters += "abcdx";
	//v_letters += " ";
	//v_letters += "abcdefghijklmnopqrstuvwxyz";
	//v_letters += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//v_letters += "\0";
	//v_letters += "~`!@#$%^&*()_+-={}[]|\\:;\"\'?/>.<,";
	//v_letters += "1234567890";
	const char * v_letters_arr = v_letters.c_str();

	string input;
	const char * inp = NULL;
	bool check = false;
	do
	{
		cout << "Choice: ";
		std::getline(cin, input);
		inp = input.c_str();
		check = checkCharacters(inp, v_letters_arr);

		if (check == false || input.size() > 1)
			cout << "Invalid Entry, please try again.\n";

	}
	while (check == false || input.size() > 1);
	input = capitalize(input);
	const char * char_arr = input.data();

	return char_arr[0];
}

string sumFunctionHelper()
{
	string v_letters;
	v_letters += " ";
	//v_letters += "abcdefghijklmnopqrstuvwxyz";
	//v_letters += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//v_letters += "\0";
	//v_letters += "~`!@#$%^&*()_+-={}[]|\\:;\"\'?/>.<,";
	v_letters += "1234567890";
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
			cout << "Valid Characters: \n -> 1 - 9 \n -> <enter>" << endl;
			cout << endl;
		}
	} while (!check);
//	input = capitalize(input);

	return input;
}

/****************
* integer_menu
* menu function
**************/

int integer_menu()
{

	cout <<"\n	::MENU::\n\n";

	cout << "1) Reverse function\n";
	cout << "2) Sum function\n";
	cout << "3) Triangular function\n";
	cout << "4) Quit\n";

	return facilitateIntInput(1,3);
}

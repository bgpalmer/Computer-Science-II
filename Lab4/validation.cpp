/*******************
* Brian Palmer
* 10.3.16
* palmebri@oregonstate.edu
* This file contains useful validation functions that should be included in future projects
********************/

#include "validation.hpp"

/**********************
 * checkIfIntAndInRange(string, int begin, int end)
* preReq: must have a string
* Parameters: string, int, int
* post: returns true if string contains an integer and is in range
* Description: This function works with checkIfIntInRange and checkIfInt to see if users input is valid
**********************/

bool checkIfIntAndInRange(string c, int begin, int end)
{
	bool checkIfInteger = false;
	bool checkIfInRange = false;

	checkIfInteger = checkIfInt(c);
	if (!checkIfInteger)
		return false;
	else
	{
		int value = atoi(c.c_str());
		checkIfInRange = checkIfIntInRange(value, begin, end);
		if (!checkIfInRange)
			return false;
		else
			return true;
	}
}


/***************
* checkIfIntInRange
* preReq: must confirm that value is an integer beforehand if coming from user input
* Parameter: integer, integer, integer
* post: returns true if value is in range
* Description: With this function, can think of range as [,). Good for working with 2d arrays. 
*****************/

bool checkIfIntInRange(int value, int begin, int end)
{
	if (value >= begin && value < end)
		return true;
	else
		return false;
}

/***************
* convertYNtoUpper
* Prereq: string input must be a Y/y or N/n ascii character
* Parameters: string
* Post: returns capitalized Y or N character
* Description: This functions takes a string character with a single Y or N character. Should use the validateYNresponse prior to this function. Returns capital Y or capital N.
***********************/ 

char convertYNtoUpper(string c)
{
	const char * ptr = c.data();
	if (ptr[0] == 'y')
		return 'Y';
	else if (ptr[0] == 'n')
		return 'N';
	else
		return ptr[0];
}

/****************
* validateYNresponse
* PreReq: String
* Post: Returns a boolean value 
* Description: Converts string to c string and checks first position to see if is Y/y or N\n
**********************/

bool validateYNresponse(string c)
{
	int len = c.length();
	const char * ptr = c.data();
	if ((ptr[0] == 'Y' || ptr[0] == 'N' || ptr[0] == 'y' || ptr[0] == 'n') && len == 1)
		return true;
	else
		return false;
}

/*****************
* checkIfInt
* PreReq: A string
* Post: Returns a boolean value
* Description: Tries to convert string to an integer
*******************/

bool checkIfInt(string c)
{
	const char * ptr = c.c_str();
	int i = 0;
	if (ptr[0] == '\0')
		return false;
	else
	{
		while (ptr[i] != '\0')
		{
			if (ptr[i] < 47 || ptr[i] > 58)
				return false;
			else
				i++;
		}
		return true;
	}		
}
/*
	if(((atoi(ptr)) == 0 && ptr[0] == '0') || (atoi(ptr) != 0)) 
		return true;
	else
		return false;
}*/

/*****************
* int getRandomInt()
* PreReq: None
* Parameters: None
* Post: returns an integer
* Description: this function returns a random integer
****************/

int getRandomPosInt()
{
	int random = rand();
	return random;
}

/***************
* int getRandomInt(integer)
* PreReq: None
* Parameters: Integer
* Post: returns an integer
* Description: this version of getRandomInt returns an integer between and the provided integer
****************/

int getRandomPosInt(int i)
{
	int random = rand() % i;
	return random;
}

bool cmpInteger(int a, int b)
{
	if (a == b)
		return true;
	else
		return false;
}

bool cmpDouble(double a, double b)
{
	if (a == b)
		return true;
	else
		return false;
}

bool cmpString(string a, string b)
{
	if (a.compare(b) == 0)
		return true;
	else
		return false;
}

bool cmpCharArray(const char * arr_A, const char * arr_B)
{
	int i = 0;
	while (arr_B[i] != '\0')
	{
		if (arr_A[i] != arr_B[i])
			return false;
		else
			i++;
	}

	return true;
}
		

bool checkCharacters(const char * test_arr, const char * allowed_chars)
{

	int arr_size = 0, allowed_size = 0;
	while (test_arr[arr_size] != '\0')
		arr_size++;
	while (allowed_chars[allowed_size] != '\0')
		allowed_size++;
	
	arr_size += 1;
	allowed_size += 1;
	char cp_arr[arr_size];
	for (int i = 0; i < arr_size; i++)
	{
		cp_arr[i] = '\0';
	}

	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < allowed_size; j++)
		{
			if (test_arr[i] == allowed_chars[j])
			{
				cp_arr[i] = allowed_chars[j];
				j = allowed_size;
			}
		}
	}

	bool check = cmpCharArray(cp_arr, test_arr);

	return check;
}

string capitalize(string c)
{
	string output;
	int size = c.size();
	const char * cstr = c.c_str();
	for (int i = 0; i < size; i++)
	{
		if (cstr[i] >= 97 && cstr[i] <= 122)
		{
			output += cstr[i] - ' ';
		}
		else
			output += cstr[i]; 
	}
	
	return output;
}

		

/******************
* Brian Palmer
* 10.5.16
* bgpalmer14@gmail.com
* This is the function that is used for the menu
********************/
#include "menu_function.hpp"

int menu_function()
{
	cout << " ** This is a game based off of Langston's Ant ** " << endl;
	cout << endl;
	
	string input;
	int width;
	bool checkIntAndInRange = false;
	cout << " --> How wide should the field be? (10 - 100) " << endl;
	do
	{
		cout << " >> ";
		cin >> input;
		checkIntAndInRange = checkIfIntAndInRange(input, 10, 101);
		if (!checkIntAndInRange)
		{
			cout << "Bad Input, please try again. Must be an integer between 10 - 100." << endl;
		}
	} while (!checkIntAndInRange);

	width = atoi(input.c_str());

	// Step 2. Get height

	int height;
	cout << " --> How tall should the field be? (10 - 100) " <<endl;
	checkIntAndInRange = false;		
	do
	{
		cout << " >> ";
		cin >> input;
		checkIntAndInRange = checkIfIntAndInRange(input, 10, 101);
		if (!checkIntAndInRange)
		{
			cout << "Bad Input, please try again. Must be an integer between 10 - 100." << endl;
		}
	} while (!checkIntAndInRange);
	
	height = atoi(input.c_str());

	// Step 3. Create Plane

	Plane p (height, width);
	
	// Step 4. Get Ant starting position from user
	
	bool validResp;
	char response;
	cout << "Would you like to choose where the ant begins (Y or N)? If N, a random position will be chosen for you." << endl;
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

	response = convertYNtoUpper(input);
	int xCoord, yCoord;
	checkIntAndInRange = false;
	switch(response)
	{
		case 'Y':
			// user determines ant coordinates
			
			cout << "What should the X coordinate be? (0 - " << width-1 << ")" << endl;
			
			do
			{
				cout << " >> ";
				cin >> input;
				checkIntAndInRange = checkIfIntAndInRange(input, 0, width);
				if (!checkIntAndInRange)
				{
					cout << "Bad input, please try again. Input should be an integer between (0 - " << width-1 << ")" << endl;
				}
			} while (!checkIntAndInRange);
			
			xCoord = atoi(input.c_str());			
			
			checkIntAndInRange = false;
			cout << "What should the Y coordinate be? (0 - " << height-1 << ")" << endl;
			do 
			{
				cout << " >> ";
				cin >> input;
				checkIntAndInRange = checkIfIntAndInRange(input, 0, height);
				if (!checkIntAndInRange)
				{
					cout << "Bad input, please try again. Input should be an integer between (0 - " << height-1 << ")" << endl;
				}
			} while (!checkIntAndInRange);
			
			yCoord = atoi(input.c_str());
			p.initializeAntPosition(xCoord, yCoord);
			
			break;

		case 'N':
			// random ant coordinates
			
			xCoord = getRandomPosInt(width);
			yCoord = getRandomPosInt (height);
			p.initializeAntPosition(xCoord, yCoord);

			break;
	}

	
	// Step 5. Get Number of generations

	cout << "How many steps should the ant take? (1 - 30000)" << endl;
	
	do
	{
		cout << " >> ";
		cin >> input;
		checkIntAndInRange = checkIfIntAndInRange(input, 1, 30001);
		if (!checkIntAndInRange)
		{
			cout << "Bad Input, please try again. Input should be an integer between (1 - 30000) " << endl;
		}
	} while (!checkIntAndInRange);

	int steps = atoi(input.c_str());

	int gens = 0;
	while (gens < steps)
	{
		cout << "STEPS: " << gens << endl;
		p.displayPlane();
		p.update();
		gens++;
	}
	cout << "STEPS: " << gens << endl;
	p.displayPlane();

	cout << endl;
	cout << " --> Program complete! " << endl;

	return 0;
};	

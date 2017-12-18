
/********************
* Brian Palmer
* 9/24/16
* Description: Overloaded readMatrix Functions, one to handle 2 X 2 static 2D-arrays, the other for 3 X 3 static 2D-arrays
*****************/


#include "matrix.hpp"

void readMatrix(double (*array) [2], const int rows)
{
        double input;
        for (int i = 0; i < rows; i++)
        {       
                for (int j = 0; j < 2; j++)
                {      
			cout << " >> ";
			cin >> input;
			array[i][j] = input;
		}
        }
}

void readMatrix(double (*array) [3], const int rows)
{
	double input;
        for (int i = 0; i < rows; i++)
        {
                for (int j = 0; j < 3; j++)
                {
			cout << " >> ";
                        cin >> input;
                        array[i][j] = input;
                }
        }
}


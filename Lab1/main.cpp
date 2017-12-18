/************************8
* Brian Palmer
* 9/24/16
*********************/

#include "matrix.hpp"
#include "determinant.hpp"

int main ()
{
	// set matrix size here
	const int SIZE = 3;

	cout << " --> note: to change to the matrix size, set the SIZE variable to a different value in main.cpp" << endl;
	cout << endl;
	cout << " --> Enter " << SIZE*SIZE << " numbers into your " << SIZE << " X " << SIZE << "matrix." << endl;

	double twoD[SIZE][SIZE];
	double (*ptr)[SIZE] = twoD;
	readMatrix(ptr, SIZE);
	double d = determinant(ptr, SIZE);
	
	cout << " --> Determinant equals " << d << endl;

	cout << endl;
	cout << " --> Program completed" << endl;
	
	return 0;
} 

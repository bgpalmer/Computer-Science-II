/***********************
* Brian Palmer
* 9/25/16
***********************/

// Determinant formula was found at http://www.mathsisfun.com/algebra/matrix-determinant.html
// 
// Determinant can be calculated for either a 2 X 2 static array or 3 X 3 static array


#include "determinant.hpp"

// 2 x 2 array
// |A| = ad - bc

double determinant(double (*array) [2], const int size)
{
	double answer = (array[0][0] * array[1][1]) - (array[0][1] * array[1][0]);
	return answer;
}

// 3 x 3 array
// |A| = a(ei - fh) - b(di - fg) + c(dh - eg)

double determinant(double (*array) [3], const int size)
{
	double answer = (array[0][0] * ((array[1][1] * array[2][2]) - (array[1][2] * array[2][1]))) - (array[0][1] * ((array[1][0] * array[2][2]) - (array[1][2] * array[2][0]))) + (array[0][2] * ((array[1][0] * array[2][1]) - (array[1][1] * array[2][0])));
	return answer;
} 
 

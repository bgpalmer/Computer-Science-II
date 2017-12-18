/*********
* brian palmer
* 10.20.16
* palmebri@oregonstate.edu
* main program
*************/


#include "menu_functions.hpp"
#include "triangular.hpp"
#include "sum.hpp"
#include "reverse_string.hpp"

int main ()
{
        int response;
        do
        {
                response = integer_menu();
                string input;
                if (response == 1)
                {
                        cout << "Enter a string" << endl;
                        string input = facilitateNameInput();
                        cout << " ==> ";
                        reverse_string("\n" + input);
                }
                else if (response == 2)
                {
                        int size = 4;
                        int counter = 0;
                        string input;
                        char character;
                        int * ptr = new int [size];
                        for (int i = 0; i < size; i++)
                                ptr[i] = 0;

                        do {
                                cout << "Enter integers to sum. When finished, hit <space> + enter to run calculation." << endl;
                                input = sumFunctionHelper();
                                const char * c_str = input.c_str();
                                character = c_str[0];
                                if (counter == size && character != ' ')
                                {
                                        int * temp = new int [size * 2];
                                       	for (int i = 0; i < size*2; i++)
						temp[i] = 0;
					
					for (int i = 0; i < size; i++)
                                                temp[i] = ptr[i];
                                        delete [] ptr;
                                        ptr = temp;
                                        size *= 2;
                                }
                                if (character != ' ')
                                {
                                        ptr[counter] = character - '0';
                                        counter++;
                                }
                        } while (character != ' ');

                        cout << " ==> Sum is " << sum(ptr, size - 1) << endl;
                        delete [] ptr;
                }
                else if (response == 3)
                {
                        cout << "Triangle Number calculator, what does N equal? (1 - 30000)" << endl;
                        int N = facilitateIntInput(1,30001);
                        cout << " ==> Triangular number is " << triangular(N) << endl;
                }

                else
                        cout << "Goodbye!" << endl;
        } while (response != 4);

        return 0;
}

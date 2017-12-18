#include "field.hpp"
#include "helper_functions.hpp"

int main()
{
        char response;

        cout << "How many turns? (5,50)" << endl;
        int t = facilitateIntInput(5,51);
        Field f(t);
        f.start();
        do
        {
                cout << "Continue?" << endl;
                response = facilitateYNresponse();
                if (response == 'Y')
                {
                        cout << "How many turns? (5,50)" << endl;
                        int t = facilitateIntInput(5,51);
                        f.set_turns(t);
                        f.start();
                }
        } while  (response != 'N');

        return 0;
}

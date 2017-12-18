#include "pack.hpp"

int main ()
{
        cout << "PACK TESTS\n\n\n";

        cout << "\n\nTEST 1: Add items and print successfully\n\n";
        Pack satchel;
        satchel.add_item("Eggs", 20);
        satchel.add_item("Milk", 88);
        satchel.print_contents();


        cout << "\n\nTEST 2: Remove items and print successfully\n\n";

        satchel.remove_item("Eggs", 10);
        satchel.print_contents();

        cout << "\n\nTEST 3: If quantity <= 0, remove item from pack \n\n";

        satchel.remove_item("Eggs", 12);
        satchel.print_contents();

        cout << "\n\nTEST 4: Add to pre-existing item and increase qty \n\n";

        satchel.add_item("Milk", 100);
        satchel.print_contents();

        cout << "\n\nTEST 5: repeat TEST 3 and check that pack is now empty \n\n";

        satchel.remove_item("Milk",188);
        satchel.print_contents();

        return 0;
}

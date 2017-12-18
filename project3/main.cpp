/*********************************************************************
** Program Filename: main.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: Main Program
** Input: none
** Output: none
*********************************************************************/

#include "vampire.hpp"
#include "harry_potter.hpp"
#include "medusa.hpp"
#include "barbarian.hpp"
#include "blue_men.hpp"
#include <ctime>
#include <fstream>

int main()
{
        cout << "\tTest Driver!\n" << endl;

        // calculating winning percentages
        srand(time(NULL));


        /* Creating rogue creatures. These creatures will have 100 battles with each creature type,
        totaling 500 battles per rogue */

        int battle_counter = 0;

        Creature ** rogue_creatures = new Creature * [5];
        rogue_creatures[0] = new Barbarian;
        rogue_creatures[1] = new Vampire;
        rogue_creatures[2] = new Harry_Potter;
        rogue_creatures[3] = new Blue_Men;
        rogue_creatures[4] = new Medusa;

        /* This 2D array captures how many KO's a Creature has in a particular
        opponent matchup (i.e Medusa vs Blue Men, Medusa vs Medusa, Blue Men
        vs. Medusa, etc.)
        */
        int ** kills = new int * [5];
        for (int i = 0; i < 5; i++)
                kills[i] = new int [5];

        for (int i = 0; i < 5; i++)
        {
                for (int j = 0; j < 5; j++)
                {
                        kills[i][j] = 0;
                }
        }

        /* This section fresh creatures for a rogue creature to fight against.
        Specifically, 100 of each creature is created. The rogue creature
        fights them all, totaling to 500 battles per rogue
        */

        for (int r = 0; r < 5 ; r++)
        {
                Creature *** creatures = new Creature ** [5];
                for (int j = 0; j < 5; j++)
                        creatures[j] = new Creature * [100];

                for (int j = 0; j < 100; j++)
                {
                        creatures[0][j] = new Barbarian;
                }
                for (int j = 0; j < 100; j++)
                {
                        creatures[1][j] = new Vampire;
                }
                for (int j = 0; j < 100; j++)
                {
                        creatures[2][j] = new Harry_Potter;
                }
                for (int j = 0; j < 100; j++)
                {
                        creatures[3][j] = new Blue_Men;
                }
                for (int j = 0; j < 100; j++)
                {
                        creatures[4][j] = new Medusa;
                }

                /* This is the battle phase. The rogue fights all the creatures
                that were just generated
                */

                for (int i = 0; i < 5; i++)
                {
                        for (int j = 0; j < 100; j++)
                        {
                                cout << "\n-------------------------------------------------------------\n";
                                cout << "Battle: " << battle_counter + 1 << "\n\n";
                                cout << rogue_creatures[r]->get_type() << " vs. " << creatures[i][j]->get_type() << "\n\n";

                                creatures[i][j]->defend(rogue_creatures[r]->attack());
                                if (creatures[i][j]->get_str_pts() == 0)
                                        kills[r][i]++;

                                battle_counter++;
                        }
                }

                cout << "\n-------------------------------------------------------------\n\n";

                /* the weary creatures are removed. Fresh creatures will be created above
                for the next rogue
                */

                for (int i = 0; i < 5; i++)
                {
                        for (int j = 0; j < 100; j++)
                        {
                                delete creatures[i][j];
                        }
                        delete [] creatures[i];
                }
                delete [] creatures;

        }

        /* Summary table provides all of the KO's that occured in a particular
        matchup (i.e Medusa vs Medusa, Blue Men vs Medusa, etc.)
        */

        cout << "\t\t\tSUMMARY" << endl;
        cout << "Table below shows number of KO's when creature fights 100 of\neach creature\n";
        cout << "\n-------------------------------------------------------------\n\n";

        cout << setw(20) << " ";
        for (int i = 0; i < 5; i++)
        {
                cout << setw(10) << rogue_creatures[i]->get_type() << "\t";
        }
        cout << "\n";
        for (int i = 0; i < 5; i++)
        {
                cout << setw(10) << rogue_creatures[i]->get_type() << "\t";
                for (int j = 0; j < 5; j++)
                {
                        cout << setw(10) << kills[i][j] << "\t";
                }
                cout << "\n";
        }

        /* This takes the same KO stats and files them to a text file
        ('results.txt')
        */

        std::ofstream out;
        out.open("results.txt");
        if (out.is_open())
        {
                cout << "\n\nWriting to \'results.txt\'......";
                out << "\t";
                for (int i = 0; i < 5; i++)
                {
                        out << rogue_creatures[i]->get_type() << "\t";
                }
                out << "\n";
                for (int i = 0; i < 5; i++)
                {
                        out << rogue_creatures[i]->get_type() << "\t";
                        for (int j = 0; j < 5; j++)
                        {
                                out << kills[i][j] << "\t";
                        }
                        out << "\n";
                }
                cout << ".....Done!\n";
                out.close();
        }
        else
        {
                cout << "ERROR: cannot write to file.";
        }
        char input;



        /* This is a separate test to confirm Harry doesn't revive more
        than once
        */

        cout << "Also run Harry Potter KO Test? (y/n)\n";
        input = facilitateYNresponse();
        if (input == 'Y')
        {
                cout << "\n-------------------------------------------------------------\n\n";
                cout << "\t\tHarry Potter KO Test\n\n";
                cout << "This test is designed to check that Harry can only revive once";
                cout << "\n-------------------------------------------------------------\n\n";
                Harry_Potter harry;
                Medusa medusa;
                for (int i = 0 ; i < 30; i++)
                {
                        cout << "\n-------------------------------------------------------------\n\n";
                        cout << "Harry Test Battle: " << i + 1 << "\n\n";
                        harry.defend(medusa.attack());

                }
                cout << "\n-------------------------------------------------------------\n\n";
                cout << "Harry Potter KO Test Complete\n\n\n\n";
        }

        /* lastly, allocated memory holding KOs and rogue creatures is deleted
        */

        for (int i = 0; i < 5; i++)
        {
                delete [] kills[i];
        }
        delete [] kills;

        for (int i = 0 ; i < 5; i++)
                delete rogue_creatures[i];
        delete [] rogue_creatures;

        cout << " \n\n **** Test Driver Complete ****\n\n";

        return 0;
}

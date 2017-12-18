/*********************************************************************
** Program Filename: field.cpp
** Author: brian palmer
** Date: 10.24.16
** Description: field class implementation
** Input: none
** Output: none
*********************************************************************/

#include "field.hpp"

/*********************************************************************
** Function: Constructor
** Description: Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*********************************************************************/

Field::Field(int t)
{
        cols = 20;
        rows = 20;
        num_ants = 100;
        num_doodlebugs = 5;
        Critter *** temp = new Critter ** [rows];
        for (int i = 0; i < rows; i++)
                temp[i] = new Critter * [cols];

        for (int i = 0; i < rows; i++)
        {
                for (int j = 0; j < cols; j++)
                {
                        temp[i][j] = NULL;
                }
        }
        for (int i = 0; i < num_ants; i++)
        {
                int x = getRandomPosInt(rows);
                int y = getRandomPosInt(cols);
                if (temp[x][y] != NULL)
                        i--;
                else
                        temp[x][y] = new Ant;
        }
        for (int i = 0; i < num_doodlebugs; i++)
        {
                int x = getRandomPosInt(rows);
                int y = getRandomPosInt(cols);
                if (temp[x][y] != NULL)
                        i--;
                else
                        temp[x][y] = new Doodlebug;
        }

        field = temp;
        turns = t;
}

void Field::start()
{
        int counter = 0;
        cout << "your board" << endl;
        print();
        while (counter < 5)
        {
                move_critters();
                counter++;
                cout << "Step: " << counter << endl;
                print();
                reset_move();
        }

        /*cout << endl;
        while (counter < turns)
        {
                move_critters();
                //breed_critters();
                doodle_starve();
                counter++;
                cout << "Step: " << counter << endl;
                print();
                reset_move();
        }*/
}

void Field::print() const
{
        for (int i = 0; i < rows; i++)
        {
                for (int j = 0; j < cols; j++)
                {
                        if (field[i][j] == NULL)
                                cout << "E ";
                        else
                        {
                                field[i][j]->print();
                                cout << " ";
                        }
                }
        cout << "\n";
        }
}

void Field::move_critters()
{
        // start with Doodlebug
        for (int i = 0; i < rows; i++)
        {
                for (int j = 0; j < cols; j++)
                {
                        if (field [i][j] != NULL && field[i][j]->get_who_am_i() == 'D')
                        {
                                field[i][j]->set_neighborhood(i, j, rows, cols, field);
                                field[i][j]->move();
                                field[i][j]->reset_neighborhood();
                        }
                }
        }
        // now move the ants
        for (int i = 0; i < rows; i++)
        {
                for (int j = 0; j < cols; j++)
                {
                        if (field [i][j] != NULL && field[i][j]->get_who_am_i() == 'A')
                        {
                                field[i][j]->set_neighborhood(i, j, rows, cols, field);
                                field[i][j]->move();
                                field[i][j]->set_neighborhood(i, j, rows, cols, field);
                        }
                }
        }
}

void Field::set_turns(int t)
{
        turns = t;
}

void Field::breed_critters()
{
        for (int i = 0; i < rows; i++)
        {
                for (int j = 0; j < cols; j++)
                {
                        if (field[i][j] != NULL && field[i][j]->get_who_am_i() == 'D')
                        {
                                field[i][j]->set_neighborhood(i, j, rows, cols, field);
                                field[i][j]->breed();
                        }
                }
        }
        for (int i = 0; i < rows; i++)
        {
                for (int j = 0; j < cols; j++)
                {
                        if (field[i][j] != NULL && field[i][j]->get_who_am_i() == 'A')
                                field[i][j]->breed();
                }
        }
}

void Field::reset_move()
{
        for (int r = 0; r < rows; r++)
        {
                for (int c = 0; c < cols; c++)
                {
                        if(field[r][c] != NULL)
                                field[r][c]->set_moved(false);
                }
        }
}

void Field::doodle_starve()
{
        for (int r = 0; r < rows; r++)
        {
                for (int c = 0; c < cols; c++)
                {
                        if(field[r][c] != NULL && field [r][c]->get_who_am_i() == 'D')
                        {
                                field[r][c]->starve();
                        }
                }
        }
}

Field::~Field()
{
        for (int i = 0; i < rows; i++)
        {
                for (int j = 0; j < cols; j++)
                {
                        delete field[i][j];
                }
                delete [] field[i];
        }
        delete [] field;
}

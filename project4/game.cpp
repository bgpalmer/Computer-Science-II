/*********************************************************************
** Program Filename: game.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: game implementation
** Input: none
** Output: none
*********************************************************************/

#include "game.hpp"

/*********************************************************************
** Function: start()
** Description: starts game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Game::start()
{
        set_lineups();
        simulate_battles();
        print_stats();

        cout << "Thanks for playing!" << endl;
}

/*********************************************************************
** Function: print_stats
** Description: basic attack function for all creatures
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Game::print_stats()
{
        cout << "\n\n\t:::Post-Game:::\n\n";
        cout << "Defeated Creatures (w/HP):\n";
        cout << "Player_1: ";
        player1->get_fainted()->display();
        cout << "\n";
        cout << "Player_2: ";
        player2->get_fainted()->display();
        cout << "\n";
        cout << "\nRemaining Creatures (w/HP):\n";
        cout << "Player_1: ";
        player1->get_lineup()->display();
        cout << "\n";
        cout << "Player_2: ";
        player2->get_lineup()->display();
        cout << "\n";
        cout << "\nScorecard: \n";
        cout << "Player_1: ";
        player1->display_stats();
        cout << "\n";
        cout << "Player_2: ";
        player2->display_stats();
        cout << "\n\n\n";
        cout << "GAME WINNER: " << winning << "!\n\n";
}

/*********************************************************************
** Function: update_winning
** Description: update winning member
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Game::update_winning()
{
        int p1_pts = player1->get_points();
        int p2_pts = player2->get_points();
        if (p1_pts > p2_pts)
                winning = "Player 1";
        else if (p2_pts > p1_pts)
                winning = "Player 2";
        else
                winning = "It's a tie!";
}

/*********************************************************************
** Function: Game Constructor
** Description: Game Constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Game::Game()
{
        player1 = NULL;
        player2 = NULL;
        player1 = new Player;
        player2 = new Player;
}

/*********************************************************************
** Function: Game Destructor
** Description: Game Destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Game::~Game()
{
        delete player1;
        delete player2;
}

/*********************************************************************
** Function: simulate_battles()
** Description: sets lineups, battles creatures, and updates scoreboard
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Game::simulate_battles()
{
        int counter = 0;
        bool game_over = false;
        cout << "\n\n";
        cout << "MATCHUP: \n\n";
        cout << "Player 1 (you): ";
        player1->get_lineup()->display();
        cout << "\n\nPlayer 2 (CPU): ";
        player2->get_lineup()->display();
        cout << "\n\n";

        press_enter_to_continue();

        do
        {
                // check the first creature
                if (player1->get_lineup()->is_empty() == true || player2->get_lineup()->is_empty() == true)
                {
                        game_over = true;
                }
                else
                {
                        Queue * player1_lineup = player1->get_lineup();
                        Queue * player2_lineup = player2->get_lineup();

                        Creature * player1_creature = player1_lineup->pop();
                        Creature * player2_creature = player2_lineup->pop();

                        cout << "\n-------------------------------------------------------------\n";
                        cout << "Battle " << counter + 1 << ": ";
                        cout << player1_creature->get_type() << " vs. ";
                        cout << player2_creature->get_type() << "\n\n";

                        Creature * winner = battle(player1_creature, player2_creature);
                        winner->heal();

                        cout << "\n\nWINNER: ";
                        if (winner == player1_creature)
                        {
                                cout << "Player 1's " << winner->get_type() << endl;
                                player1_lineup->push(winner);
                                player2->get_fainted()->push(player2_creature);
                                player1->won();
                                player2->lost();
                        }
                        else
                        {
                                cout << "Player 2's " << winner->get_type() << endl;
                                player2_lineup->push(winner);
                                player1->get_fainted()->push(player1_creature);
                                player2->won();
                                player1->lost();
                        }
                        update_winning();

                        cout << "\n\nLineup after battle " << counter+1 << " (w/HP):\n\n";
                        cout << "player_1: ";
                        player1_lineup->display();
                        cout << "\nplayer_2: ";
                        player2_lineup->display();
                        cout << "\n\nCurrent Winning Player: " << winning << "\n";
                        cout << "Points: Player_1: " << player1->get_points() << " || ";
                        cout << "Points: Player_2: " << player2->get_points() << "\n\n\n";


                        counter++;

                        press_enter_to_continue();

                }
        }
        while (game_over == false);
}

/*********************************************************************
** Function: battle
** Description: two creatures fight each other. the winner is returned.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: Creature *
*********************************************************************/

Creature * Game::battle(Creature * player1_creature, Creature * player2_creature)
{
        Creature * winner = NULL;
        bool battle_over = false;
        do
        {
                cout << "player1_creature: " << player1_creature << "\n";
                cout << "player2_creature: " << player2_creature << "\n";
                player1_creature->defend(player2_creature->attack());
                if (player1_creature->get_str_pts() == 0)
                {
                        //player1->get_fainted()->push(player1_creature);
                        winner = player2_creature;
                        battle_over = true;
                }
                else
                {
                        player2_creature->defend(player1_creature->attack());
                        if (player2_creature->get_str_pts() == 0)
                        {
                                //player2->get_fainted()->push(player2_creature);
                                winner = player1_creature;
                                battle_over = true;
                        }
                }
        }
        while (battle_over == false);

        return winner;
}

/*********************************************************************
** Function: press_enter_to_continue
** Description: utility to make viewing indiviual battles easier
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Game::press_enter_to_continue()
{
        //http://www.cplusplus.com/forum/articles/7312/
        cout << "Press ENTER to start next battle" << std::flush;
        cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
}

/*********************************************************************
** Function: set_lineups
** Description: sets lineups for user
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Game::set_lineups()
{
        cout << "Player 1, choose your monsters!" << endl;
        int count = 0;
        while (count < 5)
        {
                add_creature_to_lineup(get_users_creature_choice());
                cout << "Current Lineup: ";
                player1->get_lineup()->display();
                cout << "\n\n";
                count++;
        }
        setup_computer_player();
}

/*********************************************************************
** Function: setup_computer_player
** Description: sets lineup for computer player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Game::setup_computer_player()
{
        srand(time(NULL));
        int count = 0;

        cout << "Preparing computer player's lineup.";

        while (count < 5)
        {
                int random = getRandomPosInt(5) + 1;
                //Creature * temp = NULL;
                switch(random)
                {
                        case 1:
                                player2->get_lineup()->push(new Barbarian);
                                //temp = new Barbarian;
                                break;
                        case 2:
                                player2->get_lineup()->push(new Blue_Men);
                                //temp = new Blue_Men;
                                break;
                        case 3:
                                player2->get_lineup()->push(new Harry_Potter);
                                //temp = new Harry_Potter;
                                break;
                        case 4:
                                player2->get_lineup()->push(new Medusa);
                                //temp = new Medusa;
                                break;
                        case 5:
                                player2->get_lineup()->push(new Vampire);
                                //temp = new Vampire;
                                break;
                }
                //player2->get_lineup()->push(temp);
                cout << "." << count + 1 << ".";
                count++;
        }
        cout << ".done!\n\n";

}

/*********************************************************************
** Function: add_creature_to_lineup
** Description: takes users creature selection and adds to lineup
** Parameters: Creature *
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Game::add_creature_to_lineup(Creature * obj)
{
        player1->get_lineup()->push(obj);
}

/*********************************************************************
** Function: get_users_creature_choice
** Description: get users creature choice and return
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: Creature *
*********************************************************************/

Creature * Game::get_users_creature_choice()
{
        cout << "\t:::Creatures:::\n\n";
        cout << "1)  Barbarian\n";
        cout << "2)  Blue Men\n";
        cout << "3)  Harry Potter\n";
        cout << "4)  Medusa\n";
        cout << "5)  Vampire\n";
        int choice = facilitateIntInput(1,6);

        //Creature * temp = NULL;
        switch(choice)
        {
                case 1:
                        return new Barbarian;
                        //temp = new Barbarian;
                        break;
                case 2:
                        return new Blue_Men;
                        //temp = new Blue_Men;
                        break;
                case 3:
                        return new Harry_Potter;
                        //temp = new Harry_Potter;
                        break;
                case 4:
                        return new Medusa;
                        //temp = new Medusa;
                        break;
                case 5:
                        return new Vampire;
                        //temp = new Vampire;
                        break;
                default:
                        return NULL;
        }
        //return temp;
}

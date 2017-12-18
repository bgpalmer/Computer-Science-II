/***************
* brian palmer
* 10.12.16
* palmebri@oregonstate.edu
* game implementation file
*******************/

#include "game.hpp"

/***********
* Setup()
* preReq: none
* parameters: none
* post: none
* description: sets up players
**************/

void Game::setup()
{
	cout << " \n** Setup Player 1 ** " << endl;
	Person * p1 = createPlayer();
	cout << " \n** Setup Player 2 ** " << endl;
	Person * p2 = createPlayer();
	setPlayer1(p1);
	setPlayer2(p2);

	int rounds = determineRounds();
	setRounds(rounds);
}

/***************
* determineRounds()
* preReq: none
* parameter: none
* post: none
* description: sets up number of rounds 
****************/

int Game::determineRounds()
{
	int rounds;
        cout << "How many rounds would you like to play? (" << MIN_NUM_ROUNDS << " - " << MAX_NUM_ROUNDS << ")" << endl;
        rounds = facilitateIntInput(MIN_NUM_ROUNDS, MAX_NUM_ROUNDS + 1);	
	return rounds;
}


/*************
* CreatePlayer
* preReq: none
* parameters: none
* post: none
* description: creates a player, sets up their dice, sets their dice, and then sets the player
**************/

Person * Game::createPlayer()
{
	Dice * dice = NULL;
        Person * player = NULL;
        
        cout << "How many sides does this player's dice have? ("<<MIN_NUM_SIDES<< " - " << MAX_NUM_SIDES<< ")" << endl;
        int p1sides = facilitateIntInput(MIN_NUM_SIDES, MAX_NUM_SIDES + 1);
        
        cout << "Is this players dice loaded?" << endl;
        char response = facilitateYNresponse();
        
        switch(response)
        {               
                case 'Y':
                        dice = new Loaded_Dice(p1sides);
                        player = new Person(true);
                        break;
                case 'N':
                        dice = new Dice(p1sides);
                        player = new Person(false);
                        break;
        }               
        
        player->setDie(dice);

	return player;
}

/****************
* setPlayer1()
* preReq: need pointer to person
* parameters: Person *
* post: none
* description: sets p1 member
******************/

void Game::setPlayer1(Person * p)
{
	player1 = p;
}

/***************
* setPlayer2()
* preREq: need pointer to person
* parameters: Person *
* post: none
* description: sets p2 member
****************/

void Game::setPlayer2(Person * p)
{
	player2 = p;
}


/**************
* print
* preReq: game should be finished
* parameters: none
* post: at this point, game is over
* descripion: prints (1) number of rounds (2) size and type of die (3) num of rounds won by each player (4) and the final winner
*****************/

void Game::print() const
{
	cout << "\n ** Post-game statistics ** " << endl;
	cout << endl;
	cout << setw(10);
	cout << "Player1 /" << " Player2" << endl;
	cout << "Wins: " << getPlayer1()->getWins() << " / " << getPlayer2()->getWins() << endl;
	cout << "Dice: " << getPlayer1()->getLoaded() << " / " << getPlayer2()->getLoaded() << " [KEY: Loaded_Dice = 1, Dice = 0]" << endl;
	cout << "Size: " << getPlayer1()->getDie()->getSides() << " / " << getPlayer2()->getDie()->getSides() << endl;
	cout << endl;
	cout << "and the winner of the game is....." << calcWinner() << endl;

}

/****************
* Person * getp1()
* preReq: p1 member should be set
* parameters: none
* post: returns persono
* description: returns person
*****************/

Person * Game::getPlayer1() const
{
	return player1;
}

/***************
* Person * getP2()
* preReq: p2 member should be set
* parameter: none
* post: returns p2
* description: returns p2
*****************/

Person * Game::getPlayer2() const
{
	return player2;
}


/*****************
* Game constructor
* preReq: none
* parameters: none
* post: none
* description: creates game class
*******************/

Game::Game()
{
	srand(time(NULL));
	player1 = NULL;
	player2 = NULL;
	setRounds(0);
}

/*****************
* Game object destructor
* preReq: none
* parameters: none
* post: none
* description: destroys game object
*******************/

Game::~Game()
{
	delete player1;
	delete player2;
}

/***************
* getRounds()
* preReq: member should be set
* parameters: none
* post: returns number of rounds
* description: returns number of rounds
******************/

int Game::getRounds() const
{
	return rounds;
}

/*******************8
* setRounds()
* preReq: none
* parameters: integer
* post: sets number of rounds member
* description: sets number of  rounds member
*******************************/

void Game::setRounds(int r)
{
	rounds = r;
}

/******************
* play()
* preReq: dice should be built
* parameters: none
* post: game will be finished with all stats recorded
* description: starts the game
**********************/

void Game::play()
{
	int counter = 0, p1rolled, p2rolled;
        int rounds = getRounds();
	
	Person * player1 = getPlayer1();
	Person * player2 = getPlayer2();

	Dice * d1 = player1->getDie();
	Dice * d2 = player2->getDie();

	while (counter < rounds)
        {
		p1rolled = d1->roll();
		p2rolled = d2->roll();
		if (p1rolled > p2rolled)
                {
                        player1->updateWins();
			counter++;
                }
                else if (p1rolled < p2rolled)
                {
                        player2->updateWins();
			counter++;
                }
        }
}

/*************************
* calcWinner
* preReq: none
* parameteters: none
* post: none
* description: calculates who has the most wins
**************************/

string Game::calcWinner() const
{
	int p1wins = getPlayer1()->getWins();
	int p2wins = getPlayer2()->getWins();
	if (p1wins > p2wins)
	{
		return "Player 1!";
	}
	else if (p1wins < p2wins)
	{
		return "Player 2!";
	}
	else
	{
		return "Nobody! It was a tie!";
	}
}

/*****************
* file
* preReq: none
* parameters: none
* post: none
* description: files to a text file
*****************/

void Game::file()
{
	string filename = "results.txt";
	std::ofstream out;
	out.open(filename.c_str());
	if (out.is_open())
	{
		Person * p1 = getPlayer1();
		Person * p2 = getPlayer2();
		
		out << "\tGames Won (#)\tWin Percentage(%)\tLoaded_Die (1 = Yes, 0 = No)\tSides (#)\n";
		out << "Player_1\t" << p1->getWins() << "\t" << ((p1->getWins()/(static_cast<double>(getRounds()))) * 100) << "\t" << p1->getLoaded() << "\t" << p1->getDie()->getSides() << "\n";
		out << "Player_2\t" << p2->getWins() << "\t"<< ((p2->getWins()/(static_cast<double>(getRounds()))) * 100) << "\t" << p2->getLoaded() << "\t" << p2->getDie()->getSides() << "\n";  
		out << "Total:\t" << getRounds() << "\n";

		cout << "Your results were filed to \"results.txt\"" << endl;
	}
	else
		cout << "ERROR: File did not open" << endl;
	out.close();
}

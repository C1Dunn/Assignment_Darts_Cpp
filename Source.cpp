#include "Player.h"
#include "Board.h"

//create objects
Board* board = new Board();

//Is an interactive 301 game that allows more input then the simulation variant
void turn301(int* aimChoice, int* temporaryScore, int* temporaryHit, bool* game,Player player[],int* i)
{
	switch (player[*i].gameStage())
	{
	case 1:
		*aimChoice = 0;
		cout << player[*i].getName() << " has " << player[*i].getScore() << " points. He can aim for the bullseye(50) or a standard target(1-20). What is he aiming for?" << endl;
		cin >> *aimChoice;
		player[*i].setThrows();

		if (*aimChoice == 50)
		{
			*temporaryHit = player[*i].throwBull(board->getRandomHit());
			*temporaryScore = player[*i].getScore() - *temporaryHit;

			if (*temporaryScore >= 50)
			{
				cout << player[*i].getName() << " hit " << *temporaryHit << " points have reduced to ";
				player[*i].setScore(*temporaryHit);
				cout << player[*i].getScore() << endl;
			}
		}
		else if (*aimChoice > 0 || *aimChoice < 21)
		{
			*temporaryHit = board->throw_single(*aimChoice);
			*temporaryScore = player[*i].getScore() - *temporaryHit;

			if (*temporaryScore >= 50)
			{
				cout << player[*i].getName() << " hit " << *temporaryHit << " points have reduced to ";
				player[*i].setScore(*temporaryHit);
				cout << player[*i].getScore() << endl;
			}
		}
		break;
	case 2:
		cout << player[*i].getName() << " has " << player[*i].getScore() << " points. He must hit a standard target(1-20) to reach a score of 50. What is he aiming for?" << endl;
		cin >> *aimChoice;
		player[*i].setThrows();

		if (*aimChoice > 0 || *aimChoice < 21)
		{
			*temporaryHit = board->throw_single(*aimChoice);
			*temporaryScore = player[*i].getScore() - *temporaryHit;

			if (*temporaryScore >= 50)
			{
				cout << player[*i].getName() << " hit " << *temporaryHit << " points have reduced to ";
				player[*i].setScore(*temporaryHit);
				cout << player[*i].getScore() << endl;
			}
		}
		break;
	case 3:
		cout << player[*i].getName() << " has " << player[*i].getScore() << " points. He must hit a bullseye to end the game." << endl;
		player[*i].setThrows();

		*temporaryHit = player[*i].throwBull(board->getRandomHit());
		*temporaryScore = player[*i].getScore() - *temporaryHit;
		if (*temporaryScore == 0)
		{
			cout << player[*i].getName() << " hit " << *temporaryHit << " points have reduced to ";
			player[*i].setScore(*temporaryHit);
			cout << player[*i].getScore() << endl;
			*game = false;
		}
		else
		{
			cout << player[*i].getName() << " missed!" << endl;
		}
		break;
	case 4:
		*game = false;
		break;
	default:
		cout << "Error in input" << endl;
	}
}

//allows the player to decide the turn order
void chooseTurnOrder(Player player[], int* turnChoice)
{
	do
	{
		cout << player[0].getName() << " and " << player[1].getName() << " will take turns throwing darts to lower their score." << endl;
		cout << "Who is going first? Enter 1 for joe or 2 for sid." << endl;
		cin >> *turnChoice;

		if (*turnChoice < 1 || *turnChoice > 2)
		{
			cout << "Error input invalid" << endl;
		}

	} while (*turnChoice < 1 || *turnChoice > 2);
}

//is the 301 simulation required for part 1. 
void turnSimulation(int* aimChoice, int* temporaryScore, int* temporaryHit, bool* game, Player player[], int* i)
{
	*game = true;

	switch (player[*i].gameStage())
	{
	case 1:
		*aimChoice = 50;
		player[*i].setThrows();

		if (*aimChoice == 50)
		{
			*temporaryHit = player[*i].throwBull(board->getRandomHit());
			*temporaryScore = player[*i].getScore() - *temporaryHit;

			if (*temporaryScore >= 50)
			{
				cout << player[*i].getName() << " hit " << *temporaryHit << " points have reduced to ";
				player[*i].setScore(*temporaryHit);
				cout << player[*i].getScore() << endl;
				player[*i].increaseSuccessHits();
			}
		}
		else if (*aimChoice > 0 || *aimChoice < 21)
		{
			*temporaryHit = board->throw_single(*aimChoice);
			*temporaryScore = player[*i].getScore() - *temporaryHit;

			if (*temporaryScore >= 50)
			{
				cout << player[*i].getName() << " hit " << *temporaryHit << " points have reduced to ";
				player[*i].setScore(*temporaryHit);
				cout << player[*i].getScore() << endl;
				player[*i].increaseSuccessHits();
			}
		}
		break;
	case 2:
		*temporaryHit = player[*i].getScore() - 50;
		if(*temporaryHit < 20)
		{
			*aimChoice = *temporaryHit;
		}
		else 
		{
			*aimChoice = 20;
		}
		player[*i].setThrows();

		if (*aimChoice > 0 || *aimChoice < 21)
		{
			*temporaryHit = board->throw_single(*aimChoice);
			*temporaryScore = player[*i].getScore() - *temporaryHit;

			if (*temporaryScore >= 50)
			{
				cout << player[*i].getName() << " hit " << *temporaryHit << " points have reduced to ";
				player[*i].setScore(*temporaryHit);
				cout << player[*i].getScore() << endl;
				player[*i].increaseSuccessHits();
			}
		}
		break;
	case 3:
		player[*i].setThrows();

		*temporaryHit = player[*i].throwBull(board->getRandomHit());
		*temporaryScore = player[*i].getScore() - *temporaryHit;
		if (*temporaryScore == 0)
		{
			cout << player[*i].getName() << " hit " << *temporaryHit << " points have reduced to ";
			player[*i].setScore(*temporaryHit);
			cout << player[*i].getScore() << endl;
			*game = false;
			player[*i].increaseWins();
			player[*i].increaseSuccessHits();
		}
		else
		{
			cout << player[*i].getName() << " missed!" << endl;
		}
		break;
	case 4:
		*game = false;
		break;
	default:
		cout << "Error in input" << endl;
	}
}

//function for deciding what the dart should hit, has in built randomisation, game design choice. 
int autoAim501(int* aimChoice, int* temporaryScore, int* temporaryHit, bool* game, Player player[], int* i,int *counter)
{
	int temp1 = player[*i].getScore();;
	int temp2 = player[*i].getSuccessRate();
	player[*i].setThrows();

	if(player[*i].getScore() >= 180)
	{
		*aimChoice = 20;
		return board->throw_treble(*aimChoice,player[*i].getSuccessRate());
	}
	else if (player[*i].getScore() < 180 && player[*i].getScore() > 60 && *counter == 1)
	{ 
		return board->throw_treble(board->randomAimChoice(),player[*i].getSuccessRate());
	}
	else if(*counter == 2 && player[*i].getScore() < 180 && player[*i].getScore() > 120)
	{
		return board->throw_treble(board->randomAimChoice(), player[*i].getSuccessRate());
	}
	else if (*counter == 2 && player[*i].getScore() < 101 && player[*i].getScore() > 50)
	{
		return board->throw_double(board->randomAimChoice());
	}
	else if (*counter == 3 && player[*i].getScore() < 180 && player[*i].getScore() > 158)
	{
		return board->throw_bull(player[*i].getSuccessRate());
	}
	else if (*counter == 3 && player[*i].getScore() < 159 && player[*i].getScore() > 100)
	{
		return board->throw_double(board->randomAimChoice());
	}
	else if(*counter == 3 && player[*i].getScore() < 101 && player[*i].getScore() > 49)
	{
		return board->throw_single501(board->randomAimChoice());
	}
	else
	{
		return board->throw_single(board->randomAimChoice());
	}
}

//is the 501 game simulation 
void turn501(int* aimChoice, int* temporaryScore, int* temporaryHit, bool* game, Player player[], int* i)
{
	int dart1 = 0;
	int dart2 = 0;
	int dart3 = 0;
	int temporary = 0;
	int counter = 0;
	counter = 1;
	dart1 = autoAim501(aimChoice, temporaryScore, temporaryHit, game, player, i, &counter);
	temporary = player[*i].getScore() - dart1;
	if (temporary == 0)
	{
		if ((dart1 % 2) == 0) 
		{
			player[*i].increaseWins();
			*game = false;
			player[*i].setScore(dart1);
			cout << player[*i].getName() << " is now at " << player[*i].getScore() << endl;
			player[*i].increaseSuccessHits();
		}
	
	}
	else if (temporary == 1 || temporary < 0)
	{
	}
	else 
	{
		counter = 2;
		dart2 = autoAim501(aimChoice, temporaryScore, temporaryHit, game, player, i, &counter);
		temporary = player[*i].getScore() - (dart2+dart1);
		if(temporary == 0)
		{
			if ((dart2 % 2) == 0)
			{
				player[*i].increaseWins();
				
				*game = false;
				temporary = dart1 + dart2;
				player[*i].setScore(temporary);
				cout << player[*i].getName() << " is now at " << player[*i].getScore() << endl;
				player[*i].increaseSuccessHits();
				player[*i].increaseSuccessHits();
			}
		}
		else if (temporary == 1 || temporary < 0)
		{
		}
		else
		{
			counter = 3;
			dart3 = autoAim501(aimChoice, temporaryScore, temporaryHit, game, player, i, &counter);
			temporary = player[*i].getScore() - dart3;

			if (temporary == 0)
			{
				if ((dart3 % 2) == 0)
				{
					player[*i].increaseWins();
					*game = false;
					temporary = dart1 + dart2 + dart3;
					player[*i].setScore(temporary);
					cout << player[*i].getName() << " is now at " << player[*i].getScore() << endl;
					player[*i].increaseSuccessHits();
					player[*i].increaseSuccessHits();
					player[*i].increaseSuccessHits();
				}
			}
			else if(player[*i].getScore() - (dart1+dart2+dart3) > 1)
			{
				temporary = dart1 + dart2 + dart3;
				player[*i].setScore(temporary);
				cout << player[*i].getName() << " is now at " << player[*i].getScore() << endl;
				player[*i].increaseSuccessHits();
				player[*i].increaseSuccessHits();
				player[*i].increaseSuccessHits();
			}
			else if (temporary == 1 || temporary < 0)
			{
			}
			else
			{
			}
		}
	}
}

int main()
{
	//Function Prototypes
	void turn301(int* aimChoice, int* temporaryScore, int* temporaryHit, bool* game,Player player[],int *i);
	void chooseTurnOrder(Player player[],int *turnChoice);
	void turnSimulation(int* aimChoice, int* temporaryScore, int* temporaryHit, bool* game, Player player[], int* i);
	void turn501(int* aimChoice, int* temporaryScore, int* temporaryHit, bool* game, Player player[], int* i);

	//Object Creation
	Player joe("joe", 71, 0, 0);
	Player sid("sid", 73, 0, 0);

	//Create Main Variables
	int menu;
	int temporary;
	int turnChoice;
	int aimChoice;
	int temporaryScore;
	int temporaryHit;
	bool game = true;
	Player player[2];
	int i = 0;
	int x = 0;

	//Array of objects (players Joe & Sid)
	player[0] = joe;
	player[1] = sid;

	srand(time(0));	//initialise random num generator using time
	while (true)
	{
		menu = 0;
		cout << "You are at the initial menu. \nEnter 1 to play Darts 301 where the players take turns. \nEnter 2 to exit the program. \nEnter 3 to run a 301 simulation.\nEnter 4 to play darts 501." << endl;
		cin >> menu;
		//Switch case that acts as the menu 
		switch (menu)
		{
		case 1:
			game = true;
			chooseTurnOrder(player,&turnChoice);
			player[0].resetFor301();
			player[1].resetFor301();
			//loops until a player wins
			while (game)
			{
				if (turnChoice == 1)
				{
					i = 0;
					turn301(&aimChoice, &temporaryScore, &temporaryHit, &game,player,&i);
					if(game)
					{
						i = 1;
						turn301(&aimChoice, &temporaryScore, &temporaryHit, &game, player, &i);
					}
				}
				else if (turnChoice == 2)
				{
					i = 1;
					turn301(&aimChoice, &temporaryScore, &temporaryHit, &game,player,&i);
					if(game)
					{
						i = 0;
						turn301(&aimChoice, &temporaryScore, &temporaryHit, &game, player, &i);
					}
				}
			}
			//outputs a win message and stats to the user
			if (player[0].getScore() == 0)
			{
				cout << player[0].getName() << " has won in " << player[0].getThrows() << " with " << player[1].getName() << " losing in " << player[1].getThrows() << endl;
			}
			else if (player[1].getScore() == 0)
			{
				cout << player[1].getName() << " has won in " << player[1].getThrows() << " with " << player[0].getName() << " losing in " << player[0].getThrows() << endl;
			}
			else
			{
				cout << "There has been an error" << endl;
			}
			break;
		case 2:
			//closes the program
			exit(0);
			break;
		case 3:
			game = true;
			player[0].resetFor301();
			player[1].resetFor301();
			//asks how the length of the for loop
			cout << "How many times should the simulation run?" << endl;
			cin >> x;
			do
			{
				cout << "What should " << player[0].getName() << "'s success rate be?" << endl;
				cin >> temporary;
				if (temporary > 0 && temporary < 100)
				{
					player[0].setSuccessRate(temporary);
				}
			} while (temporary < 0 && temporary > 100);
			//the user can set the turn order and success rate
			do
			{
				cout << "What should " << player[1].getName() << "'s success rate be?" << endl;
				cin >> temporary;
				if (temporary < 0 && temporary > 100)
				{
					player[1].setSuccessRate(temporary);
				}
			} while (temporary < 0 && temporary > 100);
			
			chooseTurnOrder(player, &turnChoice);
			//will loop each time a player wins for the amount of specified games
			for(int y = x;y > 0;y--)
			{
				player[0].resetScore();
				player[1].resetScore();
				game = true;
				while (game)
				{

					if (turnChoice == 1)
					{
						i = 0;
						turnSimulation(&aimChoice, &temporaryScore, &temporaryHit, &game, player, &i);
						if (game)
						{
							i = 1;
							turnSimulation(&aimChoice, &temporaryScore, &temporaryHit, &game, player, &i);
						}
					}
					else if (turnChoice == 2)
					{
						i = 1;
						turnSimulation(&aimChoice, &temporaryScore, &temporaryHit, &game, player, &i);
						if (game)
						{
							i = 0;
							turnSimulation(&aimChoice, &temporaryScore, &temporaryHit, &game, player, &i);
						}
					}
				}
				cout << "Loop " << y <<endl;
			}
			//outputs stats after the end of all the games and resets background numbers
			cout << "A 301 game was simulated " << x << " number of times " << endl;
			player[0].statistics();
			player[1].statistics();
			temporary = 71;
			player[0].setSuccessRate(temporary);
			temporary = 73;
			player[1].setSuccessRate(temporary);
			break;
		case 4:
			game = true;
			player[0].resetFor501();
			player[1].resetFor501();
			//the user can set the turn order
			chooseTurnOrder(player, &turnChoice);
			//asks how the length of the for loop
			cout << "How many times should the simulation run?" << endl;
			cin >> x;
			//the user can set the success rate
			for (int i = 0; i < 2; i++)
			{
				do
				{
					cout << "What should " << player[i].getName() << "'s success rate be?" << endl;
					cin >> temporary;
					if (temporary > 0 && temporary < 100)
					{
						player[i].setSuccessRate(temporary);
					}
				} while (temporary < 0 && temporary > 100);
			}
			cout << "Settings completed" << endl;
			//loops until the specified numbers of games have been won 
			for (int y = 0; y < x; y++)
			{
				int i = 0;
				player[0].resetScore501();
				player[1].resetScore501();
				game = true;
				cout << "game: " << y+1 << endl;
				while (game)
				{
					if (turnChoice == 1)
					{
						i = 0;
						turn501(&aimChoice, &temporaryScore, &temporaryHit, &game, player, &i);
						if (game)
						{
							i = 1;
							turn501(&aimChoice, &temporaryScore, &temporaryHit, &game, player, &i);
						}
					}
					else if (turnChoice == 2)
					{
						i = 1;
						turn501(&aimChoice, &temporaryScore, &temporaryHit, &game, player, &i);
						if (game)
						{
							i = 0;
							turn501(&aimChoice, &temporaryScore, &temporaryHit, &game, player, &i);
						}
					}
				}
			}
			//outputs end game information to the user and resets background information
			cout << "Simulation completed" << endl;
			player[0].statistics();
			player[1].statistics();
			temporary = 71;
			player[0].setSuccessRate(temporary);
			temporary = 73;
			player[1].setSuccessRate(temporary);
			cout << "501 over, returning to menu" << endl;
			break;
		default:
			cout << "You have entered a wrong input, please try again." << endl;
		}
	}
	return 0;
}
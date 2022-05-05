#include "Board.h"
//Constructors & Deconstructors
Board::Board()
{
}

Board::~Board()
{
}

//Methods
int Board::throw_single(int aim)
{
	random = rand() % 100 + 1;
	// we must be aiming for 1 to 20 single
	if (random <= 80)
		return aim;
	else if (random <= 88)
		return bd[0][aim];
	else if (random <= 92)
		return bd[1][aim];
	else if (random <= 96)
		return 3 * aim;
	else
		return 2 * aim;
}

int Board::throw_double(int aim) 
{

	//  return result of throwing for double d with accuracy 80%
	random = rand() % 100 + 1;

	if (random < 80)
		return 2 * aim;
	else if (random < 85)
		return 0;
	else if (random < 90)
		return aim;
	else if (random < 93)
		return 2 * bd[0][aim];
	else if (random < 96)
		return 2 * bd[1][aim];
	else if (random < 98)
		return bd[0][aim];
	else
		return bd[1][aim];
}

int Board::throw_treble(int aim, int successRate) {

	//  return result of throwing for treble d with accuracy p%  (o<90)
	random = rand() % 100 + 1;
	
	if(random<successRate)
		return 3*aim;
	else if(random <90)
		return aim;
	else if(random <93)
		return 3*bd[0][aim];
	else if (random <96)
		return 3*bd[1][aim];
	else if(random <98)
		return bd[0][aim];
	else 
		return bd[1][aim];
}

int Board::throw_bull(int successRate) {

	//  Throw for the bull with accuracy p%  (20<p<85)
	random = rand() % 100;

	if (random < (successRate - 20))
		return 50;
	else if (random < 85)
		return 25;
	else
		return 1 + rand() % 20;
}

int Board::throw_single501(int d) 
{

	//  return result of throwing for single d with accuracy 88% (or 80% for the outer)
	random = rand() % 100 + 1;
	// Board neighbours ignoring slot zero
	int x = rand() % 3 + 1;
	if (x == 1)
	{
		d = 50;
	}
	else if (x = 2)
	{
		d = 25;
	}
	else 
	{
		d = rand() % 20 + 1;
	}

	if (d == 25) {		// outer  80%
		if (random < 80)
			return 25;
		else if (random < 90)
			return 50;
		else
			return 1 + rand() % 20;
	}
	else			// 1 to 20 single
		if (random < 88)
			return d;
		else if (random < 92)
			return bd[0][d];
		else if (random < 96)
			return bd[1][d];
		else if (random < 98)
			return 3 * d;
		else
			return 2 * d;
}

int Board::randomAimChoice()
{
	random = rand() % 20 + 1;
	return random;
}
//Setters & Getters
int Board::getRandomHit()
{
	random = rand() % 100 + 1;
	return random;
}
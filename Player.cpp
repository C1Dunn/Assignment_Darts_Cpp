#include "Player.h"

//Constructors & Deconstructors
Player::Player()
{
	score = 301;
}

Player::Player(string a, int b, int c, int d)
{
	name = a;
	successRate = b;
	throws = c;
	bullseyeCount = d;
	score = 301;
}

Player::~Player()
{
}

//Methods

int Player::throwBull(int random)
{
	//  Throw for the bull with percent accuracy (20<p<85)
	bullseyeAttempts++;
	if (random <= successRate)
	{
		bullseyeCount++;
		return 50;
	}
	else
	{
		return rand() % 20 + 1;
	}
}

int Player::gameStage()
{
	if (score >= 100)
	{
		return 1;
	}
	else if (score > 50 && score < 100)
	{
		return 2;
	}
	else if (score == 50)
	{
		return 3;
	}
	else
	{
		return 4;
	}
}

void Player::resetFor301()
{
	score = 301;
	throws = 0;
	bullseyeAttempts = 0;
	bullseyeCount = 0;
	numOfWins = 0;
}

void Player::statistics()
{
	cout << name << " has " << numOfWins << " wins, " << bullseyeCount << " bullseyes hit and he threw " << successfullHits << " scoring darts." << endl;
}

void Player::resetFor501()
{
	score = 501;
	throws = 0;
	bullseyeAttempts = 0;
	bullseyeCount = 0;
	numOfWins = 0;
}

//Getters and Setters

string Player::getName()
{
	return name;
}

int Player::getThrows()
{
	return throws;
}

int Player::getSuccessRate()
{
	return successRate;
}

int Player::getBulls()
{
	return bullseyeCount;
}

void Player::setThrows()
{
	throws++;
}

void Player::setBulls()
{
	bullseyeCount++;
}

int Player::getScore()
{
	return score;
}

void Player::setScore(int temporary)
{
	score = score - temporary;
}

int Player::getWins()
{
	return numOfWins;
}

void Player::increaseWins()
{
	numOfWins++;
}

void Player::resetScore()
{
	score = 301;
}

void Player::setSuccessRate(int temporary)
{
	successRate = temporary;
}

void Player::increaseSuccessHits()
{
	successfullHits++;
}
void Player::resetScore501()
{
	score = 501;
}
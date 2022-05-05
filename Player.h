#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>    // random numbers header file//
#include <ctime>	// used to get date and time information
#include <string>
using namespace std;

class Player
{
private:
	//Attributes
	string name;
	int successRate;//store Player success rate
	int throws; //store total throws of the dart
	float bullseyeAttempts;
	float bullseyeCount;//store number of bulls hit
	int score;
	int aim;
	int numOfWins = 0;
	int successfullHits = 0;

public:
	//Constructors & Deconstructors
	Player();
	Player(string name, int successRate, int throws, int bullseyeCount);
	~Player();

	//Methods
	int throwBull(int);
	int gameStage();
	void resetFor301();
	void statistics();
	void resetFor501();

	//Getters & Setters
	string getName();
	int getThrows();
	int getSuccessRate();
	int getBulls();
	void setThrows();
	void setBulls();
	int getScore();
	void setScore(int);
	int getWins();
	void increaseWins();
	void resetScore();
	void setSuccessRate(int);
	void increaseSuccessHits();
	void resetScore501();
};
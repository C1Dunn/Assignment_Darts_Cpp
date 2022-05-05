#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>    // random numbers header file//
#include <ctime>	// used to get date and time information
#include <string>
using namespace std;

class Board
{
private:
	//Attributes
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int random;
public:
	//Constructors & Deconstructors
	Board();
	~Board();
	//Methods
	int throw_single(int aim);
	int throw_treble(int aim, int successRate);
	int throw_double(int aim);
	int throw_bull(int successRate);
	int randomAimChoice();
	int throw_single501(int d);

	//Setters & Getters
	int getRandomHit();
};
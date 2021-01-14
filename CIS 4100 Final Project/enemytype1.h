/*
Author: Wengsing Wong
CIS 4100 MFA
Final Project - EnemyType1 Class Specification
*/

#include "enemy.h"
#include <iostream>
using namespace std;
#ifndef ENEMYTYPE1_H
#define ENEMYTYPE1_H

class EnemyType1 : public Enemy {
private:

	// Distance a Type 1 Enemy (Animal) can travel in a single move_position() call
	const int MOVEMENT = 6;

	// Pool of attack moves
	const string attackArr[3] = {"Intimidating Roar", "Claw Slash", "Big Bite"};

public:

	// Default Constructor
	EnemyType1();

	// Overloaded Constructor
	EnemyType1(string, int, int, int, double, double);

	// Getter for MOVEMENT constant
	int getMOVEMENT();

	// Enemy moves in a random direction
	void move_position();

	// Enemy attacks
	void fire_weapon();

	// Enemy is damaged, update status
	void update_status();

	// Redefined display function
	void displayInfo();

	// Validate enemy movement
	bool validateMovement(int);
};
#endif
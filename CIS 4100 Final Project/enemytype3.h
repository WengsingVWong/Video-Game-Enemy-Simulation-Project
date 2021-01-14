/*
Author: Wengsing Wong
CIS 4100 MFA
Final Project - EnemyType3 Class Specification
*/

#include "enemy.h"
#ifndef ENEMYTYPE3_H
#define ENEMYTYPE3_H

class EnemyType3 : public Enemy {
private:

	// Distance a Type 3 Enemy (Humanoid) can travel in a single move_position() call
	const int MOVEMENT = 3;

	// Remaining ammo
	int ammo = 0;

public:

	// Default Constructor
	EnemyType3();

	// Overloaded Constructor
	EnemyType3(string, int, int, int, double, double, int);

	// Getter for MOVEMENT constant
	int getMOVEMENT();

	// Getter for ammo variable
	int getAmmo();

	// Setter for ammo variable
	void setAmmo(int);

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
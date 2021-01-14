/*
Author: Wengsing Wong
CIS 4100 MFA
Final Project - Enemy Class Specification
*/

#include <iostream>
using namespace std;

#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
protected:
	
	// Name of enemy
	string name;

	// x_position and y_position indicate enemy's location on map
	// status indicates HP (and whether enemy is alive or dead)
	int x_position, y_position, status;

	// Width and height of the enemy
	double width, height;

	// Left-most value on x-axis
	const int MIN_X = 0;

	// Right-most value on x-axis
	const int MAX_X = 800;

	// Highest value on y-axis
	const int MIN_Y = 0;

	// Lowest value on y-axis (ground-level = 500)
	const int MAX_Y = 600;

public:

	// Constructor
	Enemy();

	// Getters
	string getName() const;
	int getXPos() const;
	int getYPos() const;
	int getStatus() const;
	double getWidth() const;
	double getHeight() const;

	// Setters
	void setName(string);
	void setXPos(int);
	void setYPos(int);
	void setStatus(int);
	void setWidth(double);
	void setHeight(double);

	// Enemy actions
	// Will be redefined in subclasses
	virtual void move_position() = 0;
	virtual void fire_weapon() = 0;
	virtual void update_status() = 0;

	// Display function
	virtual void displayInfo();
};

#endif ENEMY_H

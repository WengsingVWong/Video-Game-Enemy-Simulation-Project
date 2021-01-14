/*
Author: Wengsing Wong
CIS 4100 MFA
Final Project - Enemy Class Implementation
*/

#include "enemy.h"
#include <iostream>
using namespace std;

// Constructor
Enemy::Enemy() {
	name = "";
	x_position = 0;
	y_position = 0;
	status = 0;
	width = 0.00;
	height = 0.00;
}

// Getters
string Enemy::getName() const {
	return name;
}

int Enemy::getXPos() const {
	return x_position;
}

int Enemy::getYPos() const {
	return y_position;
}

int Enemy::getStatus() const {
	return status;
}

double Enemy::getWidth() const {
	return width;
}

double Enemy::getHeight() const {
	return height;
}

// Setters
void Enemy::setName(string n) {
	name = n;
}

void Enemy::setXPos(int xpos) {
	x_position = xpos;
}

void Enemy::setYPos(int ypos) {
	y_position = ypos;
}

void Enemy::setStatus(int st) {
	status = st;
}

void Enemy::setWidth(double w) {
	width = w;
}

void Enemy::setHeight(double h) {
	height = h;
}

// Display function
void Enemy::displayInfo() {
	cout << "Here is the info for " << name << ":" << endl;
	cout << "X-Position: " << x_position << endl;
	cout << "Y-Position: " << y_position << endl;
	cout << "Status: " << status << " HP ("; 
	
	if (status != 0)
		cout << "alive";
	else
		cout << "dead";

	cout << ")" << endl << "Width: " << width << " feet" << endl;
	cout << "Height: " << height << " feet" << endl;
}
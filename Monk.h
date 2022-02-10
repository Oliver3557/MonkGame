#pragma once
#include "Entity.h"
#include <string>

class Monk
{
public:

	int MonkHealthP = 15;
	int MonkAttackP = 3;

	void setHealth(int);
	void setAttack(int);
	int getHealth();
	int getAttack();

	void Heal(int);

	std::string name;
	void setName(std::string x);
	std::string getName();

};


#pragma once
#include "Entity.h"
#include <string>
class Monster
{
public:

	int MonsterHealthP = 10;
	int MonsterAttackP = 2;

	void setHealth(int);
	void setAttack(int);
	int getHealth();
	int getAttack();


    std::string name = "Monster";
};


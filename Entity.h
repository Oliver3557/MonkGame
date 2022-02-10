#pragma once
#include <string>

class Entity
{
public:
	static int HealthP;
	static int AttackP;
	std::string name;

	inline void setHealth(int Input);
	inline void setAttack(int Input);
	inline int getHealth();
	inline int getAttack();
};


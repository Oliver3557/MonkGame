#include "Monk.h"
#include <string>

void Monk::setHealth(int Input) {
	MonkHealthP = Input;
}

int Monk::getHealth() {
	return MonkHealthP;
}

void Monk::setAttack(int Input) {
	MonkAttackP = Input;
}

int Monk::getAttack() {
	return MonkAttackP;
}

void Monk::Heal(int HealPoints)
{
	MonkHealthP += HealPoints;
}

void Monk::setName(std::string x) {
	name = x;
}

std::string Monk::getName() {
	return name;
}


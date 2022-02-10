#include "Entity.h"

void setHealth(int Input) {
	Entity::HealthP = Input;
}

int getHealth() {
	return Entity::HealthP;
}

void setAttack(int Input) {
	Entity::AttackP = Input;
}

int getAttack() {
	return Entity::AttackP;
}

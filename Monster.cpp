#include "Monster.h"
#include "Monk.h"
#include <string>


void Monster::setHealth(int Input) {
	MonsterHealthP = Input;
}

int Monster::getHealth() {
	return MonsterHealthP;
}

void Monster::setAttack(int Input) {
	MonsterAttackP = Input;
}

int Monster::getAttack() {
	return MonsterAttackP;
}



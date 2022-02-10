#include "pch.h"


class MonsterRoom : public Observer
{
public:
	MonsterRoom();
	~MonsterRoom();

	void fight(Monk, Monster);
	void printAction(Monk, Monster, int);

	int GenerateRoom();
};

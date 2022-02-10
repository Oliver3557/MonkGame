#pragma once
#include "pch.h"
class LootRoom 
{
public:
	LootRoom();
	~LootRoom();

	void Loot(Monk monk);
	void printAction(Monk monk);
	int LootRoomVisited = 0;
};


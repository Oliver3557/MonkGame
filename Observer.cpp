#include "pch.h"
#include "Observer.h"



Observer observer;
Monk monk;
Monster monster;
PrayRoom prayRoom;
MonsterRoom monsterRoom;
// and so on
numberGenerator numbGen;
LootRoom lootRoom;

Observer::Observer()
{
	// Assign Game Variables, Pointers (if using any)
	
}

Observer::~Observer()
{
}
/* Room Key
* 0 - Monster Room
* 1 - Pray Room
* 2 - Loot Room

*/
int Observer::GenerateRoom()
{/*
	numbGen.getRandomRoom();
	if (numbGen.RandomRoom == 0) {
		// Load Monster Room
		monsterRoom.fight(monk, monster);
	}
	else if (numbGen.RandomRoom == 1) {
		// Load Pray Room
		prayRoom.Pray(monk);
	}
	else {
		// Load Loot Room
	}*/
	return 0;
	
}



// Getters
// Setters
// Functions

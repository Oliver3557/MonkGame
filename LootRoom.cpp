#include "pch.h"
#include "Observer.cpp"

LootRoom::LootRoom()
{
}

LootRoom::~LootRoom()
{
}

void LootRoom::Loot(Monk monk)
{
	LootRoomVisited += 1;
	string Option; // Keeps track of user input.

	printAction(monk);
	cin >> Option; // User Picks Loot or Next Room.

	if (Option == "1") { // User Chooses to Loot!
		cout << "You have chosen to Loot!\n" << endl;
		cout << "Your Attack is now 6!\n" << endl;
		monk.setAttack(6);

		monsterRoom.GenerateRoom();

	}
	else{ // User Chooses to Advance Room!
		monsterRoom.GenerateRoom();
	}
}


void LootRoom::printAction(Monk monk)
{
	cout << "Welcome to the Loot Room Traveller!\n" << endl;
	cout << "Here, you can Either Loot to gain 3 Attack Points (6 max)\n or Go to the next room!\n" << endl;
	cout << "Health: " << monk.getHealth() << endl << "Attack: " << monk.getAttack() << "\n" << endl;
	cout << "[1] Loot  [2] Next Room\n" << endl;
}

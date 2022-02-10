#include "pch.h"
#include "PrayRoom.h"
#include "Observer.cpp"



//Monk monk;

//MonsterRoom monsterRoom;

PrayRoom::PrayRoom()
{
}


void PrayRoom::Pray(Monk monk)
{
	string Option; // Keeps track of user input.
	PrayRoomVisited += 1;
	printAction(monk);
	cin >> Option; // User Picks Pray or Next Room.

	if (Option == "1") { // User Chooses to Heal!
		cout << "You have chosen to Pray!\n" << endl;
		if (monk.getHealth() <= 12) {
			monk.Heal(3);
			
			monsterRoom.GenerateRoom();
		}
		else {
			cout << "You cannot Heal, Moving Room!\n" << endl;
			monsterRoom.GenerateRoom();
		}
		
	}
	else { // User Chooses to Advance Room!
		monsterRoom.GenerateRoom();
	}
}

void PrayRoom::printAction(Monk monk)
{
	cout << "Welcome to the Pray Room Traveller!\n" << endl;
	cout << "Here, you can Either Pray to regain up to 3 Health Points\n or Go to the next room!\n" << endl;
	cout << "Health: " << monk.getHealth() << endl << "Attack: " << monk.getAttack() << "\n" << endl;
	cout << "[1] Pray  [2] Next Room\n" << endl;

}





PrayRoom::~PrayRoom()
{
}

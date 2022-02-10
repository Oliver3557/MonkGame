#include "pch.h"
#include "Observer.cpp"
#include <cstdlib>

numberGenerator randNum;

// Game stat counters, to be displayed at the end of the game.
int RoomCompleted = 0;
int MonkAttacks = 0;
int MonkDefends = 0;
int MonsterAttacks = 0;
int MonsterDefends = 0;


void MonsterRoom::printAction(Monk monk, Monster monster, int turn)
{
	//Monk's turn
	if (turn == 0) {
		

		cout << "Turn of: Monk" << endl;
		cout << "[1] Attack " << "[2] Defend" << endl;
		cout << "Health: " << monk.MonkHealthP << endl << "Attack: " << monk.MonkAttackP << "\n" << endl;
	}

	//Monster's turn
	else if (turn == 1) {
	
		cout << "Turn of: Monster" << endl;
		cout << "Health: " << monster.MonsterHealthP << endl << "Attack: " << monster.MonsterAttackP << "\n" << endl;
	}
	else {
		cout << "Error! Invalid State!";
	}
}

int MonsterRoom::GenerateRoom()
{
	randNum.getRandomRoom();
	if (randNum.RandomRoom == 0) {
		// Load Monster Room
		monsterRoom.fight(monk, monster);
	}
	else if (randNum.RandomRoom == 1) {
		// Load Pray Room
		prayRoom.Pray(monk);
	}
	else if (randNum.RandomRoom == 2) {
		// Load Loot Room
		lootRoom.Loot(monk);
	}
	return 0;

}


/*
Turn 0 = Monk
Turn 1 = Monster

Attack 0 = Successful
Attack 1 = Failed

Defend 0 = Successful
Defend 1 = Failed

Monster Attack = 0
Monster Defend = 1
*/

MonsterRoom::MonsterRoom()
{
}

MonsterRoom::~MonsterRoom()
{
}

void MonsterRoom::fight(Monk monk, Monster monster)
{
	string nextstep; // Keeps track of user input.
	int turn = 0;
	monster.setHealth(10);

	do {
		
		//Monk's turn
		if (turn == 0){
			printAction(monk, monster, 0);
			cin >> nextstep;
			if (nextstep == "1") { // 1 Is Attack
				MonkAttacks += 1;
				if (randNum.getActionNumber() == 0) { // 0 is Successful Attack
					cout << "Attack Successful!" << "\n" << endl;
					monster.MonsterHealthP -= monk.MonkAttackP;

					turn = 1;
				}
				else { // randNum would return 1, Which is Attack Failed.
					cout << "Attack failed!" << "\n" << endl;
					turn = 1;
				}
			}
			else if (nextstep == "2") { // 2 Is Defend
				MonkDefends += 1;
				if (monk.getHealth() == 15) {
					cout << "You already have full Health!" << "\n" << endl;
					cout << "[1] Attack" << endl;
				}
				// Defend Chosen and HP is not full
				else if(randNum.getActionNumber() == 0) { // 0 is Successful Defend 
					if (monk.MonkHealthP <= 14) { //Making sure Health does not exceed 15 limit
						monk.MonkHealthP += 1;

						turn = 1;
					}
				}
				else if (randNum.getActionNumber() == 1) { // 1 is Defend Failed.
					cout << "Defend failed!" << "\n" << endl;
					turn = 1;
				}
			}
		}

		//Monster's turn
		else if (turn == 1){
			printAction(monk, monster, 1);

			if (randNum.getActionNumber() == 0) { // 0 is Attack
				MonsterAttacks += 1;
				if (randNum.getActionNumber() == 0) { // 0 is Attack Successful
					cout << "Monster Decided To Attack!" << "\n" << endl;
					cout << "Attack Successful!" << "\n" << endl;
					monk.MonkHealthP -= monster.MonsterAttackP;
					turn = 0;
				}	

				else { // 1 was chosen, Attack Failed!
					cout << "Monster Decided To Attack!" << "\n" << endl;
					cout << "Attack Failed!" << "\n" << endl;
					turn = 0;
				}
			}
			else { // This would be 1, so Monster Defends.
				MonsterDefends += 1;
				if (randNum.getActionNumber() == 0) {// Already Defending, 0 = Successful
					cout << "Monster Decided To Defend!" << "\n" << endl;
					cout << "Defend Successful!" << "\n" << endl;
					if (monster.MonsterHealthP == 10) {
						cout << "Monster Already had full health" << "\n" << endl;
						turn = 0;
					}
					else {// Defend Successful and Monster is hurt already.
						monster.MonsterHealthP += 1;
					}
				}
				else { // Output was 1, Defend Failed!
					cout << "Monster Decided to Defend!" << "\n" << endl;
					cout << "Defend Failed!" << "\n" << endl;
					turn = 0;
				}
			}
		}

	} while (monster.MonsterHealthP > 0 && monk.MonkHealthP > 0);

	if (monster.MonsterHealthP < 1) { // Monster is dead, User wins!
		string advanceRoom; // User Input
		 // Track how many times we defeat the monster
		RoomCompleted += 1;
		
		cout << "Congratulations! You have slain the Monster!" << "\n" << endl;

		if (RoomCompleted == 3) {
			cout << "You have COMPLETED your quest!" << "\n" << endl;
			cout << "Times visited Loot Room: " << lootRoom.LootRoomVisited << endl;
			cout << "Times visited Pray Room: " << prayRoom.PrayRoomVisited << endl;
			cout << "Times visited Monster Room: " << RoomCompleted << endl;
			cout << "You Attacked " << MonkAttacks << "Time(s)." << endl;
			cout << "You Defended " << MonkDefends << "Time(s)." << endl;
			cout << "The Monster Attacked " << MonsterAttacks << "Time(s)." << endl;
			cout << "The Monster Defended " << MonsterDefends << "Time(s)." << endl;
			exit(3);
		}

		cout << "Press Any key to Advance Room!" << "\n" << endl;

		cin >> advanceRoom;
			GenerateRoom();
		
	}
	else if (monk.MonkHealthP < 1) { // Monk is dead, User loses!
		cout << "GAME OVER !! \n You have been slain by the Monster!" << "\n" << endl;
		cout << "Times visited Loot Room: " << lootRoom.LootRoomVisited << endl;
		cout << "Times visited Pray Room: " << prayRoom.PrayRoomVisited << endl;
		cout << "Times visited Monster Room: " << RoomCompleted << endl;
		cout << "You Attacked " << MonkAttacks << " Time(s)." << endl;
		cout << "You Defended " << MonkDefends << " Time(s)." << endl;
		cout << "The Monster Attacked " << MonsterAttacks << " Time(s)." << endl;
		cout << "The Monster Defended " << MonsterDefends << " Time(s)." << endl;
	}
}

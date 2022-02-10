// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

std::string name;
std::string description;



int main()
{
    Monk monk;
    Monster monster;
    MonsterRoom monsterRoom;
    PrayRoom prayRoom;

    cout << "What is your name? and a description\n";
    cin >> name;
    monk.setName(name);
   // cout << "Give me a description of yourself: \n";
    getline(cin, description);
    cout << "Your name is: " + monk.getName() << "\n" << "Your Description: " << description << endl;

    

    monk.setHealth(15);
    monk.setAttack(3);
    monster.setHealth(10);
    monster.setAttack(2);

    monsterRoom.GenerateRoom();

    return 0;
}


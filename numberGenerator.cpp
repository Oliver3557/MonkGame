#include "numberGenerator.h"
#include <utility>

int numberGenerator::getActionNumber()
{
	ActionNumber = rand() % 2; // Generates a random number between 0 and 1
	return ActionNumber;
}

int numberGenerator::getRandomRoom()
{
	RandomRoom = rand() % 3; // Generates a number between 0 and 2 - These represent rooms
	return RandomRoom;
}

#pragma once

#ifndef PCH_H
#define PCH_H

// It is important to not change the order of class headers as this may mess the game.

// TODO: add headers that you want to pre-compile here
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <stdlib.h>

//#include <ctime>

//Classes Headers

#include "Monk.h"
#include "Monster.h"
#include "numberGenerator.h"
#include "Observer.h"
#include "PrayRoom.h"
#include "MonsterRoom.h"
#include "LootRoom.h"
#include "GameCui.h"
//all others go here

using namespace std;

#endif //PCH_H

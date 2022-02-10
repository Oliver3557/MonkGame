#pragma once
#include "pch.h"

class PrayRoom : public Observer
{
public:

	PrayRoom();
	~PrayRoom();

	void Pray(Monk monk);
	void printAction(Monk monk);
	int PrayRoomVisited = 0;
};


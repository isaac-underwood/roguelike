#pragma once
#include"ETileImage.h"
using namespace System::Drawing;
ref class Room
{
private:

public:
	Room(int startWide, int startHigh, int startXlocation, int startYlocation);
	array<int, 2>^ generateRoom();
	property int xlocation;
	property int ylocation;
	property array<int, 2>^ roomTileMap;
	property int width;
	property int height;
	property int centerPosX;
	property int centerPosY;
};


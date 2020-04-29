#pragma once
#include "Room.h"
using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;
public enum EPositionBetweenRooms { NE, NW, SE, SW };
ref class Dungeon
{
private:
	array<int, 2>^ map;
	int nCols;
	int nRows;
	Random^ rGen;
public:
	Dungeon(int startNCols, int startNRows, Random^ startRandom,array<int, 2>^ startMap, int numberOfRooms);
	void generateRooms();
	void LinkRoomWithCorridor();
	EPositionBetweenRooms PosBetweenRoom(Room^ firstRoom, Room^ secondRoom);
	void CorridorLinkBetweenRoomX(EPositionBetweenRooms position, Point firstRoomCenter, Point secondRoomCenter);
	void CorridorLinkBetweenRoomY(EPositionBetweenRooms position, Point firstRoomCenter, Point secondRoomCenter);
	int CheckingRoomCollision(Room^ room, int loopIndex);
	void GeneratePortal();
	property array<Room^>^ allRooms;
};


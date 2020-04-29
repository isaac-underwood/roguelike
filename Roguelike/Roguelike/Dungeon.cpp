#include "Dungeon.h"

#define DEADZONE 33
#define MAINROOMSIZE 20
#define TILEPADDING 2
#define MAXROOMSIZE 18
#define MINROOMSIZE 10
#define PADDINGBETWEENROOMS 5

//constructor for the dungeon class
Dungeon::Dungeon(int startNCols, int startNRows, Random^ startRandom, array<int, 2>^ startMap,int numberOfRooms)
{
	nCols = startNCols;
	nRows = startNRows;
	rGen = startRandom;
	map = startMap;
	allRooms = gcnew array<Room^>(numberOfRooms);

}

//linking the room with corridor by finding the current room middle position and next room middle position and link it together
void Dungeon::LinkRoomWithCorridor() {
	for (int i = 0; i < allRooms->Length - 1; i++)
	{
		CorridorLinkBetweenRoomX(PosBetweenRoom(allRooms[i], allRooms[i + 1]), Point(allRooms[i]->centerPosX, allRooms[i]->centerPosY), Point(allRooms[i + 1]->centerPosX, allRooms[i + 1]->centerPosY));
		CorridorLinkBetweenRoomY(PosBetweenRoom(allRooms[i], allRooms[i + 1]), Point(allRooms[i]->centerPosX, allRooms[i]->centerPosY), Point(allRooms[i + 1]->centerPosX, allRooms[i + 1]->centerPosY));
	}
}

//linking the room by x position, if current room is on left side of second room then count backwards and put the floor, else count forward 
void Dungeon::CorridorLinkBetweenRoomX(EPositionBetweenRooms position, Point firstRoomCenter, Point secondRoomCenter) {
	if (position == EPositionBetweenRooms::NW || position == EPositionBetweenRooms::SW) {
		for (int x = firstRoomCenter.X; x < secondRoomCenter.X; x++)//counting forward
		{
			if (map[x, firstRoomCenter.Y] == ETileImage::WATER|| map[x, firstRoomCenter.Y] == ETileImage::WALL) {
				map[x, firstRoomCenter.Y] = ETileImage::RUG;
			}				
		}
	}
	else {
		for (int x = firstRoomCenter.X; x > secondRoomCenter.X; x--)//counting backwards
		{
			if (map[x, firstRoomCenter.Y]==ETileImage::WATER|| map[x, firstRoomCenter.Y] == ETileImage::WALL) {
				map[x, firstRoomCenter.Y] = ETileImage::RUG;
			}				
		}
	}
}

//linking the room by y position, if current room is on top of second room then count backwards and put the floor, else count forward 
void Dungeon::CorridorLinkBetweenRoomY(EPositionBetweenRooms position, Point firstRoomCenter, Point secondRoomCenter) {
	if (position == EPositionBetweenRooms::NW || position == EPositionBetweenRooms::NE) {
		for (int y = firstRoomCenter.Y; y < secondRoomCenter.Y; y++)//counting forward
		{
			if (map[secondRoomCenter.X, y] == ETileImage::WATER || map[secondRoomCenter.X, y] == ETileImage::WALL) {
				map[secondRoomCenter.X, y] = ETileImage::RUG;
			}				
		}
	}
	else {
		for (int y = firstRoomCenter.Y; y > secondRoomCenter.Y; y--)//counting backwards
		{
			if (map[secondRoomCenter.X, y]==ETileImage::WATER || map[secondRoomCenter.X, y] == ETileImage::WALL) {
				map[secondRoomCenter.X, y] = ETileImage::RUG;
			}
		}
	}
}

//giving the enum position of the first room relative to the second room
EPositionBetweenRooms Dungeon::PosBetweenRoom(Room^ firstRoom, Room^ secondRoom) {
	EPositionBetweenRooms posBetweenRoom;
	if (firstRoom->centerPosX < secondRoom->centerPosX) {
		if (firstRoom->centerPosY < secondRoom->centerPosY) {
			posBetweenRoom = EPositionBetweenRooms::NW;
		}
		else {
			posBetweenRoom = EPositionBetweenRooms::SW;
		}
	}
	else {
		if (firstRoom->centerPosY < secondRoom->centerPosY) {
			posBetweenRoom = EPositionBetweenRooms::NE;
		}
		else {
			posBetweenRoom = EPositionBetweenRooms::SE;
		}
	}
	return posBetweenRoom;
}

//generate all the rooms including collision detection between the rooms
void Dungeon::generateRooms() {
	Room^ mainRoom = gcnew Room(MAINROOMSIZE, MAINROOMSIZE, nCols / 2 - TILEPADDING, nRows / 2 - TILEPADDING);//generate the main room
	allRooms[0] = mainRoom;
	mainRoom->generateRoom();
	for (int i = 1; i < allRooms->Length; i++)
	{
		bool intersecting = false;
		int width = rGen->Next(MINROOMSIZE, MAXROOMSIZE);
		int height = rGen->Next(MINROOMSIZE, MAXROOMSIZE);
		Room^ room = gcnew Room(width, height, rGen->Next(DEADZONE, nCols - width - DEADZONE), rGen->Next(DEADZONE, nRows - height - DEADZONE));//generatnig a new room
		allRooms[i] = room;
		room->generateRoom();
		i = CheckingRoomCollision(room, i);
	}
}
//checking the room whether they overlapped or not, if so then discard the created room and loop throgh the previous index again.
int Dungeon::CheckingRoomCollision(Room^ room, int loopIndex) {
	for (int j = 0; j < loopIndex; j++)
	{
		//this if statement checks for whether the room is overlapping with each other and also make sure that there are at least 5 tile in between them
		if ((room->xlocation <= allRooms[j]->xlocation + allRooms[j]->width + PADDINGBETWEENROOMS) &&
			(room->xlocation + room->width + PADDINGBETWEENROOMS >= allRooms[j]->xlocation) &&
			(room->ylocation <= allRooms[j]->ylocation + allRooms[j]->height + PADDINGBETWEENROOMS) &&
			(room->ylocation + room->height + PADDINGBETWEENROOMS >= allRooms[j]->ylocation)) {
			loopIndex--;
		}
	}
	return loopIndex;
}

//generate the portal for the next dungeon and the healing pad
void Dungeon::GeneratePortal() {
	map[allRooms[allRooms->Length - 1]->centerPosX, allRooms[allRooms->Length - 1]->centerPosY] = ETileImage::DOOR;
	map[allRooms[0]->centerPosX, allRooms[0]->centerPosY] = ETileImage::HEALINGPAD;
}


#include "Room.h"

//constructor for the rooom class
Room::Room(int startWide, int startHigh,int startXlocation, int startYlocation)
{
	width = startWide;
	height = startHigh;
	roomTileMap = gcnew array<int, 2>(width, height);
	xlocation = startXlocation;
	ylocation = startYlocation;
	centerPosY = (ylocation + (ylocation + height)) / 2; //setting the center position of the room 
	centerPosX = (xlocation + (xlocation + width)) / 2;
}

//this method generate the room by surrounding the room with walls and putting the rest of the room as floors
array<int, 2>^ Room::generateRoom() {
	for (int r = 0; r < height; r++)
	{
		for (int c = 0; c < width; c++)
		{
			if (r == 0 || r == height - 1 || c == 0 || c == width - 1) {
				roomTileMap[c, r] = ETileImage::WALL;
			}
			else {
				roomTileMap[c, r] = ETileImage::FLOOR;
			}

		}
	}
	return roomTileMap;
}





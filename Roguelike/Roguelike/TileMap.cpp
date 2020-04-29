#include "TileMap.h"
#include"ETileImage.h"

#define TILEPIXEL 32

//contructor for the tile map
TileMap::TileMap(TileList^ startTileList, Graphics^ startCanvas, int startNCols, int startNRows, Random^ startRandom)
{
	tileList = startTileList;
	canvas = startCanvas;
	nCols = startNCols;
	nRows = startNRows;
	map = gcnew array<int, 2>(nCols, nRows); //2d array for map
	fogmap = gcnew array<int, 2>(nCols, nRows);
	CreateFogMap();
	rGen = startRandom;
}

//creating fog that covers the whole map
void TileMap::CreateFogMap() {
	for (int r = 0; r < nRows; r++)
	{
		for (int c = 0; c < nCols; c++)//looping through the cols and rows
		{
			fogmap[c, r] = ETileImage::FOG;
		}
	}
}

//setting tile(picture/index for picture) for individual tile on the map
void TileMap::SetMapEntry(int col, int row, int tileIndex) { 
	map[col, row] = tileIndex;
}

//get a certain index of a certain tile in the 2d array (map)
int TileMap::GetMapEntry(int col, int row) {
	return map[col, row];
}

//method used to put the room tiles value in to the map
void TileMap::PuttingTileIntoMap(array<Room^>^ rooms) {
	for (int i = 0; i < rooms->Length; i++) {
		for (int r = 0; r < rooms[i]->height; r++)
		{
			for (int c = 0; c < rooms[i]->width; c++)
			{
				SetMapEntry(rooms[i]->xlocation + c, rooms[i]->ylocation + r, rooms[i]->roomTileMap[c, r]);//getting the x and y of the room and putting the value in the dungeon map
			}
		}
	}
}

//method for getting the tile bitmap value
Bitmap^ TileMap::GetMapCellBitmap(int worldColumn,int worldRow) {
	int mapValue = map[worldColumn, worldRow];

	Bitmap^ tileImage = tileList->GetTileBitmap(mapValue);

	return tileImage;
}

//method for checking whether the tile is walkable
bool TileMap::isTileWalkable(int col, int row) {
	int tileIndex = map[col, row];
	if (tileList->isTileWalkable(tileIndex)) {
		return true;
	}
	else {
		return false;
	}
}

//method for getting the value of the bitmap in the fog map, simmilar to getmapcellbitmap method
Bitmap^ TileMap::GetFogMapCellBitmap(int worldColumn, int worldRow) {
	int mapValue = fogmap[worldColumn, worldRow];

	Bitmap^ tileImage = tileList->GetTileBitmap(mapValue);

	return tileImage;
}
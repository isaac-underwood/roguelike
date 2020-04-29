#include "TileList.h"

//constructor for tilelsit class
TileList::TileList(int startNTiles)
{
	nTiles = startNTiles;
	tileArray = gcnew array<Tile^>(startNTiles);
}

Bitmap^ TileList::GetTileBitmap(int tileIndex) { //get the bitmap of a certain index in the tile list
	return tileArray[tileIndex]->tileBitmap;
}

void TileList::SetTileArrayEntry(int tileIndex, Tile^ tileToEnter) {//set the bitmap of a certain index in the tile list
	tileArray[tileIndex] = tileToEnter;
}

bool TileList::isTileWalkable(int tileIndex) {//return the tile iswalkable bool, this method is used to check if the tile is walkable or not
	return tileArray[tileIndex]->isWalkable;
}

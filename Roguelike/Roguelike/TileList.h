#pragma once
#include "Tile.h"

ref class TileList
{
private:
	array<Tile^>^ tileArray;
	int nTiles;

public:
	TileList(int startNTiles);

	Bitmap^ GetTileBitmap(int tileIndex);

	void SetTileArrayEntry(int tileIndex, Tile^ tileToEnter);
	bool isTileWalkable(int tileIndex);
};


#include "Tile.h"

//contructor for tile class, this class holds the bitmap and the fields of iswalkable
Tile::Tile(Bitmap^ startTileBitmap, bool startisWalkable)
{
	tileBitmap = startTileBitmap;
	isWalkable = startisWalkable;
}

#pragma once
#include "TileList.h"
#include "Room.h"

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;

ref class TileMap
{
private:
	TileList^ tileList;
	array<Room^>^ allRooms;
	Graphics^ canvas;
	int nCols;
	int nRows;
	Random^ rGen;


public:
	TileMap(TileList^ startTileList, Graphics^ startCanvas, int startNCols, int startNRows, Random^ random);
	void SetMapEntry(int col, int row, int tileIndex);
	int GetMapEntry(int col, int row);
	void CreateFogMap();
	void PuttingTileIntoMap(array<Room^>^ rooms);
	Bitmap^ GetMapCellBitmap(int worldColumn, int worldRow);
	Bitmap^ GetFogMapCellBitmap(int worldColumn, int worldRow);
	bool isTileWalkable(int col, int row);
	property array<int, 2>^ map;
	property array<int, 2>^ fogmap;
};


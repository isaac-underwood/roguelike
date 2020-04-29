#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Tile
{
public:
	Tile(Bitmap^ startTileBitmap, bool startisWalkable);

	property Bitmap^ tileBitmap;
	property bool isWalkable;
};


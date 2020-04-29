#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "EItemType.h"
#include "Player.h"

ref class Item
{
public:
	Item(Graphics^ startCanvas, Random^ startRGen, int startXPos, int startYPos, int startFrameWidth, int startFrameHeight);
	Item(Graphics^ startCanvas, Random^ startRGen, int startXPos, int startYPos, Bitmap^ startItemImg, EItemType startItemType, int startFrameWidth, int startFrameHeight);
	property int xPos;
	property int yPos;
	property String^ Name;
	Item^ Next;
	void Draw();
	void UseAbility(Player^ player);
	void GenerateRandomType();
	bool CheckCollided(Player^ player);
	property EItemType ItemType;
	property Rectangle itemRec;
	void ForcedDraw(int forcedX, int forcedY);

private:
	Bitmap^ itemImg;
	Graphics^ canvas;
	Random^ rGen;
	
	int frameHeight;
	int frameWidth;
};


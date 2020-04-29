#pragma once
using namespace System::Diagnostics;
#include "TileMap.h"
#include "Sprite.h"
ref class Viewport
{
private:
	TileMap^ map;
	Graphics^ canvas;



public:
	Viewport(int startX, int startY, int startTilesWide, int startTilesHigh, TileMap^ startMap, Graphics^ startCanvas);
	void ViewportDraw(int spriteX, int spriteY);
	void MoveRelativeToPlayer(Sprite^ player);
	void ClearFog();
	void ViewportDrawFog(int spriteX, int spriteY);
	property int ViewportWorldX;
	property int ViewportWorldY;
	property int FogportWorldX;
	property int FogportWorldY;
	property bool FallOff;
	property int viewportTilesWide;
	property int viewportTilesHigh;


};


#include "Viewport.h"

#define TILEPIXEL 32
#define FOGSTARTX 22
#define FOGSTARTY 10
#define FOGWIDTH 32
#define FOGHEIGHT 20

//constructor for viewport
Viewport::Viewport(int startX, int startY, int startTilesWide, int startTilesHigh, TileMap^ startMap, Graphics^ startCanvas)
{
	ViewportWorldX = startX;
	ViewportWorldY = startY;
	viewportTilesWide = startTilesWide;
	viewportTilesHigh = startTilesHigh;
	map = startMap;
	canvas = startCanvas;
}

//method for drawing the viewport on the form, 
//the arguments given is used in the calculation to make the viewport draw halfway, 
//EG: tile pixel is 32 and the mod of the sprite position is 16 then the viewport will draw the tile halfway, if the mod is 0 then it will draw on the 0pixel of the tile
void Viewport::ViewportDraw(int spriteX, int spriteY) {
	for (int r = ViewportWorldY; r < (ViewportWorldY + viewportTilesHigh); r++) {
		for (int c = ViewportWorldX; c < (ViewportWorldX + viewportTilesWide); c++) {
			Bitmap^ mapBitmap = map->GetMapCellBitmap(c, r);//finding the tile which is in the view port
			int screenX = ((c - ViewportWorldX) * TILEPIXEL); // setting the x width position to draw
			int screenY = ((r - ViewportWorldY) * TILEPIXEL); // setting y 
			canvas->DrawImage(mapBitmap, screenX - (spriteX % TILEPIXEL), screenY - (spriteY % TILEPIXEL));
		}
	}

}

//method to calculate the viewport and set the x and y of the viewport
void Viewport::MoveRelativeToPlayer(Sprite^ sprite) {
	ViewportWorldX = (sprite->xPos - ((viewportTilesWide * TILEPIXEL) / 2)) / TILEPIXEL;
	ViewportWorldY = (sprite->yPos - ((viewportTilesHigh * TILEPIXEL) / 2)) / TILEPIXEL;
}

//method for drawing the fog on top of the viewport
void Viewport::ViewportDrawFog(int spriteX, int spriteY) {
	for (int r = ViewportWorldY; r < (ViewportWorldY + viewportTilesHigh); r++) {
		for (int c = ViewportWorldX; c < (ViewportWorldX + viewportTilesWide); c++) {
			Bitmap^ mapBitmap = map->GetFogMapCellBitmap(c, r);//finding the tile which is in the view port
			int screenX = ((c - ViewportWorldX) * TILEPIXEL); // setting the x width position to draw
			int screenY = ((r - ViewportWorldY) * TILEPIXEL); // setting the y height position to draw
			canvas->DrawImage(mapBitmap, screenX - (spriteX % TILEPIXEL), screenY - (spriteY % TILEPIXEL));
		}
	}
}

//method for clearing the fog, it will make the fog be transparent
void Viewport::ClearFog() {
	for (int r = ViewportWorldY+ FOGSTARTY; r < (ViewportWorldY + FOGHEIGHT); r++) {
		for (int c = ViewportWorldX+ FOGSTARTX; c < (ViewportWorldX + FOGWIDTH); c++) {
			map->fogmap[c, r] = ETileImage::TRANSPARENT;
		}
	}
}
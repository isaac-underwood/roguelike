#pragma once
#include "Sprite.h"
#include "Enemy.h"
//#include "EnemyList.h"

ref class Player :
	public Sprite
{
public:
	Player(Graphics^ startCanvas, array<Bitmap ^>^ startSpriteSheets, int startNFrames, Random^ startRGen, int formWid, int formHei, 
		Point startpos, TileMap^ startmap, int startDefence, int startStrength, int startHealth);
	bool CheckCurrentTile();
	int Attack(Sprite^ enemy) override;
	void PerformActionAcordingToState() override;
	void SetSpriteRecPos() override;
	void IncreaseMaxStrength(int increaseAmount);
	void IncreaseMaxDefence(int increaseAmount);
	void IncreaseMaxHealth(int increaseAmount);
	property int Gold;
private:
	
};


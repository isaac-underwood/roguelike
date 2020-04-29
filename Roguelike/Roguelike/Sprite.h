#pragma once
#include "ESpriteDirection.h"
#include "TileMap.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
public enum ESpriteState { MOVING, ATTACKING, CHASING };
ref class Sprite
{
protected:
	Graphics^ canvas;
	array<Bitmap ^>^ spriteSheets;
	Random^ rGen;
	int nFrames;
	int currentFrame;
	int frameWidth;
	int frameHeight;
	int formWidth;
	int formHeight;
	array<Point>^ velocityDirections;
	TileMap^ map;

public:
	Sprite^ Next;
	Sprite(Graphics^ startCanvas, array<Bitmap ^>^ startSpriteSheets, int startNFrames, Random^ startRGen, int formWid, int formHei, 
		Point startpos, TileMap^ startmap, int startDefence, int startStrength, int startHealth);
	void Move();
	void BombMove();
	void UpdateFrame();
	void SetSpriteSheet(array<Bitmap ^>^  newSpriteSheet, int newNFrames);
	virtual void Wander();
	virtual void PerformActionAcordingToState(Sprite^ player);
	void loadDirection();
	void ForcedDraw(int forcedX, int forcedY);
	void CheckNextTileThenMove(bool isBoss);
	bool CheckIsDead();
	bool CheckColidedWithTarget(Sprite^ target);
	virtual int Attack(Sprite^ player);
	virtual void SetSpriteRecPos();

	property int xPos;
	property int yPos;
	property int xVel;
	property int yVel;
	property int maxDefence;
	property int maxStrength;
	property int maxHealth;
	property bool attacking;
	property bool isDead;
	property int health;
	property Rectangle spriteRec;
	property ESpriteDirection spriteDirection;
	property ESpriteState spriteState;
};


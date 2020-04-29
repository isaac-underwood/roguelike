#pragma once

#include "Sprite.h"
#include "Viewport.h"
#include "Player.h"

using namespace System::Diagnostics;
ref class LinkedList
{
protected:
	Sprite^ head;
	Sprite^ tail;

public:
	LinkedList();
	void AddSprite(Sprite^ newSprite);
	void DeleteSprite(Sprite^ spriteToDelete);
	void PerformActionSprite(Sprite^ player);
	void MoveSprite();
	void WanderSprite();
	void UpdateFrame();
	Sprite^ CheckColided(Sprite^ player);
	void DeleteIfDead();
	void DeleteAllSprite();
	int ReturnInCombatSpriteHealth(Sprite^ player);
	int CountSprite();
	void DrawSpritesInViewport(Viewport^ viewport,Sprite^ knightPos);
};


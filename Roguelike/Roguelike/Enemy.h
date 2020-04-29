#pragma once
#include "Sprite.h"

ref class Enemy :
	public Sprite
{
public:
	Enemy(Graphics^ startCanvas, array<Bitmap ^>^ startSpriteSheets, int startNFrames, 
		Random^ startRGen, int formWid, int formHei, Point startpos, TileMap^ startmap,int startSpeed,
		int startDefence, int startStrength, int startHealth);
	Enemy^ Next; //a pointer to the next enemy in the EnemyList
	void Wander(Sprite^ player) override;
	int Attack(Sprite^ player) override;
	void PerformActionAcordingToState(Sprite^ player)override;
	void SetSpriteRecPos() override;
	void CheckColidedWithTargetBomb(Sprite^ player);
	void Orient(Sprite^ target);
	void Chase(Sprite^ target);
	bool CheckColidedWithTarget(Sprite^ player);
	double ComputeAngleToTarget(Sprite^ target);
	property Rectangle AggroRec;
private:
	int speed;
	int chaseDirectionBool;
};


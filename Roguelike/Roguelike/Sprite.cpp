#include "Sprite.h"

#define WANDERCHANCE 100
#define MAX_DIRECTION 8
#define INITIAL_VELOCITY 16
#define TILEPIXEL 32

//Constructor of the sprite class
Sprite::Sprite(Graphics^ startCanvas, array<Bitmap ^>^ startSpriteSheets, int startNFrames, Random^ startRGen, int formWid, int formHei, 
	Point startpos, TileMap^ startmap, int startDefence, int startStrength, int startHealth)
{
	canvas = startCanvas;
	rGen = startRGen;
	spriteSheets = startSpriteSheets;
	nFrames = startNFrames;
	frameWidth = (startSpriteSheets[0]->Width / startNFrames); //use the frame number to calculate the actual width of the single frame by deviding the width by the number of frame
	frameHeight = startSpriteSheets[0]->Height;
	formHeight = formHei;
	formWidth = formWid;
	spriteDirection = ESpriteDirection::EAST;
	yPos = startpos.Y;
	xPos = startpos.X;
	spriteRec = Rectangle(xPos, yPos, frameWidth, frameHeight);
	loadDirection();
	map = startmap;
	xVel = INITIAL_VELOCITY;
	yVel = INITIAL_VELOCITY;

	//Initialise combat stats
	maxDefence = startDefence;
	maxStrength = startStrength;
	maxHealth = startHealth;
	health = startHealth;
}

//loading the direction of the sprite. This sprite can have up to 8 direction. 
//But in this program we only include 4 direction.
void Sprite::loadDirection() {
	velocityDirections = gcnew array<Point>(MAX_DIRECTION);	
	int pos = 0;
	velocityDirections[pos++] = Point(1, 0);//east
	velocityDirections[pos++] = Point(0, 1);//south
	velocityDirections[pos++] = Point(-1, 0);//west
	velocityDirections[pos++] = Point(0, -1);//north
	velocityDirections[pos++] = Point(1, -1);//northeast
	velocityDirections[pos++] = Point(-1, -1);//northwest
	velocityDirections[pos++] = Point(1, 1);//southeast
	velocityDirections[pos] = Point(-1, 1);//southwest
}

//This is the vitual method which can be override in the child class
//It sets the sprite rectangle every time the sprite changes its position
void Sprite::SetSpriteRecPos() {
	// Base class does not set Rectangle
	// Empty code body. Not abstract, because we want to declare instances of
	// base class
}

//This is the move method.
//It's called in the timer tick and the position is set based on the velocity/direction the sprite is currently facing
void Sprite::Move() {		
	xPos += (xVel * velocityDirections[spriteDirection].X);
	yPos += (yVel * velocityDirections[spriteDirection].Y);
	SetSpriteRecPos();//setting the sprite rectangle position as well
}

//update the current frame on the sprite sheet
void Sprite::UpdateFrame() {
	currentFrame = (currentFrame + 1) % nFrames;
}

//method for setting a new sprite sheet
void Sprite::SetSpriteSheet(array<Bitmap ^>^  newSpriteSheet, int newNFrames) {//setting new sprite sheet
	spriteSheets = newSpriteSheet;
	nFrames = newNFrames;
}

//vitual method if sprite wanted to attack
int Sprite::Attack(Sprite^ target) {
	// Base class does not attack
	// Empty code body. Not abstract, because we want to declare instances of
	// base class
	return 0;
}

//wandering method(change velocity of x and  y randomly
void Sprite::Wander() {
	// Base class does not wander
	// Empty code body. Not abstract, because we want to declare instances of
	// base class
}

//this method force draw the sprite on the form. Given its xpos and ypos in the form
void Sprite::ForcedDraw(int forcedX, int forcedY) {//force draw the sprite to the middle of the form
		Rectangle drawRect = Rectangle(currentFrame * frameWidth, 0, frameWidth, frameHeight);
		canvas->DrawImage(spriteSheets[spriteDirection], forcedX, forcedY, drawRect, GraphicsUnit::Pixel);		
}

//method to check if the sprite is dead
bool Sprite::CheckIsDead() {
	if (health<=0) {
		isDead = true;
	}
	else {
		isDead = false;
	}
	return isDead;
}

//This method checks the tile in front of the sprite and see whether it is walkable or not
//the parameter "isBomb" is given to let the method know whether to use the Bombmove method
// or to use the normal move method. 
void Sprite::CheckNextTileThenMove(bool isBomb) {
	int tileX = (xPos) / TILEPIXEL;//calculating the tile the sprite is currently on
	int tileY = (yPos) / TILEPIXEL;
	int nextStepTile;
	switch (spriteDirection)
	{
		case EAST:
			//adding the next "step" the sprite will take, 
			//if its a walkable tile then allow it to move its position
			//The code is mostly the same for north,east,west,south
			//its just adding of subtracting the xVelocity,yVelocity
			nextStepTile = (xPos + xVel) / TILEPIXEL; 
			if (map->isTileWalkable(nextStepTile, tileY) == true) {
				if (isBomb) {
					BombMove();
				}
				else {
					Move();
				}	
			}
			break;
		case SOUTH:
			nextStepTile = (yPos + yVel) / TILEPIXEL;
			if (map->isTileWalkable(tileX, nextStepTile) == true) {
				if (isBomb) {
					BombMove();
				}
				else {
					Move();
				}
			}
			break;
		case WEST:
			nextStepTile = (xPos - xVel) / TILEPIXEL;
			if (map->isTileWalkable(nextStepTile, tileY) == true) {
				if (isBomb) {
					BombMove();
				}
				else {
					Move();
				}
			}
			break;
		case NORTH:
			nextStepTile = (yPos - yVel) / TILEPIXEL;
			if (map->isTileWalkable(tileX, nextStepTile) == true) {
				if (isBomb) {
					BombMove();
				}
				else {
					Move();
				}
			}
			break;
		default:
			break;
	}
}

//checking the sprite is colliding with another sprite
bool Sprite::CheckColidedWithTarget(Sprite^ target) {
	if (this->spriteRec.IntersectsWith(target->spriteRec)) {
		return true;
	}
	return false;
}

//different move method for bomb, because it doesnt have or use the direction sprite fields to move
void Sprite::BombMove() {
	xPos += xVel;
	yPos += yVel;
	SetSpriteRecPos();
}

//FSM for the sprite
void Sprite::PerformActionAcordingToState(Sprite^ player) {
	// Base class does not PerformActionAcordingToState
	// Empty code body. Not abstract, because we want to declare instances of
	// base class
}
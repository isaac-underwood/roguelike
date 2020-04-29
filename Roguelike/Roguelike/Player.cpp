#include "Player.h"

#define ATTACKCHANCE 100
#define INITIAL_VELOCITY 16
#define TILEPIXEL 32
#define MAXHEALTH 100
#define PLAYERRECPADDINGX 10
#define PLAYERRECPADDINGY 5
#define ATTACKCHANCE_MAX 100
#define CHANCE_NO_ATTACK 7
#define ATTACK_MULTIPLIER 1.6
#define DEFENCE_MULTIPLIER 2
#define MAX_RANDOM_DAMAGE_DEDUCTION_DIVIDER 10

Player::Player(Graphics^ startCanvas, array<Bitmap ^>^ startSpriteSheets, int startNFrames, Random^ startRGen, int formWid, int formHei, 
	Point startpos, TileMap^ startmap, int startDefence, int startStrength, int startHealth)
	: Sprite(startCanvas, startSpriteSheets, startNFrames, startRGen, formWid, formHei, startpos, startmap, startDefence, startStrength, startHealth)
{
	health = MAXHEALTH;
}

//checking the currect tile the player is standing on
bool Player::CheckCurrentTile() {
	bool isDoor = false;
	//calculating the tile the player is on using its position and dividing it by 32pixel and get the value of the tile in the tilemap class
	int tileX = (xPos) / TILEPIXEL;
	int tileY = (yPos) / TILEPIXEL;
	//checking if it is standing on the healing pad
	if (map->map[tileX, tileY] == ETileImage::HEALINGPAD&&health< maxHealth) {
		health++;
	}	
	//checking if it is standing on the door
	if (map->map[tileX, tileY] == ETileImage::DOOR) {
		isDoor = true;
	}
	return isDoor;
}

//override method called attack 
int Player::Attack(Sprite^ enemy) {		
	int maxRandomDamageDeduction = enemy->maxHealth / MAX_RANDOM_DAMAGE_DEDUCTION_DIVIDER;
	int randomDamageDeduction = rGen->Next(maxRandomDamageDeduction);

	//Calculate the damage dealt to the player
	int damageDealtToEnemy = (maxStrength * ATTACK_MULTIPLIER) - (enemy->maxDefence / DEFENCE_MULTIPLIER) - randomDamageDeduction;

	int noAttack = rGen->Next(ATTACKCHANCE_MAX); //Random chance that no damage is dealt
	if (noAttack >= CHANCE_NO_ATTACK)
	{
		return damageDealtToEnemy;
	}

	return 0;
}

//setting the rectangle for this sprite
//similar to the enemy's setspriterecpos but the value of the padding and width is different
void Player::SetSpriteRecPos() {
	spriteRec = Rectangle((xPos)+PLAYERRECPADDINGX, (yPos)+PLAYERRECPADDINGY, frameWidth / 2, frameHeight/2);
}

//FSM for the sprite
void Player::PerformActionAcordingToState() {
	switch (spriteState)
	{
	case MOVING:
		xVel = INITIAL_VELOCITY;
		yVel = INITIAL_VELOCITY;
		break;
	case ATTACKING:
		xVel = 0;
		yVel = 0;
		break;
	case CHASING:
		break;
	default:
		break;
	}
}

void Player::IncreaseMaxDefence(int increaseAmount)
{
	maxDefence += increaseAmount;
}

void Player::IncreaseMaxHealth(int increaseAmount)
{
	maxHealth += increaseAmount;
	health = maxHealth;
}

void Player::IncreaseMaxStrength(int increaseAmount)
{
	maxStrength += increaseAmount;
}
#include "Enemy.h"

#define DIRECTION_COUNT 4

#define PLAYERLOCATIONPADDING 10
#define ATTACKCHANCE 100
#define ATTACKPERCENT 50
#define POSPADDINGFORAGGROREC 50
#define SIZEPADDINGFORAGGROREC 90
#define BOMBER_ATTACK 20
#define AGGRORECTANGLEPADDING 10
#define ATTACKCHANCE_MAX 100
#define CHANCE_NO_ATTACK 5
#define ATTACK_MULTIPLIER 1.2
#define DEFENCE_MULTIPLIER 1.8
#define MAX_RANDOM_DAMAGE_DEDUCTION_DIVIDER 12


//Constructor for the enemy class
Enemy::Enemy(Graphics^ startCanvas, array<Bitmap ^>^ startSpriteSheets, int startNFrames, Random^ startRGen, 
	int formWid, int formHei, Point startpos, TileMap^ startmap, int startSpeed,
	int startDefence, int startStrength, int startHealth)
	: Sprite(startCanvas, startSpriteSheets, startNFrames, startRGen, formWid, formHei, startpos, startmap, startDefence, startStrength, startHealth)
{
	health = 10;
	speed = startSpeed;
	xVel = speed;
	yVel = speed;
	AggroRec = Rectangle(spriteRec.X, spriteRec.Y, spriteRec.Width + AGGRORECTANGLEPADDING, spriteRec.Height + AGGRORECTANGLEPADDING);
}

//override attack method for enemy
int Enemy::Attack(Sprite^ player) {
	int maxRandomDamageDeduction = player->maxHealth / MAX_RANDOM_DAMAGE_DEDUCTION_DIVIDER;
	int randomDamageDeduction = rGen->Next(maxRandomDamageDeduction);

	//Calculate the damage dealt to the player
	int damageDealtToEnemy = (maxStrength * ATTACK_MULTIPLIER) - (player->maxDefence / DEFENCE_MULTIPLIER);

	int noAttack = rGen->Next(ATTACKCHANCE_MAX); //Random chance that no damage is dealt
	if (noAttack >= CHANCE_NO_ATTACK)
	{
		return damageDealtToEnemy;
	}

	return 0;
}

//checing the collision with the other sprite
bool Enemy::CheckColidedWithTarget(Sprite^ target) {
	//AggroRec is the rectangle where if the target intersects with it will change its state to 
	//be in a chasing state and chase after the target
	//once it is out of the Aggro area it will chage its state to a moving/wandering state
	if (this->AggroRec.IntersectsWith(target->spriteRec)) {
		spriteState = ESpriteState::CHASING; //state for chasing the target
		return true;
	}
	else {
		spriteState = ESpriteState::MOVING; //state for moving itself
	}
	return false;
}

//method specificly for the bomb enemy
//it becomes dead once it hits the target.
//like a suicide bomber
void Enemy::CheckColidedWithTargetBomb(Sprite^ target) {
	if (spriteRec.IntersectsWith(target->spriteRec) && isDead == false) {
		isDead = true;
		target->health -= BOMBER_ATTACK;
	}
}

//setting the sprite rectangle and also for the aggrorectangle
void Enemy::SetSpriteRecPos() {
	spriteRec = Rectangle((xPos + (frameWidth / 3)), (yPos + (frameHeight / 3)), frameWidth / 2, frameHeight / 2);
	AggroRec = Rectangle(spriteRec.X- POSPADDINGFORAGGROREC, spriteRec.Y- POSPADDINGFORAGGROREC, spriteRec.Width + SIZEPADDINGFORAGGROREC, spriteRec.Height + SIZEPADDINGFORAGGROREC);
}

//perform the fsm action
void Enemy::PerformActionAcordingToState(Sprite^ enemy) {
	switch (spriteState)
	{
	case MOVING:
		Wander(enemy);
		break;
	case ATTACKING:
		attacking = true;
		Attack(enemy);
		break;
	case CHASING:
		Chase(enemy);
		break;
	default:
		break;
	}
	CheckNextTileThenMove(false);
}

//wandering method change velocity of x and  y
//it also checks whether it is collided with another sprite(player)
void Enemy::Wander(Sprite^ player) {
	switch (rGen->Next(DIRECTION_COUNT))
	{
	case 0:
		spriteDirection = ESpriteDirection::WEST;
		break;
	case 1:
		spriteDirection = ESpriteDirection::EAST;
		break;
	case 2:
		spriteDirection = ESpriteDirection::NORTH;
		break;
	case 3:
		spriteDirection = ESpriteDirection::SOUTH;
		break;
	default:
		break;
	}
	CheckColidedWithTarget(player); //checking whether it has collided with the player
}

//This method lets the sprite chase the player
//it calculated the distance and angle of itself and the player
void Enemy::Chase(Sprite^ player) {

	//i did a boolean switch for setting the direction of the sprite.
	//this is a work around because we did not implement 8 direct for the sprite
	//if there is no boolean switch. the sprite will just use the last sprite direction
	//it will follow the player in just 1 axis instead of 2 axis
	//i can explain it better face to face, it's hard to turn it into words

	if (chaseDirectionBool) {
		//set the X direction inside this if statement 
		if ((Math::Sin(ComputeAngleToTarget(player)))*speed < 0) {
			spriteDirection = ESpriteDirection::NORTH;
		}
		if ((Math::Sin(ComputeAngleToTarget(player)))*speed > 0) {
			spriteDirection = ESpriteDirection::SOUTH;
		}
	}
	else {
		//set the Y direction inside this if statement 
		if ((Math::Cos(ComputeAngleToTarget(player)))*speed < 0) {
			spriteDirection = ESpriteDirection::WEST;
		}
		if ((Math::Cos(ComputeAngleToTarget(player)))*speed > 0) {
			spriteDirection = ESpriteDirection::EAST;
		}
	}
	chaseDirectionBool = !chaseDirectionBool;//flip the boolean switch
	CheckColidedWithTarget(player);
}

//orient method used by the bomb. it calculates the angle between itself and the player and changes its velocity according to the angle
void Enemy::Orient(Sprite^ target){
	xVel = (Math::Cos(ComputeAngleToTarget(target)))*speed;
	yVel = (Math::Sin(ComputeAngleToTarget(target)))*speed;
}

//method that calculates the angle between itself and the player 
double Enemy::ComputeAngleToTarget(Sprite^ target) {
	double angle;
	int xDelta = target->xPos - xPos;
	int yDelta = target->yPos - yPos;
	if ((xDelta != 0) && (yDelta != 0))
	{
		// Check order of args
		// atan2 returns the angle of rotation between two points with vertical distance arg1 and horizontal distance arg2
		angle = Math::Atan2(yDelta, xDelta);	// result is in radians
	}
	else {
		angle = 0.0;	// instance and target share an x or y axis location. This works as a heuristic
	}
	return angle;
}

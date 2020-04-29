#include "LinkedList.h"

//Constructor for the linkedlist class, it sets the first and last item in the list as nullptr
LinkedList::LinkedList(){
	head = nullptr;
	tail = nullptr;
}

//adding the sprite will set the new sprite as the last sprite
void LinkedList::AddSprite(Sprite^ newSprite) {//add sprite
	if (tail == nullptr) {//if no sprite in list then add the first sprite as tail and head
		head = newSprite;
		tail = newSprite;
	}
	else {//if there is sprite then add the new sprite as a tail
		tail->Next = newSprite;
		tail = newSprite;
	}
}

//deleting sprite method
void LinkedList::DeleteSprite(Sprite^ spriteToDelete) {
	Sprite^ nodeWalker = head;
	if (nodeWalker == spriteToDelete) {
		if (nodeWalker->Next == nullptr) {//check if its only 1 sprite if so then set the sprite list to empty
			head = nullptr;
			tail = nullptr;
		}
		else {//if theres more than 2 then point the head to the next sprite
			head = nodeWalker->Next;
		}
	}
	else
	{
		while (nodeWalker->Next != spriteToDelete) { // if its not the first sprite then point the sprite to the next sprite
			nodeWalker = nodeWalker->Next;
		}
		nodeWalker->Next = spriteToDelete->Next; //setting the pointer to the next of the sprite that you want to delete.
	}
}

//method to delete all the sprite by setting the head and tail ptr to be null
void LinkedList::DeleteAllSprite() {
	head = nullptr;
	tail = nullptr;
}

//this method deletes a sprite when it is dead
void LinkedList::DeleteIfDead() {
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr) {
		if (nodeWalker->isDead == true) { //if the sprite is dead then delete the sprite by calling the delete sprite method
			DeleteSprite(nodeWalker);
		}
		nodeWalker = nodeWalker->Next;
	}
}

//move sprite
void LinkedList::MoveSprite() {
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr) {
		nodeWalker->CheckNextTileThenMove(false); //calling the check next tile move method.
		nodeWalker = nodeWalker->Next;
	}
}

//wander the sprite by randoming its direction
void LinkedList::WanderSprite() {
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr) {
		nodeWalker->Wander();
		nodeWalker = nodeWalker->Next;
	}
}

//count sprite
int LinkedList::CountSprite() {
	Sprite^ nodeWalker = head;
	int count = 0;
	while (nodeWalker != nullptr) {
		count++;
		nodeWalker = nodeWalker->Next;
	}
	return count;
}

void LinkedList::DrawSpritesInViewport(Viewport^ viewport, Sprite^ knightPos) {
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr) {
		int spriteViewPortLocationX = nodeWalker->xPos -(viewport->ViewportWorldX * 32) - knightPos->xPos % 32;
		int spriteViewPortLocationY = nodeWalker->yPos -(viewport->ViewportWorldY * 32) - knightPos->yPos % 32;
			nodeWalker->ForcedDraw(spriteViewPortLocationX-16, spriteViewPortLocationY-10);
		nodeWalker = nodeWalker->Next;
	}
}

void LinkedList::UpdateFrame() {
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr) {
		nodeWalker->UpdateFrame();
		nodeWalker = nodeWalker->Next;
	}
}

Sprite^ LinkedList::CheckColided(Sprite^ player) {
	Sprite^ nodeWalker = head;

	while (nodeWalker != nullptr) {
		if (nodeWalker->CheckColidedWithTarget(player) == true)
		{
			return nodeWalker;
		}

		nodeWalker = nodeWalker->Next;
	}
	return nullptr;
}

//getting the health of the sprite that is in combat with the player
int LinkedList::ReturnInCombatSpriteHealth(Sprite^ player) {
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr) {
		if (nodeWalker->spriteRec.IntersectsWith(player->spriteRec)) {
			return nodeWalker->health;			
		}
		nodeWalker = nodeWalker->Next;
	}
}

//FSM for sprite list
void LinkedList::PerformActionSprite(Sprite^ player) { 
	Sprite^ nodeWalker = head;
	while (nodeWalker != nullptr) {
		nodeWalker->PerformActionAcordingToState(player);
		nodeWalker = nodeWalker->Next;
	}
}

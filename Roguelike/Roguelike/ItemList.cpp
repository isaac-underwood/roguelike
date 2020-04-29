#include "ItemList.h"

#define TILE_SIZE 32


ItemList::ItemList()
{
	head = nullptr;
	tail = nullptr;
}

void ItemList::AddItem(Item^ newItem)
{
	if (tail == nullptr)
	{
		head = newItem;
		tail = newItem;
	}

	else
	{
		tail->Next = newItem;
		tail = newItem;
	}
}

void ItemList::DeleteItem(Item^ itemToDelete)
{
	Item^ nodeWalker = head;

	if (nodeWalker == tail)
	{
		head = nullptr;
		tail = nullptr;
	}

	else if (itemToDelete == nodeWalker)
	{
		head = nodeWalker->Next;
	}

	else
	{
		while (nodeWalker->Next != itemToDelete)
		{
			nodeWalker = nodeWalker->Next;

			if (itemToDelete == tail)
			{
				tail = nodeWalker;
			}
		}

		nodeWalker->Next = itemToDelete->Next;
	}
}

void ItemList::GenerateItemTypes()
{
	Item^ nodeWalker = head;

	while (nodeWalker != nullptr)
	{
		nodeWalker->GenerateRandomType();

		nodeWalker = nodeWalker->Next;
	}
}

void ItemList::UseAbilities(Player^ player)
{
	Item^ nodeWalker = head;

	while (nodeWalker != nullptr)
	{
		nodeWalker->UseAbility(player);

		nodeWalker = nodeWalker->Next;
	}
}

void ItemList::DrawItems()
{
	Item^ nodeWalker = head;

	while (nodeWalker != nullptr)
	{
		nodeWalker->Draw();

		nodeWalker = nodeWalker->Next;
	}
}

int ItemList::CountItems()
{
	return -1;
}

void ItemList::DrawItemsInViewport(Viewport^ viewport, Player^ knightPos) {
	Item^ nodeWalker = head;
	while (nodeWalker != nullptr) {
		int spriteViewPortLocationX = nodeWalker->xPos - (viewport->ViewportWorldX * TILE_SIZE) - knightPos->xPos % TILE_SIZE;
		int spriteViewPortLocationY = nodeWalker->yPos - (viewport->ViewportWorldY * TILE_SIZE) - knightPos->yPos % TILE_SIZE;
		nodeWalker->ForcedDraw(spriteViewPortLocationX, spriteViewPortLocationY);
		nodeWalker = nodeWalker->Next;
	}
}

void ItemList::CheckCollided(Player^ player)
{
	Item^ nodeWalker = head;

	while (nodeWalker != nullptr) {
		//Check if nodewalker has collided with player
		if (nodeWalker->CheckCollided(player))
		{
			DeleteItem(nodeWalker); //remove item from list
		}
		nodeWalker = nodeWalker->Next;
	}
}
#pragma once
#include "LinkedList.h"
#include "Item.h"

ref class ItemList :
	public LinkedList
{
public:
	ItemList(void);
	void AddItem(Item^ newItem);
	void DeleteItem(Item^ itemToDelete);
	void DrawItems();
	void UseAbilities(Player^ player);
	void GenerateItemTypes();
	int CountItems();
	void DrawItemsInViewport(Viewport^ viewport, Player^ player);
	void CheckCollided(Player^ player);
private:
	Item^ head;
	Item^ tail;
};


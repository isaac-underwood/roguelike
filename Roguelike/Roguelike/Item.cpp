#include "Item.h"

#define INCREASE_DEFENCE_VALUE 10
#define INCREASE_STRENGTH_VALUE 15
#define INCREASE_HEALTH_VALUE 25
#define ITEM_TYPE_COUNT 4
#define GOLD_AMOUNT 5

#define HEALTH_IMAGE_PATH "health.png"
#define STRENGTH_IMAGE_PATH "strength.png"
#define DEFENCE_IMAGE_PATH "defence.png"
#define GOLD_IMAGE_PATH "gold.png"

//Constructor is for items that will randomly generate an item type
Item::Item(Graphics^ startCanvas, Random^ startRGen, int startXPos, int startYPos, int startFrameWidth, int startFrameHeight)
{
	canvas = startCanvas;
	xPos = startXPos;
	yPos = startYPos;
	rGen = startRGen;
	frameWidth = startFrameWidth;
	frameHeight = startFrameHeight;

	itemRec = Rectangle(xPos, yPos, frameWidth, frameHeight);
}

//Constructor is for items that have their type pre-defined and do not randomly generate an item type
Item::Item(Graphics^ startCanvas, Random^ startRGen, int startXPos, int startYPos, Bitmap^ startItemImg, EItemType startItemType, int startFrameWidth, int startFrameHeight)
{
	canvas = startCanvas;
	xPos = startXPos;
	yPos = startYPos;
	rGen = startRGen;
	frameWidth = startFrameWidth;
	frameHeight = startFrameHeight;
	itemImg = startItemImg;
	ItemType = startItemType;

	itemRec = Rectangle(xPos, yPos, frameWidth, frameHeight);
}

//Randomly Generates an ItemType for the Item and sets the Item bitmap
void Item::GenerateRandomType()
{
	ItemType = (EItemType)rGen->Next(ITEM_TYPE_COUNT);
	switch (ItemType)
	{
		case HEALTH_POTION:
			itemImg = gcnew Bitmap(HEALTH_IMAGE_PATH);
			break;
		case DEFENCE_POTION:
			itemImg = gcnew Bitmap(DEFENCE_IMAGE_PATH);
			break;
		case STRENGTH_POTION:
			itemImg = gcnew Bitmap(STRENGTH_IMAGE_PATH);
			break;
		case GOLD:
			itemImg = gcnew Bitmap(GOLD_IMAGE_PATH);
			break;
		default:
			break;
	}
}

void Item::Draw()
{
	itemRec = Rectangle(xPos, yPos, frameWidth, frameHeight);
	canvas->DrawImage(itemImg, xPos, yPos);
}

//Force draw the item on the screen
void Item::ForcedDraw(int forcedX, int forcedY) {
	Rectangle drawRect = Rectangle(0, 0, frameWidth, frameHeight);
	canvas->DrawImage(itemImg, forcedX, forcedY, drawRect, GraphicsUnit::Pixel);
}

//Uses the item's ability on the player which is defined by the ItemType
void Item::UseAbility(Player^ player)
{
	switch (ItemType)
	{
		case HEALTH_POTION:
			player->IncreaseMaxHealth(INCREASE_HEALTH_VALUE);
			break;
		case DEFENCE_POTION:
			player->IncreaseMaxDefence(INCREASE_DEFENCE_VALUE);
			break;
		case STRENGTH_POTION:
			player->IncreaseMaxStrength(INCREASE_STRENGTH_VALUE);
			break;
		case GOLD:
			player->Gold += GOLD_AMOUNT;
			break;
		default:
			break;
	}
}

//Checks if a player has collided with the item and uses the item's ability on the player if true
bool Item::CheckCollided(Player^ player)
{
	if (itemRec.IntersectsWith(player->spriteRec)) //Check if item and player rectangles intersect
	{
		UseAbility(player); //Use item ability on player

		return true;
	}
	return false;
}
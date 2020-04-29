#pragma once
#include "Tile.h"
#include "TileList.h"
#include "TileMap.h"
#include"Sprite.h"
#include"ESpriteDirection.h"
#include"ETileImage.h"
#include "EItemType.h"
#include "Viewport.h"
#include "LinkedList.h"
#include "Dungeon.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "ItemList.h"

#define NROW 150
#define NCOL 150
#define NTILE 8
#define TILEPIXEL 32
#define NUMBEROFROOM 10

#define FRAMEINSPRITESHEET 8
#define MAXDIRECTION 4
#define PLAYERLOCATIONPADDINGX 10
#define PLAYERLOCATIONPADDINGY 10

#define PLAYER_START_STRENGTH 25
#define PLAYER_START_DEFENCE 20
#define PLAYER_START_HEALTH 100

#define ENEMY_START_STAT_MIN 15
#define ENEMY_START_STAT_MAX 75
#define ENEMY_START_HEALTH_MIN 75
#define ENEMY_START_HEALTH_MAX 200

#define ENEMY_NORMAL_START_SPEED 4
#define ENEMY_BOMB_START_SPEED 16
#define ENEMY_START_COUNT 1

#define ATTACK_DELAY_TICK 6

#define ITEM_DROP_CHANCE 25
#define ITEM_DROP_CHANCE_MAX 100
#define ITEM_DIMENSION 18
#define GOLD_PAD_MIN 50
#define GOLD_PAD_MAX 100

namespace Roguelike {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	/// <summary>
	/// Summary for GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		TileMap^ tileMap;
		TileList^ tileList;
		Dungeon^ dungeon;
		Graphics^ canvas;
		Random^ rGen;
		Viewport^ viewport;
		Bitmap^ bufferImage;
		Graphics^ bufferGraphics;
		Player^ knight;
		Enemy^ enemyBomb;
		System::Windows::Forms::Timer^  timer1;
		int bombTickCount;
		System::Windows::Forms::Label^  lblPlayerCurrentHealth;
		int enemiesCount;
		int attackTickCount;
		int currentAttackerTick;
		LinkedList^ enemies;
		ItemList^ items;
	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Panel^  panelGame;
	private: System::Windows::Forms::Panel^  panelPlayerInfo;
	private: System::Windows::Forms::Label^  labelPlayerTitle;


	private: System::Windows::Forms::Label^  lblPlayerMaxHealth;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  lblPlayerDefenceMax;

	private: System::Windows::Forms::Label^  label10;



	private: System::Windows::Forms::Label^  lblPlayerMaxStrength;
	private: System::Windows::Forms::Label^  label8;

	private: System::Windows::Forms::PictureBox^  picPlayer;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;


	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  lblEnemyMaxStrength;

	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  lblEnemyHealthCurrent;


	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Panel^  panelItems;
	private: System::Windows::Forms::Label^  label3;

			 Sprite^ healingFountain;


		System::Windows::Forms::Panel^  panelEnemyInfo;
		System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
private: System::Windows::Forms::Panel^  panel7;
private: System::Windows::Forms::Label^  label6;


private: System::Windows::Forms::Panel^  pnlWelcome;
private: System::Windows::Forms::Label^  lblRoguelikeWelcome;
private: System::Windows::Forms::Button^  btnQuit;

private: System::Windows::Forms::Button^  btnPlay;
private: System::Windows::Forms::Button^  btnHowToPlay;
private: System::Windows::Forms::Panel^  pnlHowToPlay;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Button^  btnCloseHelp;
private: System::Windows::Forms::Label^  lblGold;
private: System::Windows::Forms::PictureBox^  picGold;
private: System::Windows::Forms::Panel^  pnlGold;
private: System::Windows::Forms::Label^  label7;





		System::Windows::Forms::PictureBox^  picEnemy;



#pragma region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblPlayerCurrentHealth = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panelGame = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panelPlayerInfo = (gcnew System::Windows::Forms::Panel());
			this->picPlayer = (gcnew System::Windows::Forms::PictureBox());
			this->lblPlayerDefenceMax = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->lblPlayerMaxStrength = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblPlayerMaxHealth = (gcnew System::Windows::Forms::Label());
			this->labelPlayerTitle = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->lblEnemyHealthCurrent = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->lblEnemyMaxStrength = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panelItems = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panelEnemyInfo = (gcnew System::Windows::Forms::Panel());
			this->picEnemy = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pnlWelcome = (gcnew System::Windows::Forms::Panel());
			this->pnlHowToPlay = (gcnew System::Windows::Forms::Panel());
			this->btnCloseHelp = (gcnew System::Windows::Forms::Button());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->btnQuit = (gcnew System::Windows::Forms::Button());
			this->btnHowToPlay = (gcnew System::Windows::Forms::Button());
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->lblRoguelikeWelcome = (gcnew System::Windows::Forms::Label());
			this->pnlGold = (gcnew System::Windows::Forms::Panel());
			this->picGold = (gcnew System::Windows::Forms::PictureBox());
			this->lblGold = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panelGame->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panelPlayerInfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPlayer))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panelEnemyInfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picEnemy))->BeginInit();
			this->pnlWelcome->SuspendLayout();
			this->pnlHowToPlay->SuspendLayout();
			this->pnlGold->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGold))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &GameForm::timer1_Tick);
			// 
			// lblPlayerCurrentHealth
			// 
			this->lblPlayerCurrentHealth->AutoSize = true;
			this->lblPlayerCurrentHealth->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPlayerCurrentHealth->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->lblPlayerCurrentHealth->Location = System::Drawing::Point(79, 92);
			this->lblPlayerCurrentHealth->Name = L"lblPlayerCurrentHealth";
			this->lblPlayerCurrentHealth->Size = System::Drawing::Size(25, 14);
			this->lblPlayerCurrentHealth->TabIndex = 0;
			this->lblPlayerCurrentHealth->Text = L"100";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->label2->Location = System::Drawing::Point(6, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 14);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Health";
			// 
			// panelGame
			// 
			this->panelGame->Controls->Add(this->panel7);
			this->panelGame->Controls->Add(this->label9);
			this->panelGame->Location = System::Drawing::Point(2, 9);
			this->panelGame->Name = L"panelGame";
			this->panelGame->Size = System::Drawing::Size(1696, 1008);
			this->panelGame->TabIndex = 4;
			this->panelGame->Visible = false;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->label7);
			this->panel7->Controls->Add(this->label6);
			this->panel7->Location = System::Drawing::Point(0, 883);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(1902, 138);
			this->panel7->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Red;
			this->label6->Location = System::Drawing::Point(10, 13);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(269, 29);
			this->label6->TabIndex = 17;
			this->label6->Text = L"CONTROLS: Arrow Keys\r\n";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Red;
			this->label9->Location = System::Drawing::Point(1364, 11);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(12, 14);
			this->label9->TabIndex = 11;
			this->label9->Text = L"/";
			this->label9->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panelPlayerInfo
			// 
			this->panelPlayerInfo->Controls->Add(this->picPlayer);
			this->panelPlayerInfo->Controls->Add(this->lblPlayerDefenceMax);
			this->panelPlayerInfo->Controls->Add(this->label10);
			this->panelPlayerInfo->Controls->Add(this->lblPlayerMaxStrength);
			this->panelPlayerInfo->Controls->Add(this->label8);
			this->panelPlayerInfo->Controls->Add(this->label1);
			this->panelPlayerInfo->Controls->Add(this->lblPlayerMaxHealth);
			this->panelPlayerInfo->Controls->Add(this->labelPlayerTitle);
			this->panelPlayerInfo->Controls->Add(this->label2);
			this->panelPlayerInfo->Controls->Add(this->lblPlayerCurrentHealth);
			this->panelPlayerInfo->Location = System::Drawing::Point(1727, 92);
			this->panelPlayerInfo->Name = L"panelPlayerInfo";
			this->panelPlayerInfo->Size = System::Drawing::Size(148, 240);
			this->panelPlayerInfo->TabIndex = 5;
			// 
			// picPlayer
			// 
			this->picPlayer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picPlayer.Image")));
			this->picPlayer->Location = System::Drawing::Point(57, 35);
			this->picPlayer->Name = L"picPlayer";
			this->picPlayer->Size = System::Drawing::Size(32, 32);
			this->picPlayer->TabIndex = 12;
			this->picPlayer->TabStop = false;
			// 
			// lblPlayerDefenceMax
			// 
			this->lblPlayerDefenceMax->AutoSize = true;
			this->lblPlayerDefenceMax->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPlayerDefenceMax->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->lblPlayerDefenceMax->Location = System::Drawing::Point(79, 145);
			this->lblPlayerDefenceMax->Name = L"lblPlayerDefenceMax";
			this->lblPlayerDefenceMax->Size = System::Drawing::Size(14, 14);
			this->lblPlayerDefenceMax->TabIndex = 10;
			this->lblPlayerDefenceMax->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->label10->Location = System::Drawing::Point(6, 145);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(50, 14);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Defence";
			// 
			// lblPlayerMaxStrength
			// 
			this->lblPlayerMaxStrength->AutoSize = true;
			this->lblPlayerMaxStrength->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPlayerMaxStrength->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->lblPlayerMaxStrength->Location = System::Drawing::Point(79, 120);
			this->lblPlayerMaxStrength->Name = L"lblPlayerMaxStrength";
			this->lblPlayerMaxStrength->Size = System::Drawing::Size(18, 14);
			this->lblPlayerMaxStrength->TabIndex = 6;
			this->lblPlayerMaxStrength->Text = L"10";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->label8->Location = System::Drawing::Point(6, 120);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(53, 14);
			this->label8->TabIndex = 5;
			this->label8->Text = L"Strength";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->label1->Location = System::Drawing::Point(102, 92);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(12, 14);
			this->label1->TabIndex = 3;
			this->label1->Text = L"/";
			// 
			// lblPlayerMaxHealth
			// 
			this->lblPlayerMaxHealth->AutoSize = true;
			this->lblPlayerMaxHealth->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPlayerMaxHealth->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->lblPlayerMaxHealth->Location = System::Drawing::Point(114, 92);
			this->lblPlayerMaxHealth->Name = L"lblPlayerMaxHealth";
			this->lblPlayerMaxHealth->Size = System::Drawing::Size(25, 14);
			this->lblPlayerMaxHealth->TabIndex = 2;
			this->lblPlayerMaxHealth->Text = L"100";
			// 
			// labelPlayerTitle
			// 
			this->labelPlayerTitle->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPlayerTitle->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->labelPlayerTitle->Location = System::Drawing::Point(5, 9);
			this->labelPlayerTitle->Name = L"labelPlayerTitle";
			this->labelPlayerTitle->Size = System::Drawing::Size(140, 23);
			this->labelPlayerTitle->TabIndex = 0;
			this->labelPlayerTitle->Text = L"PLAYER";
			this->labelPlayerTitle->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Location = System::Drawing::Point(1699, 65);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(27, 968);
			this->panel1->TabIndex = 7;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label23);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Controls->Add(this->label22);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->lblEnemyHealthCurrent);
			this->panel2->Controls->Add(this->label16);
			this->panel2->Controls->Add(this->lblEnemyMaxStrength);
			this->panel2->Controls->Add(this->label18);
			this->panel2->Controls->Add(this->label19);
			this->panel2->Controls->Add(this->label20);
			this->panel2->Controls->Add(this->label21);
			this->panel2->Location = System::Drawing::Point(1727, 361);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(148, 295);
			this->panel2->TabIndex = 8;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::Color::Red;
			this->label23->Location = System::Drawing::Point(5, 208);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(143, 56);
			this->label23->TabIndex = 16;
			this->label23->Text = L"Deals 20 damage when in \r\ncontact with you.\r\nWill Die in 10 seconds if it \r\ndoesn"
				L"\'t reach you.\r\n";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(53, 176);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(87, 14);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Suicide Blobbo";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(10, 172);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(32, 32);
			this->pictureBox2->TabIndex = 14;
			this->pictureBox2->TabStop = false;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::Color::Red;
			this->label22->Location = System::Drawing::Point(7, 139);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(76, 14);
			this->label22->TabIndex = 13;
			this->label22->Text = L"Enemies Left";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(57, 35);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(32, 32);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Red;
			this->label13->Location = System::Drawing::Point(84, 139);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(14, 14);
			this->label13->TabIndex = 8;
			this->label13->Text = L"0";
			// 
			// lblEnemyHealthCurrent
			// 
			this->lblEnemyHealthCurrent->AutoSize = true;
			this->lblEnemyHealthCurrent->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEnemyHealthCurrent->ForeColor = System::Drawing::Color::Red;
			this->lblEnemyHealthCurrent->Location = System::Drawing::Point(73, 83);
			this->lblEnemyHealthCurrent->Name = L"lblEnemyHealthCurrent";
			this->lblEnemyHealthCurrent->Size = System::Drawing::Size(25, 14);
			this->lblEnemyHealthCurrent->TabIndex = 0;
			this->lblEnemyHealthCurrent->Text = L"100";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::Red;
			this->label16->Location = System::Drawing::Point(6, 111);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(53, 14);
			this->label16->TabIndex = 5;
			this->label16->Text = L"Strength";
			// 
			// lblEnemyMaxStrength
			// 
			this->lblEnemyMaxStrength->AutoSize = true;
			this->lblEnemyMaxStrength->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEnemyMaxStrength->ForeColor = System::Drawing::Color::Red;
			this->lblEnemyMaxStrength->Location = System::Drawing::Point(79, 111);
			this->lblEnemyMaxStrength->Name = L"lblEnemyMaxStrength";
			this->lblEnemyMaxStrength->Size = System::Drawing::Size(14, 14);
			this->lblEnemyMaxStrength->TabIndex = 4;
			this->lblEnemyMaxStrength->Text = L"0";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::Color::Red;
			this->label18->Location = System::Drawing::Point(102, 83);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(12, 14);
			this->label18->TabIndex = 3;
			this->label18->Text = L"/";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::Red;
			this->label19->Location = System::Drawing::Point(117, 83);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(25, 14);
			this->label19->TabIndex = 2;
			this->label19->Text = L"100";
			// 
			// label20
			// 
			this->label20->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::Color::Red;
			this->label20->Location = System::Drawing::Point(5, 9);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(140, 23);
			this->label20->TabIndex = 0;
			this->label20->Text = L"ENEMY";
			this->label20->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::Color::Red;
			this->label21->Location = System::Drawing::Point(6, 83);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(41, 14);
			this->label21->TabIndex = 1;
			this->label21->Text = L"Health";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Red;
			this->label11->Location = System::Drawing::Point(6, 213);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(137, 14);
			this->label11->TabIndex = 14;
			this->label11->Text = L"Number Of Enemies Left";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::Red;
			this->label12->Location = System::Drawing::Point(6, 92);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(83, 14);
			this->label12->TabIndex = 15;
			this->label12->Text = L"Enemy Health:";
			// 
			// panel3
			// 
			this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
			this->panel3->Location = System::Drawing::Point(1727, 333);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(148, 27);
			this->panel3->TabIndex = 9;
			// 
			// panel4
			// 
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->Location = System::Drawing::Point(1875, 65);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(32, 968);
			this->panel4->TabIndex = 8;
			// 
			// panel5
			// 
			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
			this->panel5->Location = System::Drawing::Point(1727, 662);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(148, 27);
			this->panel5->TabIndex = 10;
			// 
			// panel6
			// 
			this->panel6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel6.BackgroundImage")));
			this->panel6->Location = System::Drawing::Point(1727, 65);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(148, 27);
			this->panel6->TabIndex = 10;
			// 
			// panelItems
			// 
			this->panelItems->Location = System::Drawing::Point(1730, 695);
			this->panelItems->Name = L"panelItems";
			this->panelItems->Size = System::Drawing::Size(145, 103);
			this->panelItems->TabIndex = 11;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Orange;
			this->label3->Location = System::Drawing::Point(1703, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 31);
			this->label3->TabIndex = 12;
			this->label3->Text = L"ROGUELIKE";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panelEnemyInfo
			// 
			this->panelEnemyInfo->Controls->Add(this->label12);
			this->panelEnemyInfo->Controls->Add(this->label11);
			this->panelEnemyInfo->Controls->Add(this->picEnemy);
			this->panelEnemyInfo->Controls->Add(this->label5);
			this->panelEnemyInfo->Location = System::Drawing::Point(1699, 338);
			this->panelEnemyInfo->Name = L"panelEnemyInfo";
			this->panelEnemyInfo->Size = System::Drawing::Size(205, 240);
			this->panelEnemyInfo->TabIndex = 6;
			// 
			// picEnemy
			// 
			this->picEnemy->Location = System::Drawing::Point(87, 43);
			this->picEnemy->Name = L"picEnemy";
			this->picEnemy->Size = System::Drawing::Size(32, 32);
			this->picEnemy->TabIndex = 13;
			this->picEnemy->TabStop = false;
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(0, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 23);
			this->label5->TabIndex = 16;
			// 
			// pnlWelcome
			// 
			this->pnlWelcome->Controls->Add(this->pnlHowToPlay);
			this->pnlWelcome->Controls->Add(this->btnQuit);
			this->pnlWelcome->Controls->Add(this->btnHowToPlay);
			this->pnlWelcome->Controls->Add(this->btnPlay);
			this->pnlWelcome->Controls->Add(this->lblRoguelikeWelcome);
			this->pnlWelcome->Location = System::Drawing::Point(2, 1);
			this->pnlWelcome->Name = L"pnlWelcome";
			this->pnlWelcome->Size = System::Drawing::Size(1905, 1032);
			this->pnlWelcome->TabIndex = 13;
			// 
			// pnlHowToPlay
			// 
			this->pnlHowToPlay->Controls->Add(this->btnCloseHelp);
			this->pnlHowToPlay->Controls->Add(this->label26);
			this->pnlHowToPlay->Controls->Add(this->label25);
			this->pnlHowToPlay->Controls->Add(this->label24);
			this->pnlHowToPlay->Controls->Add(this->label17);
			this->pnlHowToPlay->Controls->Add(this->label15);
			this->pnlHowToPlay->Location = System::Drawing::Point(21, 583);
			this->pnlHowToPlay->Name = L"pnlHowToPlay";
			this->pnlHowToPlay->Size = System::Drawing::Size(1852, 430);
			this->pnlHowToPlay->TabIndex = 17;
			this->pnlHowToPlay->Visible = false;
			// 
			// btnCloseHelp
			// 
			this->btnCloseHelp->BackColor = System::Drawing::Color::White;
			this->btnCloseHelp->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCloseHelp->Location = System::Drawing::Point(877, 370);
			this->btnCloseHelp->Name = L"btnCloseHelp";
			this->btnCloseHelp->Size = System::Drawing::Size(150, 50);
			this->btnCloseHelp->TabIndex = 5;
			this->btnCloseHelp->Text = L"OK";
			this->btnCloseHelp->UseVisualStyleBackColor = false;
			this->btnCloseHelp->Click += gcnew System::EventHandler(this, &GameForm::btnCloseHelp_Click);
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label26->Location = System::Drawing::Point(431, 321);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(339, 28);
			this->label26->TabIndex = 4;
			this->label26->Text = L"Use the arrow keys to move.";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::Color::Red;
			this->label25->Location = System::Drawing::Point(431, 210);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(774, 28);
			this->label25->TabIndex = 3;
			this->label25->Text = L"Once you kill all of the chickens, find the door to the next dungeon.";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::Color::Red;
			this->label24->Location = System::Drawing::Point(431, 263);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(435, 28);
			this->label24->TabIndex = 2;
			this->label24->Text = L"Collect coins to increase your score.";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::Red;
			this->label17->Location = System::Drawing::Point(431, 151);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(1042, 28);
			this->label17->TabIndex = 1;
			this->label17->Text = L"Traverse the map and kill all of the chickens, avoiding the blobbo bombers along "
				L"the way.";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label15->Location = System::Drawing::Point(812, 56);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(281, 49);
			this->label15->TabIndex = 0;
			this->label15->Text = L"HOW TO PLAY";
			// 
			// btnQuit
			// 
			this->btnQuit->BackColor = System::Drawing::Color::DarkRed;
			this->btnQuit->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnQuit->ForeColor = System::Drawing::Color::White;
			this->btnQuit->Location = System::Drawing::Point(877, 835);
			this->btnQuit->Name = L"btnQuit";
			this->btnQuit->Size = System::Drawing::Size(150, 50);
			this->btnQuit->TabIndex = 15;
			this->btnQuit->Text = L"QUIT";
			this->btnQuit->UseVisualStyleBackColor = false;
			this->btnQuit->Click += gcnew System::EventHandler(this, &GameForm::btnQuit_Click);
			// 
			// btnHowToPlay
			// 
			this->btnHowToPlay->BackColor = System::Drawing::Color::SkyBlue;
			this->btnHowToPlay->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnHowToPlay->ForeColor = System::Drawing::Color::Black;
			this->btnHowToPlay->Location = System::Drawing::Point(852, 748);
			this->btnHowToPlay->Name = L"btnHowToPlay";
			this->btnHowToPlay->Size = System::Drawing::Size(200, 50);
			this->btnHowToPlay->TabIndex = 16;
			this->btnHowToPlay->Text = L"HOW TO PLAY";
			this->btnHowToPlay->UseVisualStyleBackColor = false;
			this->btnHowToPlay->Click += gcnew System::EventHandler(this, &GameForm::btnHowToPlay_Click);
			// 
			// btnPlay
			// 
			this->btnPlay->BackColor = System::Drawing::Color::White;
			this->btnPlay->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPlay->ForeColor = System::Drawing::Color::Black;
			this->btnPlay->Location = System::Drawing::Point(852, 661);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(200, 50);
			this->btnPlay->TabIndex = 14;
			this->btnPlay->Text = L"PLAY";
			this->btnPlay->UseVisualStyleBackColor = false;
			this->btnPlay->Click += gcnew System::EventHandler(this, &GameForm::btnPlay_Click);
			// 
			// lblRoguelikeWelcome
			// 
			this->lblRoguelikeWelcome->BackColor = System::Drawing::Color::Transparent;
			this->lblRoguelikeWelcome->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblRoguelikeWelcome->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRoguelikeWelcome->ForeColor = System::Drawing::Color::Orange;
			this->lblRoguelikeWelcome->Location = System::Drawing::Point(0, 0);
			this->lblRoguelikeWelcome->Name = L"lblRoguelikeWelcome";
			this->lblRoguelikeWelcome->Size = System::Drawing::Size(1905, 1032);
			this->lblRoguelikeWelcome->TabIndex = 13;
			this->lblRoguelikeWelcome->Text = L"ROGUELIKE";
			this->lblRoguelikeWelcome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pnlGold
			// 
			this->pnlGold->Controls->Add(this->picGold);
			this->pnlGold->Controls->Add(this->lblGold);
			this->pnlGold->Location = System::Drawing::Point(1735, 700);
			this->pnlGold->Name = L"pnlGold";
			this->pnlGold->Size = System::Drawing::Size(129, 67);
			this->pnlGold->TabIndex = 20;
			// 
			// picGold
			// 
			this->picGold->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picGold.Image")));
			this->picGold->Location = System::Drawing::Point(0, 31);
			this->picGold->Name = L"picGold";
			this->picGold->Size = System::Drawing::Size(32, 32);
			this->picGold->TabIndex = 18;
			this->picGold->TabStop = false;
			// 
			// lblGold
			// 
			this->lblGold->AutoSize = true;
			this->lblGold->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblGold->ForeColor = System::Drawing::Color::Lime;
			this->lblGold->Location = System::Drawing::Point(42, 35);
			this->lblGold->Name = L"lblGold";
			this->lblGold->Size = System::Drawing::Size(23, 24);
			this->lblGold->TabIndex = 19;
			this->lblGold->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Red;
			this->label7->Location = System::Drawing::Point(537, 13);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(720, 58);
			this->label7->TabIndex = 18;
			this->label7->Text = L"HOW TO PLAY:\r\nCollect Gold around the map while trying to eliminate all chickens."
				L"";
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->pnlGold);
			this->Controls->Add(this->panelGame);
			this->Controls->Add(this->pnlWelcome);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panelItems);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panelEnemyInfo);
			this->Controls->Add(this->panelPlayerInfo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MinimumSize = System::Drawing::Size(1918, 1038);
			this->Name = L"GameForm";
			this->Text = L"Roguelike";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->Click += gcnew System::EventHandler(this, &GameForm::GameForm_Click);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GameForm::GameForm_KeyDown);
			this->panelGame->ResumeLayout(false);
			this->panelGame->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panelPlayerInfo->ResumeLayout(false);
			this->panelPlayerInfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPlayer))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panelEnemyInfo->ResumeLayout(false);
			this->panelEnemyInfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picEnemy))->EndInit();
			this->pnlWelcome->ResumeLayout(false);
			this->pnlHowToPlay->ResumeLayout(false);
			this->pnlHowToPlay->PerformLayout();
			this->pnlGold->ResumeLayout(false);
			this->pnlGold->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGold))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GameForm_Load(System::Object^  sender, System::EventArgs^  e) {
		canvas = panelGame->CreateGraphics();
		rGen = gcnew Random();
		tileList = gcnew TileList(NTILE);
		SetTileImage();
		bufferImage = gcnew Bitmap(panelGame->Width, panelGame->Height);
		bufferGraphics = Graphics::FromImage(bufferImage);
		tileMap = gcnew TileMap(tileList, bufferGraphics, NCOL, NROW, rGen);
		attackTickCount = 0;
		currentAttackerTick = 0;
		enemiesCount = ENEMY_START_COUNT;
		dungeon = gcnew Dungeon(NCOL, NROW, rGen,tileMap->map, NUMBEROFROOM);
		viewport = gcnew Viewport(0, 0, (panelGame->Width / TILEPIXEL)+1, (panelGame->Height / TILEPIXEL)+1, tileMap, bufferGraphics);
		NewDungeon();
	}

	private: void NewDungeon() {
		GenerateMap();
		knight = generateKnightSprite();
		enemies = gcnew LinkedList();

		enemyBomb = GenerateBomb();
		enemyBomb->spriteRec = Rectangle(enemyBomb->spriteRec.X, enemyBomb->spriteRec.Y, enemyBomb->spriteRec.Width, enemyBomb->spriteRec.Height);
		createEnemy(enemiesCount);

		enemies->AddSprite(GenerateEnemy());
		enemies->AddSprite(GenerateEnemy());

		items = gcnew ItemList();		
		GenerateHealthItems();	
		GenerateGoldItems();
	}

	private: void createEnemy(int numberOfEnemy) {
		enemies->DeleteAllSprite();
		for (int i = 0; i < numberOfEnemy; i++) {
			enemies->AddSprite(GenerateEnemy());
		}
	}

	private: void SetTileImage() {//fililng tile list with tile image
		tileList->SetTileArrayEntry(ETileImage::FLOOR, createTile("floor.png", true));
		tileList->SetTileArrayEntry(ETileImage::WALL, createTile("wall.png", false));
		tileList->SetTileArrayEntry(ETileImage::DOOR, createTile("door.png", true));
		tileList->SetTileArrayEntry(ETileImage::WATER, createTile("water.png", false));
		tileList->SetTileArrayEntry(ETileImage::RUG, createTile("rug.png", true));
		tileList->SetTileArrayEntry(ETileImage::HEALINGPAD, createTile("healingpad.png", true));
		tileList->SetTileArrayEntry(ETileImage::TRANSPARENT, createTile("transparent.png", true));
		tileList->SetTileArrayEntry(ETileImage::FOG, createTile("fog.png", true));
	}

	private: Tile^ createTile(String^ FileName, bool isWalkable) {//creating a new tile with image passed in from the parameter
		return gcnew Tile(gcnew Bitmap(FileName), isWalkable);
	}

	private: void GenerateMap() {//making map
		tileMap->CreateFogMap();
		for (int r = 0; r < NROW; r++) {//looping throught rows 
			for (int c = 0; c < NCOL; c++) {//looping throught cols
				tileMap->SetMapEntry(c, r, ETileImage::WATER);//looping throught the whole map and put in water for each tile
			}
		}
		dungeon->generateRooms(); //generating the rooms for the dungeon
		tileMap->PuttingTileIntoMap(dungeon->allRooms); //putting the dungeon rooms in to the tile map		
		dungeon->LinkRoomWithCorridor();
		dungeon->GeneratePortal();
	}

	private: System::Void GameForm_Click(System::Object^  sender, System::EventArgs^  e) {
		
	}

	private: Player^ generateKnightSprite() {//generate knight sprite
		int framesInKnightSpriteSheet = FRAMEINSPRITESHEET;
		int direction = MAXDIRECTION;
		Bitmap^ east = gcnew Bitmap("Knight Walk East 8.bmp");
		Bitmap^ south = gcnew Bitmap("Knight Walk South 8.bmp");
		Bitmap^ west = gcnew Bitmap("Knight Walk West 8.bmp");
		Bitmap^ north = gcnew Bitmap("Knight Walk North 8.bmp");
		array<Bitmap^>^ knightImages = gcnew array<Bitmap^>(direction);
		knightImages[ESpriteDirection::EAST] = east;
		knightImages[ESpriteDirection::SOUTH] = south;
		knightImages[ESpriteDirection::WEST] = west;
		knightImages[ESpriteDirection::NORTH] = north;
		for (int d = 0; d < direction; d++) {
			knightImages[d]->MakeTransparent(knightImages[d]->GetPixel(0, 0));
		}
		return gcnew Player(bufferGraphics, knightImages, framesInKnightSpriteSheet, rGen, panelGame->Width, panelGame->Height, 
			Point((NCOL*TILEPIXEL /2)+ TILEPIXEL, NROW * TILEPIXEL / 2),tileMap, PLAYER_START_DEFENCE, PLAYER_START_STRENGTH, PLAYER_START_HEALTH);

	}

	private: System::Void GameForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyData)
		{
		case Keys::Right:
			knight->spriteDirection = ESpriteDirection::EAST;
			knight->CheckNextTileThenMove(false);
			knight->attacking = false;
			break;
		case Keys::Down:
			knight->spriteDirection = ESpriteDirection::SOUTH;
			knight->CheckNextTileThenMove(false);
			knight->attacking = false;
			break;
		case Keys::Left:
			knight->spriteDirection = ESpriteDirection::WEST;
			knight->CheckNextTileThenMove(false);
			knight->attacking = false;
			break;
		case Keys::Up:
			knight->spriteDirection = ESpriteDirection::NORTH;
			knight->CheckNextTileThenMove(false);
			knight->attacking = false;
			break;
		default:
			break;
		}
	}

	private: Enemy^ GenerateBomb() {
		int framesInEnemiesSpriteSheet = FRAMEINSPRITESHEET;
		int direction = MAXDIRECTION;
		Bitmap^ east = gcnew Bitmap("BlobboMulti.bmp");
		Bitmap^ south = gcnew Bitmap("BlobboMulti.bmp");
		Bitmap^ west = gcnew Bitmap("BlobboMulti.bmp");
		Bitmap^ north = gcnew Bitmap("BlobboMulti.bmp");
		array<Bitmap^>^ bombImages = gcnew array<Bitmap^>(direction);
		bombImages[ESpriteDirection::EAST] = east;
		bombImages[ESpriteDirection::SOUTH] = south;
		bombImages[ESpriteDirection::WEST] = west;
		bombImages[ESpriteDirection::NORTH] = north;

		for (int d = 0; d < direction; d++) {
			bombImages[d]->MakeTransparent(bombImages[d]->GetPixel(0, 0));
		}
		//int roomNumber = rGen->Next(NUMBEROFROOM);
		int roomNumber = 0;
		//Generate random stats
		int startDefence = rGen->Next(ENEMY_START_STAT_MIN, ENEMY_START_STAT_MAX);
		int startStrength = rGen->Next(ENEMY_START_STAT_MIN, ENEMY_START_STAT_MAX);
		int startHealth = rGen->Next(ENEMY_START_HEALTH_MIN, ENEMY_START_HEALTH_MAX);

		//the long random generation code is to put the enemy into any room and make sure that the enemy is not on the wall of the room.
		return gcnew Enemy(bufferGraphics, bombImages, framesInEnemiesSpriteSheet, rGen, Width, Height,
			Point(rGen->Next(((dungeon->allRooms[roomNumber]->xlocation + 2)*TILEPIXEL), ((dungeon->allRooms[roomNumber]->xlocation + dungeon->allRooms[roomNumber]->width - 2)*TILEPIXEL))
				, rGen->Next(((dungeon->allRooms[roomNumber]->ylocation + 2)*TILEPIXEL), ((dungeon->allRooms[roomNumber]->ylocation + dungeon->allRooms[roomNumber]->height - 2)*TILEPIXEL)))
			, tileMap, ENEMY_BOMB_START_SPEED, startDefence, startStrength, startHealth);
	}

	private: Enemy^ GenerateEnemy() {
		int framesInEnemiesSpriteSheet = FRAMEINSPRITESHEET;
		int direction = MAXDIRECTION;
		Bitmap^ east = gcnew Bitmap("Little Chicken Walk East 8.bmp");
		Bitmap^ south = gcnew Bitmap("Little Chicken Walk South 8.bmp");
		Bitmap^ west = gcnew Bitmap("Little Chicken Walk West 8.bmp");
		Bitmap^ north = gcnew Bitmap("Little Chicken Walk North 8.bmp");
		array<Bitmap^>^ chickenImages = gcnew array<Bitmap^>(direction);
		chickenImages[ESpriteDirection::EAST] = east;
		chickenImages[ESpriteDirection::SOUTH] = south;
		chickenImages[ESpriteDirection::WEST] = west;
		chickenImages[ESpriteDirection::NORTH] = north;

		for (int d = 0; d < direction; d++) {
			chickenImages[d]->MakeTransparent(chickenImages[d]->GetPixel(0, 0));
		}
		int roomNumber = rGen->Next(NUMBEROFROOM);
		//the long random generation code is to put the enemy into any room and make sure that the enemy is not on the wall of the room.

		//Generate random stats
		int startDefence = rGen->Next(ENEMY_START_STAT_MIN, ENEMY_START_STAT_MAX);
		int startStrength = rGen->Next(ENEMY_START_STAT_MIN, ENEMY_START_STAT_MAX);
		int startHealth = rGen->Next(ENEMY_START_STAT_MIN, ENEMY_START_HEALTH_MAX);

		return gcnew Enemy(bufferGraphics, chickenImages, framesInEnemiesSpriteSheet, rGen, panelGame->Width, panelGame->Height,
						Point(rGen->Next(((dungeon->allRooms[roomNumber]->xlocation + 2)*TILEPIXEL), ((dungeon->allRooms[roomNumber]->xlocation+ dungeon->allRooms[roomNumber]->width - 2)*TILEPIXEL))
							, rGen->Next(((dungeon->allRooms[roomNumber]->ylocation + 2)*TILEPIXEL), ((dungeon->allRooms[roomNumber]->ylocation+ dungeon->allRooms[roomNumber]->height - 2)*TILEPIXEL)))
							,tileMap, ENEMY_NORMAL_START_SPEED, startDefence, startStrength, startHealth);

	}

	//Creates health potions in the middle of each room
	private: void GenerateHealthItems()
	{
		for (int r = 0; r < dungeon->allRooms->Length; r++)
		{
			items->AddItem(gcnew Item(bufferGraphics, rGen, dungeon->allRooms[r]->centerPosX * TILEPIXEL, dungeon->allRooms[r]->centerPosY * TILEPIXEL, gcnew Bitmap("health.png"), HEALTH_POTION, ITEM_DIMENSION, ITEM_DIMENSION));
		}
	}

	private: void GenerateGoldItems()
	{
		 for (int r = 0; r < dungeon->allRooms->Length; r++)
		 {
			 int xPad = rGen->Next(GOLD_PAD_MIN, GOLD_PAD_MAX);
			 int yPad = rGen->Next(GOLD_PAD_MIN, GOLD_PAD_MAX); // Generate a random padding for gold to be positioned so it is not in the centre of each room
			 int makeNeg = rGen->Next(2);
			 if (makeNeg == 0)  // Makes the position of gold more random in each room
			 {
				 xPad *= -1;
				 yPad *= -1;
			 }
			 items->AddItem(gcnew Item(bufferGraphics, rGen, (dungeon->allRooms[r]->centerPosX * TILEPIXEL) + xPad, (dungeon->allRooms[r]->centerPosY * TILEPIXEL) + yPad, gcnew Bitmap("gold.png"), EItemType::GOLD, TILEPIXEL, TILEPIXEL));
		 }
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		//moving the viewport relative to the sprite
		viewport->MoveRelativeToPlayer(knight);
		viewport->ViewportDraw(knight->xPos, knight->yPos);		

		//knight draw and fsm method is called here
		knight->PerformActionAcordingToState();
		knight->CheckCurrentTile();
		knight->ForcedDraw((panelGame->Width / 2) + PLAYERLOCATIONPADDINGX, (panelGame->Height / 2) - PLAYERLOCATIONPADDINGY);//force draw the sprite to the middle of the form
		knight->UpdateFrame();
		if (knight->CheckCurrentTile()) {
			if (enemies->CountSprite() == 0) {
				timer1->Enabled = false;
				NewDungeon();
			}
			else {
				label9->Text = "Kill All Chickens First";
			}
		}

		else {
			label9->Text = "Kill All Chickens and Find the door to go to the next dungeon";
		}
		if (knight->CheckIsDead()) {
			timer1->Enabled = false;
			NewDungeon();
			MessageBox::Show("You're Dead");			
		}

		//Force draw all the enemies in the viewport and also call the fsm method
		Sprite^ enemyAttackingPlayer = enemies->CheckColided(knight);
		if (enemyAttackingPlayer != nullptr)
		{
			if (attackTickCount == ATTACK_DELAY_TICK)
			{
				attack(enemyAttackingPlayer);

				attackTickCount = 0;
			}
			attackTickCount++;
		}
		enemies->DeleteIfDead();
		enemies->DrawSpritesInViewport(viewport, knight);
		enemies->UpdateFrame();
		enemies->PerformActionSprite(knight);

		//enemybomb draw orient method is called here
		DrawBomb();
		enemyBomb->Orient(knight);
		enemyBomb->CheckNextTileThenMove(true);
		enemyBomb->CheckColidedWithTargetBomb(knight);
		
		//items
		items->CheckCollided(knight);
		lblGold->Text = knight->Gold.ToString();
		items->DrawItemsInViewport(viewport, knight);

		//updating the lables
		lblPlayerCurrentHealth->Text = knight->health.ToString();
		lblPlayerDefenceMax->Text = knight->maxDefence.ToString();
		lblPlayerMaxStrength->Text = knight->maxStrength.ToString();
		label13->Text = enemies->CountSprite().ToString();
		lblEnemyHealthCurrent->Text = enemies->ReturnInCombatSpriteHealth(knight).ToString();
		lblPlayerMaxHealth->Text = knight->maxHealth.ToString();

		//drawing the fog of war
		viewport->ClearFog();
		viewport->ViewportDrawFog(knight->xPos, knight->yPos);

		//draw the final graphic
		canvas->DrawImage(bufferImage, 0, 0);	
	}

	//method for drawing the bomb on the form
	private: void DrawBomb(){
		int spriteViewPortLocationX = enemyBomb->xPos - (viewport->ViewportWorldX * TILEPIXEL) - knight->xPos % TILEPIXEL;
		int spriteViewPortLocationY = enemyBomb->yPos - (viewport->ViewportWorldY * TILEPIXEL) - knight->yPos % TILEPIXEL;
		if (enemyBomb->isDead == false) {		
			enemyBomb->ForcedDraw(spriteViewPortLocationX- PLAYERLOCATIONPADDINGX, spriteViewPortLocationY-25- PLAYERLOCATIONPADDINGY);
			enemyBomb->UpdateFrame();
		}
		else 
		{
			bufferGraphics->DrawImage(gcnew Bitmap("explode.png"), spriteViewPortLocationX, spriteViewPortLocationY);
			bombTickCount = 0;
		}
		respawnBomb();
		bombTickCount++;
	}

	//method for respawning the bomb in any of the room
	//respawn every 10 seconds
	private: void respawnBomb() {
		if (bombTickCount % 100 == 0) {
			bombTickCount = 0;
			enemyBomb->isDead = false;
			//int roomNumber = rGen->Next(NUMBEROFROOM);
			int roomNumber = 0;
			enemyBomb->xPos = rGen->Next(((dungeon->allRooms[roomNumber]->xlocation + 2)*TILEPIXEL), ((dungeon->allRooms[roomNumber]->xlocation + dungeon->allRooms[roomNumber]->width - 2)*TILEPIXEL));
			enemyBomb->yPos = rGen->Next(((dungeon->allRooms[roomNumber]->ylocation + 2)*TILEPIXEL), ((dungeon->allRooms[roomNumber]->ylocation + dungeon->allRooms[roomNumber]->height - 2)*TILEPIXEL));
		}	
	}

	//Asks certain sprite to attack other sprite based off current attack tick (to enable turn based attack)
	private: void attack(Sprite^ enemyAttackingPlayer)
	{
		updateLabels(enemyAttackingPlayer);
		if (currentAttackerTick % 2 == 0) // Knight's turn to attack
		{
			enemyAttackingPlayer->health -= knight->Attack(enemyAttackingPlayer);		
			bufferGraphics->DrawImage(gcnew Bitmap("blood2.png"), (panelGame->Width / 2) + PLAYERLOCATIONPADDINGX, (panelGame->Height / 2) - PLAYERLOCATIONPADDINGY);
			//Check if enemy is dead
			if (enemyAttackingPlayer->CheckIsDead()) {
				dropItem(enemyAttackingPlayer->xPos, enemyAttackingPlayer->yPos);
				enemies->DeleteSprite(enemyAttackingPlayer); //Remove it from list
				attackTickCount = 0;
			}
		}
		else // Enemy's turn to attack
		{
			bufferGraphics->DrawImage(gcnew Bitmap("sword.png"), (panelGame->Width / 2) + PLAYERLOCATIONPADDINGX, (panelGame->Height / 2) - PLAYERLOCATIONPADDINGY);
			knight->health -= enemyAttackingPlayer->Attack(knight);
		}
		currentAttackerTick++;
	}

	private: void updateLabels(Sprite^ enemyAttackingPlayer)
	{
		lblEnemyHealthCurrent->Text = enemyAttackingPlayer->health.ToString();
		lblEnemyMaxStrength->Text = enemyAttackingPlayer->maxStrength.ToString();
		lblPlayerCurrentHealth->Text = knight->health.ToString();
		lblPlayerMaxHealth->Text = knight->maxHealth.ToString();
		lblPlayerMaxStrength->Text = knight->maxStrength.ToString();
		lblPlayerDefenceMax->Text = knight->maxDefence.ToString();
	}

	//25% chance of a random item dropping, spawns the item at the enemy position
	private: void dropItem(int enemyXPos, int enemyYPos)
	{
		int dropChance = rGen->Next(ITEM_DROP_CHANCE_MAX);
		if (dropChance < ITEM_DROP_CHANCE)
		{
			Item^ drop = gcnew Item(bufferGraphics, rGen, enemyXPos * TILEPIXEL, enemyYPos * TILEPIXEL, ITEM_DIMENSION, ITEM_DIMENSION);
			drop->GenerateRandomType();
			items->AddItem(drop);
		}
	}

private: System::Void btnPlay_Click(System::Object^  sender, System::EventArgs^  e) {
	pnlWelcome->Visible = false;
	pnlWelcome->Enabled = false;
	pnlHowToPlay->Enabled = false;
	panelGame->Visible = true;
	timer1->Start();
}
private: System::Void btnCloseHelp_Click(System::Object^  sender, System::EventArgs^  e) {
	pnlHowToPlay->Visible = false;
}
private: System::Void btnHowToPlay_Click(System::Object^  sender, System::EventArgs^  e) {
	pnlHowToPlay->Visible = true;
}
private: System::Void btnQuit_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
};
}

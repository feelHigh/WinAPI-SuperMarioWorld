#pragma once
#include "Scene.h"
#include "ntoLayerHeaders.h"
#include "Transform.h"
#include "CustomTime.h"
#include "ntoResources.h"
#include "ntoSound.h"

namespace nto
{
	class Stage1 : public Scene
	{
	public:
		Stage1();
		virtual ~Stage1();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		bool pSwitchState;
		// Interactive Box
		ForegroundSpinBox* Stage1_Foreground_SpinBox_Entity9;
		// Player
		Player* player;
		Transform* trPlayer;
		Collider* colPlayer;
		// Foreground
		ForegroundUpgradeBox* Stage1_Foreground_UpgradeBox_Entity1;
		ForegroundUpgradeBox* Stage1_Foreground_UpgradeBox_Entity2;
		ForegroundFinishFlag* Stage1_Foreground_Checkpoint_Finish_Flag_Entity;
		// Items
		ItemSuperMushroom* Stage1_Item_SuperMushroom_Entity;
		ItemFireFlower* Stage1_Item_FireFlower_Entity;
		ItemPSwitch* Stage1_Item_PSwitch_Entity;
		Transform* trSuperMushroom;
		Transform* trFireFlower;
		Transform* trPSwitch;
		float smShowTime;
		float ffShowTime;
		float eventTime;
		// UI
		HUD* Stage1_HUD_Entity;
		Transform* trHUD_Base;

		// Changable Coins
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_1;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_2;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_3;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_4;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_5;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_6;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_7;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_8;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_9;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_10;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_11;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_12;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_13;
		// Sound
		Sound* bgSound;
	};
}

#pragma once
#include "Scene.h"
#include "ntoLayerHeaders.h"
#include "Transform.h"
#include "Animator.h"
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
		HUD* HUD_Base_Entity;
		HUDLife* HUD_Life_Entity;
		HUDTimer* HUD_Timer_Entity_1;
		HUDTimer* HUD_Timer_Entity_2;
		HUDTimer* HUD_Timer_Entity_3;
		HUDCoins* HUD_Coins_Entity_1;
		HUDCoins* HUD_Coins_Entity_2;
		Transform* trHUD_Base;
		Transform* trHUD_Life;
		Transform* trHUD_Timer_1;
		Transform* trHUD_Timer_2;
		Transform* trHUD_Timer_3;
		Transform* trHUD_Coins_1;
		Transform* trHUD_Coins_2;
		Animator* atHUD_Base;
		Animator* atHUD_Life;
		Animator* atHUD_Timer_1;
		Animator* atHUD_Timer_2;
		Animator* atHUD_Timer_3;
		Animator* atHUD_Coins_1;
		Animator* atHUD_Coins_2;
		float stageTimer;
		int stageCoins;

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

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
	class Stage2 : public Scene
	{
	public:
		Stage2();
		virtual ~Stage2();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		// Player
		Player* player;
		Transform* trPlayer;
		Collider* colPlayer;
		// Foreground
		ForegroundRandomBox* Foreground_RandomBox_Entity3;
		ForegroundUpgradeBox* Foreground_UpgradeBox_Entity;
		ForegroundFinishFlag* Foreground_Checkpoint_Finish_Flag_Entity;
		ForegroundCoin* Foreground_Coin_Entity_1_1;
		ForegroundCoin* Foreground_Coin_Entity_1_2;
		ForegroundCoin* Foreground_Coin_Entity_1_3;
		ForegroundCoin* Foreground_Coin_Entity_2_1;
		ForegroundCoin* Foreground_Coin_Entity_2_2;
		ForegroundCoin* Foreground_Coin_Entity_2_3;
		ForegroundCoin* Foreground_Coin_Entity_3_1;
		ForegroundCoin* Foreground_Coin_Entity_3_2;
		ForegroundCoin* Foreground_Coin_Entity_3_3;
		ForegroundCoin* Foreground_Coin_Entity_4_1;
		ForegroundCoin* Foreground_Coin_Entity_4_2;
		ForegroundCoin* Foreground_Coin_Entity_4_3;
		ForegroundCoin* Foreground_Coin_Entity_5_1;
		ForegroundCoin* Foreground_Coin_Entity_5_2;
		ForegroundCoin* Foreground_Coin_Entity_6_1;
		ForegroundCoin* Foreground_Coin_Entity_6_2;
		ForegroundCoin* Foreground_Coin_Entity_6_3;
		ForegroundCoin* Foreground_Coin_Entity_7_1;
		ForegroundCoin* Foreground_Coin_Entity_7_2;
		ForegroundCoin* Foreground_Coin_Entity_7_3;
		ForegroundCoin* Foreground_Coin_Entity_8_1;
		ForegroundCoin* Foreground_Coin_Entity_8_2;
		ForegroundCoin* Foreground_Coin_Entity_9_1;
		ForegroundCoin* Foreground_Coin_Entity_9_2;
		ForegroundCoin* Foreground_Coin_Entity_10_1;
		ForegroundCoin* Foreground_Coin_Entity_10_2;
		ForegroundCoin* Foreground_Coin_Entity_11_1;
		ForegroundCoin* Foreground_Coin_Entity_11_2;
		ForegroundCoin* Foreground_Coin_Entity_12_1;
		ForegroundCoin* Foreground_Coin_Entity_12_2;
		ForegroundCoin* Foreground_Coin_Entity_12_3;
		ForegroundYoshiCoin* Foreground_YoshiCoin_Entity_1;
		ForegroundYoshiCoin* Foreground_YoshiCoin_Entity_2;
		ForegroundYoshiCoin* Foreground_YoshiCoin_Entity_3;
		ForegroundYoshiCoin* Foreground_YoshiCoin_Entity_4;
		int stageCoins;
		// Items
		ItemSuperMushroom* Item_SuperMushroom_Entity_1;
		ItemSuperMushroom* Item_SuperMushroom_Entity_2;
		Transform* trSuperMushroom1;
		Transform* trSuperMushroom2;
		float smShowTime1;
		float smShowTime2;
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
		// Sound
		Sound* bgSound;
	};
}

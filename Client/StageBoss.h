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
	class StageBoss : public Scene
	{
	public:
		StageBoss();
		virtual ~StageBoss();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		// Player
		Player* player;
		Transform* trPlayer;
		Collider* colPlayer;
		// Foreground
		// Enemy
		Morton* Morton_Entity;
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
		// Boss Value
		int killCount;
	};
}

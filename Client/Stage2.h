#pragma once
#include "Scene.h"
#include "ntoLayerHeaders.h"
#include "Transform.h"
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
		// Items
		ItemSuperMushroom* Item_SuperMushroom_Entity_1;
		ItemSuperMushroom* Item_SuperMushroom_Entity_2;
		Transform* trSuperMushroom1;
		Transform* trSuperMushroom2;
		float smShowTime1;
		float smShowTime2;
		// UI
		HUD* Stage2_HUD_Entity;
		Transform* trHUD_Base;
		// Sound
		Sound* bgSound;
	};
}

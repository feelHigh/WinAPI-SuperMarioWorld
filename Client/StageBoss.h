#pragma once
#include "Scene.h"
#include "ntoLayerHeaders.h"
#include "Transform.h"
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
		// 
		// UI
		HUD* HUD_Entity;
		Transform* trHUD_Base;
		// Sound
		Sound* bgSound;
	};
}

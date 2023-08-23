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

		// UI
		HUD* Stage2_HUD_Entity;
		Transform* trHUD_Base;
	};
}

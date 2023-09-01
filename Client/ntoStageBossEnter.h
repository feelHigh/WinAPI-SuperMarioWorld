#pragma once
#include "Scene.h"
#include "ntoLayerHeaders.h"
#include "Transform.h"
#include "CustomTime.h"
#include "ntoResources.h"
#include "ntoSound.h"

namespace nto
{
	class StageBossEnter : public Scene
	{
	public:
		StageBossEnter();
		virtual ~StageBossEnter();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		float sTimer;
		// Sound
		Sound* bgSound;
	};
}

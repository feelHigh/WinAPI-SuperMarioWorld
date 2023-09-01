#pragma once
#include "Scene.h"
#include "ntoLayerHeaders.h"
#include "Transform.h"
#include "CustomTime.h"
#include "ntoResources.h"
#include "ntoSound.h"

namespace nto
{
	class Stage1Enter : public Scene
	{
	public:
		Stage1Enter();
		virtual ~Stage1Enter();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		float sTimer;
		// Sound
		Sound* bgSound;
	};
}

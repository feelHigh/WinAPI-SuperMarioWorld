#pragma once
#include "Scene.h"
#include "ntoLayerHeaders.h"
#include "Transform.h"
#include "CustomTime.h"
#include "ntoResources.h"
#include "ntoSound.h"

namespace nto
{
	class EndingScene : public Scene
	{
	public:
		EndingScene();
		virtual ~EndingScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		// Sound
		Sound* bgSound;
	};
}

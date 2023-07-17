#pragma once
#include "Scene.h"

namespace nto
{
	class StageWorldMap : public Scene
	{
	public:
		StageWorldMap();
		virtual ~StageWorldMap();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}

#pragma once
#include "Scene.h"

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

	};
}

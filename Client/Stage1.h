#pragma once
#include "Scene.h"

namespace nto
{
	class Stage1 : public Scene
	{
	public:
		Stage1();
		virtual ~Stage1();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		bool pSwitchState;
	};
}

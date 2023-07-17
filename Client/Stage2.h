#pragma once
#include "Scene.h"

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

	};
}

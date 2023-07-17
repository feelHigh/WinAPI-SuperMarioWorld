#pragma once
#include "Scene.h"

namespace nto
{
	class Stage3 : public Scene
	{
	public:
		Stage3();
		virtual ~Stage3();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}

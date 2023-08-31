#pragma once
#include "GameObject.h"

namespace nto
{
	class TitleIntro : public GameObject
	{
#define INTROTIMER 3.2f

	public:
		TitleIntro();
		virtual ~TitleIntro();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		int ePhase;
		float eTimer;
	};
}

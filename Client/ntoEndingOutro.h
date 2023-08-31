#pragma once
#include "GameObject.h"

namespace nto
{
	class EndingOutro : public GameObject
	{
#define OUTROTIMER 3.2f

	public:
		EndingOutro();
		virtual ~EndingOutro();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		int ePhase;
		float eTimer;
	};
}

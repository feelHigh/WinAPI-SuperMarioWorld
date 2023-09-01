#pragma once
#include "GameObject.h"

namespace nto
{
	class StageEnter : public GameObject
	{
#define ENTERTIMER 0.9f

	public:
		StageEnter();
		virtual ~StageEnter();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		int ePhase;
		float eTimer;
	};
}



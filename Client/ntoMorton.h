#pragma once
#include "GameObject.h"

namespace nto
{
	class Morton : public GameObject
	{
	public:
		Morton();
		~Morton();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

	private:
		bool eAttacked;
		int ePhase;
		int tmpPhase;
		float eTimer;
		float tmpTimer;
		float hitTimer;
		float eDeathTime;

		int eHitCount;
		float eMaxWidth;
		float eMaxHeight;
		float ePatternSpeedX;
		float ePatternSpeedY;
		float ePatternTimer;
		float eFallTimer;
	};
}

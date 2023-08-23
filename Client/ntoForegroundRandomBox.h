#pragma once
#include "GameObject.h"

namespace nto
{
	class ForegroundRandomBox : public GameObject
	{
	public:
		ForegroundRandomBox();
		virtual ~ForegroundRandomBox();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:
		bool bHit;
	};
}

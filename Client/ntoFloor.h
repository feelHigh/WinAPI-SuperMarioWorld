#pragma once
#include "GameObject.h"

namespace nto
{
	class Floor : public GameObject
	{
	public:
		Floor();
		virtual ~Floor();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:

	};
}

#pragma once
#include "Component.h"

namespace nto
{
	using namespace math;

	class Transform : public Component
	{
	public:
		Transform();
		virtual ~Transform();

		virtual void Initialize()  override;
		virtual void Update()  override;
		virtual void Render(HDC hdc)  override;

		void SetPosition(Vector2 position) { mPosition = position; }
		Vector2 GetPosition() { return mPosition; }
		void SetRotation(float rotate) { mRotation = rotate; }
		float GetRotation() { return mRotation; }
		void SetType(int type) { mType = type; }
		int GetType() { return mType; }

	private:
		Vector2 mPosition;
		float mRotation;
		int mType;
	};
}

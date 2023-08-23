#pragma once
#include "GameObject.h"

namespace nto
{
	using namespace math;
	class Camera
	{
	public:
		static void Initialize();
		static void Update();

		static Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; }

		static GameObject* GetTarget() { return mTarget; }
		static void SetTarget(GameObject* target) { mTarget = target; }

		static Vector2 GetOffset() { return mOffset; }
		static void SetOffset(Vector2 offset) { mOffset = offset; }

	private:
		static Vector2 mResolution;		// ȭ�� �ػ�
		static Vector2 mLookPosition;	// ī�޶� �ٶ󺸰� �ִ� ��ġ
		static Vector2 mDistance;		// ����� �������� �̵��� �Ÿ�
		static GameObject* mTarget;		// ī�޶� �ٶ󺸴� ���� ������Ʈ

		Vector2 mPosition;

		static Vector2 mOffset;
		static float mThresholdX;
		static float mThresholdY;

		static float speed;
	};
}


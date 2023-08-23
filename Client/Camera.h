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
		static Vector2 mResolution;		// 화면 해상도
		static Vector2 mLookPosition;	// 카메라가 바라보고 있는 위치
		static Vector2 mDistance;		// 가운데를 원점으로 이동한 거리
		static GameObject* mTarget;		// 카메라가 바라보는 게임 오브젝트

		Vector2 mPosition;

		static Vector2 mOffset;
		static float mThresholdX;
		static float mThresholdY;

		static float speed;
	};
}


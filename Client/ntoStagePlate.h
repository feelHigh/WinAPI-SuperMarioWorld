#pragma once
#include "GameObject.h"

namespace nto
{
	class StagePlate : public GameObject
	{
	public:
		StagePlate();
		virtual ~StagePlate();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetStageNum(int num) { StageNum = num; }
		bool GetStageNum() { return StageNum; }

	private:
		int StageNum;
		bool StageEnter;
	};
}

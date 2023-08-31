#include "ntoEndingOutro.h"
#include "Transform.h"
#include "Controller.h"
#include "CustomTime.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "CustomTime.h"
#include "ntoResources.h"
#include "ntoSound.h"

namespace nto
{
	EndingOutro::EndingOutro()
		: ePhase(0)
		, eTimer(OUTROTIMER)
	{
	}

	EndingOutro::~EndingOutro()
	{
	}

	void EndingOutro::Initialize()
	{
	}

	void EndingOutro::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		eTimer -= Time::DeltaTime();
		if (eTimer < 0.0f)
		{
			if (ePhase >= 0 && ePhase <= 6)
			{
				std::wstring animationName = L"Animation_Outro_Part_" + std::to_wstring(ePhase);
				this->GetComponent<Animator>()->PlayAnimation(animationName.c_str(), false);

				if (ePhase == 5)
				{
					eTimer = 3.0f;
				}
				else if (ePhase == 6)
				{
					eTimer = 0.0f;
				}
				else
				{
					eTimer = OUTROTIMER;
				}

				if (ePhase == 6)
				{
					ePhase = 6;
				}
				else
				{
					ePhase++;
				}
			}
		}
	}

	void EndingOutro::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}

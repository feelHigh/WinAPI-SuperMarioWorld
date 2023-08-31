#include "ntoTitleIntro.h"
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
	TitleIntro::TitleIntro()
		: ePhase(0)
		, eTimer(INTROTIMER)
	{
	}

	TitleIntro::~TitleIntro()
	{
	}

	void TitleIntro::Initialize()
	{
	}

	void TitleIntro::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		eTimer -= Time::DeltaTime();
		if (eTimer < 0.0f)
		{
			if (ePhase >= 0 && ePhase <= 9)
			{
				std::wstring animationName = L"Animation_Intro_Part_" + std::to_wstring(ePhase);
				this->GetComponent<Animator>()->PlayAnimation(animationName.c_str(), false);

				if (ePhase == 8)
				{
					eTimer = 1.2f;
				}
				else
				{
					eTimer = INTROTIMER;
				}

				if (ePhase == 9)
				{
					ePhase = 2;
				}
				else
				{
					ePhase++;
				}
			}
		}
	}
	void TitleIntro::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}

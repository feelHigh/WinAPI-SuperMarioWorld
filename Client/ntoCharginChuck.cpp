#include "ntoCharginChuck.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "CustomTime.h"

namespace nto
{
	CharginChuck::CharginChuck()
		: ePhase(1)
		, eAttacked(false)
		, eTimer(2.0f)
		, eDeathTime(5.0f)
		, hitTimer(2.0f)
	{
	}

	CharginChuck::~CharginChuck()
	{
	}

	void CharginChuck::Initialize()
	{
	}

	void CharginChuck::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (!eAttacked)
		{
			if (ePhase == 1)
			{
				this->GetComponent<Animator>()->PlayAnimation(L"Monster_Animation_CharginChuck_Left", true);

				pos.x -= 250.0f * Time::DeltaTime();
				eTimer -= Time::DeltaTime();
				if (eTimer < 0.0f)
				{
					eTimer = 2.0f;
					ePhase++;
					return;
				}
			}
			else if (ePhase == 2)
			{
				this->GetComponent<Animator>()->PlayAnimation(L"Monster_Animation_CharginChuck_Middle", true);

				eTimer -= Time::DeltaTime();
				if (eTimer < 0.0f)
				{
					eTimer = 2.0f;
					ePhase++;
					return;
				}
			}
			else if (ePhase == 3)
			{
				this->GetComponent<Animator>()->PlayAnimation(L"Monster_Animation_CharginChuck_Right", true);
				pos.x += 250.0f * Time::DeltaTime();
				eTimer -= Time::DeltaTime();
				if (eTimer < 0.0f)
				{
					eTimer = 2.0f;
					ePhase++;
					return;
				}
			}
			else if (ePhase == 4)
			{
				this->GetComponent<Animator>()->PlayAnimation(L"Monster_Animation_CharginChuck_Middle", true);

				eTimer -= Time::DeltaTime();
				if (eTimer < 0.0f)
				{
					eTimer = 2.0f;
					ePhase++;
					return;
				}
			}

			tr->SetPosition(pos);
		}
		else
		{
			hitTimer -= Time::DeltaTime();
			if (hitTimer < 0.0f)
			{
				ePhase = tmpPhase;
				eTimer = tmpTimer;
				eAttacked = false;
			}
		}
	}

	void CharginChuck::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void CharginChuck::OnCollisionEnter(Collider* other)
	{
		Player* player = dynamic_cast<Player*>(other->GetOwner());

		if (player)
		{
			Transform* trPlayer = player->GetComponent<Transform>();
			Transform* trBox = GetComponent<Transform>();
			Collider* colPlayer = other;

			float lenX = fabs(trPlayer->GetPosition().x - trBox->GetPosition().x);
			float scaleX = (colPlayer->GetSize().x / 2.0f) + (GetComponent<Collider>()->GetSize().x / 2.0f);

			float lenY = fabs(trPlayer->GetPosition().y - trBox->GetPosition().y);
			float scaleY = (colPlayer->GetSize().y / 2.0f) + (GetComponent<Collider>()->GetSize().y / 2.0f);

			if (lenX < scaleX && lenY < scaleY)
			{
				float overlapX = scaleX - lenX;
				float overlapY = scaleY - lenY;

				// Separate the player from the box in the direction of the smallest overlap
				if (overlapX < overlapY)
				{
					Vector2 playerPos = trPlayer->GetPosition();
					if (trPlayer->GetPosition().x < trBox->GetPosition().x)
						playerPos.x -= overlapX;
					else
						playerPos.x += overlapX;
					trPlayer->SetPosition(playerPos);
				}
				else
				{
					Vector2 playerPos = trPlayer->GetPosition();
					if (trPlayer->GetPosition().y < trBox->GetPosition().y)
					{
						// Bump the player Up
						playerPos.y += overlapY;
						Rigidbody* rb = player->GetComponent<Rigidbody>();
						rb->SetGround(false);
						rb->SetVelocity(Vector2(0.0f, -550.0f));
						this->GetComponent<Animator>()->PlayAnimation(L"Monster_Animation_CharginChuck_Hit", true);
						tmpPhase = ePhase;
						tmpTimer = eTimer;
						eAttacked = true;
					}
					else
					{
						// Set the setGround to true when colliding on top of the box
						//Rigidbody* rb = player->GetComponent<Rigidbody>();
						//rb->SetGround(true);
					}
					trPlayer->SetPosition(playerPos);
				}
			}
		}
	}

	void CharginChuck::OnCollisionStay(Collider* other)
	{
	}

	void CharginChuck::OnCollisionExit(Collider* other)
	{
	}

}

#include "ntoRedKoopa.h"
#include "ntoRedShell.h"
#include "Player.h"
#include "ntoRedKoopa.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "CustomTime.h"
#include "ntoResources.h"
#include "ntoSound.h"

namespace nto
{
	RedKoopa::RedKoopa()
		: mRotateTime(5.0f)
		, mDeathTime(1.0f) // 5
		, mAttacked(false)
		, mAttacked2(false)
		, mTick(true)
		, mState(1)
	{
	}

	RedKoopa::~RedKoopa()
	{
	}

	void RedKoopa::Initialize()
	{
	}

	void RedKoopa::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mState == 1)
		{
			if (mTick)
			{
				pos.x -= 30.0f * Time::DeltaTime();
				mRotateTime -= Time::DeltaTime();
				if (mRotateTime < 0.0f)
				{
					this->GetComponent<Animator>()->PlayAnimation(L"Monster_Animation_RedKoopa_Right", true);
					mRotateTime = 5.0f;
					mTick = false;
				}
			}
			else
			{
				pos.x += 30.0f * Time::DeltaTime();
				mRotateTime -= Time::DeltaTime();
				if (mRotateTime < 0.0f)
				{
					this->GetComponent<Animator>()->PlayAnimation(L"Monster_Animation_RedKoopa_Left", true);
					mRotateTime = 5.0f;
					mTick = true;
				}
			}
		}

		if (mState == 2 && mAttacked)
		{
			pos.y += 32.0f * Time::DeltaTime(); //400
			tr->SetPosition(pos);

			mDeathTime -= Time::DeltaTime();
			if (mDeathTime < 0.0f && mAttacked)
			{
				mAttacked = false; // remove
				//Destroy(this);
			}
		}


		tr->SetPosition(pos);
	}

	void RedKoopa::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void RedKoopa::OnCollisionEnter(Collider* other)
	{
		/*RedShell* redShell = dynamic_cast<RedShell*>(other->GetOwner());

		if (redShell)
		{
			Sound* sound = Resources::Load<Sound>(L"sfxNoDamage", L"..\\Assets\\Sound\\SFX\\WAV\\smw_stomp.wav");
			sound->Play(false);
		}*/

		Player* player = dynamic_cast<Player*>(other->GetOwner());

		if (player)
		{
			Transform* trPlayer = player->GetComponent<Transform>();
			Transform* trBox = GetComponent<Transform>();
			Collider* colPlayer = other;

			float lenX = fabs(trPlayer->GetPosition().x - trBox->GetPosition().x);
			float scaleX = (colPlayer->GetSize().x / 2.0f) + (GetComponent<Collider>()->GetSize().x / 2.0f) + trBox->GetScale().x;

			float lenY = fabs(trPlayer->GetPosition().y - trBox->GetPosition().y);
			float scaleY = (colPlayer->GetSize().y / 2.0f) + (GetComponent<Collider>()->GetSize().y / 2.0f) + trBox->GetScale().y;

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
						mAttacked = true;
						mAttacked2 = true;
						mState = 2;
						// Bump the player up
						playerPos.y -= overlapY;
						Rigidbody* rb = player->GetComponent<Rigidbody>();
						rb->SetGround(false);
						rb->SetVelocity(Vector2(0.0f, -500.0f));
						this->GetComponent<Animator>()->PlayAnimation(L"Monster_Animation_RedKoopa_Hit", true);

						Collider* cl = GetComponent<Collider>();
						cl->SetSize(Vector2(64.0f, 64.0f));

						Sound* sound = Resources::Load<Sound>(L"sfxNoDamage", L"..\\Assets\\Sound\\SFX\\WAV\\smw_stomp.wav");
						sound->Play(false);
					}
					else
					{
					}

					trPlayer->SetPosition(playerPos);
				}
			}
		}
	}

	void RedKoopa::OnCollisionStay(Collider* other)
	{
		/*RedShell* redShell = dynamic_cast<RedShell*>(other->GetOwner());

		if (redShell)
		{
			this->GetComponent<Animator>()->PlayAnimation(L"Monster_Animation_RedKoopa_Dead", true);
			this->mAttacked = true;

			Transform* tr = GetComponent<Transform>();
			Collider* cl = GetComponent<Collider>();

			cl->SetActive(false);
		}*/
	}

	void RedKoopa::OnCollisionExit(Collider* other)
	{
	}
}

#include "ntoMorton.h"
#include "Player.h"
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
	Morton::Morton()
		: ePhase(1)
		, eAttacked(false)
		, eTimer(2.0f)
		, eDeathTime(5.0f)
		, hitTimer(2.0f)
		, eHitCount(0)
		, eMaxWidth(704.0f)
		, eMaxHeight(384.0f)
		, ePatternSpeedX(eMaxWidth / eTimer)
		, ePatternSpeedY(eMaxHeight / eTimer)
		, ePatternTimer(hitTimer)
		, eAttackNumber(1)
		, eDistanceTimer(2.0f)
		, eFallTimer(0.5f)
	{
	}

	Morton::~Morton()
	{
	}

	void Morton::Initialize()
	{
	}

	void Morton::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Collider* col = GetComponent<Collider>();

		if (!eAttacked)
		{
			if (ePhase == 1)
			{
				pos.x -= ePatternSpeedX * Time::DeltaTime();
				eTimer -= Time::DeltaTime();
				if (eTimer < 0.0f)
				{
					this->GetComponent<Animator>()->PlayAnimation(L"Animation_Morton_Left_Wall", true);
					col->SetSize(Vector2(120.0f, 96.0f));
					col->SetOffset(Vector2(-8.0f, 0.0f));
					eTimer = ePatternTimer;
					ePhase++;
				}
			}
			else if (ePhase == 2)
			{
				pos.y -= ePatternSpeedY * Time::DeltaTime();
				eTimer -= Time::DeltaTime();
				if (eTimer < 0.0f)
				{
					this->GetComponent<Animator>()->PlayAnimation(L"Animation_Morton_Ceiling", true);
					col->SetSize(Vector2(96.0f, 120.0f));
					col->SetOffset(Vector2(0.0f, -8.0f));
					eTimer = ePatternTimer;
					ePhase++;
				}
			}
			else if (ePhase == 3)
			{
				eTimer -= Time::DeltaTime();

				if (eAttackNumber % 2 == 1) // Odd number, boss will drop
				{
					if (eTimer >= 0.4f)
					{
						pos.x += ePatternSpeedX * Time::DeltaTime(); // Keep moving right
					}
					else if (eTimer < 0.4f)
					{
						this->GetComponent<Animator>()->PlayAnimation(L"Animation_Morton_Fall", true);
						col->SetSize(Vector2(120.0f, 120.0f));
						col->SetOffset(Vector2(0.0f, 0.0f));
						pos.y += 768.0f * Time::DeltaTime(); // Start moving down
						eFallTimer -= Time::DeltaTime();
						if (eFallTimer < 0.0f)
						{
							this->GetComponent<Animator>()->PlayAnimation(L"Animation_Morton_Ground", true);
							col->SetSize(Vector2(96.0f, 120.0f));
							col->SetOffset(Vector2(0.0f, 8.0f));
							eFallTimer = 0.5f;
							eTimer = 1.6f;
							eAttackNumber++;
							ePhase = 1;
						}
					}
				}
				else // Even number, boss will not drop
				{
					pos.x += ePatternSpeedX * Time::DeltaTime(); // Keep moving right

					if (eTimer < 0.0f)
					{
						this->GetComponent<Animator>()->PlayAnimation(L"Animation_Morton_Right_Wall", true);
						col->SetSize(Vector2(120.0f, 96.0f));
						col->SetOffset(Vector2(8.0f, 0.0f));
						eTimer = ePatternTimer;
						eAttackNumber++;
						ePhase++;
					}
				}
			}

			else if (ePhase == 4)
			{
				pos.y += ePatternSpeedY * Time::DeltaTime();
				eTimer -= Time::DeltaTime();
				if (eTimer < 0.0f)
				{
					this->GetComponent<Animator>()->PlayAnimation(L"Animation_Morton_Ground", true);
					col->SetSize(Vector2(96.0f, 120.0f));
					col->SetOffset(Vector2(0.0f, 8.0f));
					eTimer = ePatternTimer;
					ePhase = 1;
				}
			}
		}
		else
		{
			this->GetComponent<Animator>()->PlayAnimation(L"Animation_Morton_Fall", false);
			hitTimer -= Time::DeltaTime();
			if (hitTimer < 0.0f)
			{
				if(ePhase == 1)
					this->GetComponent<Animator>()->PlayAnimation(L"Animation_Morton_Ground", true);
				else if(ePhase == 2)
					this->GetComponent<Animator>()->PlayAnimation(L"Animation_Morton_Left_Wall", true);
				else if(ePhase == 3)
					this->GetComponent<Animator>()->PlayAnimation(L"Animation_Morton_Ceiling", true);
				else if (ePhase == 4)
					this->GetComponent<Animator>()->PlayAnimation(L"Animation_Morton_Right_Wall", true);
				ePhase = tmpPhase;
				eTimer = tmpTimer;
				eAttacked = false;
			}
		}

		tr->SetPosition(pos);
	}

	void Morton::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Morton::OnCollisionEnter(Collider* other)
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
						Sound* sound = Resources::Load<Sound>(L"sfxStun", L"..\\Assets\\Sound\\SFX\\WAV\\stun.wav");
						sound->Play(false);
						// Bump the player Up
						playerPos.y += overlapY;
						Rigidbody* rb = player->GetComponent<Rigidbody>();
						rb->SetGround(false);
						rb->SetVelocity(Vector2(0.0f, -1000.0f));

						this->GetComponent<Animator>()->PlayAnimation(L"Animation_Morton_Fall", false);
						hitTimer = 2.0f;
						tmpPhase = ePhase;
						tmpTimer = eTimer;
						eHitCount++;
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

	void Morton::OnCollisionStay(Collider* other)
	{
	}

	void Morton::OnCollisionExit(Collider* other)
	{
	}
}

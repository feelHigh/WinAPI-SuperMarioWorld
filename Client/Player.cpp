#include "Player.h"
#include "ntoRedShell.h"
#include "Transform.h"
#include "Controller.h"
#include "ntoCollider.h"
#include "Animator.h"
#include "ntoRigidbody.h"
#include "ntoCollisionManager.h"
#include "Object.h"
#include "Texture.h"
#include "ntoResources.h"
#include "ntoSound.h"
#include "CustomTime.h"

namespace nto
{
	Player::Player()
		: mPlayerClass(eMarioClass::Small)
		, mDir(eMarioDirection::Right)
		, mState(eState::Idle)
		, onGround(false)
		, mLives(3)
		, mCoins(0)
	{
	}

	Player::~Player()
	{
	}

	void Player::Initialize()
	{
	}

	void Player::Update()
	{
		GameObject::Update();

		switch (mPlayerClass)
		{
		case nto::Player::eMarioClass::Small:
			switch (mState)
			{
			case nto::Player::eState::Idle:
				SmallM_Idle();
				break;
			case nto::Player::eState::Run:
				SmallM_Run();
				break;
			case nto::Player::eState::Duck:
				SmallM_Duck();
				break;
			case nto::Player::eState::Jump:
				SmallM_Jump();
				break;
			case nto::Player::eState::Fall:
				SmallM_Fall();
				break;
			case nto::Player::eState::Kick:
				SmallM_Kick();
				break;
			case nto::Player::eState::Dead:
				SmallM_Dead();
				break;
			default:
				break;
			}
			break;
		case nto::Player::eMarioClass::Super:
			switch (mState)
			{
			case nto::Player::eState::Idle:
				SuperM_Idle();
				break;
			case nto::Player::eState::Run:
				SuperM_Run();
				break;
			case nto::Player::eState::Duck:
				SuperM_Duck();
				break;
			case nto::Player::eState::Jump:
				SuperM_Jump();
				break;
			case nto::Player::eState::Fall:
				SuperM_Fall();
				break;
			case nto::Player::eState::Kick:
				SuperM_Kick();
				break;
			case nto::Player::eState::Dead:
				SuperM_Dead();
				break;
			default:
				break;
			}
			break;
		case nto::Player::eMarioClass::Fire:
			switch (mState)
			{
			case nto::Player::eState::Idle:
				FireM_Idle();
				break;
			case nto::Player::eState::Run:
				FireM_Run();
				break;
			case nto::Player::eState::Duck:
				FireM_Duck();
				break;
			case nto::Player::eState::Jump:
				FireM_Jump();
				break;
			case nto::Player::eState::Fall:
				FireM_Fall();
				break;
			case nto::Player::eState::Kick:
				FireM_Kick();
				break;
			case nto::Player::eState::Attack:
				FireM_Attack();
			case nto::Player::eState::Dead:
				FireM_Dead();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Player::OnCollisionEnter(Collider* other)
	{
		ItemSuperMushroom* upgradeMushroom = dynamic_cast<ItemSuperMushroom*>(other->GetOwner());
		if (upgradeMushroom)
		{
			mPlayerClass = eMarioClass::Super;
		}
		ItemFireFlower* upgradeFlower = dynamic_cast<ItemFireFlower*>(other->GetOwner());
		if (upgradeFlower)
		{
			mPlayerClass = eMarioClass::Fire;
		}
	}

	void Player::OnCollisionStay(Collider* other)
	{
		RedPara* redpara = dynamic_cast<RedPara*>(other->GetOwner());
		if (redpara)
		{
			if (mPlayerClass == eMarioClass::Super || mPlayerClass == eMarioClass::Fire)
			{
				Sound* mSound = Resources::Load<Sound>(L"playerDowngrade", L"..\\Assets\\Sound\\SFX\\WAV\\smw_jump.wav");
				mSound->Play(false);
				mPlayerClass = eMarioClass::Small;
			}
		}

		Piranha* piranha = dynamic_cast<Piranha*>(other->GetOwner());
		if (piranha)
		{
			if (mPlayerClass == eMarioClass::Super || mPlayerClass == eMarioClass::Fire)
			{
				mPlayerClass = eMarioClass::Small;
			}
		}

		RedKoopa* redkoopa = dynamic_cast<RedKoopa*>(other->GetOwner());
		if (redkoopa)
		{
			if (mPlayerClass == eMarioClass::Super || mPlayerClass == eMarioClass::Fire)
			{
				mPlayerClass = eMarioClass::Small;
			}
		}

		Morton* morton = dynamic_cast<Morton*>(other->GetOwner());
		if (morton)
		{
			if (mPlayerClass == eMarioClass::Super || mPlayerClass == eMarioClass::Fire)
			{
				mPlayerClass = eMarioClass::Small;
			}
		}
	}

	void Player::OnCollisionExit(Collider* other)
	{
	}

	#pragma region Small Mario Action
	void Player::SmallM_Idle()
	{
		Animator* animator = GetComponent<Animator>();

		// 위로 보기 애니메이션 재생
		if (Controller::GetKey(eKeyCode::W))
		{
		}
		// 왼쪽 이동 애니메이션 재생
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Small_Run_Left", true);
			mState = eState::Run;
		}
		// 구부리기 애니메이션 재생
		if (Controller::GetKey(eKeyCode::S))
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Small_Duck_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Small_Duck_Right", true);
			}

			mState = eState::Duck;
		}
		// 오른쪽 이동 애니메이션 재생
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Small_Run_Right", true);
			mState = eState::Run;
		}
		// 점프 애니메이션 재생, 리지드 바디 적용
		if (Controller::GetKey(eKeyCode::Space))
		{
			Rigidbody* rb = GetComponent<Rigidbody>();
			Vector2 velocity = rb->GetVelocity();
			velocity.y = JUMPFORCE;
			rb->SetVelocity(velocity);
			rb->SetGround(false);

			Sound* mSound = Resources::Load<Sound>(L"playerJump", L"..\\Assets\\Sound\\SFX\\WAV\\smw_jump.wav");
			mSound->Play(false);

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Small_Jump_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Small_Jump_Right", true);
			}
			mState = eState::Jump;
		}
		if (Controller::GetKeyDown(eKeyCode::Z))
		{
			animator->PlayAnimation(L"Animation_Small_Kick_Right", true);
			mState = eState::Kick;
		}
	}

	void Player::SmallM_Run()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* animator = GetComponent<Animator>();

		if (Controller::GetKey(eKeyCode::W))
		{
		}
		// 플레이어 왼쪽 이동
		if (Controller::GetKey(eKeyCode::A))
		{
			pos.x -= RUNSPEED * Time::DeltaTime();
		}
		// 플레이어 구부리기
		if (Controller::GetKey(eKeyCode::S))
		{
			mState = eState::Duck;
		}
		// 플레이어 오른쪽 이동
		if (Controller::GetKey(eKeyCode::D))
		{
			pos.x += RUNSPEED * Time::DeltaTime();
		}
		// 이동중 점프 애니메이션, 리지드 바디 적용
		if (Controller::GetKey(eKeyCode::Space))
		{
			Rigidbody* rb = GetComponent<Rigidbody>();
			Vector2 velocity = rb->GetVelocity();
			velocity.y = JUMPFORCE;
			rb->SetVelocity(velocity);
			rb->SetGround(false);

			Sound* mSound = Resources::Load<Sound>(L"playerJump", L"..\\Assets\\Sound\\SFX\\WAV\\smw_jump.wav");
			mSound->Play(false);

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Small_Jump_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Small_Jump_Right", true);
			}
			mState = eState::Jump;
		}

		// 이동중 키 땔 때 Idle 상태로 복귀
		if (Controller::GetKeyUp(eKeyCode::W)
			|| Controller::GetKeyUp(eKeyCode::A)
			|| Controller::GetKeyUp(eKeyCode::S)
			|| Controller::GetKeyUp(eKeyCode::D))
		{

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Small_Idle_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Small_Idle_Right", true);
			}
			mState = eState::Idle;
		}

		tr->SetPosition(pos);
	}

	void Player::SmallM_Duck()
	{
		Transform* tr = GetComponent<Transform>();
		Animator* animator = GetComponent<Animator>();

		// 왼쪽 향해 구부리기
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Small_Duck_Left", true);
		}
		// 오른쪽 향해 구부리기
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Small_Duck_Right", true);
		}

		//  구부리기 키 땔 때 Idle 상태로 복귀
		if (Controller::GetKeyUp(eKeyCode::S))
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Small_Idle_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Small_Duck_Right", true);
			}
			mState = eState::Idle;
		}
	}

	void Player::SmallM_Jump()
	{
		Transform* tr = GetComponent<Transform>();
		Animator* animator = GetComponent<Animator>();
		Vector2 pos = tr->GetPosition();

		// 점프 할 때 적용되는 힘
		if (Controller::GetKeyDown(eKeyCode::Space))
		{
			GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, -2000.0f));
		}
		// 점프 중 왼쪽 이동
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Small_Jump_Left", true);
			pos.x -= RUNSPEED * Time::DeltaTime();
		}
		// 점프 중 오른쪽 이동
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Small_Jump_Right", true);
			pos.x += RUNSPEED * Time::DeltaTime();
		}

		// 점프 키 땔 때 Fall 상태로 전환
		if (Controller::GetKeyUp(eKeyCode::Space))
		{

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Small_Fall_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Small_Fall_Right", true);
			}
			mState = eState::Fall;
		}

		tr->SetPosition(pos);
	}

	void Player::SmallM_Fall()
	{
		Transform* tr = GetComponent<Transform>();
		Animator* animator = GetComponent<Animator>();
		Vector2 pos = tr->GetPosition();
		Rigidbody* rb = this->GetComponent<Rigidbody>();
		onGround = rb->GetGround();

		// 낙하 중 왼쪽 이동
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Small_Fall_Left", true);
			pos.x -= RUNSPEED * Time::DeltaTime();
		}
		// 낙하 중 오른쪽 이동
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Small_Fall_Right", true);
			pos.x += RUNSPEED * Time::DeltaTime();
		}

		// 낙하 전까지 Fall 애니메이션 재생, 낙하 시 Idle 상태로 복귀
		if (onGround)
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Small_Idle_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Small_Idle_Right", true);
			}
			mState = eState::Idle;
		}

		tr->SetPosition(pos);
	}

	void Player::SmallM_Kick()
	{
		Transform* tr = GetComponent<Transform>();

		Texture* image = Resources::Load<Texture>(L"RedShell_Atk"
			, L"..\\Assets\\Image\\Items\\Red_Shell.bmp");

		RedShell* thItem = object::Instantiate<RedShell>(eLayerType::Item, tr->GetPosition());
		Animator* at = thItem->AddComponent<Animator>();
		at->CreateAnimation(L"Item_Animation_RedShell_Spin_1", image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		at->SetScale(Vector2(4.0f, 4.0f));
		at->PlayAnimation(L"Item_Animation_RedShell_Spin_1", true);
		Collider* col = thItem->AddComponent<Collider>();
		col->SetSize(Vector2(64.0f, 64.0f));

		//object::Instantiate<RedShell>(eLayerType::Item, tr->GetPosition());
		mState = eState::Idle;
	}

	void Player::SmallM_Dead()
	{
	}
	#pragma endregion

	#pragma region Super Mario Action
	void Player::SuperM_Idle()
	{
		Animator* animator = GetComponent<Animator>();

		// 위로 보기 애니메이션 재생
		if (Controller::GetKey(eKeyCode::W))
		{
		}
		// 왼쪽 이동 애니메이션 재생
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Super_Run_Left", true);
			mState = eState::Run;
		}
		// 구부리기 애니메이션 재생
		if (Controller::GetKey(eKeyCode::S))
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Super_Duck_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Super_Duck_Right", true);
			}

			mState = eState::Duck;
		}
		// 오른쪽 이동 애니메이션 재생
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Super_Run_Right", true);
			mState = eState::Run;
		}
		// 점프 애니메이션 재생, 리지드 바디 적용
		if (Controller::GetKey(eKeyCode::Space))
		{
			Rigidbody* rb = GetComponent<Rigidbody>();
			Vector2 velocity = rb->GetVelocity();
			velocity.y = JUMPFORCE;
			rb->SetVelocity(velocity);
			rb->SetGround(false);

			Sound* mSound = Resources::Load<Sound>(L"playerJump", L"..\\Assets\\Sound\\SFX\\WAV\\smw_jump.wav");
			mSound->Play(false);

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Super_Jump_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Super_Jump_Right", true);
			}
			mState = eState::Jump;
		}
		if (Controller::GetKeyDown(eKeyCode::Z))
		{
			Sound* mSound = Resources::Load<Sound>(L"playerkick", L"..\\Assets\\Sound\\SFX\\WAV\\kick.wav");
			mSound->Play(false);
			animator->PlayAnimation(L"Animation_Super_Kick_Right", true);
			mState = eState::Kick;
		}
	}

	void Player::SuperM_Run()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* animator = GetComponent<Animator>();

		if (Controller::GetKey(eKeyCode::W))
		{
		}
		// 플레이어 왼쪽 이동
		if (Controller::GetKey(eKeyCode::A))
		{
			pos.x -= RUNSPEED * Time::DeltaTime();
		}
		// 플레이어 구부리기
		if (Controller::GetKey(eKeyCode::S))
		{
			mState = eState::Duck;
		}
		// 플레이어 오른쪽 이동
		if (Controller::GetKey(eKeyCode::D))
		{
			pos.x += RUNSPEED * Time::DeltaTime();
		}
		// 이동중 점프 애니메이션, 리지드 바디 적용
		if (Controller::GetKey(eKeyCode::Space))
		{
			Rigidbody* rb = GetComponent<Rigidbody>();
			Vector2 velocity = rb->GetVelocity();
			velocity.y = JUMPFORCE;
			rb->SetVelocity(velocity);
			rb->SetGround(false);

			Sound* mSound = Resources::Load<Sound>(L"playerJump", L"..\\Assets\\Sound\\SFX\\WAV\\smw_jump.wav");
			mSound->Play(false);

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Super_Jump_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Super_Jump_Right", true);
			}
			mState = eState::Jump;
		}

		// 이동중 키 땔 때 Idle 상태로 복귀
		if (Controller::GetKeyUp(eKeyCode::W)
			|| Controller::GetKeyUp(eKeyCode::A)
			|| Controller::GetKeyUp(eKeyCode::S)
			|| Controller::GetKeyUp(eKeyCode::D))
		{

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Super_Idle_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Super_Idle_Right", true);
			}
			mState = eState::Idle;
		}

		tr->SetPosition(pos);
	}

	void Player::SuperM_Duck()
	{
		Transform* tr = GetComponent<Transform>();
		Animator* animator = GetComponent<Animator>();

		// 왼쪽 향해 구부리기
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Super_Duck_Left", true);
		}
		// 오른쪽 향해 구부리기
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Super_Duck_Right", true);
		}

		//  구부리기 키 땔 때 Idle 상태로 복귀
		if (Controller::GetKeyUp(eKeyCode::S))
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Super_Idle_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Super_Duck_Right", true);
			}
			mState = eState::Idle;
		}
	}

	void Player::SuperM_Jump()
	{
		Transform* tr = GetComponent<Transform>();
		Animator* animator = GetComponent<Animator>();
		Vector2 pos = tr->GetPosition();

		// 점프 할 때 적용되는 힘
		if (Controller::GetKeyDown(eKeyCode::Space))
		{
			GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, -2000.0f));
		}
		// 점프 중 왼쪽 이동
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Super_Jump_Left", true);
			pos.x -= RUNSPEED * Time::DeltaTime();
		}
		// 점프 중 오른쪽 이동
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Super_Jump_Right", true);
			pos.x += RUNSPEED * Time::DeltaTime();
		}

		// 점프 키 땔 때 Fall 상태로 전환
		if (Controller::GetKeyUp(eKeyCode::Space))
		{

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Super_Fall_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Super_Fall_Right", true);
			}
			mState = eState::Fall;
		}

		tr->SetPosition(pos);
	}

	void Player::SuperM_Fall()
	{
		Transform* tr = GetComponent<Transform>();
		Animator* animator = GetComponent<Animator>();
		Vector2 pos = tr->GetPosition();
		Rigidbody* rb = this->GetComponent<Rigidbody>();
		onGround = rb->GetGround();

		// 낙하 중 왼쪽 이동
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Super_Fall_Left", true);
			pos.x -= RUNSPEED * Time::DeltaTime();
		}
		// 낙하 중 오른쪽 이동
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Super_Fall_Right", true);
			pos.x += RUNSPEED * Time::DeltaTime();
		}

		// 낙하 전까지 Fall 애니메이션 재생, 낙하 시 Idle 상태로 복귀
		if (onGround)
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Super_Idle_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Super_Idle_Right", true);
			}
			mState = eState::Idle;
		}

		tr->SetPosition(pos);
	}

	void Player::SuperM_Kick()
	{
		Transform* tr = GetComponent<Transform>();

		Texture* image = Resources::Load<Texture>(L"RedShell_Atk"
			, L"..\\Assets\\Image\\Items\\Red_Shell.bmp");

		RedShell* thItem = object::Instantiate<RedShell>(eLayerType::Item, tr->GetPosition());
		Animator* at = thItem->AddComponent<Animator>();
		at->CreateAnimation(L"Item_Animation_RedShell_Spin_1", image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		at->SetScale(Vector2(4.0f, 4.0f));
		at->PlayAnimation(L"Item_Animation_RedShell_Spin_1", true);
		Collider* col = thItem->AddComponent<Collider>();
		col->SetSize(Vector2(64.0f, 64.0f));

		//object::Instantiate<RedShell>(eLayerType::Item, tr->GetPosition());
		mState = eState::Idle;
	}

	void Player::SuperM_Dead()
	{
	}
	#pragma endregion

	#pragma region Fire Mario Action
	void Player::FireM_Idle()
	{
		Animator* animator = GetComponent<Animator>();

		// 위로 보기 애니메이션 재생
		if (Controller::GetKey(eKeyCode::W))
		{
		}
		// 왼쪽 이동 애니메이션 재생
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Fire_Run_Left", true);
			mState = eState::Run;
		}
		// 구부리기 애니메이션 재생
		if (Controller::GetKey(eKeyCode::S))
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Fire_Duck_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Fire_Duck_Right", true);
			}

			mState = eState::Duck;
		}
		// 오른쪽 이동 애니메이션 재생
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Fire_Run_Right", true);
			mState = eState::Run;
		}
		// 점프 애니메이션 재생, 리지드 바디 적용
		if (Controller::GetKey(eKeyCode::Space))
		{
			Rigidbody* rb = GetComponent<Rigidbody>();
			Vector2 velocity = rb->GetVelocity();
			velocity.y = JUMPFORCE;
			rb->SetVelocity(velocity);
			rb->SetGround(false);

			Sound* mSound = Resources::Load<Sound>(L"playerJump", L"..\\Assets\\Sound\\SFX\\WAV\\smw_jump.wav");
			mSound->Play(false);

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Fire_Jump_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Fire_Jump_Right", true);
			}
			mState = eState::Jump;
		}
		if (Controller::GetKeyDown(eKeyCode::Z))
		{
			Sound* mSound = Resources::Load<Sound>(L"playerkick", L"..\\Assets\\Sound\\SFX\\WAV\\kick.wav");
			mSound->Play(false);
			animator->PlayAnimation(L"Animation_Fire_Kick_Right", true);
			mState = eState::Kick;
		}
		if (Controller::GetKeyDown(eKeyCode::X))
		{
			Sound* mSound = Resources::Load<Sound>(L"SFX_Fireball", L"..\\Assets\\Sound\\SFX\\WAV\\smw_fireball.wav");
			mSound->Play(false);
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Fire_Attack_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Fire_Attack_Right", true);
			}
			mState = eState::Attack;
		}
	}

	void Player::FireM_Run()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* animator = GetComponent<Animator>();

		if (Controller::GetKey(eKeyCode::W))
		{
		}
		// 플레이어 왼쪽 이동
		if (Controller::GetKey(eKeyCode::A))
		{
			pos.x -= RUNSPEED * Time::DeltaTime();
		}
		// 플레이어 구부리기
		if (Controller::GetKey(eKeyCode::S))
		{
			mState = eState::Duck;
		}
		// 플레이어 오른쪽 이동
		if (Controller::GetKey(eKeyCode::D))
		{
			pos.x += RUNSPEED * Time::DeltaTime();
		}
		// 이동중 점프 애니메이션, 리지드 바디 적용
		if (Controller::GetKey(eKeyCode::Space))
		{
			Rigidbody* rb = GetComponent<Rigidbody>();
			Vector2 velocity = rb->GetVelocity();
			velocity.y = JUMPFORCE;
			rb->SetVelocity(velocity);
			rb->SetGround(false);

			Sound* mSound = Resources::Load<Sound>(L"playerJump", L"..\\Assets\\Sound\\SFX\\WAV\\smw_jump.wav");
			mSound->Play(false);

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Fire_Jump_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Fire_Jump_Right", true);
			}
			mState = eState::Jump;
		}

		// 이동중 키 땔 때 Idle 상태로 복귀
		if (Controller::GetKeyUp(eKeyCode::W)
			|| Controller::GetKeyUp(eKeyCode::A)
			|| Controller::GetKeyUp(eKeyCode::S)
			|| Controller::GetKeyUp(eKeyCode::D))
		{

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Fire_Idle_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Fire_Idle_Right", true);
			}
			mState = eState::Idle;
		}

		tr->SetPosition(pos);
	}

	void Player::FireM_Duck()
	{
		Transform* tr = GetComponent<Transform>();
		Animator* animator = GetComponent<Animator>();

		// 왼쪽 향해 구부리기
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Fire_Duck_Left", true);
		}
		// 오른쪽 향해 구부리기
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Fire_Duck_Right", true);
		}

		//  구부리기 키 땔 때 Idle 상태로 복귀
		if (Controller::GetKeyUp(eKeyCode::S))
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Fire_Idle_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Fire_Duck_Right", true);
			}
			mState = eState::Idle;
		}
	}

	void Player::FireM_Jump()
	{
		Transform* tr = GetComponent<Transform>();
		Animator* animator = GetComponent<Animator>();
		Vector2 pos = tr->GetPosition();

		// 점프 할 때 적용되는 힘
		if (Controller::GetKeyDown(eKeyCode::Space))
		{
			GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, -2000.0f));
		}
		// 점프 중 왼쪽 이동
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Fire_Jump_Left", true);
			pos.x -= RUNSPEED * Time::DeltaTime();
		}
		// 점프 중 오른쪽 이동
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Fire_Jump_Right", true);
			pos.x += RUNSPEED * Time::DeltaTime();
		}

		// 점프 키 땔 때 Fall 상태로 전환
		if (Controller::GetKeyUp(eKeyCode::Space))
		{

			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Fire_Fall_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Fire_Fall_Right", true);
			}
			mState = eState::Fall;
		}

		tr->SetPosition(pos);
	}

	void Player::FireM_Fall()
	{
		Transform* tr = GetComponent<Transform>();
		Animator* animator = GetComponent<Animator>();
		Vector2 pos = tr->GetPosition();
		Rigidbody* rb = this->GetComponent<Rigidbody>();
		onGround = rb->GetGround();

		// 낙하 중 왼쪽 이동
		if (Controller::GetKey(eKeyCode::A))
		{
			mDir = eMarioDirection::Left;
			animator->PlayAnimation(L"Animation_Fire_Fall_Left", true);
			pos.x -= RUNSPEED * Time::DeltaTime();
		}
		// 낙하 중 오른쪽 이동
		if (Controller::GetKey(eKeyCode::D))
		{
			mDir = eMarioDirection::Right;
			animator->PlayAnimation(L"Animation_Fire_Fall_Right", true);
			pos.x += RUNSPEED * Time::DeltaTime();
		}

		// 낙하 전까지 Fall 애니메이션 재생, 낙하 시 Idle 상태로 복귀
		if (onGround)
		{
			if (mDir == eMarioDirection::Left)
			{
				animator->PlayAnimation(L"Animation_Fire_Idle_Left", true);
			}
			else
			{
				animator->PlayAnimation(L"Animation_Fire_Idle_Right", true);
			}
			mState = eState::Idle;
		}

		tr->SetPosition(pos);
	}

	void Player::FireM_Kick()
	{
		Transform* tr = GetComponent<Transform>();

		Texture* image = Resources::Load<Texture>(L"RedShell_Atk"
			, L"..\\Assets\\Image\\Items\\Red_Shell.bmp");

		RedShell* thItem = object::Instantiate<RedShell>(eLayerType::Item, tr->GetPosition());
		Animator* at = thItem->AddComponent<Animator>();
		at->CreateAnimation(L"Item_Animation_RedShell_Spin_1", image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		at->SetScale(Vector2(4.0f, 4.0f));
		at->PlayAnimation(L"Item_Animation_RedShell_Spin_1", true);
		Collider* col = thItem->AddComponent<Collider>();
		col->SetSize(Vector2(64.0f, 64.0f));

		//object::Instantiate<RedShell>(eLayerType::Item, tr->GetPosition());
		mState = eState::Idle;
	}

	void Player::FireM_Attack()
	{
		// Get the player's transform component
		Transform* tr = GetComponent<Transform>();

		// Load the texture of the fireball image
		Texture* image = Resources::Load<Texture>(L"Attack_Fireball", L"..\\Assets\\Mario\\fireball.bmp");

		Vector2 fireballOffset(0.0f, 0.0f); // Adjust the values as needed
		// Define the fireball offset relative to the player's position
		if (mDir == eMarioDirection::Left)
		{
			Vector2 fireballOffset(-100.0f, 0.0f); // Adjust the values as needed
		}
		else
		{
			Vector2 fireballOffset(100.0f, 0.0f); // Adjust the values as needed
		}

		// Calculate the spawn position for the fireball using the offset
		Vector2 spawnPosition = tr->GetPosition() + fireballOffset;

		// Create an instance of the AttackFireball object at the calculated spawn position
		AttackFireball* mFireball = object::Instantiate<AttackFireball>(eLayerType::PlayerAttack, spawnPosition);

		// Add an Animator component to the fireball
		Animator* animator = mFireball->AddComponent<Animator>();
		animator->CreateAnimation(L"Animation_Attack_Fireball", image, Vector2(0.0f, 0.0f), Vector2(6.0f, 7.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		animator->SetScale(Vector2(4.0f, 4.0f));
		animator->PlayAnimation(L"Animation_Attack_Fireball", false);

		// Add a Collider component to the fireball
		Collider* col = mFireball->AddComponent<Collider>();
		col->SetSize(Vector2(24.0f, 27.0f));

		// Add a Rigidbody component to the fireball
		Rigidbody* rb = mFireball->AddComponent<Rigidbody>();
		rb->SetVelocity(Vector2(600.0f, 0.0f));

		// Change the player's state to idle after attacking with the fireball
		mState = eState::Idle;
	}

	void Player::FireM_Dead()
	{
	}
	#pragma endregion

}

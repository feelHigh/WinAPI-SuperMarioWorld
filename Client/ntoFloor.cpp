#include "ntoFloor.h"
#include "ntoItemPSwitch.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"

namespace nto
{
	Floor::Floor()
	{
	}

	Floor::~Floor()
	{
	}

	void Floor::Initialize()
	{
	}

	void Floor::Update()
	{
		GameObject::Update();

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();
	}

	void Floor::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Floor::OnCollisionEnter(Collider* other)
	{
		Player* player = dynamic_cast<Player*>(other->GetOwner());
		Transform* tr = player->GetComponent<Transform>();
		Rigidbody* rb = player->GetComponent<Rigidbody>();

		float lenY = fabs(other->GetPosition().y - this->GetComponent<Collider>()->GetPosition().y);
		float scaleY = fabs(other->GetSize().y / 2.0f + this->GetComponent<Collider>()->GetSize().y / 2.0f);

		if (lenY < scaleY)
		{
			Vector2 playerPos = tr->GetPosition();
			playerPos.y -= (scaleY - lenY) - 1.0f;
			tr->SetPosition(playerPos);
		}

		rb->SetGround(true);
		////
		//ItemPSwitch* PSwitch = dynamic_cast<ItemPSwitch*>(other->GetOwner());
		//Transform* trPSwitch = PSwitch->GetComponent<Transform>();
		//Rigidbody* rbPSwitch = PSwitch->GetComponent<Rigidbody>();

		//float lenYPSwitch = fabs(other->GetPosition().y - this->GetComponent<Collider>()->GetPosition().y);
		//float scaleYPSwitch = fabs(other->GetSize().y / 2.0f + this->GetComponent<Collider>()->GetSize().y / 2.0f);

		//if (lenYPSwitch < scaleYPSwitch)
		//{
		//	Vector2 PSwitchPos = tr->GetPosition();
		//	PSwitchPos.y -= (scaleYPSwitch - lenYPSwitch) - 1.0f;
		//	trPSwitch->SetPosition(PSwitchPos);
		//}

		//rbPSwitch->SetGround(true);
	}

	void Floor::OnCollisionStay(Collider* other)
	{
	}

	void Floor::OnCollisionExit(Collider* other)
	{
		Player* player = dynamic_cast<Player*>(other->GetOwner());
		player->GetComponent<Rigidbody>()->SetGround(false);
	}
}

#pragma once
#include "Entity.h"
#include "Component.h"

namespace nto
{
	class GameObject : public Entity
	{
	public:
		enum class eState
		{
			Active,
			Pause,
			Dead,
			End,
		};

		friend static __forceinline void Destroy(GameObject* gameObject);

		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		template <typename T>
		T* GetComponent()
		{
			T* comp = nullptr;
			for (Component* c : mComponents)
			{
				// 자식타입과 T타입이 일치한다면
				// 주소를 반환 그렇지않다면 nullptr 반환
				comp = dynamic_cast<T*>(c);
				if (comp != nullptr)
					return comp;
			}

			return comp;
		}

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			mComponents.push_back(comp);
			comp->SetOwner(this);

			return comp;
		}

		template <typename T>
		bool HasComponent()
		{
			return GetComponent<T>() != nullptr;
		}

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

		eState GetState() { return mState; }
		void Pause() { mState = eState::Pause; }

	private:
		void death() { mState = eState::Dead; }
		std::vector<Component*> mComponents;
		eState mState;
	};

	static __forceinline void Destroy(GameObject* gameObject)
	{
		gameObject->death();
	}
}

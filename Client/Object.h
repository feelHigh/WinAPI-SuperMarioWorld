#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "SceneManager.h"

namespace nto::object
{
	template <typename T>
	static __forceinline T* Instantiate(eLayerType type)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObject);

		return gameObject;
	}
}

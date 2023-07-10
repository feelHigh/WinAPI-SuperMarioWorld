#include "Scene.h"
#include "Player.h"
#include "SpriteRenderer.h"

namespace nto
{
	Scene::Scene()
	{
		mLayers.resize((int)eLayerType::End);
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
	}

	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(hdc);
		}
	}
}

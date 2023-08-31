#include "SceneManager.h"
#include "TitleScene.h"
#include "StageWorldMap.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "StageBoss.h"
#include "EndingScene.h"

namespace nto
{
	std::map<std::wstring, Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		CreateScene<TitleScene>(L"TitleScene");
		//CreateScene<StageWorldMap>(L"StageWorldMap");

		LoadScene(L"TitleScene");
		//LoadScene(L"StageWorldMap");
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;

		mActiveScene = iter->second;
		return iter->second;
	}
}

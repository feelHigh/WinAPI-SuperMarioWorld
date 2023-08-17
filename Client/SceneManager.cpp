#include "SceneManager.h"
#include "TitleScene.h"
#include "StageWorldMap.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "StageBoss.h"

namespace nto
{
	std::map<std::wstring, Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		CreateScene<TitleScene>(L"TitleScene");
		CreateScene<StageWorldMap>(L"StageWorldMap");
		//CreateScene<Stage1>(L"Stage1");
		//CreateScene<Stage2>(L"Stage2");
		//CreateScene<Stage3>(L"Stage3");
		//CreateScene<StageBoss>(L"StageBoss");

		LoadScene(L"StageWorldMap");
		//LoadScene(L"Stage2");
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

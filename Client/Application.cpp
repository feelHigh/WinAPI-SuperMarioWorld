#include "Application.h"
#include "Controller.h"
#include "CustomTime.h"
#include "TitleScene.h"
#include "SceneManager.h"

namespace nto
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
		, mBackBuffer(NULL)
		, mBackHdc(NULL)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		mWidth = 1600;
		mHeight = 900;


		RECT rect = { 0, 0, mWidth, mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHwnd
			, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(mHwnd, true);

		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP defaultBitmap
			= (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(defaultBitmap);

		Time::Initailize();
		Controller::Initailize();

		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Controller::Update();

		SceneManager::Update();
	}

	void Application::Render()
	{
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);
		Time::Render(mBackHdc);

		SceneManager::Render(mBackHdc);

		BitBlt(mHdc, 0, 0, mWidth, mHeight
			, mBackHdc, 0, 0, SRCCOPY);
	}
}

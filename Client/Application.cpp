#include "Application.h"
#include "Controller.h"
#include "CustomTime.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Camera.h"
#include "ntoCollisionManager.h"

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

		mWidth = 1024;
		mHeight = 896;


		RECT rect = { 0, 0, mWidth, mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHwnd
			, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(mHwnd, true);

		// ������ �ػ� ������ ��Ʈ�� ����
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		// ���� ������ ��Ʈ���� ����Ű�� DC ����
		mBackHdc = CreateCompatibleDC(mHdc);

		// ���� ������ ��Ʈ�ʰ� DC�� ���� ����
		HBITMAP defaultBitmap
			= (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(defaultBitmap);

		Time::Initailize();
		Controller::Initailize();
		Camera::Initalize();
		CollisionManager::Initialize();
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
		Camera::Update();
		CollisionManager::Update();
		SceneManager::Update();

	}

	void Application::Render()
	{
		HBRUSH brush = CreateSolidBrush(RGB(125, 125, 125));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, brush);
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);
		SelectObject(mBackHdc, oldBrush);
		DeleteObject(brush);

		Time::Render(mBackHdc);

		CollisionManager::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		BitBlt(mHdc, 0, 0, mWidth, mHeight
			, mBackHdc, 0, 0, SRCCOPY);
	}
}

#include "Texture.h"
#include "Application.h"
#include "ntoResources.h"
#include "GameObject.h"
#include "Transform.h"
#include "Camera.h"

extern nto::Application application;

namespace nto
{
	Texture::Texture()
		: mImage(nullptr)
		, mBitmap(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
		, mType(eTextureType::None)
		, mbAffectCamera(true)
	{
	}
	Texture::~Texture()
	{
		delete mImage;
		mImage = nullptr;

		DeleteObject(mBitmap);
		mBitmap = NULL;
	}
	Texture* Texture::Create(const std::wstring& name, UINT width, UINT height)
	{
		Texture* image = Resources::Find<Texture>(name);
		if (image != nullptr)
			return image;

		image = new Texture();
		image->SetWidth(width);
		image->SetHeight(height);
		HDC hdc = application.GetHdc();
		HBITMAP bitmap = CreateCompatibleBitmap(hdc, width, height);
		image->SetHBitmap(bitmap);

		HDC bitmapHdc = CreateCompatibleDC(hdc);
		image->SetHdc(bitmapHdc);

		HBITMAP defaultBitmap = (HBITMAP)SelectObject(bitmapHdc, bitmap);
		DeleteObject(defaultBitmap);

		image->SetName(name);
		image->SetType(eTextureType::AlphaBmp);
		Resources::Insert<Texture>(name, image);

		return image;
	}
	HRESULT Texture::Load(const std::wstring& path)
	{
		//bmp 일때
		//png 일때

		std::wstring ext
			= path.substr(path.find_last_of(L".") + 1);
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0
				, LR_LOADFROMFILE | LR_CREATEDIBSECTION);


			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			if (info.bmBitsPixel == 32)
				mType = eTextureType::AlphaBmp;

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);

			HBITMAP deafultBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(deafultBitmap);
		}
		else if (ext == L"png")
		{
			mType = eTextureType::Png;
			// image.png 파일을 이용하여 Texture 객체를 생성합니다.
			mImage = Gdiplus::Image::FromFile(path.c_str());

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}

		return S_OK;
	}
	void Texture::Render(HDC hdc
		, Vector2 pos
		, Vector2 size
		, Vector2 leftTop
		, Vector2 rightBottom
		, Vector2 offset
		, Vector2 scale
		, float alpha
		, float rotate)
	{
		if (mBitmap == nullptr && mImage == nullptr)
			return;

		if (mbAffectCamera)
			pos = Camera::CalculatePosition(pos);

		if (mType == eTextureType::Bmp)
		{
			TransparentBlt(hdc, (int)pos.x - (size.x * scale.x / 2.0f) + offset.x
				, (int)pos.y - (size.y * scale.y / 2.0f) + offset.y
				, size.x * scale.x
				, size.y * scale.y
				, mHdc
				, leftTop.x, leftTop.y, rightBottom.x, rightBottom.y
				, RGB(255, 0, 255));
		}
		else if (mType == eTextureType::AlphaBmp)
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			// 0.0f ~ 1.0f -> 0 ~ 255
			alpha = (int)(alpha * 255.0f);

			if (alpha <= 0)
				alpha = 0;
			func.SourceConstantAlpha = alpha; // 0 ~ 255

			AlphaBlend(hdc, (int)pos.x - (size.x * scale.x / 2.0f) + offset.x
				, (int)pos.y - (size.y * scale.y / 2.0f) + offset.y
				, size.x * scale.x
				, size.y * scale.y
				, mHdc
				, leftTop.x, leftTop.y
				, rightBottom.x, rightBottom.y
				, func);
		}
		else if (mType == eTextureType::Png)
		{
			//// 내가 원하는 픽셀을 투명화 시킬떄
			Gdiplus::ImageAttributes imageAtt = {};
			//// 투명화 시킬 픽셀 색 범위
			imageAtt.SetColorKey(Gdiplus::Color(100, 100, 100)
				, Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);
			graphics.TranslateTransform((float)pos.x, (float)pos.y);
			graphics.RotateTransform(rotate);
			graphics.TranslateTransform(-(float)pos.x, -(float)pos.y);
			graphics.DrawImage(mImage
				, Gdiplus::Rect
				(
					(int)(pos.x - (size.x * scale.x / 2.0f) + offset.x)
					, (int)(pos.y - (size.y * scale.y / 2.0f) + offset.y)
					, (int)(size.x * scale.x)
					, (int)(size.y * scale.y)
				)
				, leftTop.x, leftTop.y
				, rightBottom.x, rightBottom.y
				, Gdiplus::UnitPixel
				, nullptr);
		}

		/*Rectangle(hdc
			, pos.x, pos.y
			, pos.x + 10, pos.y + 10);*/
	}
}

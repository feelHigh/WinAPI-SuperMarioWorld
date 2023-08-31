#include "Stage2.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "Controller.h"
#include "Texture.h"
#include "Transform.h"
#include "ntoResources.h"
#include "Camera.h"
#include "Animator.h"
#include "ntoCollider.h"
#include "ntoCollisionManager.h"
#include "ntoRigidbody.h"

namespace nto
{
	Stage2::Stage2()
		:stageTimer(600.0f)
	{
	}

	Stage2::~Stage2()
	{
	}

	void Stage2::Initialize()
	{
		#pragma region Background Layer
		Texture* Background_Image = Resources::Load<Texture>(L"Stage2_BackGround"
			, L"..\\Assets\\Image\\Background\\Stage2_Background.bmp");

		BackGround* BackGround_Entity = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* BackGround_Renderer = BackGround_Entity->AddComponent<SpriteRenderer>();
		BackGround_Renderer->SetImage(Background_Image);
		BackGround_Renderer->SetScale(Vector2(4.0f, 4.0f));
		BackGround_Renderer->SetAffectCamera(false);
		BackGround_Entity->GetComponent<Transform>()->SetPosition(Vector2(11264.0f, 58.0f));
		#pragma endregion

		#pragma region Environment Layer
		Texture* Hill_1_1_Image = Resources::Load<Texture>(L"Hill_1_1"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Hill_1_1.bmp");
		Texture* Hill_1_2_Image = Resources::Load<Texture>(L"Hill_1_2"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Hill_1_2.bmp");
		Texture* Hill_1_3_Image = Resources::Load<Texture>(L"Hill_1_3"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Hill_1_3.bmp");
		Texture* Hill_1_4_Image = Resources::Load<Texture>(L"Hill_1_4"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Hill_1_4.bmp");
		Texture* Hill_1_5_Image = Resources::Load<Texture>(L"Hill_1_5"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Hill_1_5.bmp");
		Texture* Hill_2_1_Image = Resources::Load<Texture>(L"Hill_2_1"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Hill_2_1.bmp");
		Texture* Hill_3_1_Image = Resources::Load<Texture>(L"Hill_3_1"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Hill_3_1.bmp");
		Texture* Hill_4_1_Image = Resources::Load<Texture>(L"Hill_4_1"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Hill_4_1.bmp");
		Texture* Hill_5_1_Image = Resources::Load<Texture>(L"Hill_5_1"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Hill_5_1.bmp");
		Texture* Hill_6_1_Image = Resources::Load<Texture>(L"Hill_6_1"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Hill_6_1.bmp");
		Texture* Hill_7_1_Image = Resources::Load<Texture>(L"Hill_7_1"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Hill_7_1.bmp");
		Texture* Hill_8_1_Image = Resources::Load<Texture>(L"Hill_8_1"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Hill_8_1.bmp");
		Texture* Brush_Big_Image = Resources::Load<Texture>(L"Brush_Big"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Brush_Big.bmp");
		Texture* Brush_Small_Image = Resources::Load<Texture>(L"Brush_Small"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Brush_Small.bmp");
		Texture* StoneBlock_Image = Resources::Load<Texture>(L"StoneBlock"
			, L"..\\Assets\\Image\\Environment\\Stage2\\StoneBlock.bmp");
		Texture* WoodBall_Image = Resources::Load<Texture>(L"WoodBall"
			, L"..\\Assets\\Image\\Environment\\Stage2\\WoodBall.bmp");
		Texture* WoodPlank_Image = Resources::Load<Texture>(L"WoodPlank"
			, L"..\\Assets\\Image\\Environment\\Stage2\\WoodPlank.bmp");
		Texture* GrayPlank_Image = Resources::Load<Texture>(L"GrayPlank"
			, L"..\\Assets\\Image\\Environment\\Stage2\\GrayPlank.bmp");
		Texture* Pipe_Yellow_1_Image = Resources::Load<Texture>(L"Pipe_Yellow_1"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Pipe_Yellow_1.bmp");
		Texture* Pipe_Orange_1_Image = Resources::Load<Texture>(L"Pipe_Orange_1"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Pipe_Orange_1.bmp");
		Texture* Sign_Finish_Image = Resources::Load<Texture>(L"Sign_Finish"
			, L"..\\Assets\\Image\\Environment\\Stage2\\Sign_Finish.bmp");

		Environment* Environment_Hill_1_4_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Hill_1_3_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Hill_1_2_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Hill_1_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Hill_1_5_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Hill_2_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Hill_3_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Hill_4_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Hill_5_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Hill_6_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Hill_7_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Hill_8_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Brush_Big_Entity_1 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Brush_Big_Entity_2 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Brush_Small_Entity_1 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Brush_Small_Entity_2 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Brush_Small_Entity_3 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Brush_Small_Entity_4 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Brush_Small_Entity_5 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Brush_Small_Entity_6 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Brush_Small_Entity_7 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_StoneBlock_Entity_1 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_StoneBlock_Entity_2 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_StoneBlock_Entity_3 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_StoneBlock_Entity_4 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_StoneBlock_Entity_5 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_StoneBlock_Entity_6 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_StoneBlock_Entity_7 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_StoneBlock_Entity_8 = object::Instantiate<Environment>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_1_1 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_1_2 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_1_3 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_1_4 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_1_5 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_2_1 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_2_2 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_2_3 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_2_4 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_2_5 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_3_1 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_3_2 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_3_3 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_3_4 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_3_5 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_4_1 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_4_2 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_4_3 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_4_4 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_4_5 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_5_1 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_5_2 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_5_3 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_5_4 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_5_5 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_6_1 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_6_2 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_6_3 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_6_4 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_6_5 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_7_1 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_7_2 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_7_3 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_7_4 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_7_5 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_8_1 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_8_2 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_8_3 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_8_4 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodBall* Environment_WoodBall_Entity_8_5 = object::Instantiate<EnvironmentWoodBall>(eLayerType::Environment);
		EnvironmentWoodPlank* Environment_WoodPlank_Entity_1 = object::Instantiate<EnvironmentWoodPlank>(eLayerType::Environment);
		EnvironmentWoodPlank* Environment_WoodPlank_Entity_2 = object::Instantiate<EnvironmentWoodPlank>(eLayerType::Environment);
		EnvironmentWoodPlank* Environment_WoodPlank_Entity_3 = object::Instantiate<EnvironmentWoodPlank>(eLayerType::Environment);
		EnvironmentWoodPlank* Environment_WoodPlank_Entity_4 = object::Instantiate<EnvironmentWoodPlank>(eLayerType::Environment);
		EnvironmentWoodPlank* Environment_WoodPlank_Entity_5 = object::Instantiate<EnvironmentWoodPlank>(eLayerType::Environment);
		EnvironmentWoodPlank* Environment_WoodPlank_Entity_6 = object::Instantiate<EnvironmentWoodPlank>(eLayerType::Environment);
		EnvironmentWoodPlank* Environment_WoodPlank_Entity_7 = object::Instantiate<EnvironmentWoodPlank>(eLayerType::Environment);
		EnvironmentWoodPlank* Environment_WoodPlank_Entity_8 = object::Instantiate<EnvironmentWoodPlank>(eLayerType::Environment);
		EnvironmentGrayPlank* Environment_GrayPlank_Entity_1 = object::Instantiate<EnvironmentGrayPlank>(eLayerType::Environment);
		EnvironmentGrayPlank* Environment_GrayPlank_Entity_2 = object::Instantiate<EnvironmentGrayPlank>(eLayerType::Environment);
		EnvironmentGrayPlank* Environment_GrayPlank_Entity_3 = object::Instantiate<EnvironmentGrayPlank>(eLayerType::Environment);
		EnvironmentGrayPlank* Environment_GrayPlank_Entity_4 = object::Instantiate<EnvironmentGrayPlank>(eLayerType::Environment);
		Environment* Environment_Pipe_Yellow_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Pipe_Orange_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Environment_Sign_Finish_Entity = object::Instantiate<Environment>(eLayerType::Environment);

		// Set Type
		Environment_GrayPlank_Entity_2->SetType(2);
		Environment_GrayPlank_Entity_3->SetType(2);

		SpriteRenderer* Hill_1_1_Renderer = Environment_Hill_1_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_1_2_Renderer = Environment_Hill_1_2_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_1_3_Renderer = Environment_Hill_1_3_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_1_4_Renderer = Environment_Hill_1_4_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_1_5_Renderer = Environment_Hill_1_5_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_2_1_Renderer = Environment_Hill_2_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_3_1_Renderer = Environment_Hill_3_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_4_1_Renderer = Environment_Hill_4_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_5_1_Renderer = Environment_Hill_5_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_6_1_Renderer = Environment_Hill_6_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_7_1_Renderer = Environment_Hill_7_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_8_1_Renderer = Environment_Hill_8_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Big_Renderer_1 = Environment_Brush_Big_Entity_1->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Big_Renderer_2 = Environment_Brush_Big_Entity_2->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Small_Renderer_1 = Environment_Brush_Small_Entity_1->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Small_Renderer_2 = Environment_Brush_Small_Entity_2->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Small_Renderer_3 = Environment_Brush_Small_Entity_3->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Small_Renderer_4 = Environment_Brush_Small_Entity_4->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Small_Renderer_5 = Environment_Brush_Small_Entity_5->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Small_Renderer_6 = Environment_Brush_Small_Entity_6->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Small_Renderer_7 = Environment_Brush_Small_Entity_7->AddComponent<SpriteRenderer>();
		SpriteRenderer* StoneBlock_Renderer_1 = Environment_StoneBlock_Entity_1->AddComponent<SpriteRenderer>();
		SpriteRenderer* StoneBlock_Renderer_2 = Environment_StoneBlock_Entity_2->AddComponent<SpriteRenderer>();
		SpriteRenderer* StoneBlock_Renderer_3 = Environment_StoneBlock_Entity_3->AddComponent<SpriteRenderer>();
		SpriteRenderer* StoneBlock_Renderer_4 = Environment_StoneBlock_Entity_4->AddComponent<SpriteRenderer>();
		SpriteRenderer* StoneBlock_Renderer_5 = Environment_StoneBlock_Entity_5->AddComponent<SpriteRenderer>();
		SpriteRenderer* StoneBlock_Renderer_6 = Environment_StoneBlock_Entity_6->AddComponent<SpriteRenderer>();
		SpriteRenderer* StoneBlock_Renderer_7 = Environment_StoneBlock_Entity_7->AddComponent<SpriteRenderer>();
		SpriteRenderer* StoneBlock_Renderer_8 = Environment_StoneBlock_Entity_8->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_1_1 = Environment_WoodBall_Entity_1_1->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_1_2 = Environment_WoodBall_Entity_1_2->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_1_3 = Environment_WoodBall_Entity_1_3->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_1_4 = Environment_WoodBall_Entity_1_4->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_1_5 = Environment_WoodBall_Entity_1_5->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_2_1 = Environment_WoodBall_Entity_2_1->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_2_2 = Environment_WoodBall_Entity_2_2->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_2_3 = Environment_WoodBall_Entity_2_3->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_2_4 = Environment_WoodBall_Entity_2_4->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_2_5 = Environment_WoodBall_Entity_2_5->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_3_1 = Environment_WoodBall_Entity_3_1->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_3_2 = Environment_WoodBall_Entity_3_2->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_3_3 = Environment_WoodBall_Entity_3_3->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_3_4 = Environment_WoodBall_Entity_3_4->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_3_5 = Environment_WoodBall_Entity_3_5->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_4_1 = Environment_WoodBall_Entity_4_1->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_4_2 = Environment_WoodBall_Entity_4_2->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_4_3 = Environment_WoodBall_Entity_4_3->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_4_4 = Environment_WoodBall_Entity_4_4->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_4_5 = Environment_WoodBall_Entity_4_5->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_5_1 = Environment_WoodBall_Entity_5_1->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_5_2 = Environment_WoodBall_Entity_5_2->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_5_3 = Environment_WoodBall_Entity_5_3->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_5_4 = Environment_WoodBall_Entity_5_4->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_5_5 = Environment_WoodBall_Entity_5_5->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_6_1 = Environment_WoodBall_Entity_6_1->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_6_2 = Environment_WoodBall_Entity_6_2->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_6_3 = Environment_WoodBall_Entity_6_3->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_6_4 = Environment_WoodBall_Entity_6_4->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_6_5 = Environment_WoodBall_Entity_6_5->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_7_1 = Environment_WoodBall_Entity_7_1->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_7_2 = Environment_WoodBall_Entity_7_2->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_7_3 = Environment_WoodBall_Entity_7_3->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_7_4 = Environment_WoodBall_Entity_7_4->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_7_5 = Environment_WoodBall_Entity_7_5->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_8_1 = Environment_WoodBall_Entity_8_1->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_8_2 = Environment_WoodBall_Entity_8_2->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_8_3 = Environment_WoodBall_Entity_8_3->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_8_4 = Environment_WoodBall_Entity_8_4->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodBall_Renderer_8_5 = Environment_WoodBall_Entity_8_5->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodPlank_Renderer_1 = Environment_WoodPlank_Entity_1->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodPlank_Renderer_2 = Environment_WoodPlank_Entity_2->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodPlank_Renderer_3 = Environment_WoodPlank_Entity_3->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodPlank_Renderer_4 = Environment_WoodPlank_Entity_4->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodPlank_Renderer_5 = Environment_WoodPlank_Entity_5->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodPlank_Renderer_6 = Environment_WoodPlank_Entity_6->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodPlank_Renderer_7 = Environment_WoodPlank_Entity_7->AddComponent<SpriteRenderer>();
		SpriteRenderer* WoodPlank_Renderer_8 = Environment_WoodPlank_Entity_8->AddComponent<SpriteRenderer>();
		SpriteRenderer* GrayPlank_Renderer_1 = Environment_GrayPlank_Entity_1->AddComponent<SpriteRenderer>();
		SpriteRenderer* GrayPlank_Renderer_2 = Environment_GrayPlank_Entity_2->AddComponent<SpriteRenderer>();
		SpriteRenderer* GrayPlank_Renderer_3 = Environment_GrayPlank_Entity_3->AddComponent<SpriteRenderer>();
		SpriteRenderer* GrayPlank_Renderer_4 = Environment_GrayPlank_Entity_4->AddComponent<SpriteRenderer>();
		SpriteRenderer* Pipe_Yellow_1_Renderer = Environment_Pipe_Yellow_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Pipe_Orange_1_Renderer = Environment_Pipe_Orange_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Sign_Finish_Renderer = Environment_Sign_Finish_Entity->AddComponent<SpriteRenderer>();

		Hill_1_1_Renderer->SetImage(Hill_1_1_Image);
		Hill_1_2_Renderer->SetImage(Hill_1_2_Image);
		Hill_1_3_Renderer->SetImage(Hill_1_3_Image);
		Hill_1_4_Renderer->SetImage(Hill_1_4_Image);
		Hill_1_5_Renderer->SetImage(Hill_1_5_Image);
		Hill_2_1_Renderer->SetImage(Hill_2_1_Image);
		Hill_3_1_Renderer->SetImage(Hill_3_1_Image);
		Hill_4_1_Renderer->SetImage(Hill_4_1_Image);
		Hill_5_1_Renderer->SetImage(Hill_5_1_Image);
		Hill_6_1_Renderer->SetImage(Hill_6_1_Image);
		Hill_7_1_Renderer->SetImage(Hill_7_1_Image);
		Hill_8_1_Renderer->SetImage(Hill_8_1_Image);
		Brush_Big_Renderer_1->SetImage(Brush_Big_Image);
		Brush_Big_Renderer_2->SetImage(Brush_Big_Image);
		Brush_Small_Renderer_1->SetImage(Brush_Small_Image);
		Brush_Small_Renderer_2->SetImage(Brush_Small_Image);
		Brush_Small_Renderer_3->SetImage(Brush_Small_Image);
		Brush_Small_Renderer_4->SetImage(Brush_Small_Image);
		Brush_Small_Renderer_5->SetImage(Brush_Small_Image);
		Brush_Small_Renderer_6->SetImage(Brush_Small_Image);
		Brush_Small_Renderer_7->SetImage(Brush_Small_Image);
		StoneBlock_Renderer_1->SetImage(StoneBlock_Image);
		StoneBlock_Renderer_2->SetImage(StoneBlock_Image);
		StoneBlock_Renderer_3->SetImage(StoneBlock_Image);
		StoneBlock_Renderer_4->SetImage(StoneBlock_Image);
		StoneBlock_Renderer_5->SetImage(StoneBlock_Image);
		StoneBlock_Renderer_6->SetImage(StoneBlock_Image);
		StoneBlock_Renderer_7->SetImage(StoneBlock_Image);
		StoneBlock_Renderer_8->SetImage(StoneBlock_Image);
		WoodBall_Renderer_1_1->SetImage(WoodBall_Image);
		WoodBall_Renderer_1_2->SetImage(WoodBall_Image);
		WoodBall_Renderer_1_3->SetImage(WoodBall_Image);
		WoodBall_Renderer_1_4->SetImage(WoodBall_Image);
		WoodBall_Renderer_1_5->SetImage(WoodBall_Image);
		WoodBall_Renderer_2_1->SetImage(WoodBall_Image);
		WoodBall_Renderer_2_2->SetImage(WoodBall_Image);
		WoodBall_Renderer_2_3->SetImage(WoodBall_Image);
		WoodBall_Renderer_2_4->SetImage(WoodBall_Image);
		WoodBall_Renderer_2_5->SetImage(WoodBall_Image);
		WoodBall_Renderer_3_1->SetImage(WoodBall_Image);
		WoodBall_Renderer_3_2->SetImage(WoodBall_Image);
		WoodBall_Renderer_3_3->SetImage(WoodBall_Image);
		WoodBall_Renderer_3_4->SetImage(WoodBall_Image);
		WoodBall_Renderer_3_5->SetImage(WoodBall_Image);
		WoodBall_Renderer_4_1->SetImage(WoodBall_Image);
		WoodBall_Renderer_4_2->SetImage(WoodBall_Image);
		WoodBall_Renderer_4_3->SetImage(WoodBall_Image);
		WoodBall_Renderer_4_4->SetImage(WoodBall_Image);
		WoodBall_Renderer_4_5->SetImage(WoodBall_Image);
		WoodBall_Renderer_5_1->SetImage(WoodBall_Image);
		WoodBall_Renderer_5_2->SetImage(WoodBall_Image);
		WoodBall_Renderer_5_3->SetImage(WoodBall_Image);
		WoodBall_Renderer_5_4->SetImage(WoodBall_Image);
		WoodBall_Renderer_5_5->SetImage(WoodBall_Image);
		WoodBall_Renderer_6_1->SetImage(WoodBall_Image);
		WoodBall_Renderer_6_2->SetImage(WoodBall_Image);
		WoodBall_Renderer_6_3->SetImage(WoodBall_Image);
		WoodBall_Renderer_6_4->SetImage(WoodBall_Image);
		WoodBall_Renderer_6_5->SetImage(WoodBall_Image);
		WoodBall_Renderer_7_1->SetImage(WoodBall_Image);
		WoodBall_Renderer_7_2->SetImage(WoodBall_Image);
		WoodBall_Renderer_7_3->SetImage(WoodBall_Image);
		WoodBall_Renderer_7_4->SetImage(WoodBall_Image);
		WoodBall_Renderer_7_5->SetImage(WoodBall_Image);
		WoodBall_Renderer_8_1->SetImage(WoodBall_Image);
		WoodBall_Renderer_8_2->SetImage(WoodBall_Image);
		WoodBall_Renderer_8_3->SetImage(WoodBall_Image);
		WoodBall_Renderer_8_4->SetImage(WoodBall_Image);
		WoodBall_Renderer_8_5->SetImage(WoodBall_Image);
		WoodPlank_Renderer_1->SetImage(WoodPlank_Image);
		WoodPlank_Renderer_2->SetImage(WoodPlank_Image);
		WoodPlank_Renderer_3->SetImage(WoodPlank_Image);
		WoodPlank_Renderer_4->SetImage(WoodPlank_Image);
		WoodPlank_Renderer_5->SetImage(WoodPlank_Image);
		WoodPlank_Renderer_6->SetImage(WoodPlank_Image);
		WoodPlank_Renderer_7->SetImage(WoodPlank_Image);
		WoodPlank_Renderer_8->SetImage(WoodPlank_Image);
		GrayPlank_Renderer_1->SetImage(GrayPlank_Image);
		GrayPlank_Renderer_2->SetImage(GrayPlank_Image);
		GrayPlank_Renderer_3->SetImage(GrayPlank_Image);
		GrayPlank_Renderer_4->SetImage(GrayPlank_Image);
		Pipe_Yellow_1_Renderer->SetImage(Pipe_Yellow_1_Image);
		Pipe_Orange_1_Renderer->SetImage(Pipe_Orange_1_Image);
		Sign_Finish_Renderer->SetImage(Sign_Finish_Image);

		Hill_1_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_1_2_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_1_3_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_1_4_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_1_5_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_2_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_3_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_4_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_5_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_6_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_7_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_8_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Brush_Big_Renderer_1->SetScale(Vector2(4.0f, 4.0f));
		Brush_Big_Renderer_2->SetScale(Vector2(4.0f, 4.0f));
		Brush_Small_Renderer_1->SetScale(Vector2(4.0f, 4.0f));
		Brush_Small_Renderer_2->SetScale(Vector2(4.0f, 4.0f));
		Brush_Small_Renderer_3->SetScale(Vector2(4.0f, 4.0f));
		Brush_Small_Renderer_4->SetScale(Vector2(4.0f, 4.0f));
		Brush_Small_Renderer_5->SetScale(Vector2(4.0f, 4.0f));
		Brush_Small_Renderer_6->SetScale(Vector2(4.0f, 4.0f));
		Brush_Small_Renderer_7->SetScale(Vector2(4.0f, 4.0f));
		StoneBlock_Renderer_1->SetScale(Vector2(4.0f, 4.0f));
		StoneBlock_Renderer_2->SetScale(Vector2(4.0f, 4.0f));
		StoneBlock_Renderer_3->SetScale(Vector2(4.0f, 4.0f));
		StoneBlock_Renderer_4->SetScale(Vector2(4.0f, 4.0f));
		StoneBlock_Renderer_5->SetScale(Vector2(4.0f, 4.0f));
		StoneBlock_Renderer_6->SetScale(Vector2(4.0f, 4.0f));
		StoneBlock_Renderer_7->SetScale(Vector2(4.0f, 4.0f));
		StoneBlock_Renderer_8->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_1_1->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_1_2->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_1_3->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_1_4->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_1_5->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_2_1->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_2_2->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_2_3->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_2_4->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_2_5->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_3_1->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_3_2->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_3_3->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_3_4->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_3_5->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_4_1->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_4_2->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_4_3->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_4_4->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_4_5->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_5_1->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_5_2->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_5_3->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_5_4->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_5_5->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_6_1->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_6_2->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_6_3->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_6_4->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_6_5->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_7_1->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_7_2->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_7_3->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_7_4->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_7_5->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_8_1->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_8_2->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_8_3->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_8_4->SetScale(Vector2(4.0f, 4.0f));
		WoodBall_Renderer_8_5->SetScale(Vector2(4.0f, 4.0f));
		WoodPlank_Renderer_1->SetScale(Vector2(4.0f, 4.0f));
		WoodPlank_Renderer_2->SetScale(Vector2(4.0f, 4.0f));
		WoodPlank_Renderer_3->SetScale(Vector2(4.0f, 4.0f));
		WoodPlank_Renderer_4->SetScale(Vector2(4.0f, 4.0f));
		WoodPlank_Renderer_5->SetScale(Vector2(4.0f, 4.0f));
		WoodPlank_Renderer_6->SetScale(Vector2(4.0f, 4.0f));
		WoodPlank_Renderer_7->SetScale(Vector2(4.0f, 4.0f));
		WoodPlank_Renderer_8->SetScale(Vector2(4.0f, 4.0f));
		GrayPlank_Renderer_1->SetScale(Vector2(4.0f, 4.0f));
		GrayPlank_Renderer_2->SetScale(Vector2(4.0f, 4.0f));
		GrayPlank_Renderer_3->SetScale(Vector2(4.0f, 4.0f));
		GrayPlank_Renderer_4->SetScale(Vector2(4.0f, 4.0f));
		Pipe_Yellow_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Pipe_Orange_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Sign_Finish_Renderer->SetScale(Vector2(4.0f, 4.0f));

		Environment_Hill_1_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(540.0f, 600.0f));
		Environment_Hill_1_2_Entity->GetComponent<Transform>()->SetPosition(Vector2(360.0f, 472.0f));
		Environment_Hill_1_3_Entity->GetComponent<Transform>()->SetPosition(Vector2(480.0f, 344.0f));
		Environment_Hill_1_4_Entity->GetComponent<Transform>()->SetPosition(Vector2(760.0f, 248.0f));
		Environment_Hill_1_5_Entity->GetComponent<Transform>()->SetPosition(Vector2(1240.0f, 376.0f));
		Environment_Hill_2_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(2400.0f, 568.0f));
		Environment_Hill_3_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(3714.0f, 312.0f));
		Environment_Hill_4_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(4898.0f, 472.0f));
		Environment_Hill_5_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(6658.0f, 344.0f));
		Environment_Hill_6_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(12130.0f, 376.0f));
		Environment_Hill_7_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(15298.0f, 376.0f));
		Environment_Hill_8_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(16994.0f, 472.0f));
		Environment_Brush_Big_Entity_1->GetComponent<Transform>()->SetPosition(Vector2(10208.0f, 696.0f));
		Environment_Brush_Big_Entity_2->GetComponent<Transform>()->SetPosition(Vector2(19776.0f, 696.0f));
		Environment_Brush_Small_Entity_1->GetComponent<Transform>()->SetPosition(Vector2(2368.0f, 184.0f));
		Environment_Brush_Small_Entity_2->GetComponent<Transform>()->SetPosition(Vector2(3714.0f, -168.0f));
		Environment_Brush_Small_Entity_3->GetComponent<Transform>()->SetPosition(Vector2(6530.0f, -264.0f));
		Environment_Brush_Small_Entity_4->GetComponent<Transform>()->SetPosition(Vector2(9536.0f, 696.0f));
		Environment_Brush_Small_Entity_5->GetComponent<Transform>()->SetPosition(Vector2(11008.0f, 696.0f));
		Environment_Brush_Small_Entity_6->GetComponent<Transform>()->SetPosition(Vector2(16994.0f, -7.0f));
		Environment_Brush_Small_Entity_7->GetComponent<Transform>()->SetPosition(Vector2(20256.0f, 696.0f));
		Environment_StoneBlock_Entity_1->GetComponent<Transform>()->SetPosition(Vector2(1602.0f, 249.0f));
		Environment_StoneBlock_Entity_2->GetComponent<Transform>()->SetPosition(Vector2(4162.0f, 249.0f));
		Environment_StoneBlock_Entity_3->GetComponent<Transform>()->SetPosition(Vector2(7298.0f, 185.0f));
		Environment_StoneBlock_Entity_4->GetComponent<Transform>()->SetPosition(Vector2(8066.0f, 441.0f));
		Environment_StoneBlock_Entity_5->GetComponent<Transform>()->SetPosition(Vector2(12546.0f, 249.0f));
		Environment_StoneBlock_Entity_6->GetComponent<Transform>()->SetPosition(Vector2(16386.0f, 441.0f));
		Environment_StoneBlock_Entity_7->GetComponent<Transform>()->SetPosition(Vector2(17730.0f, 441.0f));
		Environment_StoneBlock_Entity_8->GetComponent<Transform>()->SetPosition(Vector2(18370.0f, 505.0f));
		Environment_WoodBall_Entity_1_1->GetComponent<Transform>()->SetPosition(Vector2(1602.0f, 185.0f));
		Environment_WoodBall_Entity_1_2->GetComponent<Transform>()->SetPosition(Vector2(1602.0f, 121.0f));
		Environment_WoodBall_Entity_1_3->GetComponent<Transform>()->SetPosition(Vector2(1602.0f, 57.0f));
		Environment_WoodBall_Entity_1_4->GetComponent<Transform>()->SetPosition(Vector2(1602.0f, -7.0f));
		Environment_WoodBall_Entity_1_5->GetComponent<Transform>()->SetPosition(Vector2(1602.0f, -71.0f));
		Environment_WoodBall_Entity_2_1->GetComponent<Transform>()->SetPosition(Vector2(4162.0f, 185.0f));
		Environment_WoodBall_Entity_2_2->GetComponent<Transform>()->SetPosition(Vector2(4162.0f, 121.0f));
		Environment_WoodBall_Entity_2_3->GetComponent<Transform>()->SetPosition(Vector2(4162.0f, 57.0f));
		Environment_WoodBall_Entity_2_4->GetComponent<Transform>()->SetPosition(Vector2(4162.0f, -7.0f));
		Environment_WoodBall_Entity_2_5->GetComponent<Transform>()->SetPosition(Vector2(4162.0f, -71.0f));
		Environment_WoodBall_Entity_3_1->GetComponent<Transform>()->SetPosition(Vector2(7298.0f, 121.0f));
		Environment_WoodBall_Entity_3_2->GetComponent<Transform>()->SetPosition(Vector2(7298.0f, 57.0f));
		Environment_WoodBall_Entity_3_3->GetComponent<Transform>()->SetPosition(Vector2(7298.0f, -7.0f));
		Environment_WoodBall_Entity_3_4->GetComponent<Transform>()->SetPosition(Vector2(7298.0f, -71.0f));
		Environment_WoodBall_Entity_3_5->GetComponent<Transform>()->SetPosition(Vector2(7298.0f, -135.0f));
		Environment_WoodBall_Entity_4_1->GetComponent<Transform>()->SetPosition(Vector2(8066.0f, 377.0f));
		Environment_WoodBall_Entity_4_2->GetComponent<Transform>()->SetPosition(Vector2(8066.0f, 313.0f));
		Environment_WoodBall_Entity_4_3->GetComponent<Transform>()->SetPosition(Vector2(8066.0f, 249.0f));
		Environment_WoodBall_Entity_4_4->GetComponent<Transform>()->SetPosition(Vector2(8066.0f, 185.0f));
		Environment_WoodBall_Entity_4_5->GetComponent<Transform>()->SetPosition(Vector2(8066.0f, 121.0f));
		Environment_WoodBall_Entity_5_1->GetComponent<Transform>()->SetPosition(Vector2(12546.0f, 185.0f));
		Environment_WoodBall_Entity_5_2->GetComponent<Transform>()->SetPosition(Vector2(12546.0f, 121.0f));
		Environment_WoodBall_Entity_5_3->GetComponent<Transform>()->SetPosition(Vector2(12546.0f, 57.0f));
		Environment_WoodBall_Entity_5_4->GetComponent<Transform>()->SetPosition(Vector2(12546.0f, -7.0f));
		Environment_WoodBall_Entity_5_5->GetComponent<Transform>()->SetPosition(Vector2(12546.0f, -71.0f));
		Environment_WoodBall_Entity_6_1->GetComponent<Transform>()->SetPosition(Vector2(16386.0f, 377.0f));
		Environment_WoodBall_Entity_6_2->GetComponent<Transform>()->SetPosition(Vector2(16386.0f, 313.0f));
		Environment_WoodBall_Entity_6_3->GetComponent<Transform>()->SetPosition(Vector2(16386.0f, 249.0f));
		Environment_WoodBall_Entity_6_4->GetComponent<Transform>()->SetPosition(Vector2(16386.0f, 185.0f));
		Environment_WoodBall_Entity_6_5->GetComponent<Transform>()->SetPosition(Vector2(16386.0f, 121.0f));
		Environment_WoodBall_Entity_7_1->GetComponent<Transform>()->SetPosition(Vector2(17730.0f, 377.0f));
		Environment_WoodBall_Entity_7_2->GetComponent<Transform>()->SetPosition(Vector2(17730.0f, 313.0f));
		Environment_WoodBall_Entity_7_3->GetComponent<Transform>()->SetPosition(Vector2(17730.0f, 249.0f));
		Environment_WoodBall_Entity_7_4->GetComponent<Transform>()->SetPosition(Vector2(17730.0f, 185.0f));
		Environment_WoodBall_Entity_7_5->GetComponent<Transform>()->SetPosition(Vector2(17730.0f, 121.0f));
		Environment_WoodBall_Entity_8_1->GetComponent<Transform>()->SetPosition(Vector2(18370.0f, 441.0f));
		Environment_WoodBall_Entity_8_2->GetComponent<Transform>()->SetPosition(Vector2(18370.0f, 377.0f));
		Environment_WoodBall_Entity_8_3->GetComponent<Transform>()->SetPosition(Vector2(18370.0f, 313.0f));
		Environment_WoodBall_Entity_8_4->GetComponent<Transform>()->SetPosition(Vector2(18370.0f, 249.0f));
		Environment_WoodBall_Entity_8_5->GetComponent<Transform>()->SetPosition(Vector2(18370.0f, 185.0f));
		Environment_WoodPlank_Entity_1->GetComponent<Transform>()->SetPosition(Vector2(1602.0f, -103.0f));
		Environment_WoodPlank_Entity_2->GetComponent<Transform>()->SetPosition(Vector2(4162.0f, -103.0f));
		Environment_WoodPlank_Entity_3->GetComponent<Transform>()->SetPosition(Vector2(7298.0f, -167.0f));
		Environment_WoodPlank_Entity_4->GetComponent<Transform>()->SetPosition(Vector2(8066.0f, 89.0f));
		Environment_WoodPlank_Entity_5->GetComponent<Transform>()->SetPosition(Vector2(12546.0f, -103.0f));
		Environment_WoodPlank_Entity_6->GetComponent<Transform>()->SetPosition(Vector2(16386.0f, 89.0f));
		Environment_WoodPlank_Entity_7->GetComponent<Transform>()->SetPosition(Vector2(17730.0f, 89.0f));
		Environment_WoodPlank_Entity_8->GetComponent<Transform>()->SetPosition(Vector2(18370.0f, 153.0f));
		Environment_GrayPlank_Entity_1->GetComponent<Transform>()->SetPosition(Vector2(5634.0f, 57.0f));
		Environment_GrayPlank_Entity_2->GetComponent<Transform>()->SetPosition(Vector2(6018.0f, 57.0f));
		Environment_GrayPlank_Entity_3->GetComponent<Transform>()->SetPosition(Vector2(11842.0f, 249.0f));
		Environment_GrayPlank_Entity_4->GetComponent<Transform>()->SetPosition(Vector2(16088.0f, -7.0f));
		Environment_Pipe_Yellow_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(7074.0f, 726.0f));
		Environment_Pipe_Orange_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(8866.0f, 474.0f));
		Environment_Sign_Finish_Entity->GetComponent<Transform>()->SetPosition(Vector2(19076.0f, 346.0f));

		Collider* colHill_1_1 = Environment_Hill_1_1_Entity->AddComponent<Collider>();
		Collider* colHill_1_2 = Environment_Hill_1_2_Entity->AddComponent<Collider>();
		Collider* colHill_1_3 = Environment_Hill_1_3_Entity->AddComponent<Collider>();
		Collider* colHill_1_4 = Environment_Hill_1_4_Entity->AddComponent<Collider>();
		Collider* colHill_1_5 = Environment_Hill_1_5_Entity->AddComponent<Collider>();
		Collider* colHill_2_1 = Environment_Hill_2_1_Entity->AddComponent<Collider>();
		Collider* colHill_3_1 = Environment_Hill_3_1_Entity->AddComponent<Collider>();
		Collider* colHill_4_1 = Environment_Hill_4_1_Entity->AddComponent<Collider>();
		Collider* colHill_5_1 = Environment_Hill_5_1_Entity->AddComponent<Collider>();
		Collider* colHill_6_1 = Environment_Hill_6_1_Entity->AddComponent<Collider>();
		Collider* colHill_7_1 = Environment_Hill_7_1_Entity->AddComponent<Collider>();
		Collider* colHill_8_1 = Environment_Hill_8_1_Entity->AddComponent<Collider>();
		Collider* colWoodPlank_1 = Environment_WoodPlank_Entity_1->AddComponent<Collider>();
		Collider* colWoodPlank_2 = Environment_WoodPlank_Entity_2->AddComponent<Collider>();
		Collider* colWoodPlank_3 = Environment_WoodPlank_Entity_3->AddComponent<Collider>();
		Collider* colWoodPlank_4 = Environment_WoodPlank_Entity_4->AddComponent<Collider>();
		Collider* colWoodPlank_5 = Environment_WoodPlank_Entity_5->AddComponent<Collider>();
		Collider* colWoodPlank_6 = Environment_WoodPlank_Entity_6->AddComponent<Collider>();
		Collider* colWoodPlank_7 = Environment_WoodPlank_Entity_7->AddComponent<Collider>();
		Collider* colWoodPlank_8 = Environment_WoodPlank_Entity_8->AddComponent<Collider>();
		Collider* colGrayPlank_1 = Environment_GrayPlank_Entity_1->AddComponent<Collider>();
		Collider* colGrayPlank_2 = Environment_GrayPlank_Entity_2->AddComponent<Collider>();
		Collider* colGrayPlank_3 = Environment_GrayPlank_Entity_3->AddComponent<Collider>();
		Collider* colGrayPlank_4 = Environment_GrayPlank_Entity_4->AddComponent<Collider>();
		Collider* colPipe_Yellow_1 = Environment_Pipe_Yellow_1_Entity->AddComponent<Collider>();
		Collider* colPipe_Orange_1 = Environment_Pipe_Orange_1_Entity->AddComponent<Collider>();

		colHill_1_1->SetSize(Vector2(384.0f, 8.0f));
		colHill_1_2->SetSize(Vector2(320.0f, 8.0f));
		colHill_1_3->SetSize(Vector2(320.0f, 8.0f));
		colHill_1_4->SetSize(Vector2(384.0f, 8.0f));
		colHill_1_5->SetSize(Vector2(266.0f, 8.0f));
		colHill_2_1->SetSize(Vector2(512.0f, 8.0f));
		colHill_3_1->SetSize(Vector2(320.0f, 8.0f));
		colHill_4_1->SetSize(Vector2(384.0f, 8.0f));
		colHill_5_1->SetSize(Vector2(576.0f, 8.0f));
		colHill_6_1->SetSize(Vector2(256.0f, 8.0f));
		colHill_7_1->SetSize(Vector2(448.0f, 8.0f));
		colHill_8_1->SetSize(Vector2(320.0f, 8.0f));
		colWoodPlank_1->SetSize(Vector2(256.0f, 8.0f));
		colWoodPlank_2->SetSize(Vector2(256.0f, 8.0f));
		colWoodPlank_3->SetSize(Vector2(256.0f, 8.0f));
		colWoodPlank_4->SetSize(Vector2(256.0f, 8.0f));
		colWoodPlank_5->SetSize(Vector2(256.0f, 8.0f));
		colWoodPlank_6->SetSize(Vector2(256.0f, 8.0f));
		colWoodPlank_7->SetSize(Vector2(256.0f, 8.0f));
		colWoodPlank_8->SetSize(Vector2(256.0f, 8.0f));
		colGrayPlank_1->SetSize(Vector2(320.0f, 8.0f));
		colGrayPlank_2->SetSize(Vector2(320.0f, 8.0f));
		colGrayPlank_3->SetSize(Vector2(320.0f, 8.0f));
		colGrayPlank_4->SetSize(Vector2(320.0f, 8.0f));
		colPipe_Yellow_1->SetSize(Vector2(128.0f, 8.0f));
		colPipe_Orange_1->SetSize(Vector2(128.0f, 8.0f));

		colHill_1_1->SetOffset(Vector2(0.0f, -120.0f));
		colHill_1_2->SetOffset(Vector2(0.0f, -248.0f));
		colHill_1_3->SetOffset(Vector2(0.0f, -376.0f));
		colHill_1_4->SetOffset(Vector2(0.0f, -472.0f));
		colHill_1_5->SetOffset(Vector2(0.0f, -536.0f));
		colHill_2_1->SetOffset(Vector2(0.0f, -344.0f));
		colHill_3_1->SetOffset(Vector2(0.0f, -440.0f));
		colHill_4_1->SetOffset(Vector2(0.0f, -440.0f));
		colHill_5_1->SetOffset(Vector2(0.0f, -568.0f));
		colHill_6_1->SetOffset(Vector2(0.0f, -536.0f));
		colHill_7_1->SetOffset(Vector2(0.0f, -536.0f));
		colHill_8_1->SetOffset(Vector2(0.0f, -440.0f));
		colWoodPlank_1->SetOffset(Vector2(0.0f, -24.0f));
		colWoodPlank_2->SetOffset(Vector2(0.0f, -24.0f));
		colWoodPlank_3->SetOffset(Vector2(0.0f, -24.0f));
		colWoodPlank_4->SetOffset(Vector2(0.0f, -24.0f));
		colWoodPlank_5->SetOffset(Vector2(0.0f, -24.0f));
		colWoodPlank_6->SetOffset(Vector2(0.0f, -24.0f));
		colWoodPlank_7->SetOffset(Vector2(0.0f, -24.0f));
		colWoodPlank_8->SetOffset(Vector2(0.0f, -24.0f));
		colGrayPlank_1->SetOffset(Vector2(0.0f, -24.0f));
		colGrayPlank_2->SetOffset(Vector2(0.0f, -24.0f));
		colGrayPlank_3->SetOffset(Vector2(0.0f, -24.0f));
		colGrayPlank_4->SetOffset(Vector2(0.0f, -24.0f));
		colPipe_Yellow_1->SetOffset(Vector2(0.0f, -186.0f));
		colPipe_Orange_1->SetOffset(Vector2(0.0f, -56.0f));

		// 원형 이동에 필요한 정보 입력
		Transform* trStoneBlock_1 = Environment_StoneBlock_Entity_1->GetComponent<Transform>();
		Transform* trStoneBlock_2 = Environment_StoneBlock_Entity_2->GetComponent<Transform>();
		Transform* trStoneBlock_3 = Environment_StoneBlock_Entity_3->GetComponent<Transform>();
		Transform* trStoneBlock_4 = Environment_StoneBlock_Entity_4->GetComponent<Transform>();
		Transform* trStoneBlock_5 = Environment_StoneBlock_Entity_5->GetComponent<Transform>();
		Transform* trStoneBlock_6 = Environment_StoneBlock_Entity_6->GetComponent<Transform>();
		Transform* trStoneBlock_7 = Environment_StoneBlock_Entity_7->GetComponent<Transform>();
		Transform* trStoneBlock_8 = Environment_StoneBlock_Entity_8->GetComponent<Transform>();
		// 원 중심 좌표
		Environment_WoodBall_Entity_1_1->SetCenter(Vector2(trStoneBlock_1->GetPosition()));
		Environment_WoodBall_Entity_1_2->SetCenter(Vector2(trStoneBlock_1->GetPosition()));
		Environment_WoodBall_Entity_1_3->SetCenter(Vector2(trStoneBlock_1->GetPosition()));
		Environment_WoodBall_Entity_1_4->SetCenter(Vector2(trStoneBlock_1->GetPosition()));
		Environment_WoodBall_Entity_1_5->SetCenter(Vector2(trStoneBlock_1->GetPosition()));
		Environment_WoodBall_Entity_2_1->SetCenter(Vector2(trStoneBlock_2->GetPosition()));
		Environment_WoodBall_Entity_2_2->SetCenter(Vector2(trStoneBlock_2->GetPosition()));
		Environment_WoodBall_Entity_2_3->SetCenter(Vector2(trStoneBlock_2->GetPosition()));
		Environment_WoodBall_Entity_2_4->SetCenter(Vector2(trStoneBlock_2->GetPosition()));
		Environment_WoodBall_Entity_2_5->SetCenter(Vector2(trStoneBlock_2->GetPosition()));
		Environment_WoodBall_Entity_3_1->SetCenter(Vector2(trStoneBlock_3->GetPosition()));
		Environment_WoodBall_Entity_3_2->SetCenter(Vector2(trStoneBlock_3->GetPosition()));
		Environment_WoodBall_Entity_3_3->SetCenter(Vector2(trStoneBlock_3->GetPosition()));
		Environment_WoodBall_Entity_3_4->SetCenter(Vector2(trStoneBlock_3->GetPosition()));
		Environment_WoodBall_Entity_3_5->SetCenter(Vector2(trStoneBlock_3->GetPosition()));
		Environment_WoodBall_Entity_4_1->SetCenter(Vector2(trStoneBlock_4->GetPosition()));
		Environment_WoodBall_Entity_4_2->SetCenter(Vector2(trStoneBlock_4->GetPosition()));
		Environment_WoodBall_Entity_4_3->SetCenter(Vector2(trStoneBlock_4->GetPosition()));
		Environment_WoodBall_Entity_4_4->SetCenter(Vector2(trStoneBlock_4->GetPosition()));
		Environment_WoodBall_Entity_4_5->SetCenter(Vector2(trStoneBlock_4->GetPosition()));
		Environment_WoodBall_Entity_5_1->SetCenter(Vector2(trStoneBlock_5->GetPosition()));
		Environment_WoodBall_Entity_5_2->SetCenter(Vector2(trStoneBlock_5->GetPosition()));
		Environment_WoodBall_Entity_5_3->SetCenter(Vector2(trStoneBlock_5->GetPosition()));
		Environment_WoodBall_Entity_5_4->SetCenter(Vector2(trStoneBlock_5->GetPosition()));
		Environment_WoodBall_Entity_5_5->SetCenter(Vector2(trStoneBlock_5->GetPosition()));
		Environment_WoodBall_Entity_6_1->SetCenter(Vector2(trStoneBlock_6->GetPosition()));
		Environment_WoodBall_Entity_6_2->SetCenter(Vector2(trStoneBlock_6->GetPosition()));
		Environment_WoodBall_Entity_6_3->SetCenter(Vector2(trStoneBlock_6->GetPosition()));
		Environment_WoodBall_Entity_6_4->SetCenter(Vector2(trStoneBlock_6->GetPosition()));
		Environment_WoodBall_Entity_6_5->SetCenter(Vector2(trStoneBlock_6->GetPosition()));
		Environment_WoodBall_Entity_7_1->SetCenter(Vector2(trStoneBlock_7->GetPosition()));
		Environment_WoodBall_Entity_7_2->SetCenter(Vector2(trStoneBlock_7->GetPosition()));
		Environment_WoodBall_Entity_7_3->SetCenter(Vector2(trStoneBlock_7->GetPosition()));
		Environment_WoodBall_Entity_7_4->SetCenter(Vector2(trStoneBlock_7->GetPosition()));
		Environment_WoodBall_Entity_7_5->SetCenter(Vector2(trStoneBlock_7->GetPosition()));
		Environment_WoodBall_Entity_8_1->SetCenter(Vector2(trStoneBlock_8->GetPosition()));
		Environment_WoodBall_Entity_8_2->SetCenter(Vector2(trStoneBlock_8->GetPosition()));
		Environment_WoodBall_Entity_8_3->SetCenter(Vector2(trStoneBlock_8->GetPosition()));
		Environment_WoodBall_Entity_8_4->SetCenter(Vector2(trStoneBlock_8->GetPosition()));
		Environment_WoodBall_Entity_8_5->SetCenter(Vector2(trStoneBlock_8->GetPosition()));
		Environment_WoodPlank_Entity_1->SetCenter(Vector2(trStoneBlock_1->GetPosition()));
		Environment_WoodPlank_Entity_2->SetCenter(Vector2(trStoneBlock_2->GetPosition()));
		Environment_WoodPlank_Entity_3->SetCenter(Vector2(trStoneBlock_3->GetPosition()));
		Environment_WoodPlank_Entity_4->SetCenter(Vector2(trStoneBlock_4->GetPosition()));
		Environment_WoodPlank_Entity_5->SetCenter(Vector2(trStoneBlock_5->GetPosition()));
		Environment_WoodPlank_Entity_6->SetCenter(Vector2(trStoneBlock_6->GetPosition()));
		Environment_WoodPlank_Entity_7->SetCenter(Vector2(trStoneBlock_7->GetPosition()));
		Environment_WoodPlank_Entity_8->SetCenter(Vector2(trStoneBlock_8->GetPosition()));
		// 반지름 설정
		Environment_WoodBall_Entity_1_1->SetRadius(320.0f);
		Environment_WoodBall_Entity_1_2->SetRadius(256.0f);
		Environment_WoodBall_Entity_1_3->SetRadius(192.0f);
		Environment_WoodBall_Entity_1_4->SetRadius(128.0f);
		Environment_WoodBall_Entity_1_5->SetRadius(64.0f);
		Environment_WoodBall_Entity_2_1->SetRadius(320.0f);
		Environment_WoodBall_Entity_2_2->SetRadius(256.0f);
		Environment_WoodBall_Entity_2_3->SetRadius(192.0f);
		Environment_WoodBall_Entity_2_4->SetRadius(128.0f);
		Environment_WoodBall_Entity_2_5->SetRadius(64.0f);
		Environment_WoodBall_Entity_3_1->SetRadius(320.0f);
		Environment_WoodBall_Entity_3_2->SetRadius(256.0f);
		Environment_WoodBall_Entity_3_3->SetRadius(192.0f);
		Environment_WoodBall_Entity_3_4->SetRadius(128.0f);
		Environment_WoodBall_Entity_3_5->SetRadius(64.0f);
		Environment_WoodBall_Entity_4_1->SetRadius(320.0f);
		Environment_WoodBall_Entity_4_2->SetRadius(256.0f);
		Environment_WoodBall_Entity_4_3->SetRadius(192.0f);
		Environment_WoodBall_Entity_4_4->SetRadius(128.0f);
		Environment_WoodBall_Entity_4_5->SetRadius(64.0f);
		Environment_WoodBall_Entity_5_1->SetRadius(320.0f);
		Environment_WoodBall_Entity_5_2->SetRadius(256.0f);
		Environment_WoodBall_Entity_5_3->SetRadius(192.0f);
		Environment_WoodBall_Entity_5_4->SetRadius(128.0f);
		Environment_WoodBall_Entity_5_5->SetRadius(64.0f);
		Environment_WoodBall_Entity_6_1->SetRadius(320.0f);
		Environment_WoodBall_Entity_6_2->SetRadius(256.0f);
		Environment_WoodBall_Entity_6_3->SetRadius(192.0f);
		Environment_WoodBall_Entity_6_4->SetRadius(128.0f);
		Environment_WoodBall_Entity_6_5->SetRadius(64.0f);
		Environment_WoodBall_Entity_7_1->SetRadius(320.0f);
		Environment_WoodBall_Entity_7_2->SetRadius(256.0f);
		Environment_WoodBall_Entity_7_3->SetRadius(192.0f);
		Environment_WoodBall_Entity_7_4->SetRadius(128.0f);
		Environment_WoodBall_Entity_7_5->SetRadius(64.0f);
		Environment_WoodBall_Entity_8_1->SetRadius(320.0f);
		Environment_WoodBall_Entity_8_2->SetRadius(256.0f);
		Environment_WoodBall_Entity_8_3->SetRadius(192.0f);
		Environment_WoodBall_Entity_8_4->SetRadius(128.0f);
		Environment_WoodBall_Entity_8_5->SetRadius(64.0f);
		#pragma endregion

		#pragma region Floor Layer
		Texture* Floor_1_Image = Resources::Load<Texture>(L"Floor_1"
			, L"..\\Assets\\Image\\Floor\\Stage2\\Floor1.bmp");
		Texture* Floor_2_Image = Resources::Load<Texture>(L"Floor_2"
			, L"..\\Assets\\Image\\Floor\\Stage2\\Floor2.bmp");
		Texture* Stair_1_1_Image = Resources::Load<Texture>(L"Stair_1_1"
			, L"..\\Assets\\Image\\Floor\\Stage2\\Stair1_1.bmp");
		Texture* Stair_1_2_Image = Resources::Load<Texture>(L"Stair_1_2"
			, L"..\\Assets\\Image\\Floor\\Stage2\\Stair1_2.bmp");
		Texture* Stair_1_3_Image = Resources::Load<Texture>(L"Stair_1_3"
			, L"..\\Assets\\Image\\Floor\\Stage2\\Stair1_3.bmp");
		Texture* Stair_1_4_Image = Resources::Load<Texture>(L"Stair_1_4"
			, L"..\\Assets\\Image\\Floor\\Stage2\\Stair1_4.bmp");
		Texture* Stair_2_1_Image = Resources::Load<Texture>(L"Stair_2_1"
			, L"..\\Assets\\Image\\Floor\\Stage2\\Stair2_1.bmp");
		Texture* Stair_2_2_Image = Resources::Load<Texture>(L"Stair_2_2"
			, L"..\\Assets\\Image\\Floor\\Stage2\\Stair2_2.bmp");
		Texture* Stair_2_3_Image = Resources::Load<Texture>(L"Stair_2_3"
			, L"..\\Assets\\Image\\Floor\\Stage2\\Stair2_3.bmp");
		Texture* Stair_2_4_Image = Resources::Load<Texture>(L"Stair_2_4"
			, L"..\\Assets\\Image\\Floor\\Stage2\\Stair2_4.bmp");
		Texture* Stair_2_5_Image = Resources::Load<Texture>(L"Stair_2_5"
			, L"..\\Assets\\Image\\Floor\\Stage2\\Stair2_5.bmp");

		Floor* Floor_1_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Floor_2_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stair_1_1_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stair_1_2_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stair_1_3_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stair_1_4_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stair_2_1_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stair_2_2_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stair_2_3_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stair_2_4_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stair_2_5_Entity = object::Instantiate<Floor>(eLayerType::Floor);

		SpriteRenderer* Floor_1_Renderer = Floor_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Floor_2_Renderer = Floor_2_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair_1_1_Renderer = Stair_1_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair_1_2_Renderer = Stair_1_2_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair_1_3_Renderer = Stair_1_3_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair_1_4_Renderer = Stair_1_4_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair_2_1_Renderer = Stair_2_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair_2_2_Renderer = Stair_2_2_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair_2_3_Renderer = Stair_2_3_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair_2_4_Renderer = Stair_2_4_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair_2_5_Renderer = Stair_2_5_Entity->AddComponent<SpriteRenderer>();

		Floor_1_Renderer->SetImage(Floor_1_Image);
		Floor_2_Renderer->SetImage(Floor_2_Image);
		Stair_1_1_Renderer->SetImage(Stair_1_1_Image);
		Stair_1_2_Renderer->SetImage(Stair_1_2_Image);
		Stair_1_3_Renderer->SetImage(Stair_1_3_Image);
		Stair_1_4_Renderer->SetImage(Stair_1_4_Image);
		Stair_2_1_Renderer->SetImage(Stair_2_1_Image);
		Stair_2_2_Renderer->SetImage(Stair_2_2_Image);
		Stair_2_3_Renderer->SetImage(Stair_2_3_Image);
		Stair_2_4_Renderer->SetImage(Stair_2_4_Image);
		Stair_2_5_Renderer->SetImage(Stair_2_5_Image);

		Floor_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Floor_2_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair_1_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair_1_2_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair_1_3_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair_1_4_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair_2_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair_2_2_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair_2_3_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair_2_4_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair_2_5_Renderer->SetScale(Vector2(4.0f, 4.0f));

		Floor_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(608.0f, 824.0f));
		Floor_2_Entity->GetComponent<Transform>()->SetPosition(Vector2(3682.0f, 824.0f));
		Stair_1_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(9922.0f, 824.0f));
		Stair_1_2_Entity->GetComponent<Transform>()->SetPosition(Vector2(8802.0f, 696.0f));
		Stair_1_3_Entity->GetComponent<Transform>()->SetPosition(Vector2(8738.0f, 600.0f));
		Stair_1_4_Entity->GetComponent<Transform>()->SetPosition(Vector2(11302.0f, 472.0f));
		Stair_2_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(20290.0f, 824.0f));
		Stair_2_2_Entity->GetComponent<Transform>()->SetPosition(Vector2(19170.0f, 696.0f));
		Stair_2_3_Entity->GetComponent<Transform>()->SetPosition(Vector2(19106.0f, 600.0f));
		Stair_2_4_Entity->GetComponent<Transform>()->SetPosition(Vector2(19042.0f, 472.0f));
		Stair_2_5_Entity->GetComponent<Transform>()->SetPosition(Vector2(18946.0f, 376.0f));

		Collider* Floor_1_Collider = Floor_1_Entity->AddComponent<Collider>();
		Collider* Floor_2_Collider = Floor_2_Entity->AddComponent<Collider>();
		Collider* Stair_1_1_Collider = Stair_1_1_Entity->AddComponent<Collider>();
		Collider* Stair_1_2_Collider = Stair_1_2_Entity->AddComponent<Collider>();
		Collider* Stair_1_3_Collider = Stair_1_3_Entity->AddComponent<Collider>();
		Collider* Stair_1_4_Collider = Stair_1_4_Entity->AddComponent<Collider>();
		Collider* Stair_2_1_Collider = Stair_2_1_Entity->AddComponent<Collider>();
		Collider* Stair_2_2_Collider = Stair_2_2_Entity->AddComponent<Collider>();
		Collider* Stair_2_3_Collider = Stair_2_3_Entity->AddComponent<Collider>();
		Collider* Stair_2_4_Collider = Stair_2_4_Entity->AddComponent<Collider>();
		Collider* Stair_2_5_Collider = Stair_2_5_Entity->AddComponent<Collider>();

		Floor_1_Collider->SetSize(Vector2(1216.0f, 192.0f));
		Floor_2_Collider->SetSize(Vector2(640.0f, 192.0f));
		Stair_1_1_Collider->SetSize(Vector2(3008.0f, 192.0f));
		Stair_1_2_Collider->SetSize(Vector2(768.0f, 64.0f));
		Stair_1_3_Collider->SetSize(Vector2(640.0f, 128.0f));
		Stair_1_4_Collider->SetSize(Vector2(256.0f, 512.0f));
		Stair_2_1_Collider->SetSize(Vector2(2816.0f, 192.0f));
		Stair_2_2_Collider->SetSize(Vector2(576.0f, 64.0f));
		Stair_2_3_Collider->SetSize(Vector2(448.0f, 128.0f));
		Stair_2_4_Collider->SetSize(Vector2(320.0f, 128.0f));
		Stair_2_5_Collider->SetSize(Vector2(128.0f, 64.0f));
		#pragma endregion

		#pragma region Foreground Layer
		// Animated Image
		Texture* Foreground_RandomBox_Image = Resources::Load<Texture>(L"RandomBox"
			, L"..\\Assets\\Image\\ForegroundTiles\\RandomBox.bmp");
		Texture* Foreground_SpinBox_Image = Resources::Load<Texture>(L"SpinBox"
			, L"..\\Assets\\Image\\ForegroundTiles\\SpinBox.bmp");
		Texture* Foreground_Coin_Image = Resources::Load<Texture>(L"Coin"
			, L"..\\Assets\\Image\\ForegroundTiles\\Coin.bmp");
		Texture* Foreground_YoshiCoin_Image = Resources::Load<Texture>(L"YoshiCoin"
			, L"..\\Assets\\Image\\ForegroundTiles\\YoshiCoin.bmp");
		Texture* Foreground_Checkpoint_Pole_Image = Resources::Load<Texture>(L"Checkpoint_Pole"
			, L"..\\Assets\\Image\\ForegroundTiles\\Checkpoint_Pole.bmp");
		// Static Image
		Texture* Foreground_UpgradeBox_Image = Resources::Load<Texture>(L"UpgradeBox"
			, L"..\\Assets\\Image\\ForegroundTiles\\UpgradeBox.bmp");
		Texture* Foreground_EmptyBox_Image = Resources::Load<Texture>(L"EmptyBox"
			, L"..\\Assets\\Image\\ForegroundTiles\\EmptyBox.bmp");
		Texture* Foreground_Checkpoint_Flag_Image = Resources::Load<Texture>(L"Checkpoint_Flag"
			, L"..\\Assets\\Image\\ForegroundTiles\\Checkpoint_Flag.bmp");
		Texture* Foreground_Checkpoint_Finish_Pole_Image = Resources::Load<Texture>(L"Checkpoint_Finish_Pole"
			, L"..\\Assets\\Image\\ForegroundTiles\\Checkpoint_Finish_Pole.bmp");
		Texture* Foreground_Checkpoint_Finish_Flag_Image = Resources::Load<Texture>(L"Checkpoint_Finish_Flag"
			, L"..\\Assets\\Image\\ForegroundTiles\\Checkpoint_Finish_Flag.bmp");

		ForegroundFloorBox* Foreground_FloorBox_Entity_1_1 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_1_2 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_1_3 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_1_4 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_1_5 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_1_6 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_1_7 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_1_8 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_1_9 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_1_10 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_1_11 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_2_1 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_2_2 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_2_3 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_2_4 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_2_5 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_2_6 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_2_7 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_3_1 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_3_2 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_3_3 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_3_4 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_3_5 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_3_6 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_3_7 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_3_8 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_3_9 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_3_10 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_3_11 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_4_1 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_4_2 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_4_3 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_4_4 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_4_5 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_4_6 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_4_7 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_4_8 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_4_9 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_1 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_2 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_3 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_4 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_5 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_6 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_7 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_8 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_9 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_10 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_11 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_12 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_13 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_5_14 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_6_1 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_6_2 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_6_3 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_6_4 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_6_5 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_6_6 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_6_7 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_6_8 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_7_1 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_7_2 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_7_3 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_7_4 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_7_5 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_8_1 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_8_2 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_8_3 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_8_4 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_8_5 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_8_6 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_8_7 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_8_8 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_8_9 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_8_10 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_8_11 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_8_12 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_8_13 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_1 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_2 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_3 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_4 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_5 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_6 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_7 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_8 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_9 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_10 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_11 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_12 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_13 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_9_14 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_10_1 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_10_2 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundFloorBox* Foreground_FloorBox_Entity_10_3 = object::Instantiate<ForegroundFloorBox>(eLayerType::Foreground);
		ForegroundSpinBox* Foreground_SpinBox_Entity_1 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundSpinBox* Foreground_SpinBox_Entity_2 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundSpinBox* Foreground_SpinBox_Entity_3 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundSpinBox* Foreground_SpinBox_Entity_4 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundSpinBox* Foreground_SpinBox_Entity_5 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundRandomBox* Foreground_RandomBox_Entity1 = object::Instantiate<ForegroundRandomBox>(eLayerType::Foreground);
		ForegroundRandomBox* Foreground_RandomBox_Entity2 = object::Instantiate<ForegroundRandomBox>(eLayerType::Foreground);
		Foreground_RandomBox_Entity3 = object::Instantiate<ForegroundRandomBox>(eLayerType::Foreground);
		Foreground_UpgradeBox_Entity = object::Instantiate<ForegroundUpgradeBox>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_1_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_1_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_1_3 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_2_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_2_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_2_3 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_3_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_3_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_3_3 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_4_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_4_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_4_3 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_5_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_5_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_6_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_6_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_6_3 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_7_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_7_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_7_3 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_8_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_8_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_9_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_9_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_10_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_10_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_11_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_11_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_12_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_12_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Coin_Entity_12_3 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundYoshiCoin* Foreground_YoshiCoin_Entity_1 = object::Instantiate<ForegroundYoshiCoin>(eLayerType::Foreground);
		ForegroundYoshiCoin* Foreground_YoshiCoin_Entity_2 = object::Instantiate<ForegroundYoshiCoin>(eLayerType::Foreground);
		ForegroundYoshiCoin* Foreground_YoshiCoin_Entity_3 = object::Instantiate<ForegroundYoshiCoin>(eLayerType::Foreground);
		ForegroundYoshiCoin* Foreground_YoshiCoin_Entity_4 = object::Instantiate<ForegroundYoshiCoin>(eLayerType::Foreground);
		ForegroundUpgradeBox* Foreground_Checkpoint_Pole_Entity = object::Instantiate<ForegroundUpgradeBox>(eLayerType::Foreground);
		ForegroundCoin* Foreground_Checkpoint_Flag_Entity = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundUpgradeBox* Foreground_Checkpoint_Finish_Pole_Entity = object::Instantiate<ForegroundUpgradeBox>(eLayerType::Foreground);
		Foreground_Checkpoint_Finish_Flag_Entity = object::Instantiate<ForegroundFinishFlag>(eLayerType::Foreground);

		// Set Type
		Foreground_Checkpoint_Finish_Flag_Entity->SetExitStage(2);

		Transform* trFloorBox_1_1 = Foreground_FloorBox_Entity_1_1->GetComponent<Transform>();
		Transform* trFloorBox_1_2 = Foreground_FloorBox_Entity_1_2->GetComponent<Transform>();
		Transform* trFloorBox_1_3 = Foreground_FloorBox_Entity_1_3->GetComponent<Transform>();
		Transform* trFloorBox_1_4 = Foreground_FloorBox_Entity_1_4->GetComponent<Transform>();
		Transform* trFloorBox_1_5 = Foreground_FloorBox_Entity_1_5->GetComponent<Transform>();
		Transform* trFloorBox_1_6 = Foreground_FloorBox_Entity_1_6->GetComponent<Transform>();
		Transform* trFloorBox_1_7 = Foreground_FloorBox_Entity_1_7->GetComponent<Transform>();
		Transform* trFloorBox_1_8 = Foreground_FloorBox_Entity_1_8->GetComponent<Transform>();
		Transform* trFloorBox_1_9 = Foreground_FloorBox_Entity_1_9->GetComponent<Transform>();
		Transform* trFloorBox_1_10 = Foreground_FloorBox_Entity_1_10->GetComponent<Transform>();
		Transform* trFloorBox_1_11 = Foreground_FloorBox_Entity_1_11->GetComponent<Transform>();
		Transform* trFloorBox_2_1 = Foreground_FloorBox_Entity_2_1->GetComponent<Transform>();
		Transform* trFloorBox_2_2 = Foreground_FloorBox_Entity_2_2->GetComponent<Transform>();
		Transform* trFloorBox_2_3 = Foreground_FloorBox_Entity_2_3->GetComponent<Transform>();
		Transform* trFloorBox_2_4 = Foreground_FloorBox_Entity_2_4->GetComponent<Transform>();
		Transform* trFloorBox_2_5 = Foreground_FloorBox_Entity_2_5->GetComponent<Transform>();
		Transform* trFloorBox_2_6 = Foreground_FloorBox_Entity_2_6->GetComponent<Transform>();
		Transform* trFloorBox_2_7 = Foreground_FloorBox_Entity_2_7->GetComponent<Transform>();
		Transform* trFloorBox_3_1 = Foreground_FloorBox_Entity_3_1->GetComponent<Transform>();
		Transform* trFloorBox_3_2 = Foreground_FloorBox_Entity_3_2->GetComponent<Transform>();
		Transform* trFloorBox_3_3 = Foreground_FloorBox_Entity_3_3->GetComponent<Transform>();
		Transform* trFloorBox_3_4 = Foreground_FloorBox_Entity_3_4->GetComponent<Transform>();
		Transform* trFloorBox_3_5 = Foreground_FloorBox_Entity_3_5->GetComponent<Transform>();
		Transform* trFloorBox_3_6 = Foreground_FloorBox_Entity_3_6->GetComponent<Transform>();
		Transform* trFloorBox_3_7 = Foreground_FloorBox_Entity_3_7->GetComponent<Transform>();
		Transform* trFloorBox_3_8 = Foreground_FloorBox_Entity_3_8->GetComponent<Transform>();
		Transform* trFloorBox_3_9 = Foreground_FloorBox_Entity_3_9->GetComponent<Transform>();
		Transform* trFloorBox_3_10 = Foreground_FloorBox_Entity_3_10->GetComponent<Transform>();
		Transform* trFloorBox_3_11 = Foreground_FloorBox_Entity_3_11->GetComponent<Transform>();
		Transform* trFloorBox_4_1 = Foreground_FloorBox_Entity_4_1->GetComponent<Transform>();
		Transform* trFloorBox_4_2 = Foreground_FloorBox_Entity_4_2->GetComponent<Transform>();
		Transform* trFloorBox_4_3 = Foreground_FloorBox_Entity_4_3->GetComponent<Transform>();
		Transform* trFloorBox_4_4 = Foreground_FloorBox_Entity_4_4->GetComponent<Transform>();
		Transform* trFloorBox_4_5 = Foreground_FloorBox_Entity_4_5->GetComponent<Transform>();
		Transform* trFloorBox_4_6 = Foreground_FloorBox_Entity_4_6->GetComponent<Transform>();
		Transform* trFloorBox_4_7 = Foreground_FloorBox_Entity_4_7->GetComponent<Transform>();
		Transform* trFloorBox_4_8 = Foreground_FloorBox_Entity_4_8->GetComponent<Transform>();
		Transform* trFloorBox_4_9 = Foreground_FloorBox_Entity_4_9->GetComponent<Transform>();
		Transform* trFloorBox_5_1 = Foreground_FloorBox_Entity_5_1->GetComponent<Transform>();
		Transform* trFloorBox_5_2 = Foreground_FloorBox_Entity_5_2->GetComponent<Transform>();
		Transform* trFloorBox_5_3 = Foreground_FloorBox_Entity_5_3->GetComponent<Transform>();
		Transform* trFloorBox_5_4 = Foreground_FloorBox_Entity_5_4->GetComponent<Transform>();
		Transform* trFloorBox_5_5 = Foreground_FloorBox_Entity_5_5->GetComponent<Transform>();
		Transform* trFloorBox_5_6 = Foreground_FloorBox_Entity_5_6->GetComponent<Transform>();
		Transform* trFloorBox_5_7 = Foreground_FloorBox_Entity_5_7->GetComponent<Transform>();
		Transform* trFloorBox_5_8 = Foreground_FloorBox_Entity_5_8->GetComponent<Transform>();
		Transform* trFloorBox_5_9 = Foreground_FloorBox_Entity_5_9->GetComponent<Transform>();
		Transform* trFloorBox_5_10 = Foreground_FloorBox_Entity_5_10->GetComponent<Transform>();
		Transform* trFloorBox_5_11 = Foreground_FloorBox_Entity_5_11->GetComponent<Transform>();
		Transform* trFloorBox_5_12 = Foreground_FloorBox_Entity_5_12->GetComponent<Transform>();
		Transform* trFloorBox_5_13 = Foreground_FloorBox_Entity_5_13->GetComponent<Transform>();
		Transform* trFloorBox_5_14 = Foreground_FloorBox_Entity_5_14->GetComponent<Transform>();
		Transform* trFloorBox_6_1 = Foreground_FloorBox_Entity_6_1->GetComponent<Transform>();
		Transform* trFloorBox_6_2 = Foreground_FloorBox_Entity_6_2->GetComponent<Transform>();
		Transform* trFloorBox_6_3 = Foreground_FloorBox_Entity_6_3->GetComponent<Transform>();
		Transform* trFloorBox_6_4 = Foreground_FloorBox_Entity_6_4->GetComponent<Transform>();
		Transform* trFloorBox_6_5 = Foreground_FloorBox_Entity_6_5->GetComponent<Transform>();
		Transform* trFloorBox_6_6 = Foreground_FloorBox_Entity_6_6->GetComponent<Transform>();
		Transform* trFloorBox_6_7 = Foreground_FloorBox_Entity_6_7->GetComponent<Transform>();
		Transform* trFloorBox_6_8 = Foreground_FloorBox_Entity_6_8->GetComponent<Transform>();
		Transform* trFloorBox_7_1 = Foreground_FloorBox_Entity_7_1->GetComponent<Transform>();
		Transform* trFloorBox_7_2 = Foreground_FloorBox_Entity_7_2->GetComponent<Transform>();
		Transform* trFloorBox_7_3 = Foreground_FloorBox_Entity_7_3->GetComponent<Transform>();
		Transform* trFloorBox_7_4 = Foreground_FloorBox_Entity_7_4->GetComponent<Transform>();
		Transform* trFloorBox_7_5 = Foreground_FloorBox_Entity_7_5->GetComponent<Transform>();
		Transform* trFloorBox_8_1 = Foreground_FloorBox_Entity_8_1->GetComponent<Transform>();
		Transform* trFloorBox_8_2 = Foreground_FloorBox_Entity_8_2->GetComponent<Transform>();
		Transform* trFloorBox_8_3 = Foreground_FloorBox_Entity_8_3->GetComponent<Transform>();
		Transform* trFloorBox_8_4 = Foreground_FloorBox_Entity_8_4->GetComponent<Transform>();
		Transform* trFloorBox_8_5 = Foreground_FloorBox_Entity_8_5->GetComponent<Transform>();
		Transform* trFloorBox_8_6 = Foreground_FloorBox_Entity_8_6->GetComponent<Transform>();
		Transform* trFloorBox_8_7 = Foreground_FloorBox_Entity_8_7->GetComponent<Transform>();
		Transform* trFloorBox_8_8 = Foreground_FloorBox_Entity_8_8->GetComponent<Transform>();
		Transform* trFloorBox_8_9 = Foreground_FloorBox_Entity_8_9->GetComponent<Transform>();
		Transform* trFloorBox_8_10 = Foreground_FloorBox_Entity_8_10->GetComponent<Transform>();
		Transform* trFloorBox_8_11 = Foreground_FloorBox_Entity_8_11->GetComponent<Transform>();
		Transform* trFloorBox_8_12 = Foreground_FloorBox_Entity_8_12->GetComponent<Transform>();
		Transform* trFloorBox_8_13 = Foreground_FloorBox_Entity_8_13->GetComponent<Transform>();
		Transform* trFloorBox_9_1 = Foreground_FloorBox_Entity_9_1->GetComponent<Transform>();
		Transform* trFloorBox_9_2 = Foreground_FloorBox_Entity_9_2->GetComponent<Transform>();
		Transform* trFloorBox_9_3 = Foreground_FloorBox_Entity_9_3->GetComponent<Transform>();
		Transform* trFloorBox_9_4 = Foreground_FloorBox_Entity_9_4->GetComponent<Transform>();
		Transform* trFloorBox_9_5 = Foreground_FloorBox_Entity_9_5->GetComponent<Transform>();
		Transform* trFloorBox_9_6 = Foreground_FloorBox_Entity_9_6->GetComponent<Transform>();
		Transform* trFloorBox_9_7 = Foreground_FloorBox_Entity_9_7->GetComponent<Transform>();
		Transform* trFloorBox_9_8 = Foreground_FloorBox_Entity_9_8->GetComponent<Transform>();
		Transform* trFloorBox_9_9 = Foreground_FloorBox_Entity_9_9->GetComponent<Transform>();
		Transform* trFloorBox_9_10 = Foreground_FloorBox_Entity_9_10->GetComponent<Transform>();
		Transform* trFloorBox_9_11 = Foreground_FloorBox_Entity_9_11->GetComponent<Transform>();
		Transform* trFloorBox_9_12 = Foreground_FloorBox_Entity_9_12->GetComponent<Transform>();
		Transform* trFloorBox_9_13 = Foreground_FloorBox_Entity_9_13->GetComponent<Transform>();
		Transform* trFloorBox_9_14 = Foreground_FloorBox_Entity_9_14->GetComponent<Transform>();
		Transform* trFloorBox_10_1 = Foreground_FloorBox_Entity_10_1->GetComponent<Transform>();
		Transform* trFloorBox_10_2 = Foreground_FloorBox_Entity_10_2->GetComponent<Transform>();
		Transform* trFloorBox_10_3 = Foreground_FloorBox_Entity_10_3->GetComponent<Transform>();
		Transform* trSpinBox_1 = Foreground_SpinBox_Entity_1->GetComponent<Transform>();
		Transform* trSpinBox_2 = Foreground_SpinBox_Entity_2->GetComponent<Transform>();
		Transform* trSpinBox_3 = Foreground_SpinBox_Entity_3->GetComponent<Transform>();
		Transform* trSpinBox_4 = Foreground_SpinBox_Entity_4->GetComponent<Transform>();
		Transform* trSpinBox_5 = Foreground_SpinBox_Entity_5->GetComponent<Transform>();
		Transform* trRandomBox_1 = Foreground_RandomBox_Entity1->GetComponent<Transform>();
		Transform* trRandomBox_2 = Foreground_RandomBox_Entity2->GetComponent<Transform>();
		Transform* trRandomBox_3 = Foreground_RandomBox_Entity3->GetComponent<Transform>();
		Transform* trUpgradeBox = Foreground_UpgradeBox_Entity->GetComponent<Transform>();
		Transform* trCoin_1_1 = Foreground_Coin_Entity_1_1->GetComponent<Transform>();
		Transform* trCoin_1_2 = Foreground_Coin_Entity_1_2->GetComponent<Transform>();
		Transform* trCoin_1_3 = Foreground_Coin_Entity_1_3->GetComponent<Transform>();
		Transform* trCoin_2_1 = Foreground_Coin_Entity_2_1->GetComponent<Transform>();
		Transform* trCoin_2_2 = Foreground_Coin_Entity_2_2->GetComponent<Transform>();
		Transform* trCoin_2_3 = Foreground_Coin_Entity_2_3->GetComponent<Transform>();
		Transform* trCoin_3_1 = Foreground_Coin_Entity_3_1->GetComponent<Transform>();
		Transform* trCoin_3_2 = Foreground_Coin_Entity_3_2->GetComponent<Transform>();
		Transform* trCoin_3_3 = Foreground_Coin_Entity_3_3->GetComponent<Transform>();
		Transform* trCoin_4_1 = Foreground_Coin_Entity_4_1->GetComponent<Transform>();
		Transform* trCoin_4_2 = Foreground_Coin_Entity_4_2->GetComponent<Transform>();
		Transform* trCoin_4_3 = Foreground_Coin_Entity_4_3->GetComponent<Transform>();
		Transform* trCoin_5_1 = Foreground_Coin_Entity_5_1->GetComponent<Transform>();
		Transform* trCoin_5_2 = Foreground_Coin_Entity_5_2->GetComponent<Transform>();
		Transform* trCoin_6_1 = Foreground_Coin_Entity_6_1->GetComponent<Transform>();
		Transform* trCoin_6_2 = Foreground_Coin_Entity_6_2->GetComponent<Transform>();
		Transform* trCoin_6_3 = Foreground_Coin_Entity_6_3->GetComponent<Transform>();
		Transform* trCoin_7_1 = Foreground_Coin_Entity_7_1->GetComponent<Transform>();
		Transform* trCoin_7_2 = Foreground_Coin_Entity_7_2->GetComponent<Transform>();
		Transform* trCoin_7_3 = Foreground_Coin_Entity_7_3->GetComponent<Transform>();
		Transform* trCoin_8_1 = Foreground_Coin_Entity_8_1->GetComponent<Transform>();
		Transform* trCoin_8_2 = Foreground_Coin_Entity_8_2->GetComponent<Transform>();
		Transform* trCoin_9_1 = Foreground_Coin_Entity_9_1->GetComponent<Transform>();
		Transform* trCoin_9_2 = Foreground_Coin_Entity_9_2->GetComponent<Transform>();
		Transform* trCoin_10_1 = Foreground_Coin_Entity_10_1->GetComponent<Transform>();
		Transform* trCoin_10_2 = Foreground_Coin_Entity_10_2->GetComponent<Transform>();
		Transform* trCoin_11_1 = Foreground_Coin_Entity_11_1->GetComponent<Transform>();
		Transform* trCoin_11_2 = Foreground_Coin_Entity_11_2->GetComponent<Transform>();
		Transform* trCoin_12_1 = Foreground_Coin_Entity_12_1->GetComponent<Transform>();
		Transform* trCoin_12_2 = Foreground_Coin_Entity_12_2->GetComponent<Transform>();
		Transform* trCoin_12_3 = Foreground_Coin_Entity_12_3->GetComponent<Transform>();
		Transform* trYoshiCoin_1 = Foreground_YoshiCoin_Entity_1->GetComponent<Transform>();
		Transform* trYoshiCoin_2 = Foreground_YoshiCoin_Entity_2->GetComponent<Transform>();
		Transform* trYoshiCoin_3 = Foreground_YoshiCoin_Entity_3->GetComponent<Transform>();
		Transform* trYoshiCoin_4 = Foreground_YoshiCoin_Entity_4->GetComponent<Transform>();
		Transform* trCheckpoint_Pole = Foreground_Checkpoint_Pole_Entity->GetComponent<Transform>();
		Transform* trCheckpoint_Flag = Foreground_Checkpoint_Flag_Entity->GetComponent<Transform>();
		Transform* trCheckpoint_Finish_Pole = Foreground_Checkpoint_Finish_Pole_Entity->GetComponent<Transform>();
		Transform* trCheckpoint_Finish_Flag = Foreground_Checkpoint_Finish_Flag_Entity->GetComponent<Transform>();

		trFloorBox_1_1->SetPosition(Vector2(1474.0f, 761.0f));
		trFloorBox_1_2->SetPosition(Vector2(1538.0f, 761.0f));
		trFloorBox_1_3->SetPosition(Vector2(1602.0f, 761.0f));
		trFloorBox_1_4->SetPosition(Vector2(1666.0f, 761.0f));
		trFloorBox_1_5->SetPosition(Vector2(1730.0f, 761.0f));
		trFloorBox_1_6->SetPosition(Vector2(1794.0f, 761.0f));
		trFloorBox_1_7->SetPosition(Vector2(1858.0f, 761.0f));
		trFloorBox_1_8->SetPosition(Vector2(1922.0f, 761.0f));
		trFloorBox_1_9->SetPosition(Vector2(1986.0f, 761.0f));
		trFloorBox_1_10->SetPosition(Vector2(2050.0f, 761.0f));
		trFloorBox_1_11->SetPosition(Vector2(2114.0f, 761.0f));
		trFloorBox_2_1->SetPosition(Vector2(3074.0f, 121.0f));
		trFloorBox_2_2->SetPosition(Vector2(3138.0f, 121.0f));
		trFloorBox_2_3->SetPosition(Vector2(3202.0f, 121.0f));
		trFloorBox_2_4->SetPosition(Vector2(3266.0f, 121.0f));
		trFloorBox_2_5->SetPosition(Vector2(3330.0f, 121.0f));
		trFloorBox_2_6->SetPosition(Vector2(3394.0f, 121.0f));
		trFloorBox_2_7->SetPosition(Vector2(3458.0f, 121.0f));
		trFloorBox_3_1->SetPosition(Vector2(2690.0f, 761.0f));
		trFloorBox_3_2->SetPosition(Vector2(2754.0f, 761.0f));
		trFloorBox_3_3->SetPosition(Vector2(2818.0f, 761.0f));
		trFloorBox_3_4->SetPosition(Vector2(2882.0f, 761.0f));
		trFloorBox_3_5->SetPosition(Vector2(2946.0f, 761.0f));
		trFloorBox_3_6->SetPosition(Vector2(3010.0f, 761.0f));
		trFloorBox_3_7->SetPosition(Vector2(3074.0f, 761.0f));
		trFloorBox_3_8->SetPosition(Vector2(3138.0f, 761.0f));
		trFloorBox_3_9->SetPosition(Vector2(3202.0f, 761.0f));
		trFloorBox_3_10->SetPosition(Vector2(3266.0f, 761.0f));
		trFloorBox_3_11->SetPosition(Vector2(3330.0f, 761.0f));
		trFloorBox_4_1->SetPosition(Vector2(4162.0f, 761.0f));
		trFloorBox_4_2->SetPosition(Vector2(4226.0f, 761.0f));
		trFloorBox_4_3->SetPosition(Vector2(4290.0f, 761.0f));
		trFloorBox_4_4->SetPosition(Vector2(4354.0f, 761.0f));
		trFloorBox_4_5->SetPosition(Vector2(4418.0f, 761.0f));
		trFloorBox_4_6->SetPosition(Vector2(4482.0f, 761.0f));
		trFloorBox_4_7->SetPosition(Vector2(4546.0f, 761.0f));
		trFloorBox_4_8->SetPosition(Vector2(4610.0f, 761.0f));
		trFloorBox_4_9->SetPosition(Vector2(4674.0f, 761.0f));
		trFloorBox_5_1->SetPosition(Vector2(5442.0f, 377.0f));
		trFloorBox_5_2->SetPosition(Vector2(5506.0f, 377.0f));
		trFloorBox_5_3->SetPosition(Vector2(5570.0f, 377.0f));
		trFloorBox_5_4->SetPosition(Vector2(5634.0f, 377.0f));
		trFloorBox_5_5->SetPosition(Vector2(5698.0f, 377.0f));
		trFloorBox_5_6->SetPosition(Vector2(5762.0f, 377.0f));
		trFloorBox_5_7->SetPosition(Vector2(5826.0f, 377.0f));
		trFloorBox_5_8->SetPosition(Vector2(5890.0f, 377.0f));
		trFloorBox_5_9->SetPosition(Vector2(5954.0f, 377.0f));
		trFloorBox_5_10->SetPosition(Vector2(6018.0f, 377.0f));
		trFloorBox_5_11->SetPosition(Vector2(6082.0f, 377.0f));
		trFloorBox_5_12->SetPosition(Vector2(6146.0f, 377.0f));
		trFloorBox_5_13->SetPosition(Vector2(6210.0f, 377.0f));
		trFloorBox_5_14->SetPosition(Vector2(6274.0f, 377.0f));
		trFloorBox_6_1->SetPosition(Vector2(7170.0f, 761.0f));
		trFloorBox_6_2->SetPosition(Vector2(7234.0f, 761.0f));
		trFloorBox_6_3->SetPosition(Vector2(7298.0f, 761.0f));
		trFloorBox_6_4->SetPosition(Vector2(7362.0f, 761.0f));
		trFloorBox_6_5->SetPosition(Vector2(7426.0f, 761.0f));
		trFloorBox_6_6->SetPosition(Vector2(7490.0f, 761.0f));
		trFloorBox_6_7->SetPosition(Vector2(7554.0f, 761.0f));
		trFloorBox_6_8->SetPosition(Vector2(7618.0f, 761.0f));
		trFloorBox_7_1->SetPosition(Vector2(12930.0f, 569.0f));
		trFloorBox_7_2->SetPosition(Vector2(12994.0f, 569.0f));
		trFloorBox_7_3->SetPosition(Vector2(13058.0f, 569.0f));
		trFloorBox_7_4->SetPosition(Vector2(13122.0f, 569.0f));
		trFloorBox_7_5->SetPosition(Vector2(13186.0f, 569.0f));
		trFloorBox_8_1->SetPosition(Vector2(13186.0f, 377.0f));
		trFloorBox_8_2->SetPosition(Vector2(13250.0f, 377.0f));
		trFloorBox_8_3->SetPosition(Vector2(13314.0f, 377.0f));
		trFloorBox_8_4->SetPosition(Vector2(13378.0f, 377.0f));
		trFloorBox_8_5->SetPosition(Vector2(13442.0f, 377.0f));
		trFloorBox_8_6->SetPosition(Vector2(13506.0f, 377.0f));
		trFloorBox_8_7->SetPosition(Vector2(13570.0f, 377.0f));
		trFloorBox_8_8->SetPosition(Vector2(13634.0f, 377.0f));
		trFloorBox_8_9->SetPosition(Vector2(13698.0f, 377.0f));
		trFloorBox_8_10->SetPosition(Vector2(13762.0f, 377.0f));
		trFloorBox_8_11->SetPosition(Vector2(13826.0f, 377.0f));
		trFloorBox_8_12->SetPosition(Vector2(13890.0f, 377.0f));
		trFloorBox_8_13->SetPosition(Vector2(13954.0f, 377.0f));
		trFloorBox_9_1->SetPosition(Vector2(14018.0f, 185.0f));
		trFloorBox_9_2->SetPosition(Vector2(14082.0f, 185.0f));
		trFloorBox_9_3->SetPosition(Vector2(14146.0f, 185.0f));
		trFloorBox_9_4->SetPosition(Vector2(14210.0f, 185.0f));
		trFloorBox_9_5->SetPosition(Vector2(14274.0f, 185.0f));
		trFloorBox_9_6->SetPosition(Vector2(14338.0f, 185.0f));
		trFloorBox_9_7->SetPosition(Vector2(14402.0f, 185.0f));
		trFloorBox_9_8->SetPosition(Vector2(14466.0f, 185.0f));
		trFloorBox_9_9->SetPosition(Vector2(14530.0f, 185.0f));
		trFloorBox_9_10->SetPosition(Vector2(14594.0f, 185.0f));
		trFloorBox_9_11->SetPosition(Vector2(14658.0f, 185.0f));
		trFloorBox_9_12->SetPosition(Vector2(14722.0f, 185.0f));
		trFloorBox_9_13->SetPosition(Vector2(14786.0f, 185.0f));
		trFloorBox_9_14->SetPosition(Vector2(14850.0f, 185.0f));
		trFloorBox_10_1->SetPosition(Vector2(14914.0f, -7.0f));
		trFloorBox_10_2->SetPosition(Vector2(14978.0f, -7.0f));
		trFloorBox_10_3->SetPosition(Vector2(15042.0f, -7.0f));
		trSpinBox_1->SetPosition(Vector2(10816.0f, 504.0f));
		trSpinBox_2->SetPosition(Vector2(10880.0f, 504.0f));
		trSpinBox_3->SetPosition(Vector2(10944.0f, 504.0f));
		trSpinBox_4->SetPosition(Vector2(11008.0f, 504.0f));
		trSpinBox_5->SetPosition(Vector2(11072.0f, 504.0f));
		trRandomBox_1->SetPosition(Vector2(4866.0f, -135.0f));
		trRandomBox_2->SetPosition(Vector2(4930.0f, -135.0f));
		trRandomBox_3->SetPosition(Vector2(11330.0f, -7.0f));
		trUpgradeBox->SetPosition(Vector2(2400.0f, -7.0f));
		trCoin_1_1->SetPosition(Vector2(1538.0f, 441.0f));
		trCoin_1_2->SetPosition(Vector2(1602.0f, 441.0f));
		trCoin_1_3->SetPosition(Vector2(1666.0f, 441.0f));
		trCoin_2_1->SetPosition(Vector2(1794.0f, -7.0f));
		trCoin_2_2->SetPosition(Vector2(1858.0f, -7.0f));
		trCoin_2_3->SetPosition(Vector2(1922.0f, -7.0f));
		trCoin_3_1->SetPosition(Vector2(4354.0f, -135.0f));
		trCoin_3_2->SetPosition(Vector2(4418.0f, -135.0f));
		trCoin_3_3->SetPosition(Vector2(4482.0f, -135.0f));
		trCoin_4_1->SetPosition(Vector2(7426.0f, -135.0f));
		trCoin_4_2->SetPosition(Vector2(7490.0f, -135.0f));
		trCoin_4_3->SetPosition(Vector2(7554.0f, -135.0f));
		trCoin_5_1->SetPosition(Vector2(8514.0f, 249.0f));
		trCoin_5_2->SetPosition(Vector2(8578.0f, 249.0f));
		trCoin_6_1->SetPosition(Vector2(11650.0f, -263.0f));
		trCoin_6_2->SetPosition(Vector2(11714.0f, -263.0f));
		trCoin_6_3->SetPosition(Vector2(11778.0f, -263.0f));
		trCoin_7_1->SetPosition(Vector2(12482.0f, 377.0f));
		trCoin_7_2->SetPosition(Vector2(12546.0f, 377.0f));
		trCoin_7_3->SetPosition(Vector2(12610.0f, 377.0f));
		trCoin_8_1->SetPosition(Vector2(12738.0f, 249.0f));
		trCoin_8_2->SetPosition(Vector2(12802.0f, 249.0f));
		trCoin_9_1->SetPosition(Vector2(13570.0f, -71.0f));
		trCoin_9_2->SetPosition(Vector2(13634.0f, -71.0f));
		trCoin_10_1->SetPosition(Vector2(13890.0f, -327.0f));
		trCoin_10_2->SetPosition(Vector2(13954.0f, -327.0f));
		trCoin_11_1->SetPosition(Vector2(16770.0f, -199.0f));
		trCoin_11_2->SetPosition(Vector2(16834.0f, -199.0f));
		trCoin_12_1->SetPosition(Vector2(17986.0f, 185.0f));
		trCoin_12_2->SetPosition(Vector2(18050.0f, 185.0f));
		trCoin_12_3->SetPosition(Vector2(18114.0f, 185.0f));
		trYoshiCoin_1->SetPosition(Vector2(3074.0f, -295.0f));
		trYoshiCoin_2->SetPosition(Vector2(10176.0f, 472.0f));
		trYoshiCoin_3->SetPosition(Vector2(14594.0f, -551.0f));
		trYoshiCoin_4->SetPosition(Vector2(18846.0f, 153.0f));
		trCheckpoint_Pole->SetPosition(Vector2(9792.0f, 600.0f));
		trCheckpoint_Flag->SetPosition(Vector2(9792.0f, 680.0f));
		trCheckpoint_Finish_Pole->SetPosition(Vector2(20704.0f, 438.0f));
		trCheckpoint_Finish_Flag->SetPosition(Vector2(20688.0f, 190.0f));

		Animator* atFloorBox_1_1 = Foreground_FloorBox_Entity_1_1->AddComponent<Animator>();
		Animator* atFloorBox_1_2 = Foreground_FloorBox_Entity_1_2->AddComponent<Animator>();
		Animator* atFloorBox_1_3 = Foreground_FloorBox_Entity_1_3->AddComponent<Animator>();
		Animator* atFloorBox_1_4 = Foreground_FloorBox_Entity_1_4->AddComponent<Animator>();
		Animator* atFloorBox_1_5 = Foreground_FloorBox_Entity_1_5->AddComponent<Animator>();
		Animator* atFloorBox_1_6 = Foreground_FloorBox_Entity_1_6->AddComponent<Animator>();
		Animator* atFloorBox_1_7 = Foreground_FloorBox_Entity_1_7->AddComponent<Animator>();
		Animator* atFloorBox_1_8 = Foreground_FloorBox_Entity_1_8->AddComponent<Animator>();
		Animator* atFloorBox_1_9 = Foreground_FloorBox_Entity_1_9->AddComponent<Animator>();
		Animator* atFloorBox_1_10 = Foreground_FloorBox_Entity_1_10->AddComponent<Animator>();
		Animator* atFloorBox_1_11 = Foreground_FloorBox_Entity_1_11->AddComponent<Animator>();
		Animator* atFloorBox_2_1 = Foreground_FloorBox_Entity_2_1->AddComponent<Animator>();
		Animator* atFloorBox_2_2 = Foreground_FloorBox_Entity_2_2->AddComponent<Animator>();
		Animator* atFloorBox_2_3 = Foreground_FloorBox_Entity_2_3->AddComponent<Animator>();
		Animator* atFloorBox_2_4 = Foreground_FloorBox_Entity_2_4->AddComponent<Animator>();
		Animator* atFloorBox_2_5 = Foreground_FloorBox_Entity_2_5->AddComponent<Animator>();
		Animator* atFloorBox_2_6 = Foreground_FloorBox_Entity_2_6->AddComponent<Animator>();
		Animator* atFloorBox_2_7 = Foreground_FloorBox_Entity_2_7->AddComponent<Animator>();
		Animator* atFloorBox_3_1 = Foreground_FloorBox_Entity_3_1->AddComponent<Animator>();
		Animator* atFloorBox_3_2 = Foreground_FloorBox_Entity_3_2->AddComponent<Animator>();
		Animator* atFloorBox_3_3 = Foreground_FloorBox_Entity_3_3->AddComponent<Animator>();
		Animator* atFloorBox_3_4 = Foreground_FloorBox_Entity_3_4->AddComponent<Animator>();
		Animator* atFloorBox_3_5 = Foreground_FloorBox_Entity_3_5->AddComponent<Animator>();
		Animator* atFloorBox_3_6 = Foreground_FloorBox_Entity_3_6->AddComponent<Animator>();
		Animator* atFloorBox_3_7 = Foreground_FloorBox_Entity_3_7->AddComponent<Animator>();
		Animator* atFloorBox_3_8 = Foreground_FloorBox_Entity_3_8->AddComponent<Animator>();
		Animator* atFloorBox_3_9 = Foreground_FloorBox_Entity_3_9->AddComponent<Animator>();
		Animator* atFloorBox_3_10 = Foreground_FloorBox_Entity_3_10->AddComponent<Animator>();
		Animator* atFloorBox_3_11 = Foreground_FloorBox_Entity_3_11->AddComponent<Animator>();
		Animator* atFloorBox_4_1 = Foreground_FloorBox_Entity_4_1->AddComponent<Animator>();
		Animator* atFloorBox_4_2 = Foreground_FloorBox_Entity_4_2->AddComponent<Animator>();
		Animator* atFloorBox_4_3 = Foreground_FloorBox_Entity_4_3->AddComponent<Animator>();
		Animator* atFloorBox_4_4 = Foreground_FloorBox_Entity_4_4->AddComponent<Animator>();
		Animator* atFloorBox_4_5 = Foreground_FloorBox_Entity_4_5->AddComponent<Animator>();
		Animator* atFloorBox_4_6 = Foreground_FloorBox_Entity_4_6->AddComponent<Animator>();
		Animator* atFloorBox_4_7 = Foreground_FloorBox_Entity_4_7->AddComponent<Animator>();
		Animator* atFloorBox_4_8 = Foreground_FloorBox_Entity_4_8->AddComponent<Animator>();
		Animator* atFloorBox_4_9 = Foreground_FloorBox_Entity_4_9->AddComponent<Animator>();
		Animator* atFloorBox_5_1 = Foreground_FloorBox_Entity_5_1->AddComponent<Animator>();
		Animator* atFloorBox_5_2 = Foreground_FloorBox_Entity_5_2->AddComponent<Animator>();
		Animator* atFloorBox_5_3 = Foreground_FloorBox_Entity_5_3->AddComponent<Animator>();
		Animator* atFloorBox_5_4 = Foreground_FloorBox_Entity_5_4->AddComponent<Animator>();
		Animator* atFloorBox_5_5 = Foreground_FloorBox_Entity_5_5->AddComponent<Animator>();
		Animator* atFloorBox_5_6 = Foreground_FloorBox_Entity_5_6->AddComponent<Animator>();
		Animator* atFloorBox_5_7 = Foreground_FloorBox_Entity_5_7->AddComponent<Animator>();
		Animator* atFloorBox_5_8 = Foreground_FloorBox_Entity_5_8->AddComponent<Animator>();
		Animator* atFloorBox_5_9 = Foreground_FloorBox_Entity_5_9->AddComponent<Animator>();
		Animator* atFloorBox_5_10 = Foreground_FloorBox_Entity_5_10->AddComponent<Animator>();
		Animator* atFloorBox_5_11 = Foreground_FloorBox_Entity_5_11->AddComponent<Animator>();
		Animator* atFloorBox_5_12 = Foreground_FloorBox_Entity_5_12->AddComponent<Animator>();
		Animator* atFloorBox_5_13 = Foreground_FloorBox_Entity_5_13->AddComponent<Animator>();
		Animator* atFloorBox_5_14 = Foreground_FloorBox_Entity_5_14->AddComponent<Animator>();
		Animator* atFloorBox_6_1 = Foreground_FloorBox_Entity_6_1->AddComponent<Animator>();
		Animator* atFloorBox_6_2 = Foreground_FloorBox_Entity_6_2->AddComponent<Animator>();
		Animator* atFloorBox_6_3 = Foreground_FloorBox_Entity_6_3->AddComponent<Animator>();
		Animator* atFloorBox_6_4 = Foreground_FloorBox_Entity_6_4->AddComponent<Animator>();
		Animator* atFloorBox_6_5 = Foreground_FloorBox_Entity_6_5->AddComponent<Animator>();
		Animator* atFloorBox_6_6 = Foreground_FloorBox_Entity_6_6->AddComponent<Animator>();
		Animator* atFloorBox_6_7 = Foreground_FloorBox_Entity_6_7->AddComponent<Animator>();
		Animator* atFloorBox_6_8 = Foreground_FloorBox_Entity_6_8->AddComponent<Animator>();
		Animator* atFloorBox_7_1 = Foreground_FloorBox_Entity_7_1->AddComponent<Animator>();
		Animator* atFloorBox_7_2 = Foreground_FloorBox_Entity_7_2->AddComponent<Animator>();
		Animator* atFloorBox_7_3 = Foreground_FloorBox_Entity_7_3->AddComponent<Animator>();
		Animator* atFloorBox_7_4 = Foreground_FloorBox_Entity_7_4->AddComponent<Animator>();
		Animator* atFloorBox_7_5 = Foreground_FloorBox_Entity_7_5->AddComponent<Animator>();
		Animator* atFloorBox_8_1 = Foreground_FloorBox_Entity_8_1->AddComponent<Animator>();
		Animator* atFloorBox_8_2 = Foreground_FloorBox_Entity_8_2->AddComponent<Animator>();
		Animator* atFloorBox_8_3 = Foreground_FloorBox_Entity_8_3->AddComponent<Animator>();
		Animator* atFloorBox_8_4 = Foreground_FloorBox_Entity_8_4->AddComponent<Animator>();
		Animator* atFloorBox_8_5 = Foreground_FloorBox_Entity_8_5->AddComponent<Animator>();
		Animator* atFloorBox_8_6 = Foreground_FloorBox_Entity_8_6->AddComponent<Animator>();
		Animator* atFloorBox_8_7 = Foreground_FloorBox_Entity_8_7->AddComponent<Animator>();
		Animator* atFloorBox_8_8 = Foreground_FloorBox_Entity_8_8->AddComponent<Animator>();
		Animator* atFloorBox_8_9 = Foreground_FloorBox_Entity_8_9->AddComponent<Animator>();
		Animator* atFloorBox_8_10 = Foreground_FloorBox_Entity_8_10->AddComponent<Animator>();
		Animator* atFloorBox_8_11 = Foreground_FloorBox_Entity_8_11->AddComponent<Animator>();
		Animator* atFloorBox_8_12 = Foreground_FloorBox_Entity_8_12->AddComponent<Animator>();
		Animator* atFloorBox_8_13 = Foreground_FloorBox_Entity_8_13->AddComponent<Animator>();
		Animator* atFloorBox_9_1 = Foreground_FloorBox_Entity_9_1->AddComponent<Animator>();
		Animator* atFloorBox_9_2 = Foreground_FloorBox_Entity_9_2->AddComponent<Animator>();
		Animator* atFloorBox_9_3 = Foreground_FloorBox_Entity_9_3->AddComponent<Animator>();
		Animator* atFloorBox_9_4 = Foreground_FloorBox_Entity_9_4->AddComponent<Animator>();
		Animator* atFloorBox_9_5 = Foreground_FloorBox_Entity_9_5->AddComponent<Animator>();
		Animator* atFloorBox_9_6 = Foreground_FloorBox_Entity_9_6->AddComponent<Animator>();
		Animator* atFloorBox_9_7 = Foreground_FloorBox_Entity_9_7->AddComponent<Animator>();
		Animator* atFloorBox_9_8 = Foreground_FloorBox_Entity_9_8->AddComponent<Animator>();
		Animator* atFloorBox_9_9 = Foreground_FloorBox_Entity_9_9->AddComponent<Animator>();
		Animator* atFloorBox_9_10 = Foreground_FloorBox_Entity_9_10->AddComponent<Animator>();
		Animator* atFloorBox_9_11 = Foreground_FloorBox_Entity_9_11->AddComponent<Animator>();
		Animator* atFloorBox_9_12 = Foreground_FloorBox_Entity_9_12->AddComponent<Animator>();
		Animator* atFloorBox_9_13 = Foreground_FloorBox_Entity_9_13->AddComponent<Animator>();
		Animator* atFloorBox_9_14 = Foreground_FloorBox_Entity_9_14->AddComponent<Animator>();
		Animator* atFloorBox_10_1 = Foreground_FloorBox_Entity_10_1->AddComponent<Animator>();
		Animator* atFloorBox_10_2 = Foreground_FloorBox_Entity_10_2->AddComponent<Animator>();
		Animator* atFloorBox_10_3 = Foreground_FloorBox_Entity_10_3->AddComponent<Animator>();
		Animator* atSpinBox_1 = Foreground_SpinBox_Entity_1->AddComponent<Animator>();
		Animator* atSpinBox_2 = Foreground_SpinBox_Entity_2->AddComponent<Animator>();
		Animator* atSpinBox_3 = Foreground_SpinBox_Entity_3->AddComponent<Animator>();
		Animator* atSpinBox_4 = Foreground_SpinBox_Entity_4->AddComponent<Animator>();
		Animator* atSpinBox_5 = Foreground_SpinBox_Entity_5->AddComponent<Animator>();
		Animator* atRandomBox_1 = Foreground_RandomBox_Entity1->AddComponent<Animator>();
		Animator* atRandomBox_2 = Foreground_RandomBox_Entity2->AddComponent<Animator>();
		Animator* atRandomBox_3 = Foreground_RandomBox_Entity3->AddComponent<Animator>();
		Animator* atUpgradeBox = Foreground_UpgradeBox_Entity->AddComponent<Animator>();
		Animator* atCoin_1_1 = Foreground_Coin_Entity_1_1->AddComponent<Animator>();
		Animator* atCoin_1_2 = Foreground_Coin_Entity_1_2->AddComponent<Animator>();
		Animator* atCoin_1_3 = Foreground_Coin_Entity_1_3->AddComponent<Animator>();
		Animator* atCoin_2_1 = Foreground_Coin_Entity_2_1->AddComponent<Animator>();
		Animator* atCoin_2_2 = Foreground_Coin_Entity_2_2->AddComponent<Animator>();
		Animator* atCoin_2_3 = Foreground_Coin_Entity_2_3->AddComponent<Animator>();
		Animator* atCoin_3_1 = Foreground_Coin_Entity_3_1->AddComponent<Animator>();
		Animator* atCoin_3_2 = Foreground_Coin_Entity_3_2->AddComponent<Animator>();
		Animator* atCoin_3_3 = Foreground_Coin_Entity_3_3->AddComponent<Animator>();
		Animator* atCoin_4_1 = Foreground_Coin_Entity_4_1->AddComponent<Animator>();
		Animator* atCoin_4_2 = Foreground_Coin_Entity_4_2->AddComponent<Animator>();
		Animator* atCoin_4_3 = Foreground_Coin_Entity_4_3->AddComponent<Animator>();
		Animator* atCoin_5_1 = Foreground_Coin_Entity_5_1->AddComponent<Animator>();
		Animator* atCoin_5_2 = Foreground_Coin_Entity_5_2->AddComponent<Animator>();
		Animator* atCoin_6_1 = Foreground_Coin_Entity_6_1->AddComponent<Animator>();
		Animator* atCoin_6_2 = Foreground_Coin_Entity_6_2->AddComponent<Animator>();
		Animator* atCoin_6_3 = Foreground_Coin_Entity_6_3->AddComponent<Animator>();
		Animator* atCoin_7_1 = Foreground_Coin_Entity_7_1->AddComponent<Animator>();
		Animator* atCoin_7_2 = Foreground_Coin_Entity_7_2->AddComponent<Animator>();
		Animator* atCoin_7_3 = Foreground_Coin_Entity_7_3->AddComponent<Animator>();
		Animator* atCoin_8_1 = Foreground_Coin_Entity_8_1->AddComponent<Animator>();
		Animator* atCoin_8_2 = Foreground_Coin_Entity_8_2->AddComponent<Animator>();
		Animator* atCoin_9_1 = Foreground_Coin_Entity_9_1->AddComponent<Animator>();
		Animator* atCoin_9_2 = Foreground_Coin_Entity_9_2->AddComponent<Animator>();
		Animator* atCoin_10_1 = Foreground_Coin_Entity_10_1->AddComponent<Animator>();
		Animator* atCoin_10_2 = Foreground_Coin_Entity_10_2->AddComponent<Animator>();
		Animator* atCoin_11_1 = Foreground_Coin_Entity_11_1->AddComponent<Animator>();
		Animator* atCoin_11_2 = Foreground_Coin_Entity_11_2->AddComponent<Animator>();
		Animator* atCoin_12_1 = Foreground_Coin_Entity_12_1->AddComponent<Animator>();
		Animator* atCoin_12_2 = Foreground_Coin_Entity_12_2->AddComponent<Animator>();
		Animator* atCoin_12_3 = Foreground_Coin_Entity_12_3->AddComponent<Animator>();
		Animator* atYoshiCoin_1 = Foreground_YoshiCoin_Entity_1->AddComponent<Animator>();
		Animator* atYoshiCoin_2 = Foreground_YoshiCoin_Entity_2->AddComponent<Animator>();
		Animator* atYoshiCoin_3 = Foreground_YoshiCoin_Entity_3->AddComponent<Animator>();
		Animator* atYoshiCoin_4 = Foreground_YoshiCoin_Entity_4->AddComponent<Animator>();
		Animator* atCheckpoint_Pole = Foreground_Checkpoint_Pole_Entity->AddComponent<Animator>();
		Animator* atCheckpoint_Flag = Foreground_Checkpoint_Flag_Entity->AddComponent<Animator>();
		Animator* atCheckpoint_Finish_Pole = Foreground_Checkpoint_Finish_Pole_Entity->AddComponent<Animator>();
		Animator* atCheckpoint_Finish_Flag = Foreground_Checkpoint_Finish_Flag_Entity->AddComponent<Animator>();

		atFloorBox_1_1->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_1_2->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_1_3->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_1_4->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_1_5->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_1_6->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_1_7->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_1_8->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_1_9->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_1_10->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_1_11->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_2_1->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_2_2->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_2_3->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_2_4->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_2_5->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_2_6->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_2_7->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_3_1->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_3_2->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_3_3->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_3_4->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_3_5->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_3_6->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_3_7->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_3_8->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_3_9->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_3_10->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_3_11->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_4_1->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_4_2->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_4_3->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_4_4->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_4_5->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_4_6->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_4_7->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_4_8->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_4_9->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_1->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_2->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_3->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_4->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_5->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_6->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_7->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_8->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_9->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_10->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_11->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_12->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_13->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_5_14->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_6_1->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_6_2->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_6_3->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_6_4->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_6_5->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_6_6->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_6_7->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_6_8->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_7_1->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_7_2->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_7_3->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_7_4->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_7_5->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_8_1->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_8_2->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_8_3->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_8_4->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_8_5->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_8_6->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_8_7->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_8_8->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_8_9->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_8_10->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_8_11->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_8_12->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_8_13->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_1->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_2->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_3->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_4->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_5->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_6->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_7->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_8->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_9->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_10->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_11->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_12->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_13->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_9_14->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_10_1->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_10_2->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atFloorBox_10_3->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_1->CreateAnimation(L"Foreground_Animation_SpinBox", Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_2->CreateAnimation(L"Foreground_Animation_SpinBox", Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_3->CreateAnimation(L"Foreground_Animation_SpinBox", Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_4->CreateAnimation(L"Foreground_Animation_SpinBox", Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_5->CreateAnimation(L"Foreground_Animation_SpinBox", Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_1->CreateAnimation(L"Foreground_Animation_EmptyBox", Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_2->CreateAnimation(L"Foreground_Animation_EmptyBox", Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_3->CreateAnimation(L"Foreground_Animation_EmptyBox", Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_4->CreateAnimation(L"Foreground_Animation_EmptyBox", Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_5->CreateAnimation(L"Foreground_Animation_EmptyBox", Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRandomBox_1->CreateAnimation(L"Foreground_Animation_RandomBox", Foreground_RandomBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atRandomBox_2->CreateAnimation(L"Foreground_Animation_RandomBox", Foreground_RandomBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atRandomBox_3->CreateAnimation(L"Foreground_Animation_RandomBox", Foreground_RandomBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atRandomBox_1->CreateAnimation(L"Foreground_Animation_EmptyBox", Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRandomBox_2->CreateAnimation(L"Foreground_Animation_EmptyBox", Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRandomBox_3->CreateAnimation(L"Foreground_Animation_EmptyBox", Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atUpgradeBox->CreateAnimation(L"Foreground_Animation_UpgradeBox", Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atUpgradeBox->CreateAnimation(L"Foreground_Animation_EmptyBox", Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_1_1->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_1_2->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_1_3->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_2_1->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_2_2->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_2_3->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_3_1->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_3_2->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_3_3->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_1->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_2->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_3->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_5_1->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_5_2->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_6_1->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_6_2->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_6_3->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_7_1->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_7_2->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_7_3->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_8_1->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_8_2->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_9_1->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_9_2->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_10_1->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_10_2->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_11_1->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_11_2->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_12_1->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_12_2->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_12_3->CreateAnimation(L"Foreground_Animation_Coin", Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atYoshiCoin_1->CreateAnimation(L"Foreground_Animation_YoshiCoin", Foreground_YoshiCoin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 32.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atYoshiCoin_2->CreateAnimation(L"Foreground_Animation_YoshiCoin", Foreground_YoshiCoin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 32.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atYoshiCoin_3->CreateAnimation(L"Foreground_Animation_YoshiCoin", Foreground_YoshiCoin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 32.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atYoshiCoin_4->CreateAnimation(L"Foreground_Animation_YoshiCoin", Foreground_YoshiCoin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 32.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCheckpoint_Pole->CreateAnimation(L"Foreground_Animation_Checkpoint_Pole", Foreground_Checkpoint_Pole_Image, Vector2(0.0f, 0.0f), Vector2(24.0f, 64.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCheckpoint_Flag->CreateAnimation(L"Foreground_Animation_Checkpoint_Flag", Foreground_Checkpoint_Flag_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 1);
		atCheckpoint_Finish_Pole->CreateAnimation(L"Foreground_Animation_Checkpoint_Finish_Pole", Foreground_Checkpoint_Finish_Pole_Image, Vector2(0.0f, 0.0f), Vector2(48.0f, 144.0f), 1);
		atCheckpoint_Finish_Flag->CreateAnimation(L"Foreground_Animation_Checkpoint_Finish_Flag", Foreground_Checkpoint_Finish_Flag_Image, Vector2(0.0f, 0.0f), Vector2(24.0f, 8.0f), 1);

		atFloorBox_1_1->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_1_2->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_1_3->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_1_4->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_1_5->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_1_6->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_1_7->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_1_8->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_1_9->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_1_10->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_1_11->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_2_1->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_2_2->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_2_3->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_2_4->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_2_5->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_2_6->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_2_7->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_3_1->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_3_2->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_3_3->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_3_4->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_3_5->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_3_6->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_3_7->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_3_8->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_3_9->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_3_10->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_3_11->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_4_1->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_4_2->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_4_3->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_4_4->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_4_5->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_4_6->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_4_7->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_4_8->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_4_9->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_1->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_2->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_3->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_4->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_5->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_6->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_7->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_8->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_9->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_10->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_11->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_12->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_13->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_5_14->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_6_1->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_6_2->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_6_3->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_6_4->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_6_5->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_6_6->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_6_7->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_6_8->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_7_1->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_7_2->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_7_3->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_7_4->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_7_5->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_8_1->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_8_2->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_8_3->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_8_4->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_8_5->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_8_6->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_8_7->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_8_8->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_8_9->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_8_10->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_8_11->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_8_12->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_8_13->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_1->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_2->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_3->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_4->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_5->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_6->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_7->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_8->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_9->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_10->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_11->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_12->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_13->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_9_14->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_10_1->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_10_2->SetScale(Vector2(4.0f, 4.0f));
		atFloorBox_10_3->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_1->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_2->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_3->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_4->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_5->SetScale(Vector2(4.0f, 4.0f));
		atRandomBox_1->SetScale(Vector2(4.0f, 4.0f));
		atRandomBox_2->SetScale(Vector2(4.0f, 4.0f));
		atRandomBox_3->SetScale(Vector2(4.0f, 4.0f));
		atUpgradeBox->SetScale(Vector2(4.0f, 4.0f));
		atCoin_1_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_1_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_1_3->SetScale(Vector2(4.0f, 4.0f));
		atCoin_2_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_2_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_2_3->SetScale(Vector2(4.0f, 4.0f));
		atCoin_3_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_3_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_3_3->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_3->SetScale(Vector2(4.0f, 4.0f));
		atCoin_5_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_5_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_6_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_6_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_6_3->SetScale(Vector2(4.0f, 4.0f));
		atCoin_7_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_7_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_7_3->SetScale(Vector2(4.0f, 4.0f));
		atCoin_8_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_8_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_9_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_9_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_10_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_10_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_11_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_11_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_12_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_12_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_12_3->SetScale(Vector2(4.0f, 4.0f));
		atYoshiCoin_1->SetScale(Vector2(4.0f, 4.0f));
		atYoshiCoin_2->SetScale(Vector2(4.0f, 4.0f));
		atYoshiCoin_3->SetScale(Vector2(4.0f, 4.0f));
		atYoshiCoin_4->SetScale(Vector2(4.0f, 4.0f));
		atCheckpoint_Pole->SetScale(Vector2(4.0f, 4.0f));
		atCheckpoint_Flag->SetScale(Vector2(4.0f, 4.0f));
		atCheckpoint_Finish_Pole->SetScale(Vector2(4.0f, 4.0f));
		atCheckpoint_Finish_Flag->SetScale(Vector2(4.0f, 4.0f));

		atFloorBox_1_1->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_1_2->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_1_3->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_1_4->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_1_5->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_1_6->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_1_7->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_1_8->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_1_9->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_1_10->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_1_11->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_2_1->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_2_2->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_2_3->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_2_4->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_2_5->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_2_6->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_2_7->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_3_1->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_3_2->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_3_3->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_3_4->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_3_5->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_3_6->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_3_7->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_3_8->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_3_9->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_3_10->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_3_11->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_4_1->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_4_2->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_4_3->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_4_4->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_4_5->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_4_6->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_4_7->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_4_8->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_4_9->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_1->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_2->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_3->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_4->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_5->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_6->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_7->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_8->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_9->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_10->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_11->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_12->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_13->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_5_14->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_6_1->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_6_2->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_6_3->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_6_4->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_6_5->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_6_6->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_6_7->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_6_8->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_7_1->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_7_2->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_7_3->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_7_4->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_7_5->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_8_1->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_8_2->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_8_3->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_8_4->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_8_5->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_8_6->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_8_7->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_8_8->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_8_9->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_8_10->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_8_11->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_8_12->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_8_13->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_1->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_2->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_3->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_4->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_5->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_6->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_7->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_8->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_9->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_10->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_11->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_12->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_13->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_9_14->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_10_1->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_10_2->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atFloorBox_10_3->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atSpinBox_1->PlayAnimation(L"Foreground_Animation_SpinBox", true);
		atSpinBox_2->PlayAnimation(L"Foreground_Animation_SpinBox", true);
		atSpinBox_3->PlayAnimation(L"Foreground_Animation_SpinBox", true);
		atSpinBox_4->PlayAnimation(L"Foreground_Animation_SpinBox", true);
		atSpinBox_5->PlayAnimation(L"Foreground_Animation_SpinBox", true);
		atRandomBox_1->PlayAnimation(L"Foreground_Animation_RandomBox", true);
		atRandomBox_2->PlayAnimation(L"Foreground_Animation_RandomBox", true);
		atRandomBox_3->PlayAnimation(L"Foreground_Animation_RandomBox", true);
		atUpgradeBox->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atCoin_1_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_1_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_1_3->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_2_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_2_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_2_3->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_3_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_3_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_3_3->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_3->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_5_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_5_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_6_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_6_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_6_3->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_7_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_7_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_7_3->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_8_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_8_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_9_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_9_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_10_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_10_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_11_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_11_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_12_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_12_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_12_3->PlayAnimation(L"Foreground_Animation_Coin", true);
		atYoshiCoin_1->PlayAnimation(L"Foreground_Animation_YoshiCoin", true);
		atYoshiCoin_2->PlayAnimation(L"Foreground_Animation_YoshiCoin", true);
		atYoshiCoin_3->PlayAnimation(L"Foreground_Animation_YoshiCoin", true);
		atYoshiCoin_4->PlayAnimation(L"Foreground_Animation_YoshiCoin", true);
		atCheckpoint_Pole->PlayAnimation(L"Foreground_Animation_Checkpoint_Pole", true);
		atCheckpoint_Flag->PlayAnimation(L"Foreground_Animation_Checkpoint_Flag", true);
		atCheckpoint_Finish_Pole->PlayAnimation(L"Foreground_Animation_Checkpoint_Finish_Pole", true);
		atCheckpoint_Finish_Flag->PlayAnimation(L"Foreground_Animation_Checkpoint_Finish_Flag", true);

		Collider* colFloorBox_1_1 = Foreground_FloorBox_Entity_1_1->AddComponent<Collider>();
		Collider* colFloorBox_1_2 = Foreground_FloorBox_Entity_1_2->AddComponent<Collider>();
		Collider* colFloorBox_1_3 = Foreground_FloorBox_Entity_1_3->AddComponent<Collider>();
		Collider* colFloorBox_1_4 = Foreground_FloorBox_Entity_1_4->AddComponent<Collider>();
		Collider* colFloorBox_1_5 = Foreground_FloorBox_Entity_1_5->AddComponent<Collider>();
		Collider* colFloorBox_1_6 = Foreground_FloorBox_Entity_1_6->AddComponent<Collider>();
		Collider* colFloorBox_1_7 = Foreground_FloorBox_Entity_1_7->AddComponent<Collider>();
		Collider* colFloorBox_1_8 = Foreground_FloorBox_Entity_1_8->AddComponent<Collider>();
		Collider* colFloorBox_1_9 = Foreground_FloorBox_Entity_1_9->AddComponent<Collider>();
		Collider* colFloorBox_1_10 = Foreground_FloorBox_Entity_1_10->AddComponent<Collider>();
		Collider* colFloorBox_1_11 = Foreground_FloorBox_Entity_1_11->AddComponent<Collider>();
		Collider* colFloorBox_2_1 = Foreground_FloorBox_Entity_2_1->AddComponent<Collider>();
		Collider* colFloorBox_2_2 = Foreground_FloorBox_Entity_2_2->AddComponent<Collider>();
		Collider* colFloorBox_2_3 = Foreground_FloorBox_Entity_2_3->AddComponent<Collider>();
		Collider* colFloorBox_2_4 = Foreground_FloorBox_Entity_2_4->AddComponent<Collider>();
		Collider* colFloorBox_2_5 = Foreground_FloorBox_Entity_2_5->AddComponent<Collider>();
		Collider* colFloorBox_2_6 = Foreground_FloorBox_Entity_2_6->AddComponent<Collider>();
		Collider* colFloorBox_2_7 = Foreground_FloorBox_Entity_2_7->AddComponent<Collider>();
		Collider* colFloorBox_3_1 = Foreground_FloorBox_Entity_3_1->AddComponent<Collider>();
		Collider* colFloorBox_3_2 = Foreground_FloorBox_Entity_3_2->AddComponent<Collider>();
		Collider* colFloorBox_3_3 = Foreground_FloorBox_Entity_3_3->AddComponent<Collider>();
		Collider* colFloorBox_3_4 = Foreground_FloorBox_Entity_3_4->AddComponent<Collider>();
		Collider* colFloorBox_3_5 = Foreground_FloorBox_Entity_3_5->AddComponent<Collider>();
		Collider* colFloorBox_3_6 = Foreground_FloorBox_Entity_3_6->AddComponent<Collider>();
		Collider* colFloorBox_3_7 = Foreground_FloorBox_Entity_3_7->AddComponent<Collider>();
		Collider* colFloorBox_3_8 = Foreground_FloorBox_Entity_3_8->AddComponent<Collider>();
		Collider* colFloorBox_3_9 = Foreground_FloorBox_Entity_3_9->AddComponent<Collider>();
		Collider* colFloorBox_3_10 = Foreground_FloorBox_Entity_3_10->AddComponent<Collider>();
		Collider* colFloorBox_3_11 = Foreground_FloorBox_Entity_3_11->AddComponent<Collider>();
		Collider* colFloorBox_4_1 = Foreground_FloorBox_Entity_4_1->AddComponent<Collider>();
		Collider* colFloorBox_4_2 = Foreground_FloorBox_Entity_4_2->AddComponent<Collider>();
		Collider* colFloorBox_4_3 = Foreground_FloorBox_Entity_4_3->AddComponent<Collider>();
		Collider* colFloorBox_4_4 = Foreground_FloorBox_Entity_4_4->AddComponent<Collider>();
		Collider* colFloorBox_4_5 = Foreground_FloorBox_Entity_4_5->AddComponent<Collider>();
		Collider* colFloorBox_4_6 = Foreground_FloorBox_Entity_4_6->AddComponent<Collider>();
		Collider* colFloorBox_4_7 = Foreground_FloorBox_Entity_4_7->AddComponent<Collider>();
		Collider* colFloorBox_4_8 = Foreground_FloorBox_Entity_4_8->AddComponent<Collider>();
		Collider* colFloorBox_4_9 = Foreground_FloorBox_Entity_4_9->AddComponent<Collider>();
		Collider* colFloorBox_5_1 = Foreground_FloorBox_Entity_5_1->AddComponent<Collider>();
		Collider* colFloorBox_5_2 = Foreground_FloorBox_Entity_5_2->AddComponent<Collider>();
		Collider* colFloorBox_5_3 = Foreground_FloorBox_Entity_5_3->AddComponent<Collider>();
		Collider* colFloorBox_5_4 = Foreground_FloorBox_Entity_5_4->AddComponent<Collider>();
		Collider* colFloorBox_5_5 = Foreground_FloorBox_Entity_5_5->AddComponent<Collider>();
		Collider* colFloorBox_5_6 = Foreground_FloorBox_Entity_5_6->AddComponent<Collider>();
		Collider* colFloorBox_5_7 = Foreground_FloorBox_Entity_5_7->AddComponent<Collider>();
		Collider* colFloorBox_5_8 = Foreground_FloorBox_Entity_5_8->AddComponent<Collider>();
		Collider* colFloorBox_5_9 = Foreground_FloorBox_Entity_5_9->AddComponent<Collider>();
		Collider* colFloorBox_5_10 = Foreground_FloorBox_Entity_5_10->AddComponent<Collider>();
		Collider* colFloorBox_5_11 = Foreground_FloorBox_Entity_5_11->AddComponent<Collider>();
		Collider* colFloorBox_5_12 = Foreground_FloorBox_Entity_5_12->AddComponent<Collider>();
		Collider* colFloorBox_5_13 = Foreground_FloorBox_Entity_5_13->AddComponent<Collider>();
		Collider* colFloorBox_5_14 = Foreground_FloorBox_Entity_5_14->AddComponent<Collider>();
		Collider* colFloorBox_6_1 = Foreground_FloorBox_Entity_6_1->AddComponent<Collider>();
		Collider* colFloorBox_6_2 = Foreground_FloorBox_Entity_6_2->AddComponent<Collider>();
		Collider* colFloorBox_6_3 = Foreground_FloorBox_Entity_6_3->AddComponent<Collider>();
		Collider* colFloorBox_6_4 = Foreground_FloorBox_Entity_6_4->AddComponent<Collider>();
		Collider* colFloorBox_6_5 = Foreground_FloorBox_Entity_6_5->AddComponent<Collider>();
		Collider* colFloorBox_6_6 = Foreground_FloorBox_Entity_6_6->AddComponent<Collider>();
		Collider* colFloorBox_6_7 = Foreground_FloorBox_Entity_6_7->AddComponent<Collider>();
		Collider* colFloorBox_6_8 = Foreground_FloorBox_Entity_6_8->AddComponent<Collider>();
		Collider* colFloorBox_7_1 = Foreground_FloorBox_Entity_7_1->AddComponent<Collider>();
		Collider* colFloorBox_7_2 = Foreground_FloorBox_Entity_7_2->AddComponent<Collider>();
		Collider* colFloorBox_7_3 = Foreground_FloorBox_Entity_7_3->AddComponent<Collider>();
		Collider* colFloorBox_7_4 = Foreground_FloorBox_Entity_7_4->AddComponent<Collider>();
		Collider* colFloorBox_7_5 = Foreground_FloorBox_Entity_7_5->AddComponent<Collider>();
		Collider* colFloorBox_8_1 = Foreground_FloorBox_Entity_8_1->AddComponent<Collider>();
		Collider* colFloorBox_8_2 = Foreground_FloorBox_Entity_8_2->AddComponent<Collider>();
		Collider* colFloorBox_8_3 = Foreground_FloorBox_Entity_8_3->AddComponent<Collider>();
		Collider* colFloorBox_8_4 = Foreground_FloorBox_Entity_8_4->AddComponent<Collider>();
		Collider* colFloorBox_8_5 = Foreground_FloorBox_Entity_8_5->AddComponent<Collider>();
		Collider* colFloorBox_8_6 = Foreground_FloorBox_Entity_8_6->AddComponent<Collider>();
		Collider* colFloorBox_8_7 = Foreground_FloorBox_Entity_8_7->AddComponent<Collider>();
		Collider* colFloorBox_8_8 = Foreground_FloorBox_Entity_8_8->AddComponent<Collider>();
		Collider* colFloorBox_8_9 = Foreground_FloorBox_Entity_8_9->AddComponent<Collider>();
		Collider* colFloorBox_8_10 = Foreground_FloorBox_Entity_8_10->AddComponent<Collider>();
		Collider* colFloorBox_8_11 = Foreground_FloorBox_Entity_8_11->AddComponent<Collider>();
		Collider* colFloorBox_8_12 = Foreground_FloorBox_Entity_8_12->AddComponent<Collider>();
		Collider* colFloorBox_8_13 = Foreground_FloorBox_Entity_8_13->AddComponent<Collider>();
		Collider* colFloorBox_9_1 = Foreground_FloorBox_Entity_9_1->AddComponent<Collider>();
		Collider* colFloorBox_9_2 = Foreground_FloorBox_Entity_9_2->AddComponent<Collider>();
		Collider* colFloorBox_9_3 = Foreground_FloorBox_Entity_9_3->AddComponent<Collider>();
		Collider* colFloorBox_9_4 = Foreground_FloorBox_Entity_9_4->AddComponent<Collider>();
		Collider* colFloorBox_9_5 = Foreground_FloorBox_Entity_9_5->AddComponent<Collider>();
		Collider* colFloorBox_9_6 = Foreground_FloorBox_Entity_9_6->AddComponent<Collider>();
		Collider* colFloorBox_9_7 = Foreground_FloorBox_Entity_9_7->AddComponent<Collider>();
		Collider* colFloorBox_9_8 = Foreground_FloorBox_Entity_9_8->AddComponent<Collider>();
		Collider* colFloorBox_9_9 = Foreground_FloorBox_Entity_9_9->AddComponent<Collider>();
		Collider* colFloorBox_9_10 = Foreground_FloorBox_Entity_9_10->AddComponent<Collider>();
		Collider* colFloorBox_9_11 = Foreground_FloorBox_Entity_9_11->AddComponent<Collider>();
		Collider* colFloorBox_9_12 = Foreground_FloorBox_Entity_9_12->AddComponent<Collider>();
		Collider* colFloorBox_9_13 = Foreground_FloorBox_Entity_9_13->AddComponent<Collider>();
		Collider* colFloorBox_9_14 = Foreground_FloorBox_Entity_9_14->AddComponent<Collider>();
		Collider* colFloorBox_10_1 = Foreground_FloorBox_Entity_10_1->AddComponent<Collider>();
		Collider* colFloorBox_10_2 = Foreground_FloorBox_Entity_10_2->AddComponent<Collider>();
		Collider* colFloorBox_10_3 = Foreground_FloorBox_Entity_10_3->AddComponent<Collider>();
		Collider* colSpinBox_1 = Foreground_SpinBox_Entity_1->AddComponent<Collider>();
		Collider* colSpinBox_2 = Foreground_SpinBox_Entity_2->AddComponent<Collider>();
		Collider* colSpinBox_3 = Foreground_SpinBox_Entity_3->AddComponent<Collider>();
		Collider* colSpinBox_4 = Foreground_SpinBox_Entity_4->AddComponent<Collider>();
		Collider* colSpinBox_5 = Foreground_SpinBox_Entity_5->AddComponent<Collider>();
		Collider* colRandomBox_1 = Foreground_RandomBox_Entity1->AddComponent<Collider>();
		Collider* colRandomBox_2 = Foreground_RandomBox_Entity2->AddComponent<Collider>();
		Collider* colRandomBox_3 = Foreground_RandomBox_Entity3->AddComponent<Collider>();
		Collider* colUpgradeBox = Foreground_UpgradeBox_Entity->AddComponent<Collider>();
		Collider* colCoin_1_1 = Foreground_Coin_Entity_1_1->AddComponent<Collider>();
		Collider* colCoin_1_2 = Foreground_Coin_Entity_1_2->AddComponent<Collider>();
		Collider* colCoin_1_3 = Foreground_Coin_Entity_1_3->AddComponent<Collider>();
		Collider* colCoin_2_1 = Foreground_Coin_Entity_2_1->AddComponent<Collider>();
		Collider* colCoin_2_2 = Foreground_Coin_Entity_2_2->AddComponent<Collider>();
		Collider* colCoin_2_3 = Foreground_Coin_Entity_2_3->AddComponent<Collider>();
		Collider* colCoin_3_1 = Foreground_Coin_Entity_3_1->AddComponent<Collider>();
		Collider* colCoin_3_2 = Foreground_Coin_Entity_3_2->AddComponent<Collider>();
		Collider* colCoin_3_3 = Foreground_Coin_Entity_3_3->AddComponent<Collider>();
		Collider* colCoin_4_1 = Foreground_Coin_Entity_4_1->AddComponent<Collider>();
		Collider* colCoin_4_2 = Foreground_Coin_Entity_4_2->AddComponent<Collider>();
		Collider* colCoin_4_3 = Foreground_Coin_Entity_4_3->AddComponent<Collider>();
		Collider* colCoin_5_1 = Foreground_Coin_Entity_5_1->AddComponent<Collider>();
		Collider* colCoin_5_2 = Foreground_Coin_Entity_5_2->AddComponent<Collider>();
		Collider* colCoin_6_1 = Foreground_Coin_Entity_6_1->AddComponent<Collider>();
		Collider* colCoin_6_2 = Foreground_Coin_Entity_6_2->AddComponent<Collider>();
		Collider* colCoin_6_3 = Foreground_Coin_Entity_6_3->AddComponent<Collider>();
		Collider* colCoin_7_1 = Foreground_Coin_Entity_7_1->AddComponent<Collider>();
		Collider* colCoin_7_2 = Foreground_Coin_Entity_7_2->AddComponent<Collider>();
		Collider* colCoin_7_3 = Foreground_Coin_Entity_7_3->AddComponent<Collider>();
		Collider* colCoin_8_1 = Foreground_Coin_Entity_8_1->AddComponent<Collider>();
		Collider* colCoin_8_2 = Foreground_Coin_Entity_8_2->AddComponent<Collider>();
		Collider* colCoin_9_1 = Foreground_Coin_Entity_9_1->AddComponent<Collider>();
		Collider* colCoin_9_2 = Foreground_Coin_Entity_9_2->AddComponent<Collider>();
		Collider* colCoin_10_1 = Foreground_Coin_Entity_10_1->AddComponent<Collider>();
		Collider* colCoin_10_2 = Foreground_Coin_Entity_10_2->AddComponent<Collider>();
		Collider* colCoin_11_1 = Foreground_Coin_Entity_11_1->AddComponent<Collider>();
		Collider* colCoin_11_2 = Foreground_Coin_Entity_11_2->AddComponent<Collider>();
		Collider* colCoin_12_1 = Foreground_Coin_Entity_12_1->AddComponent<Collider>();
		Collider* colCoin_12_2 = Foreground_Coin_Entity_12_2->AddComponent<Collider>();
		Collider* colCoin_12_3 = Foreground_Coin_Entity_12_3->AddComponent<Collider>();
		Collider* colYoshiCoin_1 = Foreground_YoshiCoin_Entity_1->AddComponent<Collider>();
		Collider* colYoshiCoin_2 = Foreground_YoshiCoin_Entity_2->AddComponent<Collider>();
		Collider* colYoshiCoin_3 = Foreground_YoshiCoin_Entity_3->AddComponent<Collider>();
		Collider* colYoshiCoin_4 = Foreground_YoshiCoin_Entity_4->AddComponent<Collider>();
		Collider* colCheckpoint_Flag = Foreground_Checkpoint_Flag_Entity->AddComponent<Collider>();
		Collider* colCheckpoint_Finish_Flag = Foreground_Checkpoint_Finish_Flag_Entity->AddComponent<Collider>();

		colFloorBox_1_1->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_1_2->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_1_3->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_1_4->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_1_5->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_1_6->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_1_7->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_1_8->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_1_9->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_1_10->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_1_11->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_2_1->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_2_2->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_2_3->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_2_4->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_2_5->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_2_6->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_2_7->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_3_1->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_3_2->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_3_3->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_3_4->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_3_5->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_3_6->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_3_7->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_3_8->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_3_9->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_3_10->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_3_11->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_4_1->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_4_2->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_4_3->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_4_4->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_4_5->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_4_6->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_4_7->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_4_8->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_4_9->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_1->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_2->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_3->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_4->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_5->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_6->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_7->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_8->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_9->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_10->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_11->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_12->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_13->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_5_14->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_6_1->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_6_2->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_6_3->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_6_4->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_6_5->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_6_6->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_6_7->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_6_8->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_7_1->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_7_2->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_7_3->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_7_4->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_7_5->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_8_1->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_8_2->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_8_3->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_8_4->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_8_5->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_8_6->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_8_7->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_8_8->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_8_9->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_8_10->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_8_11->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_8_12->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_8_13->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_1->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_2->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_3->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_4->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_5->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_6->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_7->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_8->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_9->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_10->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_11->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_12->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_13->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_9_14->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_10_1->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_10_2->SetSize(Vector2(64.0f, 64.0f));
		colFloorBox_10_3->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_1->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_2->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_3->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_4->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_5->SetSize(Vector2(64.0f, 64.0f));
		colRandomBox_1->SetSize(Vector2(64.0f, 64.0f));
		colRandomBox_2->SetSize(Vector2(64.0f, 64.0f));
		colRandomBox_3->SetSize(Vector2(64.0f, 64.0f));
		colUpgradeBox->SetSize(Vector2(64.0f, 64.0f));
		colCoin_1_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_1_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_1_3->SetSize(Vector2(64.0f, 64.0f));
		colCoin_2_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_2_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_2_3->SetSize(Vector2(64.0f, 64.0f));
		colCoin_3_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_3_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_3_3->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_3->SetSize(Vector2(64.0f, 64.0f));
		colCoin_5_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_5_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_6_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_6_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_6_3->SetSize(Vector2(64.0f, 64.0f));
		colCoin_7_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_7_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_7_3->SetSize(Vector2(64.0f, 64.0f));
		colCoin_8_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_8_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_9_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_9_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_10_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_10_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_11_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_11_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_12_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_12_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_12_3->SetSize(Vector2(64.0f, 64.0f));
		colYoshiCoin_1->SetSize(Vector2(64.0f, 100.0f));
		colYoshiCoin_2->SetSize(Vector2(64.0f, 100.0f));
		colYoshiCoin_3->SetSize(Vector2(64.0f, 100.0f));
		colYoshiCoin_4->SetSize(Vector2(64.0f, 100.0f));
		colCheckpoint_Flag->SetSize(Vector2(32.0f, 32.0f));
		colCheckpoint_Finish_Flag->SetSize(Vector2(96.0f, 32.0f));
		#pragma endregion

		#pragma region Player Layer
		Texture* Mario_Left_Image = Resources::Load<Texture>(L"Direction_Left"
			, L"..\\Assets\\Mario\\Mario_Left.bmp");
		Texture* Mario_Right_Image = Resources::Load<Texture>(L"Direction_Right"
			, L"..\\Assets\\Mario\\Mario_Right.bmp");

		player = object::Instantiate<Player>(eLayerType::Player);

		player->SetPlayerClass(Player::eMarioClass::Super);

		trPlayer = player->GetComponent<Transform>();

		trPlayer->SetPosition(Vector2(500.0f, 600.0f)); // 500,1920

		Animator* atPlayer = player->AddComponent<Animator>();
		// 방향 = 왼쪽
		// <Small Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Small_Idle_Left", Mario_Left_Image, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Run_Left", Mario_Left_Image, Vector2(48.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Jump_Left", Mario_Left_Image, Vector2(192.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Fall_Left", Mario_Left_Image, Vector2(240.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_LookUp_Left", Mario_Left_Image, Vector2(288.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Duck_Left", Mario_Left_Image, Vector2(336.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Kick_Left", Mario_Left_Image, Vector2(384.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Swim_Left", Mario_Left_Image, Vector2(432.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -56.0f), 0.2f);

		// <Super Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Super_Idle_Left", Mario_Left_Image, Vector2(0.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Run_Left", Mario_Left_Image, Vector2(48.0f, 48.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Jump_Left", Mario_Left_Image, Vector2(192.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Fall_Left", Mario_Left_Image, Vector2(240.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_LookUp_Left", Mario_Left_Image, Vector2(288.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Duck_Left", Mario_Left_Image, Vector2(336.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Kick_Left", Mario_Left_Image, Vector2(384.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Swim_Left", Mario_Left_Image, Vector2(432.0f, 48.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);

		// <Fire Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Fire_Idle_Left", Mario_Left_Image, Vector2(0.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Run_Left", Mario_Left_Image, Vector2(48.0f, 96.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Jump_Left", Mario_Left_Image, Vector2(192.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Fall_Left", Mario_Left_Image, Vector2(240.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_LookUp_Left", Mario_Left_Image, Vector2(288.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Duck_Left", Mario_Left_Image, Vector2(336.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Kick_Left", Mario_Left_Image, Vector2(384.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Swim_Left", Mario_Left_Image, Vector2(432.0f, 96.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);

		// 방향 = 오른쪽
		// <Small Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Small_Idle_Right", Mario_Right_Image, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Run_Right", Mario_Right_Image, Vector2(48.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Jump_Right", Mario_Right_Image, Vector2(192.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Fall_Right", Mario_Right_Image, Vector2(240.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_LookUp_Right", Mario_Right_Image, Vector2(288.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Duck_Right", Mario_Right_Image, Vector2(336.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Kick_Right", Mario_Right_Image, Vector2(384.0f, 0.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -56.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Small_Swim_Right", Mario_Right_Image, Vector2(432.0f, 0.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -56.0f), 0.2f);

		// <Super Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Super_Idle_Right", Mario_Right_Image, Vector2(0.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Run_Right", Mario_Right_Image, Vector2(48.0f, 48.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Jump_Right", Mario_Right_Image, Vector2(192.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Fall_Right", Mario_Right_Image, Vector2(240.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_LookUp_Right", Mario_Right_Image, Vector2(288.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Duck_Right", Mario_Right_Image, Vector2(336.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Kick_Right", Mario_Right_Image, Vector2(384.0f, 48.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Super_Swim_Right", Mario_Right_Image, Vector2(432.0f, 48.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);

		// <Fire Mario Animation>
		atPlayer->CreateAnimation(L"Animation_Fire_Idle_Right", Mario_Right_Image, Vector2(0.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Run_Right", Mario_Right_Image, Vector2(48.0f, 96.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Jump_Right", Mario_Right_Image, Vector2(192.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Fall_Right", Mario_Right_Image, Vector2(240.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_LookUp_Right", Mario_Right_Image, Vector2(288.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Duck_Right", Mario_Right_Image, Vector2(336.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Kick_Right", Mario_Right_Image, Vector2(384.0f, 96.0f), Vector2(48.0f, 48.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Swim_Right", Mario_Right_Image, Vector2(432.0f, 96.0f), Vector2(48.0f, 48.0f), 3, Vector2(0.0f, -40.0f), 0.2f);

		atPlayer->SetScale(Vector2(4.0f, 4.0f));

		if (player->GetPlayerClass() == Player::eMarioClass::Small)
		{
			atPlayer->PlayAnimation(L"Animation_Small_Idle_Right", true);
		}
		if (player->GetPlayerClass() == Player::eMarioClass::Super)
		{
			atPlayer->PlayAnimation(L"Animation_Super_Idle_Right", true);
		}
		if (player->GetPlayerClass() == Player::eMarioClass::Fire)
		{
			atPlayer->PlayAnimation(L"Animation_Fire_Idle_Right", true);
		}
		atPlayer->SetAffectedCamera(true);

		colPlayer = player->AddComponent<Collider>();
		player->AddComponent<Rigidbody>();
		#pragma endregion

		#pragma region Enemy Layer
		Texture* Koopa_Red_Left_Image = Resources::Load<Texture>(L"Koopa_Red_Left"
			, L"..\\Assets\\Image\\Enemies\\KoopaTroopa_Red_Left.bmp");
		Texture* Koopa_Red_Right_Image = Resources::Load<Texture>(L"Koopa_Red_Right"
			, L"..\\Assets\\Image\\Enemies\\KoopaTroopa_Red_Right.bmp");
		Texture* Koopa_Red_Hit_Image = Resources::Load<Texture>(L"Koopa_Red_Hit"
			, L"..\\Assets\\Image\\Enemies\\KoopaTroopa_Red_Hit.bmp");
		Texture* Para_Red_Left_Image = Resources::Load<Texture>(L"Para_Red_Left"
			, L"..\\Assets\\Image\\Enemies\\ParaTroopa_Red_Left.bmp");
		Texture* Para_Red_Right_Image = Resources::Load<Texture>(L"Para_Red_Right"
			, L"..\\Assets\\Image\\Enemies\\ParaTroopa_Red_Right.bmp");

		RedKoopa* Monster_RedKoopa_Entity_1 = object::Instantiate<RedKoopa>(eLayerType::Monster);
		RedKoopa* Monster_RedKoopa_Entity_2 = object::Instantiate<RedKoopa>(eLayerType::Monster);
		RedPara* Monster_RedPara_Entity_1 = object::Instantiate<RedPara>(eLayerType::Monster);
		RedPara* Monster_RedPara_Entity_2 = object::Instantiate<RedPara>(eLayerType::Monster);
		RedPara* Monster_RedPara_Entity_3 = object::Instantiate<RedPara>(eLayerType::Monster);
		RedPara* Monster_RedPara_Entity_4 = object::Instantiate<RedPara>(eLayerType::Monster);

		Transform* trRedKoopa_1 = Monster_RedKoopa_Entity_1->GetComponent<Transform>();
		Transform* trRedKoopa_2 = Monster_RedKoopa_Entity_2->GetComponent<Transform>();
		Transform* trRedPara_1 = Monster_RedPara_Entity_1->GetComponent<Transform>();
		Transform* trRedPara_2 = Monster_RedPara_Entity_2->GetComponent<Transform>();
		Transform* trRedPara_3 = Monster_RedPara_Entity_3->GetComponent<Transform>();
		Transform* trRedPara_4 = Monster_RedPara_Entity_4->GetComponent<Transform>();

		trRedKoopa_1->SetPosition(Vector2(6882.0f, -285.0f));
		trRedKoopa_2->SetPosition(Vector2(11072.0f, 420.0f));
		trRedPara_1->SetPosition(Vector2(5122.0f, -359.0f));
		trRedPara_2->SetPosition(Vector2(5634.0f, -231.0f));
		trRedPara_3->SetPosition(Vector2(16088.0f, -423.0f));
		trRedPara_4->SetPosition(Vector2(16088.0f, 89.0f));


		Animator* atRedKoopa_1 = Monster_RedKoopa_Entity_1->AddComponent<Animator>();
		Animator* atRedKoopa_2 = Monster_RedKoopa_Entity_2->AddComponent<Animator>();
		Animator* atRedPara_1 = Monster_RedPara_Entity_1->AddComponent<Animator>();
		Animator* atRedPara_2 = Monster_RedPara_Entity_2->AddComponent<Animator>();
		Animator* atRedPara_3 = Monster_RedPara_Entity_3->AddComponent<Animator>();
		Animator* atRedPara_4 = Monster_RedPara_Entity_4->AddComponent<Animator>();

		// Left
		atRedKoopa_1->CreateAnimation(L"Animation_RedKoopa_Left", Koopa_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 32.0f), 2, Vector2(0.0f, -8.0f), 0.4f);
		atRedKoopa_2->CreateAnimation(L"Animation_RedKoopa_Left", Koopa_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 32.0f), 2, Vector2(0.0f, -8.0f), 0.4f);
		atRedPara_1->CreateAnimation(L"Animation_RedPara_Left", Para_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(22.0f, 28.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedPara_2->CreateAnimation(L"Animation_RedPara_Left", Para_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(22.0f, 28.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedPara_3->CreateAnimation(L"Animation_RedPara_Left", Para_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(22.0f, 28.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedPara_4->CreateAnimation(L"Animation_RedPara_Left", Para_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(22.0f, 28.0f), 2, Vector2(0.0f, 0.0f), 0.4f);

		// Right
		atRedKoopa_1->CreateAnimation(L"Animation_RedKoopa_Right", Koopa_Red_Right_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 32.0f), 2, Vector2(0.0f, -8.0f), 0.4f);
		atRedKoopa_2->CreateAnimation(L"Animation_RedKoopa_Right", Koopa_Red_Right_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 32.0f), 2, Vector2(0.0f, -8.0f), 0.4f);
		atRedPara_1->CreateAnimation(L"Animation_RedPara_Right", Para_Red_Right_Image, Vector2(0.0f, 0.0f), Vector2(22.0f, 28.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedPara_2->CreateAnimation(L"Animation_RedPara_Right", Para_Red_Right_Image, Vector2(0.0f, 0.0f), Vector2(22.0f, 28.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedPara_3->CreateAnimation(L"Animation_RedPara_Right", Para_Red_Right_Image, Vector2(0.0f, 0.0f), Vector2(22.0f, 28.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedPara_4->CreateAnimation(L"Animation_RedPara_Right", Para_Red_Right_Image, Vector2(0.0f, 0.0f), Vector2(22.0f, 28.0f), 2, Vector2(0.0f, 0.0f), 0.4f);

		atRedKoopa_1->CreateAnimation(L"Animation_RedKoopa_Hit", Koopa_Red_Hit_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRedKoopa_2->CreateAnimation(L"Animation_RedKoopa_Hit", Koopa_Red_Hit_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		
		atRedKoopa_1->SetScale(Vector2(4.0f, 4.0f));
		atRedKoopa_2->SetScale(Vector2(4.0f, 4.0f));
		atRedPara_1->SetScale(Vector2(4.0f, 4.0f));
		atRedPara_2->SetScale(Vector2(4.0f, 4.0f));
		atRedPara_3->SetScale(Vector2(4.0f, 4.0f));
		atRedPara_4->SetScale(Vector2(4.0f, 4.0f));

		atRedKoopa_1->PlayAnimation(L"Animation_RedKoopa_Left", true);
		atRedKoopa_2->PlayAnimation(L"Animation_RedKoopa_Left", true);
		atRedPara_1->PlayAnimation(L"Animation_RedPara_Left", true);
		atRedPara_2->PlayAnimation(L"Animation_RedPara_Left", true);
		atRedPara_3->PlayAnimation(L"Animation_RedPara_Left", true);
		atRedPara_4->PlayAnimation(L"Animation_RedPara_Left", true);

		Collider* colRedKoopa_1 = Monster_RedKoopa_Entity_1->AddComponent<Collider>();
		Collider* colRedKoopa_2 = Monster_RedKoopa_Entity_2->AddComponent<Collider>();
		Collider* colRedPara_1 = Monster_RedPara_Entity_1->AddComponent<Collider>();
		Collider* colRedPara_2 = Monster_RedPara_Entity_2->AddComponent<Collider>();
		Collider* colRedPara_3 = Monster_RedPara_Entity_3->AddComponent<Collider>();
		Collider* colRedPara_4 = Monster_RedPara_Entity_4->AddComponent<Collider>();

		colRedKoopa_1->SetSize(Vector2(64.0f, 108.0f));
		colRedKoopa_2->SetSize(Vector2(64.0f, 108.0f));
		colRedPara_1->SetSize(Vector2(64.0f, 112.0f));
		colRedPara_2->SetSize(Vector2(64.0f, 112.0f));
		colRedPara_3->SetSize(Vector2(64.0f, 112.0f));
		colRedPara_4->SetSize(Vector2(64.0f, 112.0f));
		#pragma endregion

		#pragma region Item Layer
		// Static Image
		Texture* Item_SuperMushroom_Image = Resources::Load<Texture>(L"SuperMushroom"
			, L"..\\Assets\\Image\\Items\\SuperMushroom.bmp");

		Item_SuperMushroom_Entity_1 = object::Instantiate<ItemSuperMushroom>(eLayerType::HiddenItem);
		Item_SuperMushroom_Entity_2 = object::Instantiate<ItemSuperMushroom>(eLayerType::HiddenItem);

		trSuperMushroom1 = Item_SuperMushroom_Entity_1->GetComponent<Transform>();
		trSuperMushroom2 = Item_SuperMushroom_Entity_2->GetComponent<Transform>();

		trSuperMushroom1->SetPosition(Vector2(11330.0f, -7.0f));
		trSuperMushroom2->SetPosition(Vector2(2400.0f, -7.0f));

		Animator* atSuperMushroom1 = Item_SuperMushroom_Entity_1->AddComponent<Animator>();
		Animator* atSuperMushroom2 = Item_SuperMushroom_Entity_2->AddComponent<Animator>();

		atSuperMushroom1->CreateAnimation(L"Animation_SuperMushroom", Item_SuperMushroom_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSuperMushroom2->CreateAnimation(L"Animation_SuperMushroom", Item_SuperMushroom_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);

		atSuperMushroom1->SetScale(Vector2(4.0f, 4.0f));
		atSuperMushroom2->SetScale(Vector2(4.0f, 4.0f));

		atSuperMushroom1->PlayAnimation(L"Animation_SuperMushroom", true);
		atSuperMushroom2->PlayAnimation(L"Animation_SuperMushroom", true);

		smShowTime1 = 1.0f;
		smShowTime2 = 1.0f;
		#pragma endregion

		#pragma region UI Layer
		Texture* HUD_Base_Image = Resources::Load<Texture>(L"StageBoss_HUD_Base"
			, L"..\\Assets\\HUD\\HUD_Base.bmp");
		Texture* HUD_NormalNum_Image = Resources::Load<Texture>(L"StageBoss_HUD_NormalNum"
			, L"..\\Assets\\HUD\\NormalNum.bmp");
		Texture* HUD_CountdownNum_Image = Resources::Load<Texture>(L"StageBoss_HUD_Coundown"
			, L"..\\Assets\\HUD\\CountdownNum.bmp");

		HUD_Base_Entity = object::Instantiate<HUD>(eLayerType::UI);
		HUD_Life_Entity = object::Instantiate<HUDLife>(eLayerType::UI);
		HUD_Timer_Entity_1 = object::Instantiate<HUDTimer>(eLayerType::UI);
		HUD_Timer_Entity_2 = object::Instantiate<HUDTimer>(eLayerType::UI);
		HUD_Timer_Entity_3 = object::Instantiate<HUDTimer>(eLayerType::UI);
		HUD_Coins_Entity_1 = object::Instantiate<HUDCoins>(eLayerType::UI);
		HUD_Coins_Entity_2 = object::Instantiate<HUDCoins>(eLayerType::UI);

		HUD_Timer_Entity_1->SetType(1);
		HUD_Timer_Entity_2->SetType(2);
		HUD_Timer_Entity_3->SetType(3);
		HUD_Coins_Entity_1->SetType(1);
		HUD_Coins_Entity_2->SetType(2);

		trHUD_Base = HUD_Base_Entity->GetComponent<Transform>();
		trHUD_Life = HUD_Life_Entity->GetComponent<Transform>();
		trHUD_Timer_1 = HUD_Timer_Entity_1->GetComponent<Transform>();
		trHUD_Timer_2 = HUD_Timer_Entity_2->GetComponent<Transform>();
		trHUD_Timer_3 = HUD_Timer_Entity_3->GetComponent<Transform>();
		trHUD_Coins_1 = HUD_Coins_Entity_1->GetComponent<Transform>();
		trHUD_Coins_2 = HUD_Coins_Entity_2->GetComponent<Transform>();

		atHUD_Base = HUD_Base_Entity->AddComponent<Animator>();
		atHUD_Life = HUD_Life_Entity->AddComponent<Animator>();
		atHUD_Timer_1 = HUD_Timer_Entity_1->AddComponent<Animator>();
		atHUD_Timer_2 = HUD_Timer_Entity_2->AddComponent<Animator>();
		atHUD_Timer_3 = HUD_Timer_Entity_3->AddComponent<Animator>();
		atHUD_Coins_1 = HUD_Coins_Entity_1->AddComponent<Animator>();
		atHUD_Coins_2 = HUD_Coins_Entity_2->AddComponent<Animator>();

		atHUD_Base->CreateAnimation(L"Animation_HUD_Base", HUD_Base_Image, Vector2(0.0f, 0.0f), Vector2(256.0f, 47.0f), 1);
		atHUD_Life->CreateAnimation(L"Animation_HUD_Life", HUD_NormalNum_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 10, Vector2(0.0f, 0.0f), 0.1f);
		atHUD_Timer_1->CreateAnimation(L"Animation_HUD_Timer_1", HUD_CountdownNum_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 10, Vector2(0.0f, 0.0f), 0.1f);
		atHUD_Timer_2->CreateAnimation(L"Animation_HUD_Timer_2", HUD_CountdownNum_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 10, Vector2(0.0f, 0.0f), 0.1f);
		atHUD_Timer_3->CreateAnimation(L"Animation_HUD_Timer_3", HUD_CountdownNum_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 10, Vector2(0.0f, 0.0f), 0.1f);
		atHUD_Coins_1->CreateAnimation(L"Animation_HUD_Coins_1", HUD_NormalNum_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 10, Vector2(0.0f, 0.0f), 0.1f);
		atHUD_Coins_2->CreateAnimation(L"Animation_HUD_Coins_2", HUD_NormalNum_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 10, Vector2(0.0f, 0.0f), 0.1f);

		atHUD_Base->SetScale(Vector2(4.0f, 4.0f));
		atHUD_Life->SetScale(Vector2(4.0f, 4.0f));
		atHUD_Timer_1->SetScale(Vector2(4.0f, 4.0f));
		atHUD_Timer_2->SetScale(Vector2(4.0f, 4.0f));
		atHUD_Timer_3->SetScale(Vector2(4.0f, 4.0f));
		atHUD_Coins_1->SetScale(Vector2(4.0f, 4.0f));
		atHUD_Coins_2->SetScale(Vector2(4.0f, 4.0f));

		atHUD_Base->PlayAnimation(L"Animation_HUD_Base", false);
		atHUD_Life->PlayAnimation(L"Animation_HUD_Life", true);
		atHUD_Timer_1->PlayAnimation(L"Animation_HUD_Timer_1", true);
		atHUD_Timer_2->PlayAnimation(L"Animation_HUD_Timer_2", true);
		atHUD_Timer_3->PlayAnimation(L"Animation_HUD_Timer_3", true);
		atHUD_Coins_1->PlayAnimation(L"Animation_HUD_Coins_1", true);
		atHUD_Coins_2->PlayAnimation(L"Animation_HUD_Coins_2", true);
		#pragma endregion

		#pragma region Collision Manager
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Environment, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Foreground, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::HiddenItem, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Item, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::MonsterCover, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Item, eLayerType::Monster, true);
		#pragma endregion

		#pragma region Sound
		bgSound = Resources::Load<Sound>(L"bgmAthletic", L"..\\Assets\\Sound\\BGM\\WAV\\11.Athletic_Bgm.wav");
		bgSound->Play(true);
		#pragma endregion

		Camera::SetTarget(player);
		Camera::SetOffset(Vector2(0.0f, -218.0f));
	}

	void Stage2::Update()
	{
		Scene::Update();
		Camera::SetTarget(player);

		#pragma region Mario Class
		if (player->GetPlayerClass() == Player::eMarioClass::Small)
		{
			colPlayer->SetSize(Vector2(64.0f, 80.0f)); // Small Mario
		}
		if (player->GetPlayerClass() == Player::eMarioClass::Super)
		{
			colPlayer->SetSize(Vector2(64.0f, 112.0f)); // Super, Fire Mario
		}
		if (player->GetPlayerClass() == Player::eMarioClass::Fire)
		{
			colPlayer->SetSize(Vector2(64.0f, 112.0f)); // Super, Fire Mario
		}
		#pragma endregion

		#pragma region	Mario Upgrade Items
		if (Foreground_RandomBox_Entity3->GetHit())
		{
			Vector2 smPos1 = trSuperMushroom1->GetPosition();
			smPos1.y -= 64 * Time::DeltaTime();
			trSuperMushroom1->SetPosition(smPos1);

			smShowTime1 -= Time::DeltaTime();
			if (smShowTime1 < 0.0f)
			{
				Foreground_RandomBox_Entity3->SetHit(false);
				Collider* colSuperMushroom1 = Item_SuperMushroom_Entity_1->AddComponent<Collider>();
				colSuperMushroom1->SetSize(Vector2(64.0f, 64.0f));
			}
		}
		if (Foreground_UpgradeBox_Entity->GetHit())
		{
			Vector2 smPos2 = trSuperMushroom2->GetPosition();
			smPos2.y -= 64 * Time::DeltaTime();
			trSuperMushroom2->SetPosition(smPos2);

			smShowTime2 -= Time::DeltaTime();
			if (smShowTime2 < 0.0f)
			{
				Foreground_UpgradeBox_Entity->SetHit(false);
				Collider* colSuperMushroom2 = Item_SuperMushroom_Entity_2->AddComponent<Collider>();
				colSuperMushroom2->SetSize(Vector2(64.0f, 64.0f));
			}
		}
		#pragma endregion

		#pragma region HUD Update
		stageTimer -= Time::DeltaTime();

		int hundreds = (int)stageTimer / 100;
		int tens = ((int)stageTimer % 100) / 10;
		int ones = (int)stageTimer % 10;

		atHUD_Timer_1->SetFrame(hundreds);
		atHUD_Timer_2->SetFrame(tens);
		atHUD_Timer_3->SetFrame(ones);

		atHUD_Life->SetFrame(3);
		atHUD_Coins_1->SetFrame(0);
		atHUD_Coins_2->SetFrame(0);
		#pragma endregion

		#pragma region Finish Flag
		if (Foreground_Checkpoint_Finish_Flag_Entity->GetHit())
		{
			bgSound->Stop(true);
			Camera::Reset();
			SceneManager::LoadScene(L"StageWorldMap");
		}
		#pragma endregion

		if (Controller::GetKeyDown(eKeyCode::P))
		{
			bgSound->Stop(true);
			Camera::Reset();
			SceneManager::LoadScene(L"StageWorldMap");
		}
	}

	void Stage2::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}

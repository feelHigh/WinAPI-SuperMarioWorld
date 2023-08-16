#include "Stage1.h"
#include "ntoLayerHeaders.h"
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
	Stage1::Stage1()
	{
	}

	Stage1::~Stage1()
	{
	}

	void Stage1::Initialize()
	{
		#pragma region Background Layer
		Texture* Stage1_Background_Image = Resources::Load<Texture>(L"Stage1_BackGround"
			, L"..\\Assets\\Image\\Background\\Stage1_Background.bmp");

		BackGround* Stage1_BackGround_Entity = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* Stage1_BackGround_Renderer = Stage1_BackGround_Entity->AddComponent<SpriteRenderer>();
		Stage1_BackGround_Renderer->SetImage(Stage1_Background_Image);
		Stage1_BackGround_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stage1_BackGround_Renderer->SetAffectCamera(false);
		Stage1_BackGround_Entity->GetComponent<Transform>()->SetPosition(Vector2(11154.0f, 100.0f));
		#pragma endregion

		#pragma region Environment Layer
		Texture* Stage1_Bush_Big_Image = Resources::Load<Texture>(L"Stage1_Bush_Big"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Bush_Big.bmp");
		Texture* Stage1_Bush_Small_Image = Resources::Load<Texture>(L"Stage1_Bush_Small"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Bush_Small.bmp");
		Texture* Stage1_Brush_Big_Image = Resources::Load<Texture>(L"Stage1_Brush_Big"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Brush_Big.bmp");
		Texture* Stage1_Brush_Small_Image = Resources::Load<Texture>(L"Stage1_Brush_Small"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Brush_Small.bmp");
		Texture* Stage1_Pipe_Yellow_1_Image = Resources::Load<Texture>(L"Stage1_Pipe_Yellow_1"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Pipe_Yellow_1.bmp");
		Texture* Stage1_Pipe_Yellow_2_Image = Resources::Load<Texture>(L"Stage1_Pipe_Yellow_2"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Pipe_Yellow_2.bmp");
		Texture* Stage1_Pipe_Blue_1_Image = Resources::Load<Texture>(L"Stage1_Pipe_Blue_1"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Pipe_Blue_1.bmp");
		Texture* Stage1_Pipe_Blue_2_Image = Resources::Load<Texture>(L"Stage1_Pipe_Blue_2"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Pipe_Blue_2.bmp");
		Texture* Stage1_Pipe_Gray_1_Image = Resources::Load<Texture>(L"Stage1_Pipe_Gray_1"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Pipe_Gray_1.bmp");
		Texture* Stage1_Pipe_Green_1_Image = Resources::Load<Texture>(L"Stage1_Pipe_Green_1"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Pipe_Green_1.bmp");
		Texture* Stage1_Sign_Finish_Image = Resources::Load<Texture>(L"Stage1_Sign_Finish"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Sign_Finish.bmp");
		Texture* Stage1_Hill_1_Image = Resources::Load<Texture>(L"Stage1_Hill_1"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Hill_1.bmp");
		Texture* Stage1_Hill_2_Image = Resources::Load<Texture>(L"Stage1_Hill_2"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Hill_2.bmp");
		Texture* Stage1_Hill_3_Image = Resources::Load<Texture>(L"Stage1_Hill_3"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Hill_3.bmp");
		Texture* Stage1_Hill_4_Image = Resources::Load<Texture>(L"Stage1_Hill_4"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Hill_4.bmp");
		Texture* Stage1_Hill_5_Image = Resources::Load<Texture>(L"Stage1_Hill_5"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Hill_5.bmp");
		Texture* Stage1_Hill_6_Image = Resources::Load<Texture>(L"Stage1_Hill_6"
			, L"..\\Assets\\Image\\Environment\\Stage1\\Hill_6.bmp");

		// Bush
		Environment* Stage1_Environment_Bush_Small_Entity1 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Big_Entity1 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Small_Entity2 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Big_Entity2 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Big_Entity4 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Big_Entity3 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Small_Entity3 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Small_Entity4 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Big_Entity5 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Small_Entity5 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Big_Entity6 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Small_Entity6 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Small_Entity7 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Big_Entity7 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Small_Entity8 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Big_Entity8 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Big_Entity9 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Small_Entity9 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Small_Entity10 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Small_Entity11 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Bush_Big_Entity10 = object::Instantiate<Environment>(eLayerType::Environment);
		// Brush
		Environment* Stage1_Environment_Brush_Small_Entity1 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Brush_Big_Entity1 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Brush_Small_Entity2 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Brush_Big_Entity2 = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Brush_Small_Entity3 = object::Instantiate<Environment>(eLayerType::Environment);
		// Pipe
		Environment* Stage1_Environment_Pipe_Yellow_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Pipe_Yellow_2_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Pipe_Blue_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Pipe_Blue_2_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Pipe_Gray_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Pipe_Green_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		// Sign
		Environment* Stage1_Environment_Sign_Finish_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		// Hill
		Environment* Stage1_Environment_Hill_1_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Hill_2_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Hill_4_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Hill_3_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Hill_5_Entity = object::Instantiate<Environment>(eLayerType::Environment);
		Environment* Stage1_Environment_Hill_6_Entity = object::Instantiate<Environment>(eLayerType::Environment);

		SpriteRenderer* Bush_Small_Renderer1 = Stage1_Environment_Bush_Small_Entity1->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Big_Renderer1 = Stage1_Environment_Bush_Big_Entity1->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Small_Renderer2 = Stage1_Environment_Bush_Small_Entity2->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Big_Renderer2 = Stage1_Environment_Bush_Big_Entity2->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Big_Renderer4 = Stage1_Environment_Bush_Big_Entity4->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Big_Renderer3 = Stage1_Environment_Bush_Big_Entity3->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Small_Renderer3 = Stage1_Environment_Bush_Small_Entity3->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Small_Renderer4 = Stage1_Environment_Bush_Small_Entity4->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Big_Renderer5 = Stage1_Environment_Bush_Big_Entity5->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Small_Renderer5 = Stage1_Environment_Bush_Small_Entity5->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Big_Renderer6 = Stage1_Environment_Bush_Big_Entity6->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Small_Renderer6 = Stage1_Environment_Bush_Small_Entity6->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Small_Renderer7 = Stage1_Environment_Bush_Small_Entity7->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Big_Renderer7 = Stage1_Environment_Bush_Big_Entity7->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Small_Renderer8 = Stage1_Environment_Bush_Small_Entity8->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Big_Renderer8 = Stage1_Environment_Bush_Big_Entity8->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Big_Renderer9 = Stage1_Environment_Bush_Big_Entity9->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Small_Renderer9 = Stage1_Environment_Bush_Small_Entity9->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Small_Renderer10 = Stage1_Environment_Bush_Small_Entity10->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Small_Renderer11 = Stage1_Environment_Bush_Small_Entity11->AddComponent<SpriteRenderer>();
		SpriteRenderer* Bush_Big_Renderer10 = Stage1_Environment_Bush_Big_Entity10->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Small_Renderer1 = Stage1_Environment_Brush_Small_Entity1->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Big_Renderer1 = Stage1_Environment_Brush_Big_Entity1->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Small_Renderer2 = Stage1_Environment_Brush_Small_Entity2->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Big_Renderer2 = Stage1_Environment_Brush_Big_Entity2->AddComponent<SpriteRenderer>();
		SpriteRenderer* Brush_Small_Renderer3 = Stage1_Environment_Brush_Small_Entity3->AddComponent<SpriteRenderer>();
		SpriteRenderer* Pipe_Yellow_1_Renderer = Stage1_Environment_Pipe_Yellow_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Pipe_Yellow_2_Renderer = Stage1_Environment_Pipe_Yellow_2_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Pipe_Blue_1_Renderer = Stage1_Environment_Pipe_Blue_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Pipe_Blue_2_Renderer = Stage1_Environment_Pipe_Blue_2_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Pipe_Gray_1_Renderer = Stage1_Environment_Pipe_Gray_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Pipe_Green_1_Renderer = Stage1_Environment_Pipe_Green_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Sign_Finish_Renderer = Stage1_Environment_Sign_Finish_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_1_Renderer = Stage1_Environment_Hill_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_2_Renderer = Stage1_Environment_Hill_2_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_4_Renderer = Stage1_Environment_Hill_4_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_3_Renderer = Stage1_Environment_Hill_3_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_5_Renderer = Stage1_Environment_Hill_5_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Hill_6_Renderer = Stage1_Environment_Hill_6_Entity->AddComponent<SpriteRenderer>();

		Bush_Small_Renderer1->SetImage(Stage1_Bush_Small_Image);
		Bush_Big_Renderer1->SetImage(Stage1_Bush_Big_Image);
		Bush_Small_Renderer2->SetImage(Stage1_Bush_Small_Image);
		Bush_Big_Renderer2->SetImage(Stage1_Bush_Big_Image);
		Bush_Big_Renderer4->SetImage(Stage1_Bush_Big_Image);
		Bush_Big_Renderer3->SetImage(Stage1_Bush_Big_Image);
		Bush_Small_Renderer3->SetImage(Stage1_Bush_Small_Image);
		Bush_Small_Renderer4->SetImage(Stage1_Bush_Small_Image);
		Bush_Big_Renderer5->SetImage(Stage1_Bush_Big_Image);
		Bush_Small_Renderer5->SetImage(Stage1_Bush_Small_Image);
		Bush_Big_Renderer6->SetImage(Stage1_Bush_Big_Image);
		Bush_Small_Renderer6->SetImage(Stage1_Bush_Small_Image);
		Bush_Small_Renderer7->SetImage(Stage1_Bush_Small_Image);
		Bush_Big_Renderer7->SetImage(Stage1_Bush_Big_Image);
		Bush_Small_Renderer8->SetImage(Stage1_Bush_Small_Image);
		Bush_Big_Renderer8->SetImage(Stage1_Bush_Big_Image);
		Bush_Big_Renderer9->SetImage(Stage1_Bush_Big_Image);
		Bush_Small_Renderer9->SetImage(Stage1_Bush_Small_Image);
		Bush_Small_Renderer10->SetImage(Stage1_Bush_Small_Image);
		Bush_Small_Renderer11->SetImage(Stage1_Bush_Small_Image);
		Bush_Big_Renderer10->SetImage(Stage1_Bush_Big_Image);
		Brush_Small_Renderer1->SetImage(Stage1_Brush_Small_Image);
		Brush_Big_Renderer1->SetImage(Stage1_Brush_Big_Image);
		Brush_Small_Renderer2->SetImage(Stage1_Brush_Small_Image);
		Brush_Big_Renderer2->SetImage(Stage1_Brush_Big_Image);
		Brush_Small_Renderer3->SetImage(Stage1_Brush_Small_Image);
		Pipe_Yellow_1_Renderer->SetImage(Stage1_Pipe_Yellow_1_Image);
		Pipe_Yellow_2_Renderer->SetImage(Stage1_Pipe_Yellow_2_Image);
		Pipe_Blue_1_Renderer->SetImage(Stage1_Pipe_Blue_1_Image);
		Pipe_Blue_2_Renderer->SetImage(Stage1_Pipe_Blue_2_Image);
		Pipe_Gray_1_Renderer->SetImage(Stage1_Pipe_Gray_1_Image);
		Pipe_Green_1_Renderer->SetImage(Stage1_Pipe_Green_1_Image);
		Sign_Finish_Renderer->SetImage(Stage1_Sign_Finish_Image);
		Hill_1_Renderer->SetImage(Stage1_Hill_1_Image);
		Hill_2_Renderer->SetImage(Stage1_Hill_2_Image);
		Hill_4_Renderer->SetImage(Stage1_Hill_4_Image);
		Hill_3_Renderer->SetImage(Stage1_Hill_3_Image);
		Hill_5_Renderer->SetImage(Stage1_Hill_5_Image);
		Hill_6_Renderer->SetImage(Stage1_Hill_6_Image);

		Bush_Small_Renderer1->SetScale(Vector2(4.0f, 4.0f));
		Bush_Big_Renderer1->SetScale(Vector2(4.0f, 4.0f));
		Bush_Small_Renderer2->SetScale(Vector2(4.0f, 4.0f));
		Bush_Big_Renderer2->SetScale(Vector2(4.0f, 4.0f));
		Bush_Big_Renderer4->SetScale(Vector2(4.0f, 4.0f));
		Bush_Big_Renderer3->SetScale(Vector2(4.0f, 4.0f));
		Bush_Small_Renderer3->SetScale(Vector2(4.0f, 4.0f));
		Bush_Small_Renderer4->SetScale(Vector2(4.0f, 4.0f));
		Bush_Big_Renderer5->SetScale(Vector2(4.0f, 4.0f));
		Bush_Small_Renderer5->SetScale(Vector2(4.0f, 4.0f));
		Bush_Big_Renderer6->SetScale(Vector2(4.0f, 4.0f));
		Bush_Small_Renderer6->SetScale(Vector2(4.0f, 4.0f));
		Bush_Small_Renderer7->SetScale(Vector2(4.0f, 4.0f));
		Bush_Big_Renderer7->SetScale(Vector2(4.0f, 4.0f));
		Bush_Small_Renderer8->SetScale(Vector2(4.0f, 4.0f));
		Bush_Big_Renderer8->SetScale(Vector2(4.0f, 4.0f));
		Bush_Big_Renderer9->SetScale(Vector2(4.0f, 4.0f));
		Bush_Small_Renderer9->SetScale(Vector2(4.0f, 4.0f));
		Bush_Small_Renderer10->SetScale(Vector2(4.0f, 4.0f));
		Bush_Small_Renderer11->SetScale(Vector2(4.0f, 4.0f));
		Bush_Big_Renderer10->SetScale(Vector2(4.0f, 4.0f));
		Brush_Small_Renderer1->SetScale(Vector2(4.0f, 4.0f));
		Brush_Big_Renderer1->SetScale(Vector2(4.0f, 4.0f));
		Brush_Small_Renderer2->SetScale(Vector2(4.0f, 4.0f));
		Brush_Big_Renderer2->SetScale(Vector2(4.0f, 4.0f));
		Brush_Small_Renderer3->SetScale(Vector2(4.0f, 4.0f));
		Pipe_Yellow_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Pipe_Yellow_2_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Pipe_Blue_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Pipe_Blue_2_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Pipe_Gray_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Pipe_Green_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Sign_Finish_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_2_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_4_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_3_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_5_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Hill_6_Renderer->SetScale(Vector2(4.0f, 4.0f));

		Stage1_Environment_Bush_Small_Entity1->GetComponent<Transform>()->SetPosition(Vector2(192.0f, 600.0f));
		Stage1_Environment_Bush_Big_Entity1->GetComponent<Transform>()->SetPosition(Vector2(840.0f, 570.0f));
		Stage1_Environment_Bush_Small_Entity2->GetComponent<Transform>()->SetPosition(Vector2(4800.0f, 600.0f));
		Stage1_Environment_Bush_Big_Entity2->GetComponent<Transform>()->SetPosition(Vector2(4460.0f, 570.0f));
		Stage1_Environment_Bush_Big_Entity4->GetComponent<Transform>()->SetPosition(Vector2(6450.0f, 570.0f));
		Stage1_Environment_Bush_Big_Entity3->GetComponent<Transform>()->SetPosition(Vector2(6000.0f, 570.0f));
		Stage1_Environment_Bush_Small_Entity3->GetComponent<Transform>()->SetPosition(Vector2(5720.0f, 600.0f));
		Stage1_Environment_Bush_Small_Entity4->GetComponent<Transform>()->SetPosition(Vector2(7200.0f, 600.0f));
		Stage1_Environment_Bush_Big_Entity5->GetComponent<Transform>()->SetPosition(Vector2(8820.0f, 314.0f));
		Stage1_Environment_Bush_Small_Entity5->GetComponent<Transform>()->SetPosition(Vector2(8540.0f, 344.0f));
		Stage1_Environment_Bush_Big_Entity6->GetComponent<Transform>()->SetPosition(Vector2(9600.0f, 570.0f));
		Stage1_Environment_Bush_Small_Entity6->GetComponent<Transform>()->SetPosition(Vector2(11700.0f, 600.0f));
		Stage1_Environment_Bush_Small_Entity7->GetComponent<Transform>()->SetPosition(Vector2(13360.0f, 600.0f));
		Stage1_Environment_Bush_Big_Entity7->GetComponent<Transform>()->SetPosition(Vector2(15220.0f, 570.0f));
		Stage1_Environment_Bush_Small_Entity8->GetComponent<Transform>()->SetPosition(Vector2(14940.0f, 600.0f));
		Stage1_Environment_Bush_Big_Entity8->GetComponent<Transform>()->SetPosition(Vector2(15936.0f, 570.0f));
		Stage1_Environment_Bush_Big_Entity9->GetComponent<Transform>()->SetPosition(Vector2(16930.0f, 570.0f));
		Stage1_Environment_Bush_Small_Entity9->GetComponent<Transform>()->SetPosition(Vector2(16650.0f, 600.0f));
		Stage1_Environment_Bush_Small_Entity10->GetComponent<Transform>()->SetPosition(Vector2(19042.0f, 600.0f));
		Stage1_Environment_Bush_Small_Entity11->GetComponent<Transform>()->SetPosition(Vector2(20290.0f, 600.0f));
		Stage1_Environment_Bush_Big_Entity10->GetComponent<Transform>()->SetPosition(Vector2(20010.0f, 570.0f));
		Stage1_Environment_Brush_Small_Entity1->GetComponent<Transform>()->SetPosition(Vector2(2940.0f, 696.0f));
		Stage1_Environment_Brush_Big_Entity1->GetComponent<Transform>()->SetPosition(Vector2(5200.0f, 696.0f));
		Stage1_Environment_Brush_Small_Entity2->GetComponent<Transform>()->SetPosition(Vector2(7660.0f, 634.0f));
		Stage1_Environment_Brush_Big_Entity2->GetComponent<Transform>()->SetPosition(Vector2(17880.0f, 696.0f));
		Stage1_Environment_Brush_Small_Entity3->GetComponent<Transform>()->SetPosition(Vector2(18400.0f, 696.0f));
		Stage1_Environment_Pipe_Yellow_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(10760.0f, 634.0f));
		Stage1_Environment_Pipe_Yellow_2_Entity->GetComponent<Transform>()->SetPosition(Vector2(10888.0f, 600.0f));
		Stage1_Environment_Pipe_Blue_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(15572.0f, 666.0f));
		Stage1_Environment_Pipe_Blue_2_Entity->GetComponent<Transform>()->SetPosition(Vector2(16288.0f, 634.0f));
		Stage1_Environment_Pipe_Gray_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(17340.0f, 666.0f));
		Stage1_Environment_Pipe_Green_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(17520.0f, 634.0f));
		Stage1_Environment_Sign_Finish_Entity->GetComponent<Transform>()->SetPosition(Vector2(18180.0f, 666.0f));
		Stage1_Environment_Hill_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(1860.0f, 634.0f));
		Stage1_Environment_Hill_2_Entity->GetComponent<Transform>()->SetPosition(Vector2(3260.0f, 600.0f));
		Stage1_Environment_Hill_4_Entity->GetComponent<Transform>()->SetPosition(Vector2(12300.0f, 554.0f));
		Stage1_Environment_Hill_3_Entity->GetComponent<Transform>()->SetPosition(Vector2(12100.0f, 634.0f));
		Stage1_Environment_Hill_5_Entity->GetComponent<Transform>()->SetPosition(Vector2(12660.0f, 634.0f));
		Stage1_Environment_Hill_6_Entity->GetComponent<Transform>()->SetPosition(Vector2(13920.0f, 580.0f));

		Collider* colHill_1 = Stage1_Environment_Hill_1_Entity->AddComponent<Collider>();
		Collider* colHill_2 = Stage1_Environment_Hill_2_Entity->AddComponent<Collider>();
		Collider* colHill_3 = Stage1_Environment_Hill_3_Entity->AddComponent<Collider>();
		Collider* colHill_4 = Stage1_Environment_Hill_4_Entity->AddComponent<Collider>();
		Collider* colHill_5 = Stage1_Environment_Hill_5_Entity->AddComponent<Collider>();
		Collider* colHill_6 = Stage1_Environment_Hill_6_Entity->AddComponent<Collider>();
		Collider* colPipe_Yellow_1 = Stage1_Environment_Pipe_Yellow_1_Entity->AddComponent<Collider>();
		Collider* colPipe_Yellow_2 = Stage1_Environment_Pipe_Yellow_2_Entity->AddComponent<Collider>();
		Collider* colPipe_Blue_1 = Stage1_Environment_Pipe_Blue_1_Entity->AddComponent<Collider>();
		Collider* colPipe_Blue_2 = Stage1_Environment_Pipe_Blue_2_Entity->AddComponent<Collider>();
		Collider* colPipe_Gray_1 = Stage1_Environment_Pipe_Gray_1_Entity->AddComponent<Collider>();
		Collider* colPipe_Green_1 = Stage1_Environment_Pipe_Green_1_Entity->AddComponent<Collider>();

		colHill_1->SetSize(Vector2(1024.0f, 8.0f));
		colHill_2->SetSize(Vector2(448.0f, 8.0f));
		colHill_3->SetSize(Vector2(320.0f, 8.0f));
		colHill_4->SetSize(Vector2(512.0f, 8.0f));
		colHill_5->SetSize(Vector2(384.0f, 8.0f));
		colHill_6->SetSize(Vector2(640.0f, 8.0f));
		colPipe_Yellow_1->SetSize(Vector2(128.0f, 8.0f));
		colPipe_Yellow_2->SetSize(Vector2(128.0f, 8.0f));
		colPipe_Blue_1->SetSize(Vector2(128.0f, 8.0f));
		colPipe_Blue_2->SetSize(Vector2(128.0f, 8.0f));
		colPipe_Gray_1->SetSize(Vector2(128.0f, 8.0f));
		colPipe_Green_1->SetSize(Vector2(128.0f, 8.0f));
		colHill_1->SetOffset(Vector2(0.0f, -88.0f));
		colHill_2->SetOffset(Vector2(0.0f, -120.0f));
		colHill_3->SetOffset(Vector2(0.0f, -88.0f));
		colHill_4->SetOffset(Vector2(0.0f, -184.0f));
		colHill_5->SetOffset(Vector2(0.0f, -88.0f));
		colHill_6->SetOffset(Vector2(0.0f, -152.0f));
		colPipe_Yellow_1->SetOffset(Vector2(0.0f, -88.0f));
		colPipe_Yellow_2->SetOffset(Vector2(0.0f, -120.0f));
		colPipe_Blue_1->SetOffset(Vector2(0.0f, -60.0f));
		colPipe_Blue_2->SetOffset(Vector2(0.0f, -88.0f));
		colPipe_Gray_1->SetOffset(Vector2(0.0f, -60.0f));
		colPipe_Green_1->SetOffset(Vector2(0.0f, -88.0f));
		#pragma endregion

		#pragma region Floor Layer
		Texture* Stage1_Floor_FrontHalf_Image = Resources::Load<Texture>(L"Stage1_Floor_FrontHalf"
			, L"..\\Assets\\Image\\Floor\\Stage1\\Stage1_FrontHalf.bmp");
		Texture* Stage1_Floor_Stair1_1_Image = Resources::Load<Texture>(L"Stage1_Floor_Stair1_1"
			, L"..\\Assets\\Image\\Floor\\Stage1\\Stage1_Stair1_1_4.bmp");
		Texture* Stage1_Floor_Stair1_2_Image = Resources::Load<Texture>(L"Stage1_Floor_Stair1_2"
			, L"..\\Assets\\Image\\Floor\\Stage1\\Stage1_Stair1_2_4.bmp");
		Texture* Stage1_Floor_Stair1_3_Image = Resources::Load<Texture>(L"Stage1_Floor_Stair1_3"
			, L"..\\Assets\\Image\\Floor\\Stage1\\Stage1_Stair1_3_4.bmp");
		Texture* Stage1_Floor_Stair1_4_Image = Resources::Load<Texture>(L"Stage1_Floor_Stair1_4"
			, L"..\\Assets\\Image\\Floor\\Stage1\\Stage1_Stair1_4_4.bmp");
		Texture* Stage1_Floor_Stair2_1_Image = Resources::Load<Texture>(L"Stage1_Floor_Stair2_1"
			, L"..\\Assets\\Image\\Floor\\Stage1\\Stage1_Stair2_1_2.bmp");
		Texture* Stage1_Floor_Stair2_2_Image = Resources::Load<Texture>(L"Stage1_Floor_Stair2_2"
			, L"..\\Assets\\Image\\Floor\\Stage1\\Stage1_Stair2_2_2.bmp");
		Texture* Stage1_Floor_BackHalf_Image = Resources::Load<Texture>(L"Stage1_Floor_BackHalf"
			, L"..\\Assets\\Image\\Floor\\Stage1\\Stage1_BackHalf.bmp");

		Floor* Stage1_Floor_FrontHalf_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stage1_Floor_Stair1_1_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stage1_Floor_Stair1_2_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stage1_Floor_Stair1_3_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stage1_Floor_Stair1_4_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stage1_Floor_Stair2_1_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stage1_Floor_Stair2_2_Entity = object::Instantiate<Floor>(eLayerType::Floor);
		Floor* Stage1_Floor_BackHalf_Entity = object::Instantiate<Floor>(eLayerType::Floor);

		SpriteRenderer* FrontHalf_Renderer = Stage1_Floor_FrontHalf_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair1_1_Renderer = Stage1_Floor_Stair1_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair1_2_Renderer = Stage1_Floor_Stair1_2_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair1_3_Renderer = Stage1_Floor_Stair1_3_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair1_4_Renderer = Stage1_Floor_Stair1_4_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair2_1_Renderer = Stage1_Floor_Stair2_1_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* Stair2_2_Renderer = Stage1_Floor_Stair2_2_Entity->AddComponent<SpriteRenderer>();
		SpriteRenderer* BackHalf_Renderer = Stage1_Floor_BackHalf_Entity->AddComponent<SpriteRenderer>();

		FrontHalf_Renderer->SetImage(Stage1_Floor_FrontHalf_Image);
		Stair1_1_Renderer->SetImage(Stage1_Floor_Stair1_1_Image);
		Stair1_2_Renderer->SetImage(Stage1_Floor_Stair1_2_Image);
		Stair1_3_Renderer->SetImage(Stage1_Floor_Stair1_3_Image);
		Stair1_4_Renderer->SetImage(Stage1_Floor_Stair1_4_Image);
		Stair2_1_Renderer->SetImage(Stage1_Floor_Stair2_1_Image);
		Stair2_2_Renderer->SetImage(Stage1_Floor_Stair2_2_Image);
		BackHalf_Renderer->SetImage(Stage1_Floor_BackHalf_Image);

		FrontHalf_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair1_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair1_2_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair1_3_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair1_4_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair2_1_Renderer->SetScale(Vector2(4.0f, 4.0f));
		Stair2_2_Renderer->SetScale(Vector2(4.0f, 4.0f));
		BackHalf_Renderer->SetScale(Vector2(4.0f, 4.0f));

		FrontHalf_Renderer->SetAffectCamera(false);
		Stair1_1_Renderer->SetAffectCamera(false);
		Stair1_2_Renderer->SetAffectCamera(false);
		Stair1_3_Renderer->SetAffectCamera(false);
		Stair1_4_Renderer->SetAffectCamera(false);
		Stair2_1_Renderer->SetAffectCamera(false);
		Stair2_2_Renderer->SetAffectCamera(false);
		BackHalf_Renderer->SetAffectCamera(false);

		Stage1_Floor_FrontHalf_Entity->GetComponent<Transform>()->SetPosition(Vector2(7296.0f, 824.0f));
		Stage1_Floor_Stair1_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(8320.0f, 696.0f));
		Stage1_Floor_Stair1_2_Entity->GetComponent<Transform>()->SetPosition(Vector2(8480.0f, 632.0f));
		Stage1_Floor_Stair1_3_Entity->GetComponent<Transform>()->SetPosition(Vector2(8608.0f, 568.0f));
		Stage1_Floor_Stair1_4_Entity->GetComponent<Transform>()->SetPosition(Vector2(8704.0f, 504.0f));
		Stage1_Floor_Stair2_1_Entity->GetComponent<Transform>()->SetPosition(Vector2(14272.0f, 696.0f));
		Stage1_Floor_Stair2_2_Entity->GetComponent<Transform>()->SetPosition(Vector2(14272.0f, 632.0f));
		Stage1_Floor_BackHalf_Entity->GetComponent<Transform>()->SetPosition(Vector2(17600.0f, 824.0f));

		Collider* FrontHalf_Collider = Stage1_Floor_FrontHalf_Entity->AddComponent<Collider>();
		Collider* Stair1_1_Collider = Stage1_Floor_Stair1_1_Entity->AddComponent<Collider>();
		Collider* Stair1_2_Collider = Stage1_Floor_Stair1_2_Entity->AddComponent<Collider>();
		Collider* Stair1_3_Collider = Stage1_Floor_Stair1_3_Entity->AddComponent<Collider>();
		Collider* Stair1_4_Collider = Stage1_Floor_Stair1_4_Entity->AddComponent<Collider>();
		Collider* Stair2_1_Collider = Stage1_Floor_Stair2_1_Entity->AddComponent<Collider>();
		Collider* Stair2_2_Collider = Stage1_Floor_Stair2_2_Entity->AddComponent<Collider>();
		Collider* BackHalf_Collider = Stage1_Floor_BackHalf_Entity->AddComponent<Collider>();

		FrontHalf_Collider->SetSize(Vector2(14592.0f, 192.0f));
		Stair1_1_Collider->SetSize(Vector2(1664.0f, 64.0f));
		Stair1_2_Collider->SetSize(Vector2(1344.0f, 64.0f));
		Stair1_3_Collider->SetSize(Vector2(1088.0f, 64.0f));
		Stair1_4_Collider->SetSize(Vector2(896.0f, 64.0f));
		Stair2_1_Collider->SetSize(Vector2(640.0f, 64.0f));
		Stair2_2_Collider->SetSize(Vector2(640.0f, 64.0f));
		BackHalf_Collider->SetSize(Vector2(5760.0f, 192.0f));
		#pragma endregion

		#pragma region Foreground Layer
		// Animated Image
		Texture* Stage1_Foreground_RandomBox_Image = Resources::Load<Texture>(L"Stage1_RandomBox"
			, L"..\\Assets\\Image\\ForegroundTiles\\RandomBox.bmp");
		Texture* Stage1_Foreground_SpinBox_Image = Resources::Load<Texture>(L"Stage1_SpinBox"
			, L"..\\Assets\\Image\\ForegroundTiles\\SpinBox.bmp");
		Texture* Stage1_Foreground_Coin_Image = Resources::Load<Texture>(L"Stage1_Coin"
			, L"..\\Assets\\Image\\ForegroundTiles\\Coin.bmp");
		Texture* Stage1_Foreground_YoshiCoin_Image = Resources::Load<Texture>(L"Stage1_YoshiCoin"
			, L"..\\Assets\\Image\\ForegroundTiles\\YoshiCoin.bmp");
		Texture* Stage1_Foreground_RedApple_Image = Resources::Load<Texture>(L"Stage1_RedApple"
			, L"..\\Assets\\Image\\ForegroundTiles\\RedApple.bmp");
		Texture* Stage1_Foreground_Checkpoint_Pole_Image = Resources::Load<Texture>(L"Stage1_Checkpoint_Pole"
			, L"..\\Assets\\Image\\ForegroundTiles\\Checkpoint_Pole.bmp");
		// Static Image
		Texture* Stage1_Foreground_UpgradeBox_Image = Resources::Load<Texture>(L"Stage1_UpgradeBox"
			, L"..\\Assets\\Image\\ForegroundTiles\\UpgradeBox.bmp");
		Texture* Stage1_Foreground_EmptyBox_Image = Resources::Load<Texture>(L"Stage1_EmptyBox"
			, L"..\\Assets\\Image\\ForegroundTiles\\EmptyBox.bmp");
		Texture* Stage1_Foreground_Checkpoint_Flag_Image = Resources::Load<Texture>(L"Stage1_Checkpoint_Flag"
			, L"..\\Assets\\Image\\ForegroundTiles\\Checkpoint_Flag.bmp");
		Texture* Stage1_Foreground_Checkpoint_Finish_Pole_Image = Resources::Load<Texture>(L"Stage1_Checkpoint_Finish_Pole"
			, L"..\\Assets\\Image\\ForegroundTiles\\Checkpoint_Finish_Pole.bmp");
		Texture* Stage1_Foreground_Checkpoint_Finish_Flag_Image = Resources::Load<Texture>(L"Stage1_Checkpoint_Finish_Flag"
			, L"..\\Assets\\Image\\ForegroundTiles\\Checkpoint_Finish_Flag.bmp");

		ForegroundRandomBox* Stage1_Foreground_RandomBox_Entity1 = object::Instantiate<ForegroundRandomBox>(eLayerType::Foreground);
		ForegroundRandomBox* Stage1_Foreground_RandomBox_Entity2 = object::Instantiate<ForegroundRandomBox>(eLayerType::Foreground);
		ForegroundRandomBox* Stage1_Foreground_RandomBox_Entity3 = object::Instantiate<ForegroundRandomBox>(eLayerType::Foreground);
		ForegroundRandomBox* Stage1_Foreground_RandomBox_Entity4 = object::Instantiate<ForegroundRandomBox>(eLayerType::Foreground);
		ForegroundRandomBox* Stage1_Foreground_RandomBox_Entity5 = object::Instantiate<ForegroundRandomBox>(eLayerType::Foreground);
		ForegroundRandomBox* Stage1_Foreground_RandomBox_Entity6 = object::Instantiate<ForegroundRandomBox>(eLayerType::Foreground);
		ForegroundRandomBox* Stage1_Foreground_RandomBox_Entity7 = object::Instantiate<ForegroundRandomBox>(eLayerType::Foreground);
		ForegroundSpinBox* Stage1_Foreground_SpinBox_Entity1 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundSpinBox* Stage1_Foreground_SpinBox_Entity2 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundSpinBox* Stage1_Foreground_SpinBox_Entity3 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundSpinBox* Stage1_Foreground_SpinBox_Entity4 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundSpinBox* Stage1_Foreground_SpinBox_Entity5 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundSpinBox* Stage1_Foreground_SpinBox_Entity6 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundSpinBox* Stage1_Foreground_SpinBox_Entity7 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundSpinBox* Stage1_Foreground_SpinBox_Entity8 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundSpinBox* Stage1_Foreground_SpinBox_Entity9 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundSpinBox* Stage1_Foreground_SpinBox_Entity10 = object::Instantiate<ForegroundSpinBox>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_1_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_1_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_1_3 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_1_4 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_2_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_2_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_2_3 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_3_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_3_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_3_3 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_1 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_2 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_3 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_4 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_5 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_6 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_7 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_8 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_9 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_10 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_11 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_12 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_13 = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundYoshiCoin* Stage1_Foreground_YoshiCoin_Entity1 = object::Instantiate<ForegroundYoshiCoin>(eLayerType::Foreground);
		ForegroundYoshiCoin* Stage1_Foreground_YoshiCoin_Entity2 = object::Instantiate<ForegroundYoshiCoin>(eLayerType::Foreground);
		ForegroundYoshiCoin* Stage1_Foreground_YoshiCoin_Entity3 = object::Instantiate<ForegroundYoshiCoin>(eLayerType::Foreground);
		ForegroundYoshiCoin* Stage1_Foreground_YoshiCoin_Entity4 = object::Instantiate<ForegroundYoshiCoin>(eLayerType::Foreground);
		ForegroundRedApple* Stage1_Foreground_RedApple_Entity = object::Instantiate<ForegroundRedApple>(eLayerType::Foreground);
		ForegroundUpgradeBox* Stage1_Foreground_UpgradeBox_Entity1 = object::Instantiate<ForegroundUpgradeBox>(eLayerType::Foreground);
		ForegroundUpgradeBox* Stage1_Foreground_UpgradeBox_Entity2 = object::Instantiate<ForegroundUpgradeBox>(eLayerType::Foreground);
		ForegroundUpgradeBox* Stage1_Foreground_UpgradeBox_Entity3 = object::Instantiate<ForegroundUpgradeBox>(eLayerType::Foreground);
		ForegroundUpgradeBox* Stage1_Foreground_UpgradeBox_Entity4 = object::Instantiate<ForegroundUpgradeBox>(eLayerType::Foreground);
		ForegroundUpgradeBox* Stage1_Foreground_Checkpoint_Pole_Entity = object::Instantiate<ForegroundUpgradeBox>(eLayerType::Foreground);
		ForegroundCoin* Stage1_Foreground_Checkpoint_Flag_Entity = object::Instantiate<ForegroundCoin>(eLayerType::Foreground);
		ForegroundUpgradeBox* Stage1_Foreground_Checkpoint_Finish_Pole_Entity = object::Instantiate<ForegroundUpgradeBox>(eLayerType::Foreground);
		ForegroundFinishFlag* Stage1_Foreground_Checkpoint_Finish_Flag_Entity = object::Instantiate<ForegroundFinishFlag>(eLayerType::Foreground);

		// Set Type
		Stage1_Foreground_Coin_Entity_4_1->SetType(2);
		Stage1_Foreground_Coin_Entity_4_2->SetType(2);
		Stage1_Foreground_Coin_Entity_4_3->SetType(2);
		Stage1_Foreground_Coin_Entity_4_4->SetType(2);
		Stage1_Foreground_Coin_Entity_4_5->SetType(2);
		Stage1_Foreground_Coin_Entity_4_6->SetType(2);
		Stage1_Foreground_Coin_Entity_4_7->SetType(2);
		Stage1_Foreground_Coin_Entity_4_8->SetType(2);
		Stage1_Foreground_Coin_Entity_4_9->SetType(2);
		Stage1_Foreground_Coin_Entity_4_10->SetType(2);
		Stage1_Foreground_Coin_Entity_4_11->SetType(2);
		Stage1_Foreground_Coin_Entity_4_12->SetType(2);
		Stage1_Foreground_Coin_Entity_4_13->SetType(2);
		Stage1_Foreground_SpinBox_Entity9->SetType(2);

		Transform* trRandomBox_1 = Stage1_Foreground_RandomBox_Entity1->GetComponent<Transform>();
		Transform* trRandomBox_2 = Stage1_Foreground_RandomBox_Entity2->GetComponent<Transform>();
		Transform* trRandomBox_3 = Stage1_Foreground_RandomBox_Entity3->GetComponent<Transform>();
		Transform* trRandomBox_4 = Stage1_Foreground_RandomBox_Entity4->GetComponent<Transform>();
		Transform* trRandomBox_5 = Stage1_Foreground_RandomBox_Entity5->GetComponent<Transform>();
		Transform* trRandomBox_6 = Stage1_Foreground_RandomBox_Entity6->GetComponent<Transform>();
		Transform* trRandomBox_7 = Stage1_Foreground_RandomBox_Entity7->GetComponent<Transform>();
		Transform* trSpinBox_1 = Stage1_Foreground_SpinBox_Entity1->GetComponent<Transform>();
		Transform* trSpinBox_2 = Stage1_Foreground_SpinBox_Entity2->GetComponent<Transform>();
		Transform* trSpinBox_3 = Stage1_Foreground_SpinBox_Entity3->GetComponent<Transform>();
		Transform* trSpinBox_4 = Stage1_Foreground_SpinBox_Entity4->GetComponent<Transform>();
		Transform* trSpinBox_5 = Stage1_Foreground_SpinBox_Entity5->GetComponent<Transform>();
		Transform* trSpinBox_6 = Stage1_Foreground_SpinBox_Entity6->GetComponent<Transform>();
		Transform* trSpinBox_7 = Stage1_Foreground_SpinBox_Entity7->GetComponent<Transform>();
		Transform* trSpinBox_8 = Stage1_Foreground_SpinBox_Entity8->GetComponent<Transform>();
		Transform* trSpinBox_9 = Stage1_Foreground_SpinBox_Entity9->GetComponent<Transform>();
		Transform* trSpinBox_10 = Stage1_Foreground_SpinBox_Entity10->GetComponent<Transform>();
		Transform* trCoin_1_1 = Stage1_Foreground_Coin_Entity_1_1->GetComponent<Transform>();
		Transform* trCoin_1_2 = Stage1_Foreground_Coin_Entity_1_2->GetComponent<Transform>();
		Transform* trCoin_1_3 = Stage1_Foreground_Coin_Entity_1_3->GetComponent<Transform>();
		Transform* trCoin_1_4 = Stage1_Foreground_Coin_Entity_1_4->GetComponent<Transform>();
		Transform* trCoin_2_1 = Stage1_Foreground_Coin_Entity_2_1->GetComponent<Transform>();
		Transform* trCoin_2_2 = Stage1_Foreground_Coin_Entity_2_2->GetComponent<Transform>();
		Transform* trCoin_2_3 = Stage1_Foreground_Coin_Entity_2_3->GetComponent<Transform>();
		Transform* trCoin_3_1 = Stage1_Foreground_Coin_Entity_3_1->GetComponent<Transform>();
		Transform* trCoin_3_2 = Stage1_Foreground_Coin_Entity_3_2->GetComponent<Transform>();
		Transform* trCoin_3_3 = Stage1_Foreground_Coin_Entity_3_3->GetComponent<Transform>();
		Transform* trCoin_4_1 = Stage1_Foreground_Coin_Entity_4_1->GetComponent<Transform>();
		Transform* trCoin_4_2 = Stage1_Foreground_Coin_Entity_4_2->GetComponent<Transform>();
		Transform* trCoin_4_3 = Stage1_Foreground_Coin_Entity_4_3->GetComponent<Transform>();
		Transform* trCoin_4_4 = Stage1_Foreground_Coin_Entity_4_4->GetComponent<Transform>();
		Transform* trCoin_4_5 = Stage1_Foreground_Coin_Entity_4_5->GetComponent<Transform>();
		Transform* trCoin_4_6 = Stage1_Foreground_Coin_Entity_4_6->GetComponent<Transform>();
		Transform* trCoin_4_7 = Stage1_Foreground_Coin_Entity_4_7->GetComponent<Transform>();
		Transform* trCoin_4_8 = Stage1_Foreground_Coin_Entity_4_8->GetComponent<Transform>();
		Transform* trCoin_4_9 = Stage1_Foreground_Coin_Entity_4_9->GetComponent<Transform>();
		Transform* trCoin_4_10 = Stage1_Foreground_Coin_Entity_4_10->GetComponent<Transform>();
		Transform* trCoin_4_11 = Stage1_Foreground_Coin_Entity_4_11->GetComponent<Transform>();
		Transform* trCoin_4_12 = Stage1_Foreground_Coin_Entity_4_12->GetComponent<Transform>();
		Transform* trCoin_4_13 = Stage1_Foreground_Coin_Entity_4_13->GetComponent<Transform>();
		Transform* trYoshiCoin_1 = Stage1_Foreground_YoshiCoin_Entity1->GetComponent<Transform>();
		Transform* trYoshiCoin_2 = Stage1_Foreground_YoshiCoin_Entity2->GetComponent<Transform>();
		Transform* trYoshiCoin_3 = Stage1_Foreground_YoshiCoin_Entity3->GetComponent<Transform>();
		Transform* trYoshiCoin_4 = Stage1_Foreground_YoshiCoin_Entity4->GetComponent<Transform>();
		Transform* trUpgradeBox_1 = Stage1_Foreground_UpgradeBox_Entity1->GetComponent<Transform>();
		Transform* trUpgradeBox_2 = Stage1_Foreground_UpgradeBox_Entity2->GetComponent<Transform>();
		Transform* trUpgradeBox_3 = Stage1_Foreground_UpgradeBox_Entity3->GetComponent<Transform>();
		Transform* trUpgradeBox_4 = Stage1_Foreground_UpgradeBox_Entity4->GetComponent<Transform>();
		Transform* trCheckpoint_Pole = Stage1_Foreground_Checkpoint_Pole_Entity->GetComponent<Transform>();
		Transform* trCheckpoint_Flag = Stage1_Foreground_Checkpoint_Flag_Entity->GetComponent<Transform>();
		Transform* trCheckpoint_Finish_Pole = Stage1_Foreground_Checkpoint_Finish_Pole_Entity->GetComponent<Transform>();
		Transform* trCheckpoint_Finish_Flag = Stage1_Foreground_Checkpoint_Finish_Flag_Entity->GetComponent<Transform>();

		trRandomBox_1->SetPosition(Vector2(2620.0f, 510.0f));
		trRandomBox_2->SetPosition(Vector2(2748.0f, 510.0f));
		trRandomBox_3->SetPosition(Vector2(3700.0f, 550.0f));
		trRandomBox_4->SetPosition(Vector2(3764.0f, 550.0f));
		trRandomBox_5->SetPosition(Vector2(11340.0f, 550.0f));
		trRandomBox_6->SetPosition(Vector2(11404.0f, 550.0f));
		trRandomBox_7->SetPosition(Vector2(11468.0f, 550.0f));
		trSpinBox_1->SetPosition(Vector2(12760.0f, 270.0f));
		trSpinBox_2->SetPosition(Vector2(12824.0f, 270.0f));
		trSpinBox_3->SetPosition(Vector2(18080.0f, 320.0f));
		trSpinBox_4->SetPosition(Vector2(18144.0f, 320.0f));
		trSpinBox_5->SetPosition(Vector2(18208.0f, 320.0f));
		trSpinBox_6->SetPosition(Vector2(18080.0f, 384.0f));
		trSpinBox_7->SetPosition(Vector2(18208.0f, 384.0f));
		trSpinBox_8->SetPosition(Vector2(18080.0f, 448.0f));
		trSpinBox_9->SetPosition(Vector2(18144.0f, 448.0f));
		trSpinBox_10->SetPosition(Vector2(18208.0f, 448.0f));
		trCoin_1_1->SetPosition(Vector2(5060.0f, 530.0f));
		trCoin_1_2->SetPosition(Vector2(5124.0f, 498.0f));
		trCoin_1_3->SetPosition(Vector2(5252.0f, 498.0f));
		trCoin_1_4->SetPosition(Vector2(5316.0f, 520.0f));
		trCoin_2_1->SetPosition(Vector2(9180.0f, 270.0f));
		trCoin_2_2->SetPosition(Vector2(9244.0f, 206.0f));
		trCoin_2_3->SetPosition(Vector2(9308.0f, 206.0f));
		trCoin_3_1->SetPosition(Vector2(13800.0f, 206.0f));
		trCoin_3_2->SetPosition(Vector2(13864.0f, 206.0f));
		trCoin_3_3->SetPosition(Vector2(13928.0f, 206.0f));
		trCoin_4_1->SetPosition(Vector2(18370.0f, 600.0f));
		trCoin_4_2->SetPosition(Vector2(18434.0f, 536.0f));
		trCoin_4_3->SetPosition(Vector2(18498.0f, 472.0f));
		trCoin_4_4->SetPosition(Vector2(18562.0f, 408.0f));
		trCoin_4_5->SetPosition(Vector2(18626.0f, 408.0f));
		trCoin_4_6->SetPosition(Vector2(18690.0f, 408.0f));
		trCoin_4_7->SetPosition(Vector2(18754.0f, 408.0f));
		trCoin_4_8->SetPosition(Vector2(18818.0f, 408.0f));
		trCoin_4_9->SetPosition(Vector2(18882.0f, 408.0f));
		trCoin_4_10->SetPosition(Vector2(18946.0f, 408.0f));
		trCoin_4_11->SetPosition(Vector2(19010.0f, 408.0f));
		trCoin_4_12->SetPosition(Vector2(19074.0f, 408.0f));
		trCoin_4_13->SetPosition(Vector2(19138.0f, 408.0f));
		trYoshiCoin_1->SetPosition(Vector2(5188.0f, 466.0f));
		trYoshiCoin_2->SetPosition(Vector2(7000.0f, 466.0f));
		trYoshiCoin_3->SetPosition(Vector2(9372.0f, 190.0f));
		trYoshiCoin_4->SetPosition(Vector2(14056.0f, 190.0f));
		trUpgradeBox_1->SetPosition(Vector2(2684.0f, 510.0f));
		trUpgradeBox_2->SetPosition(Vector2(14380.0f, 398.0f));
		trUpgradeBox_3->SetPosition(Vector2(14624.0f, 760.0f));
		trUpgradeBox_4->SetPosition(Vector2(14688.0f, 760.0f));
		trCheckpoint_Pole->SetPosition(Vector2(10240.0f, 602.0f));
		trCheckpoint_Flag->SetPosition(Vector2(10240.0f, 682.0f));
		trCheckpoint_Finish_Pole->SetPosition(Vector2(19500.0f, 438.0f));
		trCheckpoint_Finish_Flag->SetPosition(Vector2(19484.0f, 190.0f));

		Animator* atRandomBox_1 = Stage1_Foreground_RandomBox_Entity1->AddComponent<Animator>();
		Animator* atRandomBox_2 = Stage1_Foreground_RandomBox_Entity2->AddComponent<Animator>();
		Animator* atRandomBox_3 = Stage1_Foreground_RandomBox_Entity3->AddComponent<Animator>();
		Animator* atRandomBox_4 = Stage1_Foreground_RandomBox_Entity4->AddComponent<Animator>();
		Animator* atRandomBox_5 = Stage1_Foreground_RandomBox_Entity5->AddComponent<Animator>();
		Animator* atRandomBox_6 = Stage1_Foreground_RandomBox_Entity6->AddComponent<Animator>();
		Animator* atRandomBox_7 = Stage1_Foreground_RandomBox_Entity7->AddComponent<Animator>();
		Animator* atSpinBox_1 = Stage1_Foreground_SpinBox_Entity1->AddComponent<Animator>();
		Animator* atSpinBox_2 = Stage1_Foreground_SpinBox_Entity2->AddComponent<Animator>();
		Animator* atSpinBox_3 = Stage1_Foreground_SpinBox_Entity3->AddComponent<Animator>();
		Animator* atSpinBox_4 = Stage1_Foreground_SpinBox_Entity4->AddComponent<Animator>();
		Animator* atSpinBox_5 = Stage1_Foreground_SpinBox_Entity5->AddComponent<Animator>();
		Animator* atSpinBox_6 = Stage1_Foreground_SpinBox_Entity6->AddComponent<Animator>();
		Animator* atSpinBox_7 = Stage1_Foreground_SpinBox_Entity7->AddComponent<Animator>();
		Animator* atSpinBox_8 = Stage1_Foreground_SpinBox_Entity8->AddComponent<Animator>();
		Animator* atSpinBox_9 = Stage1_Foreground_SpinBox_Entity9->AddComponent<Animator>();
		Animator* atSpinBox_10 = Stage1_Foreground_SpinBox_Entity10->AddComponent<Animator>();
		Animator* atCoin_1_1 = Stage1_Foreground_Coin_Entity_1_1->AddComponent<Animator>();
		Animator* atCoin_1_2 = Stage1_Foreground_Coin_Entity_1_2->AddComponent<Animator>();
		Animator* atCoin_1_3 = Stage1_Foreground_Coin_Entity_1_3->AddComponent<Animator>();
		Animator* atCoin_1_4 = Stage1_Foreground_Coin_Entity_1_4->AddComponent<Animator>();
		Animator* atCoin_2_1 = Stage1_Foreground_Coin_Entity_2_1->AddComponent<Animator>();
		Animator* atCoin_2_2 = Stage1_Foreground_Coin_Entity_2_2->AddComponent<Animator>();
		Animator* atCoin_2_3 = Stage1_Foreground_Coin_Entity_2_3->AddComponent<Animator>();
		Animator* atCoin_3_1 = Stage1_Foreground_Coin_Entity_3_1->AddComponent<Animator>();
		Animator* atCoin_3_2 = Stage1_Foreground_Coin_Entity_3_2->AddComponent<Animator>();
		Animator* atCoin_3_3 = Stage1_Foreground_Coin_Entity_3_3->AddComponent<Animator>();
		Animator* atCoin_4_1 = Stage1_Foreground_Coin_Entity_4_1->AddComponent<Animator>();
		Animator* atCoin_4_2 = Stage1_Foreground_Coin_Entity_4_2->AddComponent<Animator>();
		Animator* atCoin_4_3 = Stage1_Foreground_Coin_Entity_4_3->AddComponent<Animator>();
		Animator* atCoin_4_4 = Stage1_Foreground_Coin_Entity_4_4->AddComponent<Animator>();
		Animator* atCoin_4_5 = Stage1_Foreground_Coin_Entity_4_5->AddComponent<Animator>();
		Animator* atCoin_4_6 = Stage1_Foreground_Coin_Entity_4_6->AddComponent<Animator>();
		Animator* atCoin_4_7 = Stage1_Foreground_Coin_Entity_4_7->AddComponent<Animator>();
		Animator* atCoin_4_8 = Stage1_Foreground_Coin_Entity_4_8->AddComponent<Animator>();
		Animator* atCoin_4_9 = Stage1_Foreground_Coin_Entity_4_9->AddComponent<Animator>();
		Animator* atCoin_4_10 = Stage1_Foreground_Coin_Entity_4_10->AddComponent<Animator>();
		Animator* atCoin_4_11 = Stage1_Foreground_Coin_Entity_4_11->AddComponent<Animator>();
		Animator* atCoin_4_12 = Stage1_Foreground_Coin_Entity_4_12->AddComponent<Animator>();
		Animator* atCoin_4_13 = Stage1_Foreground_Coin_Entity_4_13->AddComponent<Animator>();
		Animator* atYoshiCoin_1 = Stage1_Foreground_YoshiCoin_Entity1->AddComponent<Animator>();
		Animator* atYoshiCoin_2 = Stage1_Foreground_YoshiCoin_Entity2->AddComponent<Animator>();
		Animator* atYoshiCoin_3 = Stage1_Foreground_YoshiCoin_Entity3->AddComponent<Animator>();
		Animator* atYoshiCoin_4 = Stage1_Foreground_YoshiCoin_Entity4->AddComponent<Animator>();
		Animator* atUpgradeBox_1 = Stage1_Foreground_UpgradeBox_Entity1->AddComponent<Animator>();
		Animator* atUpgradeBox_2 = Stage1_Foreground_UpgradeBox_Entity2->AddComponent<Animator>();
		Animator* atUpgradeBox_3 = Stage1_Foreground_UpgradeBox_Entity3->AddComponent<Animator>();
		Animator* atUpgradeBox_4 = Stage1_Foreground_UpgradeBox_Entity4->AddComponent<Animator>();
		Animator* atCheckpoint_Pole = Stage1_Foreground_Checkpoint_Pole_Entity->AddComponent<Animator>();
		Animator* atCheckpoint_Flag = Stage1_Foreground_Checkpoint_Flag_Entity->AddComponent<Animator>();
		Animator* atCheckpoint_Finish_Pole = Stage1_Foreground_Checkpoint_Finish_Pole_Entity->AddComponent<Animator>();
		Animator* atCheckpoint_Finish_Flag = Stage1_Foreground_Checkpoint_Finish_Flag_Entity->AddComponent<Animator>();

		atRandomBox_1->CreateAnimation(L"Foreground_Animation_RandomBox", Stage1_Foreground_RandomBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atRandomBox_2->CreateAnimation(L"Foreground_Animation_RandomBox", Stage1_Foreground_RandomBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atRandomBox_3->CreateAnimation(L"Foreground_Animation_RandomBox", Stage1_Foreground_RandomBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atRandomBox_4->CreateAnimation(L"Foreground_Animation_RandomBox", Stage1_Foreground_RandomBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atRandomBox_5->CreateAnimation(L"Foreground_Animation_RandomBox", Stage1_Foreground_RandomBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atRandomBox_6->CreateAnimation(L"Foreground_Animation_RandomBox", Stage1_Foreground_RandomBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atRandomBox_7->CreateAnimation(L"Foreground_Animation_RandomBox", Stage1_Foreground_RandomBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atRandomBox_1->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRandomBox_2->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRandomBox_3->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRandomBox_4->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRandomBox_5->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRandomBox_6->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRandomBox_7->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_1->CreateAnimation(L"Foreground_Animation_SpinBox_Idle", Stage1_Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_2->CreateAnimation(L"Foreground_Animation_SpinBox_Idle", Stage1_Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_3->CreateAnimation(L"Foreground_Animation_SpinBox_Idle", Stage1_Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_4->CreateAnimation(L"Foreground_Animation_SpinBox_Idle", Stage1_Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_5->CreateAnimation(L"Foreground_Animation_SpinBox_Idle", Stage1_Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_6->CreateAnimation(L"Foreground_Animation_SpinBox_Idle", Stage1_Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_7->CreateAnimation(L"Foreground_Animation_SpinBox_Idle", Stage1_Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_8->CreateAnimation(L"Foreground_Animation_SpinBox_Idle", Stage1_Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_9->CreateAnimation(L"Foreground_Animation_SpinBox_Idle", Stage1_Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_10->CreateAnimation(L"Foreground_Animation_SpinBox_Idle", Stage1_Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_1->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_2->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_3->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_4->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_5->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_6->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_7->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_8->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atSpinBox_9->CreateAnimation(L"Foreground_Animation_SpinBox_Spin", Stage1_Foreground_SpinBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atSpinBox_10->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_1_1->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_1_2->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_1_3->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_1_4->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_2_1->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_2_2->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_2_3->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_3_1->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_3_2->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_3_3->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_1->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_2->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_3->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_4->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_5->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_6->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_7->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_8->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_9->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_10->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_11->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_12->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_13->CreateAnimation(L"Foreground_Animation_Coin", Stage1_Foreground_Coin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCoin_4_1->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_4_2->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_4_3->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_4_4->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_4_5->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_4_6->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_4_7->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_4_8->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_4_9->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_4_10->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_4_11->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_4_12->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCoin_4_13->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atYoshiCoin_1->CreateAnimation(L"Foreground_Animation_YoshiCoin", Stage1_Foreground_YoshiCoin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 32.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atYoshiCoin_2->CreateAnimation(L"Foreground_Animation_YoshiCoin", Stage1_Foreground_YoshiCoin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 32.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atYoshiCoin_3->CreateAnimation(L"Foreground_Animation_YoshiCoin", Stage1_Foreground_YoshiCoin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 32.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atYoshiCoin_4->CreateAnimation(L"Foreground_Animation_YoshiCoin", Stage1_Foreground_YoshiCoin_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 32.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atUpgradeBox_1->CreateAnimation(L"Foreground_Animation_UpgradeBox", Stage1_Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atUpgradeBox_2->CreateAnimation(L"Foreground_Animation_UpgradeBox", Stage1_Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atUpgradeBox_3->CreateAnimation(L"Foreground_Animation_UpgradeBox", Stage1_Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atUpgradeBox_4->CreateAnimation(L"Foreground_Animation_UpgradeBox", Stage1_Foreground_UpgradeBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atUpgradeBox_1->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atUpgradeBox_2->CreateAnimation(L"Foreground_Animation_EmptyBox", Stage1_Foreground_EmptyBox_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCheckpoint_Pole->CreateAnimation(L"Foreground_Animation_Checkpoint_Pole", Stage1_Foreground_Checkpoint_Pole_Image, Vector2(0.0f, 0.0f), Vector2(24.0f, 64.0f), 4, Vector2(0.0f, 0.0f), 0.2f);
		atCheckpoint_Flag->CreateAnimation(L"Foreground_Animation_Checkpoint_Flag", Stage1_Foreground_Checkpoint_Flag_Image, Vector2(0.0f, 0.0f), Vector2(8.0f, 8.0f), 1);
		atCheckpoint_Finish_Pole->CreateAnimation(L"Foreground_Animation_Checkpoint_Finish_Pole", Stage1_Foreground_Checkpoint_Finish_Pole_Image, Vector2(0.0f, 0.0f), Vector2(48.0f, 144.0f), 1);
		atCheckpoint_Finish_Flag->CreateAnimation(L"Foreground_Animation_Checkpoint_Finish_Flag", Stage1_Foreground_Checkpoint_Finish_Flag_Image, Vector2(0.0f, 0.0f), Vector2(24.0f, 8.0f), 1);

		atRandomBox_1->SetScale(Vector2(4.0f, 4.0f));
		atRandomBox_2->SetScale(Vector2(4.0f, 4.0f));
		atRandomBox_3->SetScale(Vector2(4.0f, 4.0f));
		atRandomBox_4->SetScale(Vector2(4.0f, 4.0f));
		atRandomBox_5->SetScale(Vector2(4.0f, 4.0f));
		atRandomBox_6->SetScale(Vector2(4.0f, 4.0f));
		atRandomBox_7->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_1->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_2->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_3->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_4->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_5->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_6->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_7->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_8->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_9->SetScale(Vector2(4.0f, 4.0f));
		atSpinBox_10->SetScale(Vector2(4.0f, 4.0f));
		atCoin_1_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_1_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_1_3->SetScale(Vector2(4.0f, 4.0f));
		atCoin_1_4->SetScale(Vector2(4.0f, 4.0f));
		atCoin_2_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_2_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_2_3->SetScale(Vector2(4.0f, 4.0f));
		atCoin_3_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_3_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_3_3->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_1->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_2->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_3->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_4->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_5->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_6->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_7->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_8->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_9->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_10->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_11->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_12->SetScale(Vector2(4.0f, 4.0f));
		atCoin_4_13->SetScale(Vector2(4.0f, 4.0f));
		atYoshiCoin_1->SetScale(Vector2(4.0f, 4.0f));
		atYoshiCoin_2->SetScale(Vector2(4.0f, 4.0f));
		atYoshiCoin_3->SetScale(Vector2(4.0f, 4.0f));
		atYoshiCoin_4->SetScale(Vector2(4.0f, 4.0f));
		atUpgradeBox_1->SetScale(Vector2(4.0f, 4.0f));
		atUpgradeBox_2->SetScale(Vector2(4.0f, 4.0f));
		atUpgradeBox_3->SetScale(Vector2(4.0f, 4.0f));
		atUpgradeBox_4->SetScale(Vector2(4.0f, 4.0f));
		atCheckpoint_Pole->SetScale(Vector2(4.0f, 4.0f));
		atCheckpoint_Flag->SetScale(Vector2(4.0f, 4.0f));
		atCheckpoint_Finish_Pole->SetScale(Vector2(4.0f, 4.0f));
		atCheckpoint_Finish_Flag->SetScale(Vector2(4.0f, 4.0f));

		atRandomBox_1->PlayAnimation(L"Foreground_Animation_RandomBox", true);
		atRandomBox_2->PlayAnimation(L"Foreground_Animation_RandomBox", true);
		atRandomBox_3->PlayAnimation(L"Foreground_Animation_RandomBox", true);
		atRandomBox_4->PlayAnimation(L"Foreground_Animation_RandomBox", true);
		atRandomBox_5->PlayAnimation(L"Foreground_Animation_RandomBox", true);
		atRandomBox_6->PlayAnimation(L"Foreground_Animation_RandomBox", true);
		atRandomBox_7->PlayAnimation(L"Foreground_Animation_RandomBox", true);
		atSpinBox_1->PlayAnimation(L"Foreground_Animation_SpinBox_Idle", true);
		atSpinBox_2->PlayAnimation(L"Foreground_Animation_SpinBox_Idle", true);
		atSpinBox_3->PlayAnimation(L"Foreground_Animation_SpinBox_Idle", true);
		atSpinBox_4->PlayAnimation(L"Foreground_Animation_SpinBox_Idle", true);
		atSpinBox_5->PlayAnimation(L"Foreground_Animation_SpinBox_Idle", true);
		atSpinBox_6->PlayAnimation(L"Foreground_Animation_SpinBox_Idle", true);
		atSpinBox_7->PlayAnimation(L"Foreground_Animation_SpinBox_Idle", true);
		atSpinBox_8->PlayAnimation(L"Foreground_Animation_SpinBox_Idle", true);
		atSpinBox_9->PlayAnimation(L"Foreground_Animation_SpinBox_Idle", true);
		atSpinBox_10->PlayAnimation(L"Foreground_Animation_SpinBox_Idle", true);
		atCoin_1_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_1_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_1_3->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_1_4->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_2_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_2_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_2_3->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_3_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_3_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_3_3->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_1->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_2->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_3->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_4->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_5->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_6->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_7->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_8->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_9->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_10->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_11->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_12->PlayAnimation(L"Foreground_Animation_Coin", true);
		atCoin_4_13->PlayAnimation(L"Foreground_Animation_Coin", true);
		atYoshiCoin_1->PlayAnimation(L"Foreground_Animation_YoshiCoin", true);
		atYoshiCoin_2->PlayAnimation(L"Foreground_Animation_YoshiCoin", true);
		atYoshiCoin_3->PlayAnimation(L"Foreground_Animation_YoshiCoin", true);
		atYoshiCoin_4->PlayAnimation(L"Foreground_Animation_YoshiCoin", true);
		atUpgradeBox_1->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atUpgradeBox_2->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atUpgradeBox_3->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atUpgradeBox_4->PlayAnimation(L"Foreground_Animation_UpgradeBox", true);
		atCheckpoint_Pole->PlayAnimation(L"Foreground_Animation_Checkpoint_Pole", true);
		atCheckpoint_Flag->PlayAnimation(L"Foreground_Animation_Checkpoint_Flag", true);
		atCheckpoint_Finish_Pole->PlayAnimation(L"Foreground_Animation_Checkpoint_Finish_Pole", true);
		atCheckpoint_Finish_Flag->PlayAnimation(L"Foreground_Animation_Checkpoint_Finish_Flag", true);

		Collider* colRandomBox_1 = Stage1_Foreground_RandomBox_Entity1->AddComponent<Collider>();
		Collider* colRandomBox_2 = Stage1_Foreground_RandomBox_Entity2->AddComponent<Collider>();
		Collider* colRandomBox_3 = Stage1_Foreground_RandomBox_Entity3->AddComponent<Collider>();
		Collider* colRandomBox_4 = Stage1_Foreground_RandomBox_Entity4->AddComponent<Collider>();
		Collider* colRandomBox_5 = Stage1_Foreground_RandomBox_Entity5->AddComponent<Collider>();
		Collider* colRandomBox_6 = Stage1_Foreground_RandomBox_Entity6->AddComponent<Collider>();
		Collider* colRandomBox_7 = Stage1_Foreground_RandomBox_Entity7->AddComponent<Collider>();
		Collider* colSpinBox_1 = Stage1_Foreground_SpinBox_Entity1->AddComponent<Collider>();
		Collider* colSpinBox_2 = Stage1_Foreground_SpinBox_Entity2->AddComponent<Collider>();
		Collider* colSpinBox_3 = Stage1_Foreground_SpinBox_Entity3->AddComponent<Collider>();
		Collider* colSpinBox_4 = Stage1_Foreground_SpinBox_Entity4->AddComponent<Collider>();
		Collider* colSpinBox_5 = Stage1_Foreground_SpinBox_Entity5->AddComponent<Collider>();
		Collider* colSpinBox_6 = Stage1_Foreground_SpinBox_Entity6->AddComponent<Collider>();
		Collider* colSpinBox_7 = Stage1_Foreground_SpinBox_Entity7->AddComponent<Collider>();
		Collider* colSpinBox_8 = Stage1_Foreground_SpinBox_Entity8->AddComponent<Collider>();
		Collider* colSpinBox_9 = Stage1_Foreground_SpinBox_Entity9->AddComponent<Collider>();
		Collider* colSpinBox_10 = Stage1_Foreground_SpinBox_Entity10->AddComponent<Collider>();
		Collider* colCoin_1_1 = Stage1_Foreground_Coin_Entity_1_1->AddComponent<Collider>();
		Collider* colCoin_1_2 = Stage1_Foreground_Coin_Entity_1_2->AddComponent<Collider>();
		Collider* colCoin_1_3 = Stage1_Foreground_Coin_Entity_1_3->AddComponent<Collider>();
		Collider* colCoin_1_4 = Stage1_Foreground_Coin_Entity_1_4->AddComponent<Collider>();
		Collider* colCoin_2_1 = Stage1_Foreground_Coin_Entity_2_1->AddComponent<Collider>();
		Collider* colCoin_2_2 = Stage1_Foreground_Coin_Entity_2_2->AddComponent<Collider>();
		Collider* colCoin_2_3 = Stage1_Foreground_Coin_Entity_2_3->AddComponent<Collider>();
		Collider* colCoin_3_1 = Stage1_Foreground_Coin_Entity_3_1->AddComponent<Collider>();
		Collider* colCoin_3_2 = Stage1_Foreground_Coin_Entity_3_2->AddComponent<Collider>();
		Collider* colCoin_3_3 = Stage1_Foreground_Coin_Entity_3_3->AddComponent<Collider>();
		Collider* colCoin_4_1 = Stage1_Foreground_Coin_Entity_4_1->AddComponent<Collider>();
		Collider* colCoin_4_2 = Stage1_Foreground_Coin_Entity_4_2->AddComponent<Collider>();
		Collider* colCoin_4_3 = Stage1_Foreground_Coin_Entity_4_3->AddComponent<Collider>();
		Collider* colCoin_4_4 = Stage1_Foreground_Coin_Entity_4_4->AddComponent<Collider>();
		Collider* colCoin_4_5 = Stage1_Foreground_Coin_Entity_4_5->AddComponent<Collider>();
		Collider* colCoin_4_6 = Stage1_Foreground_Coin_Entity_4_6->AddComponent<Collider>();
		Collider* colCoin_4_7 = Stage1_Foreground_Coin_Entity_4_7->AddComponent<Collider>();
		Collider* colCoin_4_8 = Stage1_Foreground_Coin_Entity_4_8->AddComponent<Collider>();
		Collider* colCoin_4_9 = Stage1_Foreground_Coin_Entity_4_9->AddComponent<Collider>();
		Collider* colCoin_4_10 = Stage1_Foreground_Coin_Entity_4_10->AddComponent<Collider>();
		Collider* colCoin_4_11 = Stage1_Foreground_Coin_Entity_4_11->AddComponent<Collider>();
		Collider* colCoin_4_12 = Stage1_Foreground_Coin_Entity_4_12->AddComponent<Collider>();
		Collider* colCoin_4_13 = Stage1_Foreground_Coin_Entity_4_13->AddComponent<Collider>();
		Collider* colYoshiCoin_1 = Stage1_Foreground_YoshiCoin_Entity1->AddComponent<Collider>();
		Collider* colYoshiCoin_2 = Stage1_Foreground_YoshiCoin_Entity2->AddComponent<Collider>();
		Collider* colYoshiCoin_3 = Stage1_Foreground_YoshiCoin_Entity3->AddComponent<Collider>();
		Collider* colYoshiCoin_4 = Stage1_Foreground_YoshiCoin_Entity4->AddComponent<Collider>();
		Collider* colUpgradeBox_1 = Stage1_Foreground_UpgradeBox_Entity1->AddComponent<Collider>();
		Collider* colUpgradeBox_2 = Stage1_Foreground_UpgradeBox_Entity2->AddComponent<Collider>();
		Collider* colUpgradeBox_3 = Stage1_Foreground_UpgradeBox_Entity3->AddComponent<Collider>();
		Collider* colUpgradeBox_4 = Stage1_Foreground_UpgradeBox_Entity4->AddComponent<Collider>();
		Collider* colCheckpoint_Flag = Stage1_Foreground_Checkpoint_Flag_Entity->AddComponent<Collider>();
		Collider* colCheckpoint_Finish_Flag = Stage1_Foreground_Checkpoint_Finish_Flag_Entity->AddComponent<Collider>();

		colRandomBox_1->SetSize(Vector2(64.0f, 64.0f));
		colRandomBox_2->SetSize(Vector2(64.0f, 64.0f));
		colRandomBox_3->SetSize(Vector2(64.0f, 64.0f));
		colRandomBox_4->SetSize(Vector2(64.0f, 64.0f));
		colRandomBox_5->SetSize(Vector2(64.0f, 64.0f));
		colRandomBox_6->SetSize(Vector2(64.0f, 64.0f));
		colRandomBox_7->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_1->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_2->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_3->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_4->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_5->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_6->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_7->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_8->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_9->SetSize(Vector2(64.0f, 64.0f));
		colSpinBox_10->SetSize(Vector2(64.0f, 64.0f));
		colCoin_1_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_1_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_1_3->SetSize(Vector2(64.0f, 64.0f));
		colCoin_1_4->SetSize(Vector2(64.0f, 64.0f));
		colCoin_2_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_2_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_2_3->SetSize(Vector2(64.0f, 64.0f));
		colCoin_3_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_3_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_3_3->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_1->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_2->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_3->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_4->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_5->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_6->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_7->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_8->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_9->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_10->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_11->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_12->SetSize(Vector2(64.0f, 64.0f));
		colCoin_4_13->SetSize(Vector2(64.0f, 64.0f));
		colYoshiCoin_1->SetSize(Vector2(64.0f, 100.0f));
		colYoshiCoin_2->SetSize(Vector2(64.0f, 100.0f));
		colYoshiCoin_3->SetSize(Vector2(64.0f, 100.0f));
		colYoshiCoin_4->SetSize(Vector2(64.0f, 100.0f));
		colUpgradeBox_1->SetSize(Vector2(64.0f, 64.0f));
		colUpgradeBox_2->SetSize(Vector2(64.0f, 64.0f));
		colUpgradeBox_3->SetSize(Vector2(64.0f, 64.0f));
		colUpgradeBox_4->SetSize(Vector2(64.0f, 64.0f));
		colCheckpoint_Flag->SetSize(Vector2(32.0f, 32.0f));
		colCheckpoint_Finish_Flag->SetSize(Vector2(96.0f, 32.0f));
		#pragma endregion

		#pragma region Player Layer
		Texture* Mario_Left_Image = Resources::Load<Texture>(L"Direction_Left"
			, L"..\\Assets\\Mario\\Mario_Left.bmp");
		Texture* Mario_Right_Image = Resources::Load<Texture>(L"Direction_Right"
			, L"..\\Assets\\Mario\\Mario_Right.bmp");

		Player* player = object::Instantiate<Player>(eLayerType::Player);
		Transform* trPlayer = player->GetComponent<Transform>();

		trPlayer->SetPosition(Vector2(600.0f, 1248.0f));

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
		atPlayer->CreateAnimation(L"Animation_Fire_Idle_Left", Mario_Left_Image, Vector2(0.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Run_Left", Mario_Left_Image, Vector2(48.0f, 48.0f), Vector2(48.0f, 96.0f), 3, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Jump_Left", Mario_Left_Image, Vector2(192.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Fall_Left", Mario_Left_Image, Vector2(240.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_LookUp_Left", Mario_Left_Image, Vector2(288.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Duck_Left", Mario_Left_Image, Vector2(336.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Kick_Left", Mario_Left_Image, Vector2(384.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Swim_Left", Mario_Left_Image, Vector2(432.0f, 48.0f), Vector2(48.0f, 96.0f), 3, Vector2(0.0f, -40.0f), 0.2f);
		
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
		atPlayer->CreateAnimation(L"Animation_Fire_Idle_Right", Mario_Right_Image, Vector2(0.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Run_Right", Mario_Right_Image, Vector2(48.0f, 48.0f), Vector2(48.0f, 96.0f), 3, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Jump_Right", Mario_Right_Image, Vector2(192.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Fall_Right", Mario_Right_Image, Vector2(240.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_LookUp_Right", Mario_Right_Image, Vector2(288.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Duck_Right", Mario_Right_Image, Vector2(336.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Kick_Right", Mario_Right_Image, Vector2(384.0f, 48.0f), Vector2(48.0f, 96.0f), 1, Vector2(0.0f, -40.0f), 0.2f);
		atPlayer->CreateAnimation(L"Animation_Fire_Swim_Right", Mario_Right_Image, Vector2(432.0f, 48.0f), Vector2(48.0f, 96.0f), 3, Vector2(0.0f, -40.0f), 0.2f);

		atPlayer->SetScale(Vector2(4.0f, 4.0f));
		atPlayer->PlayAnimation(L"Animation_Small_Idle_Right", true);
		atPlayer->SetAffectedCamera(true);

		Collider* colPlayer = player->AddComponent<Collider>();
		colPlayer->SetSize(Vector2(64.0f, 80.0f)); // Small Mario
		//colPlayer->SetSize(Vector2(64.0f, 112.0f)); // Super, Fire Mario
		player->AddComponent<Rigidbody>();
		#pragma endregion

		#pragma region Enemy Layer
		Texture* Koopa_Red_Left_Image = Resources::Load<Texture>(L"Koopa_Red_Left"
			, L"..\\Assets\\Image\\Enemies\\KoopaTroopa_Red_Left.bmp");
		Texture* Koopa_Red_Dead_Image = Resources::Load<Texture>(L"Koopa_Red_Dead"
			, L"..\\Assets\\Image\\Enemies\\KoopaTroopa_Red_Dead.bmp");
		Texture* CharginChuck_Basic_Left_Image = Resources::Load<Texture>(L"CharginChuck_Basic_Left"
			, L"..\\Assets\\Image\\Enemies\\CharginChuck_Basic_Left.bmp");
		Texture* CharginChuck_Basic_Middle_Image = Resources::Load<Texture>(L"CharginChuck_Basic_Middle"
			, L"..\\Assets\\Image\\Enemies\\CharginChuck_Basic_Middle.bmp");
		Texture* CharginChuck_Basic_Right_Image = Resources::Load<Texture>(L"CharginChuck_Basic_Right"
			, L"..\\Assets\\Image\\Enemies\\CharginChuck_Basic_Right.bmp");
		Texture* CharginChuck_Basic_Hit_Image = Resources::Load<Texture>(L"CharginChuck_Basic_Hit"
			, L"..\\Assets\\Image\\Enemies\\CharginChuck_Basic_Hit.bmp");
		Texture* Piranha_Jump_Image = Resources::Load<Texture>(L"Piranha_Jump"
			, L"..\\Assets\\Image\\Enemies\\Piranha_Jump.bmp");

		RedKoopa* Stage1_Monster_RedKoopa_Entity_1_1 = object::Instantiate<RedKoopa>(eLayerType::Monster);
		RedKoopa* Stage1_Monster_RedKoopa_Entity_1_2 = object::Instantiate<RedKoopa>(eLayerType::Monster);
		RedKoopa* Stage1_Monster_RedKoopa_Entity_1_3 = object::Instantiate<RedKoopa>(eLayerType::Monster);
		RedKoopa* Stage1_Monster_RedKoopa_Entity_1_4 = object::Instantiate<RedKoopa>(eLayerType::Monster);
		RedKoopa* Stage1_Monster_RedKoopa_Entity_1_5 = object::Instantiate<RedKoopa>(eLayerType::Monster);
		RedKoopa* Stage1_Monster_RedKoopa_Entity_1_6 = object::Instantiate<RedKoopa>(eLayerType::Monster);
		RedKoopa* Stage1_Monster_RedKoopa_Entity_1_7 = object::Instantiate<RedKoopa>(eLayerType::Monster);
		RedKoopa* Stage1_Monster_RedKoopa_Entity_1_8 = object::Instantiate<RedKoopa>(eLayerType::Monster);
		CharginChuck* Stage1_Monster_CharginChuck_Entity1 = object::Instantiate<CharginChuck>(eLayerType::Monster);
		CharginChuck* Stage1_Monster_CharginChuck_Entity2 = object::Instantiate<CharginChuck>(eLayerType::Monster);
		Piranha* Stage1_Monster_Piranha_Entity = object::Instantiate<Piranha>(eLayerType::Monster);

		Transform* trRedKoopa_1_1 = Stage1_Monster_RedKoopa_Entity_1_1->GetComponent<Transform>();
		Transform* trRedKoopa_1_2 = Stage1_Monster_RedKoopa_Entity_1_2->GetComponent<Transform>();
		Transform* trRedKoopa_1_3 = Stage1_Monster_RedKoopa_Entity_1_3->GetComponent<Transform>();
		Transform* trRedKoopa_1_4 = Stage1_Monster_RedKoopa_Entity_1_4->GetComponent<Transform>();
		Transform* trRedKoopa_1_5 = Stage1_Monster_RedKoopa_Entity_1_5->GetComponent<Transform>();
		Transform* trRedKoopa_1_6 = Stage1_Monster_RedKoopa_Entity_1_6->GetComponent<Transform>();
		Transform* trRedKoopa_1_7 = Stage1_Monster_RedKoopa_Entity_1_7->GetComponent<Transform>();
		Transform* trRedKoopa_1_8 = Stage1_Monster_RedKoopa_Entity_1_8->GetComponent<Transform>();
		Transform* trCharginChuck_1 = Stage1_Monster_CharginChuck_Entity1->GetComponent<Transform>();
		Transform* trCharginChuck_2 = Stage1_Monster_CharginChuck_Entity2->GetComponent<Transform>();
		Transform* trPiranha = Stage1_Monster_Piranha_Entity->GetComponent<Transform>();

		trRedKoopa_1_1->SetPosition(Vector2(1700.0f, 486.0f));
		trRedKoopa_1_2->SetPosition(Vector2(1784.0f, 486.0f));
		trRedKoopa_1_3->SetPosition(Vector2(1868.0f, 486.0f));
		trRedKoopa_1_4->SetPosition(Vector2(1952.0f, 486.0f));
		trRedKoopa_1_5->SetPosition(Vector2(2036.0f, 486.0f));
		trRedKoopa_1_6->SetPosition(Vector2(2120.0f, 486.0f));
		trRedKoopa_1_7->SetPosition(Vector2(2204.0f, 486.0f));
		trRedKoopa_1_8->SetPosition(Vector2(2288.0f, 486.0f));
		trCharginChuck_1->SetPosition(Vector2(9040.0f, 420.0f));
		trCharginChuck_2->SetPosition(Vector2(19100.0f, 676.0f));
		trPiranha->SetPosition(Vector2(17520.0f, 600.0f));

		Animator* atRedKoopa_1_1 = Stage1_Monster_RedKoopa_Entity_1_1->AddComponent<Animator>();
		Animator* atRedKoopa_1_2 = Stage1_Monster_RedKoopa_Entity_1_2->AddComponent<Animator>();
		Animator* atRedKoopa_1_3 = Stage1_Monster_RedKoopa_Entity_1_3->AddComponent<Animator>();
		Animator* atRedKoopa_1_4 = Stage1_Monster_RedKoopa_Entity_1_4->AddComponent<Animator>();
		Animator* atRedKoopa_1_5 = Stage1_Monster_RedKoopa_Entity_1_5->AddComponent<Animator>();
		Animator* atRedKoopa_1_6 = Stage1_Monster_RedKoopa_Entity_1_6->AddComponent<Animator>();
		Animator* atRedKoopa_1_7 = Stage1_Monster_RedKoopa_Entity_1_7->AddComponent<Animator>();
		Animator* atRedKoopa_1_8 = Stage1_Monster_RedKoopa_Entity_1_8->AddComponent<Animator>();
		Animator* atCharginChuck_1 = Stage1_Monster_CharginChuck_Entity1->AddComponent<Animator>();
		Animator* atCharginChuck_2 = Stage1_Monster_CharginChuck_Entity2->AddComponent<Animator>();
		Animator* atPiranha = Stage1_Monster_Piranha_Entity->AddComponent<Animator>();

		atRedKoopa_1_1->CreateAnimation(L"Monster_Animation_RedKoopa", Koopa_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 27.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedKoopa_1_2->CreateAnimation(L"Monster_Animation_RedKoopa", Koopa_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 27.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedKoopa_1_3->CreateAnimation(L"Monster_Animation_RedKoopa", Koopa_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 27.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedKoopa_1_4->CreateAnimation(L"Monster_Animation_RedKoopa", Koopa_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 27.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedKoopa_1_5->CreateAnimation(L"Monster_Animation_RedKoopa", Koopa_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 27.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedKoopa_1_6->CreateAnimation(L"Monster_Animation_RedKoopa", Koopa_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 27.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedKoopa_1_7->CreateAnimation(L"Monster_Animation_RedKoopa", Koopa_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 27.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedKoopa_1_8->CreateAnimation(L"Monster_Animation_RedKoopa", Koopa_Red_Left_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 27.0f), 2, Vector2(0.0f, 0.0f), 0.4f);
		atRedKoopa_1_1->CreateAnimation(L"Monster_Animation_RedKoopa_Dead", Koopa_Red_Dead_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRedKoopa_1_2->CreateAnimation(L"Monster_Animation_RedKoopa_Dead", Koopa_Red_Dead_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRedKoopa_1_3->CreateAnimation(L"Monster_Animation_RedKoopa_Dead", Koopa_Red_Dead_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRedKoopa_1_4->CreateAnimation(L"Monster_Animation_RedKoopa_Dead", Koopa_Red_Dead_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRedKoopa_1_5->CreateAnimation(L"Monster_Animation_RedKoopa_Dead", Koopa_Red_Dead_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRedKoopa_1_6->CreateAnimation(L"Monster_Animation_RedKoopa_Dead", Koopa_Red_Dead_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRedKoopa_1_7->CreateAnimation(L"Monster_Animation_RedKoopa_Dead", Koopa_Red_Dead_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atRedKoopa_1_8->CreateAnimation(L"Monster_Animation_RedKoopa_Dead", Koopa_Red_Dead_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		atCharginChuck_1->CreateAnimation(L"Monster_Animation_CharginChuck_Left", CharginChuck_Basic_Left_Image, Vector2(0.0f, 0.0f), Vector2(28.0f, 26.0f), 2, Vector2(0.0f, 0.0f), 0.1f);
		atCharginChuck_2->CreateAnimation(L"Monster_Animation_CharginChuck_Left", CharginChuck_Basic_Left_Image, Vector2(0.0f, 0.0f), Vector2(28.0f, 26.0f), 2, Vector2(0.0f, 0.0f), 0.1f);
		atCharginChuck_1->CreateAnimation(L"Monster_Animation_CharginChuck_Middle", CharginChuck_Basic_Middle_Image, Vector2(0.0f, 0.0f), Vector2(28.0f, 26.0f), 12, Vector2(0.0f, 0.0f), 0.2f);
		atCharginChuck_2->CreateAnimation(L"Monster_Animation_CharginChuck_Middle", CharginChuck_Basic_Middle_Image, Vector2(0.0f, 0.0f), Vector2(28.0f, 26.0f), 12, Vector2(0.0f, 0.0f), 0.2f);
		atCharginChuck_1->CreateAnimation(L"Monster_Animation_CharginChuck_Right", CharginChuck_Basic_Right_Image, Vector2(0.0f, 0.0f), Vector2(28.0f, 26.0f), 2, Vector2(0.0f, 0.0f), 0.1f);
		atCharginChuck_2->CreateAnimation(L"Monster_Animation_CharginChuck_Right", CharginChuck_Basic_Right_Image, Vector2(0.0f, 0.0f), Vector2(28.0f, 26.0f), 2, Vector2(0.0f, 0.0f), 0.1f);
		atCharginChuck_1->CreateAnimation(L"Monster_Animation_CharginChuck_Hit", CharginChuck_Basic_Hit_Image, Vector2(0.0f, 0.0f), Vector2(28.0f, 26.0f), 9, Vector2(0.0f, 0.0f), 0.2f);
		atCharginChuck_2->CreateAnimation(L"Monster_Animation_CharginChuck_Hit", CharginChuck_Basic_Hit_Image, Vector2(0.0f, 0.0f), Vector2(28.0f, 26.0f), 9, Vector2(0.0f, 0.0f), 0.2f);
		atPiranha->CreateAnimation(L"Monster_Animation_Piranha", Piranha_Jump_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 21.0f), 2, Vector2(0.0f, 0.0f), 0.2f);

		atRedKoopa_1_1->SetScale(Vector2(4.0f, 4.0f));
		atRedKoopa_1_2->SetScale(Vector2(4.0f, 4.0f));
		atRedKoopa_1_3->SetScale(Vector2(4.0f, 4.0f));
		atRedKoopa_1_4->SetScale(Vector2(4.0f, 4.0f));
		atRedKoopa_1_5->SetScale(Vector2(4.0f, 4.0f));
		atRedKoopa_1_6->SetScale(Vector2(4.0f, 4.0f));
		atRedKoopa_1_7->SetScale(Vector2(4.0f, 4.0f));
		atRedKoopa_1_8->SetScale(Vector2(4.0f, 4.0f));
		atCharginChuck_1->SetScale(Vector2(4.0f, 4.0f));
		atCharginChuck_2->SetScale(Vector2(4.0f, 4.0f));
		atPiranha->SetScale(Vector2(4.0f, 4.0f));

		atRedKoopa_1_1->PlayAnimation(L"Monster_Animation_RedKoopa", true);
		atRedKoopa_1_2->PlayAnimation(L"Monster_Animation_RedKoopa", true);
		atRedKoopa_1_3->PlayAnimation(L"Monster_Animation_RedKoopa", true);
		atRedKoopa_1_4->PlayAnimation(L"Monster_Animation_RedKoopa", true);
		atRedKoopa_1_5->PlayAnimation(L"Monster_Animation_RedKoopa", true);
		atRedKoopa_1_6->PlayAnimation(L"Monster_Animation_RedKoopa", true);
		atRedKoopa_1_7->PlayAnimation(L"Monster_Animation_RedKoopa", true);
		atRedKoopa_1_8->PlayAnimation(L"Monster_Animation_RedKoopa", true);
		//atCharginChuck_1->PlayAnimation(L"Monster_Animation_CharginChuck_Left", true);
		//atCharginChuck_2->PlayAnimation(L"Monster_Animation_CharginChuck_Left", true);
		atPiranha->PlayAnimation(L"Monster_Animation_Piranha", true);

		atRedKoopa_1_1->SetAffectedCamera(false);
		atRedKoopa_1_2->SetAffectedCamera(false);
		atRedKoopa_1_3->SetAffectedCamera(false);
		atRedKoopa_1_4->SetAffectedCamera(false);
		atRedKoopa_1_5->SetAffectedCamera(false);
		atRedKoopa_1_6->SetAffectedCamera(false);
		atRedKoopa_1_7->SetAffectedCamera(false);
		atRedKoopa_1_8->SetAffectedCamera(false);
		atCharginChuck_1->SetAffectedCamera(false);
		atCharginChuck_2->SetAffectedCamera(false);
		atPiranha->SetAffectedCamera(false);

		Collider* colRedKoopa_1_1 = Stage1_Monster_RedKoopa_Entity_1_1->AddComponent<Collider>();
		Collider* colRedKoopa_1_2 = Stage1_Monster_RedKoopa_Entity_1_2->AddComponent<Collider>();
		Collider* colRedKoopa_1_3 = Stage1_Monster_RedKoopa_Entity_1_3->AddComponent<Collider>();
		Collider* colRedKoopa_1_4 = Stage1_Monster_RedKoopa_Entity_1_4->AddComponent<Collider>();
		Collider* colRedKoopa_1_5 = Stage1_Monster_RedKoopa_Entity_1_5->AddComponent<Collider>();
		Collider* colRedKoopa_1_6 = Stage1_Monster_RedKoopa_Entity_1_6->AddComponent<Collider>();
		Collider* colRedKoopa_1_7 = Stage1_Monster_RedKoopa_Entity_1_7->AddComponent<Collider>();
		Collider* colRedKoopa_1_8 = Stage1_Monster_RedKoopa_Entity_1_8->AddComponent<Collider>();
		Collider* colCharginChuck_1 = Stage1_Monster_CharginChuck_Entity1->AddComponent<Collider>();
		Collider* colCharginChuck_2 = Stage1_Monster_CharginChuck_Entity2->AddComponent<Collider>();
		Collider* colPiranha = Stage1_Monster_Piranha_Entity->AddComponent<Collider>();

		colRedKoopa_1_1->SetSize(Vector2(64.0f, 108.0f));
		colRedKoopa_1_2->SetSize(Vector2(64.0f, 108.0f));
		colRedKoopa_1_3->SetSize(Vector2(64.0f, 108.0f));
		colRedKoopa_1_4->SetSize(Vector2(64.0f, 108.0f));
		colRedKoopa_1_5->SetSize(Vector2(64.0f, 108.0f));
		colRedKoopa_1_6->SetSize(Vector2(64.0f, 108.0f));
		colRedKoopa_1_7->SetSize(Vector2(64.0f, 108.0f));
		colRedKoopa_1_8->SetSize(Vector2(64.0f, 108.0f));
		colCharginChuck_1->SetSize(Vector2(112.0f, 104.0f));
		colCharginChuck_2->SetSize(Vector2(112.0f, 104.0f));
		colPiranha->SetSize(Vector2(64.0f, 84.0f));
		#pragma endregion

		#pragma region Item Layer
		// Animated Image
		
		// Static Image
		Texture* Stage1_Item_PSwitch_Off_Image = Resources::Load<Texture>(L"Stage1_PSwitch_Off"
			, L"..\\Assets\\Image\\ForegroundTiles\\PSwitch_Off.bmp");
		Texture* Stage1_Item_PSwitch_On_Image = Resources::Load<Texture>(L"Stage1_PSwitch_On"
			, L"..\\Assets\\Image\\ForegroundTiles\\PSwitch_On.bmp");
		
		ItemPSwitch* Stage1_Item_PSwitch_Entity = object::Instantiate<ItemPSwitch>(eLayerType::Item);
		
		Transform* trPSwitch = Stage1_Item_PSwitch_Entity->GetComponent<Transform>();
		
		trPSwitch->SetPosition(Vector2(18144.0f, 383.0f));
		
		Animator* atPSwitch = Stage1_Item_PSwitch_Entity->AddComponent<Animator>();
		
		atPSwitch->CreateAnimation(L"Item_Animation_PSwitch_Off", Stage1_Item_PSwitch_Off_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f), 1);
		
		atPSwitch->CreateAnimation(L"Item_Animation_PSwitch_On", Stage1_Item_PSwitch_On_Image, Vector2(0.0f, 0.0f), Vector2(16.0f, 8.0f), 1, Vector2(0.0f, 16.0f));
		
		atPSwitch->SetScale(Vector2(4.0f, 4.0f));

		atPSwitch->PlayAnimation(L"Item_Animation_PSwitch_Off", true);

		atPSwitch->SetAffectedCamera(false);

		Collider* colPSwitch = Stage1_Item_PSwitch_Entity->AddComponent<Collider>();

		colPSwitch->SetSize(Vector2(64.0f, 64.0f));
		//Stage1_Item_PSwitch_Entity->AddComponent<Rigidbody>();
		#pragma endregion

		#pragma region Collision Manager
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Environment, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Foreground, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Item, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Item, eLayerType::Monster, true);
		//CollisionManager::CollisionLayerCheck(eLayerType::Item, eLayerType::Floor, true);
		#pragma endregion

		Camera::SetTarget(player);
		Camera::SetOffset(Vector2(0.0f, -218.0f));
	}

	void Stage1::Update()
	{
		Scene::Update();
	}

	void Stage1::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}

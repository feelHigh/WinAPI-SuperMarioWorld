#pragma once
#include "Scene.h"
#include "ntoLayerHeaders.h"
#include "ntoResources.h"
#include "ntoSound.h"

namespace nto
{
	class StageWorldMap : public Scene
	{
	public:
		StageWorldMap();
		virtual ~StageWorldMap();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		BackGround* WorldMap_Border_Entity;
		BackGround* WorldMap_World_1_Entity;
		StageDirector* player;
		StagePlate* StagePlate1_Entity;
		StagePlate* StagePlate2_Entity;
		StagePlate* StagePlate3_Entity;
		StagePlate* StagePlate4_Entity;

		Sound* bgSound;
	};
}

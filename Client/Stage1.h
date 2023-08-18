#pragma once
#include "Scene.h"
#include "ntoLayerHeaders.h"

namespace nto
{
	class Stage1 : public Scene
	{
	public:
		Stage1();
		virtual ~Stage1();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		bool pSwitchState;
		ItemPSwitch* Stage1_Item_PSwitch_Entity;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_1;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_2;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_3;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_4;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_5;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_6;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_7;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_8;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_9;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_10;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_11;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_12;
		ForegroundCoin* Stage1_Foreground_Coin_Entity_4_13;
	};
}

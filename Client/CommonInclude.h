#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <string>
#include <filesystem>

#include "framework.h"
#include "CustomMath.h"

#pragma comment(lib, "Msimg32.lib")

namespace nto::enums
{
	enum class eLayerType
	{
		Background,
		Floor,
		Player,
		Monster,
		Effect,
		UI,
		End,
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animation,
		Animator,
		End,
	};
}

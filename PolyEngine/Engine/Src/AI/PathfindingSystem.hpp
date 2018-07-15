#pragma once

#include <functional>
#include <Core.hpp>

namespace Poly
{
	class World;
	class Entity;

	namespace PathfindingSystem
	{
		ENGINE_DLLEXPORT Dynarray<Vector> QueryPathToPosition(World* world, Entity* entity, std::function<Vector(World*, Entity*)> entityPositionQuery);
		ENGINE_DLLEXPORT void UpdatePhase(World* world);
	};
}

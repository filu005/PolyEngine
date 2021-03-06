#pragma once

#include "ECS/ComponentBase.hpp"
#include "Movement/MovementSystem.hpp"

namespace Poly {

	class ENGINE_DLLEXPORT FreeFloatMovementComponent : public ComponentBase
	{
		friend void MovementSystem::MovementUpdatePhase(World*);
	public:
		FreeFloatMovementComponent(float movementSpeed = 1.0f, float rotationSpeed = 1.0f);

		float GetMovementSpeed() const { return MovementSpeed; }
		void SetMovementSpeed(float value) { MovementSpeed = value; }
		float GetAngularVelocity() const { return RotationSpeed; }

	private:
		float MovementSpeed = 1.0f;
		float RotationSpeed = 1.0f;
	};

	REGISTER_COMPONENT(ComponentsIDGroup, FreeFloatMovementComponent)
}
#include "EnginePCH.hpp"

#include "ECS/Entity.hpp"
#include "ECS/EntityTransform.hpp"

using namespace Poly;

Entity::Entity(World* world, Entity* parent)
	: EntityID(UniqueID::Generate()), Transform(this), EntityWorld(world), ComponentPosessionFlags(0)
{
	memset(Components, 0, sizeof(ComponentBase*) * MAX_COMPONENTS_COUNT);

	if (parent)
		SetParent(parent);
}


Poly::Entity::~Entity()
{
	if (Parent != nullptr)
	{
		Parent->Children.Remove(this);
	}
}

void Poly::Entity::SetParent(Entity* parent)
{
	ASSERTE(parent, "New parent cannot be null");
	ASSERTE(parent != this, "Cannot parent myself!");
	HEAVY_ASSERTE(!ContainsChildRecursive(parent), "Detected parenting cycle!");

	if (Parent)
	{
		Parent->Children.Remove(this);
		Parent = nullptr;
		Transform.UpdateParentTransform();
	}

	Parent = parent;
	Parent->Children.PushBack(this);
	Transform.UpdateParentTransform();
}

bool Poly::Entity::ContainsChildRecursive(Entity* child) const
{
	if (Children.Contains(child))
		return true;

	for (Entity* myChild : Children)
		if (myChild->ContainsChildRecursive(child))
			return true;

	return false;
}

bool Entity::HasComponent(size_t ID) const
{
	HEAVY_ASSERTE(ID < MAX_COMPONENTS_COUNT, "Invalid component ID - greater than MAX_COMPONENTS_COUNT.");
	return ComponentPosessionFlags[ID];
}

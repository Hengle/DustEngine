#pragma once

#include <UECS/Entity.h>
#include <vector>

namespace Ubpa::DustEngine {
	struct Parent {
		UECS::Entity value{ UECS::Entity::Invalid() };
	};
}

#include "details/Parent_AutoRefl.inl"

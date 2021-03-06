#pragma once

#include <UECS/World.h>
#include <ULuaPP/ULuaPP.h>

namespace Ubpa::DustEngine {
	class LuaSystem : public UECS::System {
	public:
		using System::System;

		static void RegisterSystem(UECS::World* world, std::string name, sol::function onUpdate);

		// World, SingletonsView, Entity, size_t index, CmptsView
		static const UECS::SystemFunc* RegisterEntityJob(
			UECS::Schedule*,
			sol::function systemFunc,
			std::string name,
			UECS::ArchetypeFilter,
			UECS::CmptLocator,
			UECS::SingletonLocator
		);

		// World, SingletonsView, ChunkView
		static const UECS::SystemFunc* RegisterChunkJob(
			UECS::Schedule*,
			sol::function systemFunc,
			std::string name,
			UECS::ArchetypeFilter,
			UECS::SingletonLocator
		);

		// World, SingletonsView
		static const UECS::SystemFunc* RegisterJob(
			UECS::Schedule*,
			sol::function systemFunc,
			std::string name,
			UECS::SingletonLocator
		);

	private:
		LuaSystem(UECS::World* world, std::string name, sol::function onUpdate);

		virtual void OnUpdate(UECS::Schedule& schedule) override;

		sol::bytecode onUpdate;
	};
}

#include "detail/UECS_AutoRefl/System_AutoRefl.inl"
#include "detail/LuaSystem_AutoRefl.inl"

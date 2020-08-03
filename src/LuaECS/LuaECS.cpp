#include <DustEngine/LuaECS/LuaECS.h>

#include "ECSRefl/ECSRefl.h"

void Ubpa::DustEngine::LuaECS::Init(lua_State* L) {
	ULuaPP::Register<UECS::AccessMode>(L);
	ULuaPP::Register<UECS::ChunkView>(L);
	ULuaPP::Register<UECS::CmptPtr>(L);
	ULuaPP::Register<UECS::CmptsView>(L);
	ULuaPP::Register<UECS::CmptType>(L);
	ULuaPP::Register<UECS::EntityFilter>(L);
	ULuaPP::Register<UECS::EntityLocator>(L);
	ULuaPP::Register<UECS::EntityMngr>(L);
	ULuaPP::Register<UECS::EntityQuery>(L);
	ULuaPP::Register<UECS::Entity>(L);
	ULuaPP::Register<UECS::RTDCmptTraits>(L);
	ULuaPP::Register<UECS::SystemMngr>(L);
	ULuaPP::Register<UECS::World>(L);
}
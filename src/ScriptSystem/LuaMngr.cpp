#include <DustEngine/ScriptSystem/LuaMngr.h>

#include <UECS/CmptType.h>

#include "InitUECS.h"
#include "InitUGraphviz.h"
#include "LuaArray.h"
#include "LuaBuffer.h"
#include "LuaMemory.h"
#include "LuaSystem.h"

#include <mutex>

using namespace Ubpa::DustEngine;

struct LuaMngr::Impl {
	std::mutex m;
	std::set<lua_State*> busyLuas;
	std::vector<lua_State*> freeLuas;
	lua_State* mainLua;

	static lua_State* Construct();
	static void Destruct(lua_State* L);
};

void LuaMngr::Init() {
	pImpl = new LuaMngr::Impl;
	pImpl->mainLua = Impl::Construct();
}

lua_State* LuaMngr::Main() const {
	return pImpl->mainLua;
}

void LuaMngr::Reserve(size_t n) {
	size_t num = pImpl->busyLuas.size() + pImpl->freeLuas.size();
	if (num < n) {
		for (size_t i = 0; i < n - num; i++) {
			auto L = Impl::Construct();
			pImpl->freeLuas.push_back(L);
		}
	}
}

lua_State* LuaMngr::Request() {
	std::lock_guard<std::mutex> guard(pImpl->m);

	if (pImpl->freeLuas.empty()) {
		auto L = Impl::Construct();
		pImpl->freeLuas.push_back(L);
	}

	auto L = pImpl->freeLuas.back();
	pImpl->freeLuas.pop_back();
	pImpl->busyLuas.insert(L);

	return L;
}

void LuaMngr::Recycle(lua_State* L) {
	std::lock_guard<std::mutex> guard(pImpl->m);

	assert(pImpl->busyLuas.find(L) != pImpl->busyLuas.end());

	pImpl->busyLuas.erase(L);
	pImpl->freeLuas.push_back(L);
}

void LuaMngr::Clear() {
	assert(pImpl->busyLuas.empty());
	for (auto L : pImpl->freeLuas)
		Impl::Destruct(L);
	Impl::Destruct(pImpl->mainLua);
	delete pImpl;
}

// ================================

class LuaArray_CmptType : public LuaArray<Ubpa::UECS::CmptType>{};
template<>
struct Ubpa::USRefl::TypeInfo<LuaArray_CmptType>
	: Ubpa::USRefl::TypeInfoBase<LuaArray_CmptType, Base<LuaArray<Ubpa::UECS::CmptType>>>
{
	static constexpr AttrList attrs = {};

	static constexpr FieldList fields = {
	};
};

lua_State* LuaMngr::Impl::Construct() {
	lua_State* L = luaL_newstate(); /* opens Lua */
	luaL_openlibs(L); /* opens the standard libraries */
	detail::InitUECS(L);
	detail::InitUGraphviz(L);
	ULuaPP::Register<LuaArray_CmptType>(L);
	ULuaPP::Register<LuaBuffer>(L);
	ULuaPP::Register<LuaMemory>(L);
	ULuaPP::Register<LuaSystem>(L);
	return L;
}

void LuaMngr::Impl::Destruct(lua_State* L) {
	lua_close(L);
}

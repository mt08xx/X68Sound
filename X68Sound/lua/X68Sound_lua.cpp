#include "X68Sound_lua.h"

#include <string>

#define X68SOUND_LUA_FILE "X68Sound.lua"
#define FILENAME_SIZE_MAX (128)
int dump_flag = 0;
char dump_filename[FILENAME_SIZE_MAX] = "DumpWav.bin";

int X68Sound_lua_init(void)
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	if (luaL_loadfile(L, X68SOUND_LUA_FILE) != LUA_OK)
	{
		lua_close(L);
		return -1;
	}
	if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
		//std::cout << lua_tostring(L, -1);
		lua_close(L);
		return -1;
	}

	lua_getglobal(L, "DUMP_FLAG");
	if (lua_type(L, -1) == LUA_TNUMBER)
	{
		dump_flag = lua_tonumber(L, -1);
	}
	lua_getglobal(L, "DUMP_FILE");
	if (lua_type(L, -1) == LUA_TSTRING)
	{
		const char *p = lua_tostring(L, -1);
		strncpy(dump_filename, p, FILENAME_SIZE_MAX);
	}

	lua_close(L);
	return 0;
}
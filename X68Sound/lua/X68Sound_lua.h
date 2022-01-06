#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"


extern int dump_flag;
extern char dump_filename[];

extern "C" {
	int X68Sound_lua_init(void);
}
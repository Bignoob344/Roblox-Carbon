#include "_hooks.h"
#include "globals.h"

BOOL dSetSysCursorPos(int X, int Y) {
	if (ShowMenu)
		return TRUE;

	return SetSysCursorPos(X, Y);
}
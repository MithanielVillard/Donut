#include "screen.h"
#include "settings.h"


int main(int argc, char** argv)
{
	Settings s(argc, argv);
	int width = s.GetScreenWidth();
	int height = s.GetScreenHeight();
	if (width == 0 || height == 0)
		return -1;

	Screen screen(s);
	screen.Clear();
	screen.HomeCursor();
	screen.SetCursorVisibility(false);
	screen.Display();

}

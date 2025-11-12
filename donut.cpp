#include "screen.h"
#include "settings.h"


int main(int argc, char** argv)
{
	Settings s(argc, argv);

	Screen screen(s);
	screen.Clear();
	screen.HomeCursor();
	screen.SetCursorVisibility(false);
	screen.Display();

}

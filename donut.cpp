#include "mesh.h"
#include "screen.h"
#include "settings.h"

int main(int argc, char** argv)
{
	Settings s(argc, argv);

	Mesh mesh(s);
	mesh.GenerateCircle(40);
	//mesh.PrintMesh();

	Screen screen(s);
	screen.SetCursorVisibility(false);

	while (true) 
	{
		screen.Clear();
		screen.HomeCursor();

		mesh.Rotate(Y, 0.0003);

		screen.Display(mesh);
		screen.Display();
	}

	screen.SetCursorVisibility(true);
}

#include "mesh.h"
#include "screen.h"
#include "settings.h"

int main(int argc, char** argv)
{
	Settings s(argc, argv);

	Mesh mesh(s);
	mesh.GenerateTorus(1.9f, 4);
	//mesh.PrintMesh();

	Screen screen(s);
	screen.SetCursorVisibility(false);

	while (true) 
	{
		screen.Clear();
		screen.HomeCursor();

		mesh.Rotate(X, 0.001);

		screen.Display(mesh);
		screen.Display();
	}

	screen.SetCursorVisibility(true);
}

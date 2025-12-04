#include "mesh.h"
#include "screen.h"
#include "settings.h"

int main(int argc, char** argv)
{
	Settings s(argc, argv);

	Mesh mesh(s);
	mesh.GenereateSquare(50.0f);
	//mesh.PrintMesh();

	Screen screen(s);
	screen.Clear();
	screen.HomeCursor();

	mesh.Rotate(Z, 3.1415 / 4.0f);
	screen.Display(mesh);
	screen.Display();

}

#include "mesh.h"
#include "screen.h"
#include "settings.h"

int main(int argc, char** argv)
{
	Settings s(argc, argv);

	Mesh mesh(s);
	mesh.GenereateSquare(30.0f);
	//mesh.PrintMesh();

	Screen screen(s);
	screen.Clear();
	screen.HomeCursor();
	screen.Display(mesh);
	screen.Display();

}

#include "settings.h"
#include <cstring>
#include <iostream>

#define HOME_ESCAPE "\x1B[H"
#define CLEAR_ESCAPE "\x1B[2J"
#define HIDE_ESCAPE "\x1B[?25l"
#define SHOW_ESCAPE "\x1B[?25h"

int main(int argc, char** argv)
{
	std::cout << CLEAR_ESCAPE << HOME_ESCAPE  << HIDE_ESCAPE << std::endl;

	Settings s(argc, argv);
	int width = s.GetScreenWidth();
	int height = s.GetScreenHeight();
	if (width == 0 || height == 0)
		return -1;

	char screen[width * height];
	memset(screen, '.', width * height);

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
			std::cout << screen[w * h];
		std::cout << '\n';
	}

	std::cout << SHOW_ESCAPE;
}

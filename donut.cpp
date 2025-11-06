#include <cstring>
#include <iostream>
#include <string>

#define HOME_ESCAPE "\x1B[H"
#define CLEAR_ESCAPE "\x1B[2J"
#define HIDE_ESCAPE "\x1B[?25l"
#define SHOW_ESCAPE "\x1B[?25h"

int main(int argc, char** argv)
{
	std::cout << CLEAR_ESCAPE << HOME_ESCAPE  << HIDE_ESCAPE << std::endl;

	if (argc < 5) return -1; //not enought argument
	
	int width, height;
	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "-h") == 0)
			height = std::stoi(argv[i+1]);
		else if (strcmp(argv[i], "-w") == 0)
			width = std::stoi(argv[i+1]);
	}

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

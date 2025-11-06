#include <cstring>
#include <iostream>

#define HOME_ESCAPE "\x1B[H"
#define CLEAR_ESCAPE "\x1B[2J"
#define HIDE_ESCAPE "\x1B[?25l"
#define SHOW_ESCAPE "\x1B[?25h"

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 20

int main()
{
	std::cout << CLEAR_ESCAPE << HOME_ESCAPE  << HIDE_ESCAPE << std::endl;

	char screen[SCREEN_WIDTH * SCREEN_HEIGHT];
	memset(screen, '.', SCREEN_WIDTH * SCREEN_HEIGHT);

	for (int h = 0; h < SCREEN_HEIGHT; h++)
	{
		for (int w = 0; w < SCREEN_WIDTH; w++)
			std::cout << screen[w * h];
		std::cout << '\n';
	}
}

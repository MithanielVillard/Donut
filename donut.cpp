#include <iostream>

#define HOME_ESCAPE "\x1B[H"
#define CLEAR_ESCAPE "\x1B[2J"
#define HIDE_ESCAPE "\x1B[?25l"
#define SHOW_ESCAPE "\x1B[?25h"

int main()
{
	std::cout << CLEAR_ESCAPE << HOME_ESCAPE  << HIDE_ESCAPE << "hello world" << std::endl;
	std::cout << SHOW_ESCAPE;
}

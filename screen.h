#ifndef SCREEN_H
#define SCREEN_H

#include "mesh.h"
#include "settings.h"

#define HOME_ESCAPE "\x1B[H"
#define CLEAR_ESCAPE "\x1B[2J"
#define HIDE_ESCAPE "\x1B[?25l"
#define SHOW_ESCAPE "\x1B[?25h"

class Screen
{
public:
	Screen(Settings const& settings);
	~Screen();

	void Display();
	void Display(Mesh& mesh);
	void Clear();
	void SetCursorVisibility(bool visibility);
	void HomeCursor();

private:
	char* m_pData;
	int m_width = 0;
	int m_height = 0;
	int m_screenPosition = 0;
	int m_meshPosition = 0;
};

#endif // SCREEN_H

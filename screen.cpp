#include "screen.h"
#include "settings.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

Screen::Screen(Settings const& s) : m_width(s.GetScreenWidth()), m_height(s.GetScreenHeight())
{
	m_pData = new char[s.GetScreenWidth() * s.GetScreenHeight()];
	memset(m_pData, '.', s.GetScreenWidth() * s.GetScreenHeight());
}

Screen::~Screen()
{
	delete[] m_pData;
}

void Screen::Display()
{
	for (int h = 0; h < m_width; h++)
	{
		for (int w = 0; w < m_width; w++)
			std::cout << m_pData[w * h];
		std::cout << '\n';
	}
}

void Screen::Clear()
{
	std::cout << CLEAR_ESCAPE;
}

void Screen::SetCursorVisibility(bool visibility)
{
	std::cout << (visibility ? SHOW_ESCAPE : HIDE_ESCAPE);
}

void Screen::HomeCursor()
{
	std::cout << HOME_ESCAPE;
}

#include "screen.h"
#include "mesh.h"
#include "settings.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

Screen::Screen(Settings const& s) : 
	m_width(s.GetScreenWidth()), 
	m_height(s.GetScreenHeight()),
	m_screenPosition(s.GetScreenPosition()),
	m_meshPosition(s.GetMeshPosition())
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
	for (int h = 0; h < m_height; h++)
	{
		for (int w = 0; w < m_width; w++)
			std::cout << m_pData[m_width * h + w];
		std::cout << '\n';
	}
}

void Screen::Display(Mesh& mesh)
{
	for (Vertex& vertex : mesh.GetVertices())
	{
		float screenPosX = (vertex.x * m_screenPosition ) / (vertex.z + m_meshPosition) + m_width / 2.0f;
		float screenPosY = (vertex.y * m_screenPosition ) / (vertex.z + m_meshPosition) + m_height / 2.0f;

		int x = static_cast<int>(screenPosX);
		int y = static_cast<int>(screenPosY) / 2.0f;
		m_pData[y * m_width + x] = 'X';
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

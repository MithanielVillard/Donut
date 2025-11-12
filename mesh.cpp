#include "mesh.h"
#include <cmath>
#include <iostream>

Mesh::Mesh(Settings const& settings) : m_meshResolution(settings.GetMesResolution()) {}
	
void Mesh::GenerateCircle(float const radius)
{
	for (float i = 0; i < m_meshResolution; i++)
	{
		for (float j = 0; j < m_meshResolution; j++)
		{
			//Ajouter un vertex dans la liste
			float r = radius / (i / m_meshResolution);
			m_vertices.emplace_back(std::cos(j) * r, std::sin(j) * r, 0);
		}
	}
}

void Mesh::GenerateHalfCircle(float const radius)
{
	for (float i = 0; i < m_meshResolution; i++)
	{
		for (float j = 0; j < m_meshResolution / 2.0f; j++)
		{
			float r = radius / (i / m_meshResolution);
			m_vertices.emplace_back(std::cos(j) * r, std::sin(j) * r, 0);
		}
	}
}

void Mesh::GenerateRectangle(float const width, float const height)
{
	for (float y = 0; y < m_meshResolution; y++)
	{
		for (float x = 0; x < m_meshResolution; x++)
		{
			float h = height / (y / m_meshResolution);
			float w = width / (x / m_meshResolution);
			m_vertices.emplace_back(w, h, 0);
		}
	}
}

void Mesh::GenereateSquare(float const size)
{
	GenerateRectangle(size, size);
}

void Mesh::PrintMesh()
{
	for(Vertex v : m_vertices)
	{
		std::cout << "x: " << v.x << " y: " << v.y << " z: " << v.z << "\n";
	}
}

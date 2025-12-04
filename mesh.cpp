#include "mesh.h"
#include <cmath>
#include <iostream>

Mesh::Mesh(Settings const& settings) : m_meshResolution(settings.GetMesResolution()) {}
	
void Mesh::GenerateCircle(float const radius)
{
    m_vertices.resize(m_meshResolution * m_meshResolution);
	for (float i = 0; i < m_meshResolution; i++)
	{
		for (float j = 0; j < m_meshResolution; j++)
		{
    		float r = (radius * j) / (m_meshResolution);
			m_vertices.emplace_back(std::cos(j) * r, std::sin(j) * r, 1);
		}
	}
}

void Mesh::GenerateHalfCircle(float const radius)
{  
    m_vertices.resize(m_meshResolution * m_meshResolution);
	for (float i = 0; i < m_meshResolution; i++)
	{
		for (float j = 0; j < m_meshResolution / 2.0f ; j++)
		{
    		float r = (radius * j) / (m_meshResolution);
			m_vertices.emplace_back(std::cos(j) * r, std::sin(j) * r, 1);
		}
	}
}

void Mesh::GenerateRectangle(float const width, float const height)
{
    m_vertices.resize(m_meshResolution * m_meshResolution);
    for(int i = 0; i < m_meshResolution; i++)
    {
        for(int j = 0; j < m_meshResolution - 1; j++)
        {
            m_vertices[m_meshResolution * i + j].x = (1.f*i / (m_meshResolution - 1) - 0.5f) * width;
            m_vertices[m_meshResolution * i + j].y = (1.f*j / (m_meshResolution - 1) - 0.5f) * height;
            m_vertices[m_meshResolution * i + j].z = 1.f;
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

void Mesh::Rotate(Axis axis, float angle)
{
	for(Vertex& v : m_vertices)
	{
		v.Rotate(angle, axis);
	}
}

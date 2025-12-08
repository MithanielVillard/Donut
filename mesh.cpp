#include "mesh.h"
#include <cmath>
#include <iostream>

Mesh::Mesh(Settings const& settings) : m_meshResolution(settings.GetMesResolution()) {}
	
void Mesh::GenerateCircle(float const radius)
{
    m_vertices.resize(m_meshResolution * m_meshResolution);
	for (float i = 0; i < m_meshResolution; i++)
	{
    	float r = (radius * i) / (m_meshResolution - 1);
		for (float j = 0; j < m_meshResolution; j++)
		{
			float theta = (M_PI * 2 * j) / (m_meshResolution - 1);
			m_vertices[m_meshResolution * i + j] = {std::cos(theta) * r, std::sin(theta) * r, 0};
		}
	}
}

void Mesh::GenerateHalfCircle(float const radius)
{  
    m_vertices.resize(m_meshResolution * m_meshResolution);
	for (float i = 0; i < m_meshResolution; i++)
	{
    	float r = (radius * i) / (m_meshResolution - 1);
		for (float j = 0; j < m_meshResolution; j++)
		{
			float theta = (M_PI * j) / (m_meshResolution - 1);
			m_vertices[m_meshResolution * i + j] = {std::cos(theta) * r, std::sin(theta) * r, 0};
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
            m_vertices[m_meshResolution * i + j].z = 0.f;
        }
    }
}

void Mesh::GenerateSquare(float const size)
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

void Mesh::GenerateTorus(float R1, float R2)
{
    m_vertices.resize(m_meshResolution * m_meshResolution);


	for (float seg = 0; seg < m_meshResolution ; seg++)
	{
		float angle = (M_PI * 2) / (m_meshResolution - 1);
		for (float j = 0; j < m_meshResolution; j++)
		{
			float theta = (M_PI * 2 * j) / (m_meshResolution - 1);
			m_vertices[m_meshResolution * seg + j] = {R2 + std::cos(theta) * R1, std::sin(theta) * R1, 1};
			m_vertices[m_meshResolution * seg + j].Rotate(angle * seg / 100, Y);
		}
	}
}

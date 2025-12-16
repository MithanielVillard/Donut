#ifndef MESH_H
#define MESH_H

#include "settings.h"
#include <cmath>
#include <vector>

enum Axis
{
	X,Y, Z
};

struct Vertex
{
	Vertex() = default;
	Vertex(float _x, float _y, float _z, float _nx, float _ny, float _nz) : x(_x), y(_y), z(_z), nx(_nx), ny(_ny), nz(_ny) {}

	void Rotate(float angle, Axis axis)
	{
		Vertex previous = *this;
		switch(axis)
		{
			case X:
				y = ny = previous.y * std::cos(angle) - previous.z * std::sin(angle); 
				z = nz = previous.y * std::sin(angle) + previous.z * std::cos(angle);
				break;
			case Y:
				x = nx = previous.x * std::cos(angle) + previous.z * std::sin(angle);
				z = nz = -previous.x * std::sin(angle) + previous.z * std::cos(angle);
				break;
			case Z:
				x = nx = previous.x * std::cos(angle) - previous.y * std::sin(angle);
				y = ny = previous.x * std::sin(angle) + previous.y * std::cos(angle);
				break;
		}
	}

	float x = 0;
	float y = 0;
	float z = 0;

	float nx = 0;
	float ny = 0;
	float nz = 0;
};

class Mesh
{
public:
	Mesh(Settings const& settings);
	~Mesh() = default;

	void PrintMesh();

	void GenerateCircle(float radius);
	void GenerateHalfCircle(float radius);
	void GenerateRectangle(float width, float height);
	void GenerateSquare(float size);
	void GenerateTorus(float R1, float R2);

	void Rotate(Axis axis, float angle);

	std::vector<Vertex>& GetVertices() { return m_vertices; }

private:
	std::vector<Vertex> m_vertices;
	int m_meshResolution;
};

#endif // !MESH_H

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
	Vertex(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	void Rotate(float angle, Axis axis)
	{
		Vertex previous = *this;
		switch(axis)
		{
			case X:
				y = previous.y * std::cos(angle) - previous.z * std::sin(angle); 
				z = previous.y * std::sin(angle) + previous.z * std::cos(angle);
				break;
			case Y:
				x = previous.x * std::cos(angle) + previous.z * std::sin(angle);
				z = -previous.x * std::sin(angle) + previous.z * std::cos(angle);
				break;
			case Z:
				x = previous.x * std::cos(angle) - previous.y * std::sin(angle);
				y = previous.x * std::sin(angle) + previous.y * std::cos(angle);
				break;
		}
	}

	float x;
	float y;
	float z;
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
	void GenereateSquare(float size);

	void Rotate(Axis axis, float angle);

	std::vector<Vertex>& GetVertices() { return m_vertices; }

private:
	std::vector<Vertex> m_vertices;
	int m_meshResolution;
};

#endif // !MESH_H

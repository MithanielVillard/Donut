#ifndef MESH_H
#define MESH_H

#include "settings.h"
#include <vector>
struct Vertex
{
	Vertex(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

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

private:
	std::vector<Vertex> m_vertices;
	int m_meshResolution;
};

#endif // !MESH_H

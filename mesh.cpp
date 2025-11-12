#include "mesh.h"
#include <iostream>

Mesh::Mesh(Settings const& settings) : m_meshResolution(settings.GetMesResolution()) {}
	
void Mesh::GenerateCircle(float const radius)
{

}

void Mesh::PrintMesh()
{
	for(Vertex v : m_vertices)
	{
		std::cout << "x: " << v.x << " y: " << v.y << " z: " << v.z << "\n";
	}
}

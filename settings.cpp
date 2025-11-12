#include "settings.h"

#include <cstring>
#include <string>

Settings::Settings(int argc, char ** argv)
{
	if (argc < 5) return;

	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "-h") == 0)
			m_height = std::stoi(argv[i+1]);
		else if (strcmp(argv[i], "-w") == 0)
			m_width = std::stoi(argv[i+1]);
		else if (strcmp(argv[i], "-r") == 0)
			m_meshResolution = std::stoi(argv[i+1]);
	}
}

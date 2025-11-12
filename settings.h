#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{
public:
	Settings(int argc, char** argv);
	~Settings() = default;

	int GetScreenWidth() const { return m_width; }
	int GetScreenHeight() const { return m_height; }
	int GetMesResolution() const { return m_meshResolution; }

private:
	int m_width = 100;
	int m_height = 20;
	int m_meshResolution = 32;
};

#endif // !SETTINGS_H

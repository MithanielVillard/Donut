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
	int GetScreenPosition() const { return m_screenPosition; }
	int GetMeshPosition() const { return m_meshPosition; }

private:
	int m_width = 150;
	int m_height = 30;
	int m_meshResolution = 300;
	float m_screenPosition = 8.3;
	int m_meshPosition = 10;
	char m_screenBackground = '.';
	char m_screenMeshProjection = 'X';
};

#endif // !SETTINGS_H

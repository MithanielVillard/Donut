#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{
public:
	Settings(int argc, char** argv);
	~Settings() = default;

	int GetScreenWidth() { return m_width; }
	int GetScreenHeight() { return m_height; }

private:
	int m_width = 0;
	int m_height = 0;
};

#endif // !SETTINGS_H

#pragma once

#include "SFML/Graphics.hpp"

class Window
{
public:
	Window(const char* name);
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	~Window();
	
	sf::RenderWindow* GetWindow();
	void ProcessEvents();
	void SetName(const char* name);
	void SetIcon(const char* filepath = "res/icon.png");
	void ClearWindow();
	void Display();
private:
	sf::RenderWindow wnd;
	sf::Image icon;
	int width;
	int height;
};
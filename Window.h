#pragma once

#include "SFML/Graphics.hpp"

class Window
{
public:
	Window(int width, int height, const char* name);
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	~Window();
	
	void SetName(const char* name);
private:
	sf::RenderWindow wnd;
	sf::Image icon;
};
#include "Window.h"

Window::Window(int width, int height, const char* name)
{
	wnd.create(sf::VideoMode(width, height), name, sf::Style::Fullscreen);
	icon.loadFromFile("./res/icon.png");
	wnd.setIcon(32, 32, icon.getPixelsPtr());
}

/*
	Close the window.
*/
Window::~Window()
{
	wnd.close();
}

/*
	Set the name of the window to the given name.
*/
void Window::SetName(const char* name)
{
	wnd.setTitle(name);
}
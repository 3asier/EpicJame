#include "Window.h"

Window::Window(const char* name)
	:
	width(sf::VideoMode::getDesktopMode().width),
	height(sf::VideoMode::getDesktopMode().height)
{
	wnd.create(sf::VideoMode(width, height), name, sf::Style::Fullscreen);

	SetIcon();
}

/*
	Close the window.
*/
Window::~Window()
{
	wnd.close();
}

sf::RenderWindow* Window::GetWindow()
{
	return &wnd;
}

void Window::ProcessEvents()
{
	sf::Event evt;
	while (wnd.pollEvent(evt))
	{
		switch (evt.type)
		{
		case sf::Event::Closed:
			wnd.close();
		}
	}
}

/*
	Set the name of the window to the given name.
*/
void Window::SetName(const char* name)
{
	wnd.setTitle(name);
}

/*
	Load the icon from file, and set it to the window.
*/
void Window::SetIcon(const char* filepath)
{
	icon.loadFromFile(filepath);
	wnd.setIcon(1024, 1024, icon.getPixelsPtr());
}

/*
	Clear the window with a black colour.
*/
void Window::ClearWindow()
{
	wnd.clear(sf::Color());
}

/*
	Display what has currently been rendered, to the screen.
*/
void Window::Display()
{
	wnd.display();
}
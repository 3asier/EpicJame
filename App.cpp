#include "App.h"
#include <iostream>

App::App()
	:
	wnd(WNDNAME)
{
	
}

App::~App()
{
	std::cout << "App was destroyed" << std::endl;
}

void App::Start()
{
	while (wnd.GetWindow()->isOpen()) {
		wnd.ProcessEvents();
		wnd.ClearWindow();
		wnd.Display();
	}
}

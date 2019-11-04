#include "App.h"
#include <iostream>

App::App()
{
	std::cout << "App was created" << std::endl;
}

App::~App()
{
	std::cout << "App was destroyed" << std::endl;
}

void App::Start()
{
	std::cout << "App was started!" << std::endl;
}

#pragma once
#include "Window.h"

#define VERSION "0.01a"
#define TITLE "Ton3l Engine"
#define WNDNAME TITLE VERSION

class App
{
public:
	App();
	App(const App&) = delete;
	App& operator=(const App&) = delete;
	~App();
	void Start();
private:
	Window wnd;
	// Audio Controler
	// Game Logic
	// Physics Engine
	// Window Handler?
};
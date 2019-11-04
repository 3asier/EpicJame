#pragma once

class App
{
public:
	App();
	App(const App&) = delete;
	App& operator=(const App&) = delete;
	~App();
	void Start();
private:
	// Audio Controler
	// Game Logic
	// Physics Engine
	// Window Handler?
};
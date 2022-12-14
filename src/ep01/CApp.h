
#pragma once

#include <SDL2/SDL.h>
#include "qbImage.hpp"


class CApp
{
public:
	CApp();
	int OnExecute();
	bool OnInit();
	void OnEvent(SDL_Event* event);
	void OnLoop();
	void OnRender();
	void OnExit();
private:
	qbImage m_image;
	bool isRunning;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
};
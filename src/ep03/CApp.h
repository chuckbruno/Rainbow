
#pragma once

#include <SDL2/SDL.h>
#include "qbImage.hpp"
#include "scene.hpp"
#include "camera.hpp"


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
	void PrintVector(const qbVector<double>& inputVector);
private:
	qbImage m_image;
	RT::Scene m_scene;
	bool isRunning;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
};
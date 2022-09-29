
#include "CApp.h"
#include "../qbLinAlg/qbVector.h"


CApp::CApp()
{
	isRunning = true;
	pWindow = nullptr;
	pRenderer = nullptr;
}

bool CApp::OnInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}

	pWindow = SDL_CreateWindow("RayTracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	if (pWindow != nullptr)
	{
		pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
		m_image.Initialize(1280, 720, pRenderer);

		SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
		SDL_RenderClear(pRenderer);

		// render the scene
		m_scene.Render(m_image);

		// display the image
		m_image.Display();

		// show the result
		SDL_RenderPresent(pRenderer);
		//for (int x = 0; x < 1280; ++x)
		//{
		//	for (int y = 0; y < 720; ++y)
		//	{
		//		double red = (static_cast<double>(x) / 1280.0) * 255.0;
		//		double green = (static_cast<double>(y) / 720.0) * 255.0;
		//		m_image.SetPixel(x, y, red, green, 0.0);
		//	}
		//}
	}
	else
	{
		return false;
	}

	return true;
}

int CApp::OnExecute()
{
	SDL_Event event;
	if (OnInit() == false)
	{
		return -1;
	}
	while (isRunning)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			OnEvent(&event);
		}
		OnLoop();
		OnRender();
	}

	return 0;
}

void CApp::OnEvent(SDL_Event* event)
{
	if (event->type == SDL_QUIT)
	{
		isRunning = false;
	}
}

void CApp::OnLoop()
{

}

void CApp::OnRender()
{
	//SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
	//SDL_RenderClear(pRenderer);

	//m_image.Display();

	//SDL_RenderPresent(pRenderer);
}

void CApp::OnExit()
{
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;
	SDL_Quit();
}

void CApp::PrintVector(const qbVector<double>& inputVector)
{
	int nRows = inputVector.GetNumDims();
	for (int row = 0; row < nRows; ++row)
	{
		std::cout << std::fixed << std::setprecision(3) << inputVector.GetElement(row) << std::endl;
	}
}
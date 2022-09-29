#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include "qbImage.hpp"
#include "camera.hpp"
#include "objsphere.hpp"


namespace RT
{
	class Scene
	{
	public:
		Scene();
		bool Render(qbImage& outputImage);
	//private functions
	private:

	//private members
	private:
		RT::Camera m_camera;
		RT::ObjSphere m_testSphere;
	};
}
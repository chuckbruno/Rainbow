
#pragma once

#include <string>
#include <vector>
#include <SDL2/SDL.h>


class qbImage
{
public:
	qbImage();
	~qbImage();
	void Initialize(const int xSize, const int ySize, SDL_Renderer* pRenderer);
	void SetPixel(const int x, const int y, const double red, const double green, const double blue);
	void Display();

	//Functions to return the dimensions of the image
	int GetXSize();
	int GetYSize();
private:
	Uint32 ConvertColor(const double red, const double green, const double blue);
	void InitTexture();
private:
	std::vector<std::vector<double>> m_rChannel;
	std::vector<std::vector<double>> m_gChannel;
	std::vector<std::vector<double>> m_bChannel;

	int m_xSize, m_ySize;
	SDL_Renderer *m_pRenderer;
	SDL_Texture *m_pTexture;

};

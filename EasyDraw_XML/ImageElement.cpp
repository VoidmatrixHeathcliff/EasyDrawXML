#include "ImageElement.h"

ImageElement::ImageElement(SDL_Renderer* pRenderer, string path, SDL_Rect rect, int alpha, int layer)
	: _pRenderer(pRenderer), _rect(rect), Element(layer)
{
	SDL_Surface* pSurface = IMG_Load(path.c_str());
	if (pSurface)
	{
		_pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
		if (255 != alpha)
		{
			SDL_SetTextureBlendMode(_pTexture, SDL_BLENDMODE_BLEND);
			SDL_SetTextureAlphaMod(_pTexture, alpha);
		}

		_rect.w = rect.w < 0 ? pSurface->w : rect.w;
		_rect.h = rect.h < 0 ? pSurface->h : rect.h;

		SDL_FreeSurface(pSurface);
	}
}

void ImageElement::Update()
{
	if (_pTexture)
		SDL_RenderCopy(_pRenderer, _pTexture, nullptr, &_rect);
}

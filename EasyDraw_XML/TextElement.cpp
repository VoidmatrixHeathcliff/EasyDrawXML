#include "TextElement.h"

#include <iostream>
using namespace std;

TextElement::TextElement(SDL_Renderer* pRenderer, TTF_Font* pFont, string text, SDL_Rect rect, SDL_Color fgcolor, SDL_Color bgcolor, int layer)
	: _pRenderer(pRenderer), _bgColor(bgcolor), _rect(rect), Element(layer)
{
	if (pFont && !text.empty())
	{
		SDL_Surface* pSurface = TTF_RenderUTF8_Blended(pFont, text.c_str(), fgcolor);

		_pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);

		_rect.w = rect.w < 0 ? pSurface->w : rect.w;
		_rect.h = rect.h < 0 ? pSurface->h : rect.h;

		SDL_FreeSurface(pSurface);
	}
}

void TextElement::Update()
{
	if (_pTexture)
	{
		SDL_SetRenderDrawColor(_pRenderer, _bgColor.r, _bgColor.g, _bgColor.b, _bgColor.a);
		SDL_SetRenderDrawBlendMode(_pRenderer, SDL_BLENDMODE_BLEND);
		SDL_RenderFillRect(_pRenderer, &_rect);
		SDL_RenderCopy(_pRenderer, _pTexture, nullptr, &_rect);
	}
		
}

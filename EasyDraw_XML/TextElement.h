#ifndef _TEXTELEMENT_H_
#define _TEXTELEMENT_H_

#include "Element.h"

#include "../libs/SDL2-2.0.12/include/SDL.h"
#include "../libs/SDL2_ttf-2.0.15/include/SDL_ttf.h"

#include <string>
using namespace std;

#define ELEMENT_TEXT "Text"

class TextElement : public Element
{
public:
	TextElement(SDL_Renderer* pRenderer, TTF_Font* pFont, string text, SDL_Rect rect, SDL_Color fgcolor, SDL_Color bgcolor, int layer);
	~TextElement() {}
	void Update();

private:
	SDL_Renderer* _pRenderer;
	SDL_Texture* _pTexture = nullptr;
	SDL_Color _bgColor;
	SDL_Rect _rect;
};

#endif // !_TEXTELEMENT_H_

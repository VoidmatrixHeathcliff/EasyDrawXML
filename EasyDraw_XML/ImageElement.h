#ifndef _IMAGEELEMENT_H_
#define _IMAGEELEMENT_H_

#include "Element.h"

#include "../libs/SDL2-2.0.12/include/SDL.h"
#include "../libs/SDL2_image-2.0.5/include/SDL_image.h"

#include <string>
using namespace std;

#define ELEMENT_IMAGE "Image"

class ImageElement : public Element
{
public:
	ImageElement(SDL_Renderer* pRenderer, string path, SDL_Rect rect, int alpha, int layer);
	~ImageElement() {}
	void Update();

private:
	SDL_Renderer* _pRenderer;
	SDL_Texture* _pTexture = nullptr;
	SDL_Rect _rect;
};

#endif // !_IMAGEELEMENT_H_

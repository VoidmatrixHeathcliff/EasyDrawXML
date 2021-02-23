#ifndef _GEOMETRYELEMENT_H_
#define _GEOMETRYELEMENT_H_

#include "Element.h"

#include "../libs/SDL2-2.0.12/include/SDL.h"
#include "../libs/SDL2_gfx-1.0.4/SDL2_gfxPrimitives.h"

class GeometryElement : public Element
{
public:
	GeometryElement(SDL_Renderer* pRenderer, SDL_Color color, int layer)
		: _pRenderer(pRenderer), _color(color), Element(layer) {}
	~GeometryElement() {}

protected:
	SDL_Renderer* _pRenderer;
	SDL_Color _color;
};

#endif // !_GEOMETRYELEMENT_H_

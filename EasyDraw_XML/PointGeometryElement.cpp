#include "PointGeometryElement.h"

void PointGeometryElement::Update()
{
	SDL_RenderDrawPoint(_pRenderer, _point.x, _point.y);
}

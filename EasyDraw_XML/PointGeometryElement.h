#ifndef _POINTGEOMETRYELEMENT_H_
#define _POINTGEOMETRYELEMENT_H_

#include "GeometryElement.h"

#define ELEMENT_POINT "Point"

class PointGeometryElement : public GeometryElement
{
public:
	PointGeometryElement(SDL_Renderer* pRenderer, SDL_Point point, SDL_Color color, int layer)
		: _point(point), GeometryElement(pRenderer, color, layer) {}
	~PointGeometryElement() {}
	void Update();

private:
	SDL_Point _point;
};

#endif // !_POINTGEOMETRYELEMENT_H_

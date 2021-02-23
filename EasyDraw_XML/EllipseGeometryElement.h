#ifndef _ELLIPSEGEOMETRYELEMENT_H_
#define _ELLIPSEGEOMETRYELEMENT_H_

#include "GeometryElement.h"

#define ELEMENT_ELLIPSE "Ellipse"

class EllipseGeometryElement : public GeometryElement
{
public:
	EllipseGeometryElement(SDL_Renderer* pRenderer, SDL_Point center, int radiusX, int radiusY, bool isFilled, SDL_Color color, int layer)
		: _center(center), _radiusX(radiusX), _radiusY(radiusY), _isFilled(isFilled), GeometryElement(pRenderer, color, layer) {}
	~EllipseGeometryElement() {}
	void Update();

private:
	SDL_Point _center;
	int _radiusX, _radiusY;
	bool _isFilled;
};

#endif // !_ELLIPSEGEOMETRYELEMENT_H_

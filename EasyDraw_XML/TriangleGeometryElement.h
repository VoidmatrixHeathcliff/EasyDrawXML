#ifndef _TRIANGLEGEOMETRYELEMENT_H_
#define _TRIANGLEGEOMETRYELEMENT_H_

#include "GeometryElement.h"

#define ELEMENT_TRIANGLE "Triangle"

class TriangleGeometryElement : public GeometryElement
{
public:
	TriangleGeometryElement(SDL_Renderer* pRenderer, SDL_Point pointA, SDL_Point pointB, SDL_Point pointC, bool isFilled, SDL_Color color, int layer)
		: _pointA(pointA), _pointB(pointB), _pointC(pointC), _isFilled(isFilled), GeometryElement(pRenderer, color, layer) {}
	~TriangleGeometryElement() {}
	void Update();

private:
	SDL_Point _pointA, _pointB, _pointC;
	bool _isFilled;
};

#endif // !_TRIANGLEGEOMETRYELEMENT_H_


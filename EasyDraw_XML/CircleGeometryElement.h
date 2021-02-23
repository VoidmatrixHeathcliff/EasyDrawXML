#ifndef _CIRCLEGEOMETRYELEMENT_H_
#define _CIRCLEGEOMETRYELEMENT_H_

#include "GeometryElement.h"

#define ELEMENT_CIRCLE "Circle"

class CircleGeometryElement : public GeometryElement
{
public:
	CircleGeometryElement(SDL_Renderer* pRenderer, SDL_Point center, int radius, bool isFilled, SDL_Color color, int layer)
		: _center(center), _radius(radius), _isFilled(isFilled), GeometryElement(pRenderer, color, layer) {}
	~CircleGeometryElement() {}
	void Update();

private:
	SDL_Point _center;
	int _radius;
	bool _isFilled;
};

#endif // !_CIRCLEGEOMETRYELEMENT_H_

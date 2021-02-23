#ifndef _RECTANGLEGEOMETRYELEMENT_H_
#define _RECTANGLEGEOMETRYELEMENT_H_

#include "GeometryElement.h"

#define ELEMENT_RECTANGLE "Rectangle"

class RectangleGeometryElement : public GeometryElement
{
public:
	RectangleGeometryElement(SDL_Renderer* pRenderer, SDL_Rect rect, int radius, bool isFilled, SDL_Color color, int layer)
		: _rect(rect), _radius(radius), _isFilled(isFilled), GeometryElement(pRenderer, color, layer) {}
	~RectangleGeometryElement() {}
	void Update();

private:
	SDL_Rect _rect;
	int _radius;
	bool _isFilled;
	
};

#endif // !_RECTANGLEGEOMETRYELEMENT_H_

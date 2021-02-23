#ifndef _LINEGEOMETRYELEMENT_H_
#define _LINEGEOMETRYELEMENT_H_

#include "GeometryElement.h"

#define ELEMENT_LINE "Line"

class LineGeometryElement : public GeometryElement
{
public:
	LineGeometryElement(SDL_Renderer* pRenderer, SDL_Point startPoint, SDL_Point endPoint, int width, SDL_Color color, int layer)
		: _startPoint(startPoint), _endPoint(endPoint), _width(width), GeometryElement(pRenderer, color, layer) {}
	~LineGeometryElement() {}
	void Update();

private:
	SDL_Point _startPoint, _endPoint;
	int _width;
};

#endif // !_LINEGEOMETRYELEMENT_H_

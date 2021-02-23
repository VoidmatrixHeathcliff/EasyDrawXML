#ifndef _PIEGEOMETRYELEMENT_H_
#define _PIEGEOMETRYELEMENT_H_

#include "GeometryElement.h"

#define ELEMENT_PIE "Pie"

class PieGeometryElement : public GeometryElement
{
public:
	PieGeometryElement(SDL_Renderer* pRenderer, SDL_Point center, int radius, int startAngle, int endAngle, bool isFilled, SDL_Color color, int layer)
		: _center(center), _radius(radius), _startAngle(startAngle), _endAngle(endAngle), _isFilled(isFilled), GeometryElement(pRenderer, color, layer) {}
	~PieGeometryElement() {}
	void Update();

private:
	SDL_Point _center;
	int _radius, _startAngle, _endAngle;
	bool _isFilled;
};

#endif // !_PIEGEOMETRYELEMENT_H_

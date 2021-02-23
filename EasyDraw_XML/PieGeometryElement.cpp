#include "PieGeometryElement.h"

void PieGeometryElement::Update()
{
	_isFilled ? filledPieRGBA(_pRenderer, _center.x, _center.y, _radius, _startAngle, _endAngle, _color.r, _color.g, _color.b, _color.a)
		: pieRGBA(_pRenderer, _center.x, _center.y, _radius, _startAngle, _endAngle, _color.r, _color.g, _color.b, _color.a);
}

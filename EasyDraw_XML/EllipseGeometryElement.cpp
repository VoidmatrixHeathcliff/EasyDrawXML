#include "EllipseGeometryElement.h"

void EllipseGeometryElement::Update()
{
	_isFilled ? filledEllipseRGBA(_pRenderer, _center.x, _center.y, _radiusX, _radiusY, _color.r, _color.g, _color.b, _color.a)
		: aaellipseRGBA(_pRenderer, _center.x, _center.y, _radiusX, _radiusY, _color.r, _color.g, _color.b, _color.a);
}

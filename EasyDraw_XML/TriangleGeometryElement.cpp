#include "TriangleGeometryElement.h"

void TriangleGeometryElement::Update()
{
	_isFilled ? filledTrigonRGBA(_pRenderer, _pointA.x, _pointA.y, _pointB.x, _pointB.y, _pointC.x, _pointC.y, _color.r, _color.g, _color.b, _color.a)
		: aatrigonRGBA(_pRenderer, _pointA.x, _pointA.y, _pointB.x, _pointB.y, _pointC.x, _pointC.y, _color.r, _color.g, _color.b, _color.a);
}

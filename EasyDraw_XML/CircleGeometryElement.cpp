#include "CircleGeometryElement.h"

void CircleGeometryElement::Update()
{
	_isFilled ? filledCircleRGBA(_pRenderer, _center.x, _center.y, _radius, _color.r, _color.g, _color.b, _color.a)
		: aacircleRGBA(_pRenderer, _center.x, _center.y, _radius, _color.r, _color.g, _color.b, _color.a);
}

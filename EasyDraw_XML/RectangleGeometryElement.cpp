#include "RectangleGeometryElement.h"

void RectangleGeometryElement::Update()
{
	_isFilled ? roundedBoxRGBA(_pRenderer, _rect.x, _rect.y, _rect.x + _rect.w, _rect.y + _rect.h, _radius, _color.r, _color.g, _color.b, _color.a)
		: roundedRectangleRGBA(_pRenderer, _rect.x, _rect.y, _rect.x + _rect.w, _rect.y + _rect.h, _radius, _color.r, _color.g, _color.b, _color.a);
}
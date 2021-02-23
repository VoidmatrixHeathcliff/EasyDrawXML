#include "LineGeometryElement.h"

void LineGeometryElement::Update()
{
	_width > 1 ? thickLineRGBA(_pRenderer, _startPoint.x, _startPoint.y, _endPoint.x, _endPoint.y, _width, _color.r, _color.g, _color.b, _color.a)
		: aalineRGBA(_pRenderer, _startPoint.x, _startPoint.y, _endPoint.x, _endPoint.y, _color.r, _color.g, _color.b, _color.a);
}

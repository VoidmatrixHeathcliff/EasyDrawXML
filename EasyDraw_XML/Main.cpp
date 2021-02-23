#include "Main.h"

int iWidthWindow = 1280, iHeightWindow = 720, iFontSize = 35;

string strTitleWindow = "Window";

TTF_Font* pFontText = nullptr;

SDL_Color clrBackgroundWindow = COLORDEFAULT_BACK;

SDL_Renderer* pWRenderer = nullptr;

SDL_Surface* pSurfaceIcon = nullptr;

vector<Element*> vPElements;

struct MainWalker : xml_tree_walker
{
	bool for_each(xml_node& node)
	{
		string _strNameNode = node.name();

		if (ELEMENT_CIRCLE == _strNameNode)
		{
			SDL_Point _center = { 0, 0 };
			int _iRadius = 0;
			bool _isFilled = false;
			SDL_Color _color = COLORDEFAULT_DRAW;
			GetIntegerValue(node, ATTRIBUTE_X, _center.x);
			GetIntegerValue(node, ATTRIBUTE_Y, _center.y);
			GetIntegerValue(node, ATTRIBUTE_RADIUS, _iRadius);
			GetBooleanValue(node, ATTRIBUTE_ISFILLED, _isFilled);
			GetColorValue(node, ATTRIBUTE_COLOR, _color);
			Element* elementCircle = new CircleGeometryElement(pWRenderer, _center, _iRadius, _isFilled, _color, depth());
			vPElements.push_back(elementCircle);
		}
		else if (ELEMENT_ELLIPSE == _strNameNode)
		{
			SDL_Point _center = { 0, 0 };
			int _iRadiusX = 0, _iRadiusY = 0;
			bool _isFilled = false;
			SDL_Color _color = COLORDEFAULT_DRAW;
			GetIntegerValue(node, ATTRIBUTE_X, _center.x);
			GetIntegerValue(node, ATTRIBUTE_Y, _center.y);
			GetIntegerValue(node, ATTRIBUTE_RADIUSX, _iRadiusX);
			GetIntegerValue(node, ATTRIBUTE_RADIUSY, _iRadiusY);
			GetBooleanValue(node, ATTRIBUTE_ISFILLED, _isFilled);
			GetColorValue(node, ATTRIBUTE_COLOR, _color);
			Element* elementEllipse = new EllipseGeometryElement(pWRenderer, _center, _iRadiusX, _iRadiusY, _isFilled, _color, depth());
			vPElements.push_back(elementEllipse);
		}
		else if (ELEMENT_LINE == _strNameNode)
		{
			SDL_Point _startPoint = { 0, 0 }, _endPoint = { 0, 0 };
			int _width = 1;
			SDL_Color _color = COLORDEFAULT_DRAW;
			GetIntegerValue(node, ATTRIBUTE_STARTX, _startPoint.x);
			GetIntegerValue(node, ATTRIBUTE_STARTY, _startPoint.y);
			GetIntegerValue(node, ATTRIBUTE_ENDX, _endPoint.x);
			GetIntegerValue(node, ATTRIBUTE_ENDY, _endPoint.y);
			GetIntegerValue(node, ATTRIBUTE_WIDTH, _width);
			GetColorValue(node, ATTRIBUTE_COLOR, _color);
			Element* elementLine = new LineGeometryElement(pWRenderer, _startPoint, _endPoint, _width, _color, depth());
			vPElements.push_back(elementLine);
		}
		else if (ELEMENT_PIE == _strNameNode)
		{
			SDL_Point _center = { 0, 0 };
			int _radius = 0, _startAngle = 0, _endAngle = 0;
			bool _isFilled = false;
			SDL_Color _color = COLORDEFAULT_DRAW;
			GetIntegerValue(node, ATTRIBUTE_X, _center.x);
			GetIntegerValue(node, ATTRIBUTE_Y, _center.y);
			GetIntegerValue(node, ATTRIBUTE_RADIUSX, _radius);
			GetIntegerValue(node, ATTRIBUTE_STARTANGLE, _startAngle);
			GetIntegerValue(node, ATTRIBUTE_ENDANGLE, _endAngle);
			GetBooleanValue(node, ATTRIBUTE_ISFILLED, _isFilled);
			GetColorValue(node, ATTRIBUTE_COLOR, _color);
			Element* elementPie = new PieGeometryElement(pWRenderer, _center, _radius, _startAngle, _endAngle, _isFilled, _color, depth());
			vPElements.push_back(elementPie);
		}
		else if (ELEMENT_POINT == _strNameNode)
		{
			SDL_Point _point = { 0, 0 };
			SDL_Color _color = COLORDEFAULT_DRAW;
			GetIntegerValue(node, ATTRIBUTE_X, _point.x);
			GetIntegerValue(node, ATTRIBUTE_Y, _point.y);
			GetColorValue(node, ATTRIBUTE_COLOR, _color);
			Element* elementPoint = new PointGeometryElement(pWRenderer, _point, _color, depth());
			vPElements.push_back(elementPoint);
		}
		else if (ELEMENT_RECTANGLE == _strNameNode)
		{
			SDL_Rect _rect = { 0, 0, 0, 0 };
			int _radius = 0;
			bool _isFilled = false;
			SDL_Color _color = COLORDEFAULT_DRAW;
			GetIntegerValue(node, ATTRIBUTE_X, _rect.x);
			GetIntegerValue(node, ATTRIBUTE_Y, _rect.y);
			GetIntegerValue(node, ATTRIBUTE_WIDTH, _rect.w);
			GetIntegerValue(node, ATTRIBUTE_HEIGHT, _rect.h);
			GetBooleanValue(node, ATTRIBUTE_ISFILLED, _isFilled);
			GetColorValue(node, ATTRIBUTE_COLOR, _color);
			Element* elementRectangle = new RectangleGeometryElement(pWRenderer, _rect, _radius, _isFilled, _color, depth());
			vPElements.push_back(elementRectangle);
		}
		else if (ELEMENT_TRIANGLE == _strNameNode)
		{
			SDL_Point _pointA = { 0, 0 }, _pointB = { 0, 0 }, _pointC = { 0, 0 };
			bool _isFilled = false;
			SDL_Color _color = COLORDEFAULT_DRAW;
			GetIntegerValue(node, ATTRIBUTE_POINTAX, _pointA.x);
			GetIntegerValue(node, ATTRIBUTE_POINTAY, _pointA.y);
			GetIntegerValue(node, ATTRIBUTE_POINTBX, _pointB.x);
			GetIntegerValue(node, ATTRIBUTE_POINTBY, _pointB.y);
			GetIntegerValue(node, ATTRIBUTE_POINTCX, _pointC.x);
			GetIntegerValue(node, ATTRIBUTE_POINTCY, _pointC.y);
			GetBooleanValue(node, ATTRIBUTE_ISFILLED, _isFilled);
			GetColorValue(node, ATTRIBUTE_COLOR, _color);
			Element* elementRectangle = new TriangleGeometryElement(pWRenderer, _pointA, _pointB, _pointC, _isFilled, _color, depth());
			vPElements.push_back(elementRectangle);
		}
		else if (ELEMENT_IMAGE == _strNameNode)
		{
			SDL_Rect _rect = { 0, 0, -1, -1 };
			string _path;
			int _alpha = 255;
			GetIntegerValue(node, ATTRIBUTE_X, _rect.x);
			GetIntegerValue(node, ATTRIBUTE_Y, _rect.y);
			GetIntegerValue(node, ATTRIBUTE_WIDTH, _rect.w);
			GetIntegerValue(node, ATTRIBUTE_HEIGHT, _rect.h);
			GetStringValue(node, ATTRIBUTE_PATH, _path);
			GetIntegerValue(node, ATTRIBUTE_ALPHA, _alpha);
			Element* elementImage = new ImageElement(pWRenderer, _path, _rect, _alpha, depth());
			vPElements.push_back(elementImage);
		}
		else if (ELEMENT_TEXT == _strNameNode)
		{
			SDL_Rect _rect = { 0, 0, -1, -1 };
			SDL_Color clrfg = COLORDEFAULT_DRAW, clrbg = { 0, 0, 0, 0 };
			string _text;
			GetIntegerValue(node, ATTRIBUTE_X, _rect.x);
			GetIntegerValue(node, ATTRIBUTE_Y, _rect.y);
			GetIntegerValue(node, ATTRIBUTE_WIDTH, _rect.w);
			GetIntegerValue(node, ATTRIBUTE_HEIGHT, _rect.h);
			GetStringValue(node, ATTRIBUTE_CONTENT, _text);
			GetColorValue(node, ATTRIBUTE_COLOR, clrfg);
			GetColorValue(node, ATTRIBUTE_BACKCOLOR, clrbg);
			Element* elementText = new TextElement(pWRenderer, pFontText, _text, _rect, clrfg, clrbg, depth());
			vPElements.push_back(elementText);
		}

		return true;
	}
};

bool CompElementLayer(Element* elementA, Element* elementB)
{
	return elementA->GetLayer() < elementB->GetLayer();
}

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);

	xml_document mainDoc;
	xml_parse_result result = mainDoc.load_file(FILE_NAME);

	if (result.status)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ParsingError", result.description(), nullptr);
		return -1;
	}
	
	xml_node nodeRoot = mainDoc.child("EDX");
	if (nodeRoot.empty())
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ParsingError", "root element 'EDX' missing", nullptr);
		return -1;
	}

	xml_node nodeConfig = nodeRoot.child(ELEMENT_CONFIG);
	if (!nodeConfig.empty())
	{
		xml_node nodeConfigWindow = nodeConfig.child(ELEMENT_CONFIG_WINDOW);
		if (!nodeConfigWindow.empty())
		{
			GetStringValue(nodeConfigWindow, ATTRIBUTE_TITLE, strTitleWindow);
			GetIntegerValue(nodeConfigWindow, ATTRIBUTE_WIDTH, iWidthWindow);
			GetIntegerValue(nodeConfigWindow, ATTRIBUTE_HEIGHT, iHeightWindow);
			GetColorValue(nodeConfigWindow, ATTRIBUTE_COLOR, clrBackgroundWindow);
		}
		for (pugi::xml_node nodeResource = nodeConfig.child(ELEMENT_CONFIG_RESOURCE); nodeResource; nodeResource = nodeResource.next_sibling(ELEMENT_CONFIG_RESOURCE))
		{
			string strTypeValue;
			if (!GetStringValue(nodeResource, ATTRIBUTE_TYPE, strTypeValue))
			{
				if (RESOURCETYPE_FONT == strTypeValue)
				{
					string strPathFont;
					GetStringValue(nodeResource, ATTRIBUTE_PATH, strPathFont);
					GetIntegerValue(nodeResource, ATTRIBUTE_SIZE, iFontSize);
					pFontText = TTF_OpenFont(strPathFont.c_str(), iFontSize);
				}
				else if (RESOURCETYPE_ICON == strTypeValue)
				{
					string strPathIcon;
					GetStringValue(nodeResource, ATTRIBUTE_PATH, strPathIcon);
					pSurfaceIcon = IMG_Load(strPathIcon.c_str());
				}
				else
				{
					/* 处理其他类型资源 */
				}
			}
		}
	}

	if (!pFontText)
		pFontText = TTF_OpenFont(PATHDEFAULT_FONT, iFontSize);

	SDL_Window* pWindow = SDL_CreateWindow(strTitleWindow.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, iWidthWindow, iHeightWindow, SDL_WINDOW_SHOWN);

	pWRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawBlendMode(pWRenderer, SDL_BLENDMODE_BLEND);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");

	MainWalker mainWalker;

	xml_node nodeBody = nodeRoot.child(ELEMENT_BODY);
	if (!nodeBody.empty())
		nodeBody.traverse(mainWalker);

	SDL_SetWindowIcon(pWindow, pSurfaceIcon);
	SDL_FreeSurface(pSurfaceIcon);

	sort(vPElements.begin(), vPElements.end(), CompElementLayer);

	while (true)
	{
		Uint32 _timeStart = SDL_GetTicks();

		SDL_SetRenderDrawColor(pWRenderer, 0, 0, 0, 255);
		SDL_RenderClear(pWRenderer);

		SDL_SetRenderDrawColor(pWRenderer, clrBackgroundWindow.r, clrBackgroundWindow.g, clrBackgroundWindow.b, clrBackgroundWindow.a);
		SDL_SetRenderDrawBlendMode(pWRenderer, SDL_BLENDMODE_BLEND);
		SDL_RenderFillRect(pWRenderer, nullptr);

		SDL_Event _event;
		if (SDL_PollEvent(&_event))
			if (_event.type == SDL_QUIT)
				break;

		for (auto _pElement : vPElements)
			_pElement->Update();

		SDL_RenderPresent(pWRenderer);

		Uint32 _timeEnd = SDL_GetTicks();

		if (_timeEnd - _timeStart < 1000 / FPS)
			SDL_Delay(1000 / FPS - (_timeEnd - _timeStart));
	}

	SDL_DestroyRenderer(pWRenderer);
	SDL_DestroyWindow(pWindow);

	return 0;
}
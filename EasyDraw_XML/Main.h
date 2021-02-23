#ifndef _MAIN_H_
#define _MAIN_H_

#include "AttributeName.h"
#include "ResourceType.h"
#include "Value.h"
#include "Element.h"
#include "ImageElement.h"
#include "TextElement.h"
#include "CircleGeometryElement.h"
#include "EllipseGeometryElement.h"
#include "LineGeometryElement.h"
#include "PieGeometryElement.h"
#include "PointGeometryElement.h"
#include "RectangleGeometryElement.h"
#include "TriangleGeometryElement.h"

#include "../libs/pugixml-1.11.4/pugixml.hpp"
using namespace pugi;

#include "../libs/SDL2-2.0.12/include/SDL.h"
#include "../libs/SDL2_ttf-2.0.15/include/SDL_ttf.h"
#include "../libs/SDL2_image-2.0.5/include/SDL_image.h"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

#define FPS 24

#define FILE_NAME "index.xml"

#define ELEMENT_BODY			"Body"
#define ELEMENT_CONFIG			"Config"
#define ELEMENT_CONFIG_WINDOW	"Window"
#define ELEMENT_CONFIG_RESOURCE "Resource"

#define COLORDEFAULT_BACK { 0, 0, 0, 255 }
#define COLORDEFAULT_DRAW { 255, 255, 255, 255 }

#define PATHDEFAULT_FONT "C:/Windows/Fonts/msyh.ttc"

#ifndef _DEBUG
#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )
#endif // !_DEBUG

#ifdef _WIN64
#pragma comment(lib, "../libs/SDL2-2.0.12/lib/x64/SDL2.lib")
#pragma comment(lib, "../libs/SDL2-2.0.12/lib/x64/SDL2main.lib")
#pragma comment(lib, "../libs/SDL2_image-2.0.5/lib/x64/SDL2_image.lib")
#pragma comment(lib, "../libs/SDL2_ttf-2.0.15/lib/x64/SDL2_ttf.lib")
#else
#pragma comment(lib, "../libs/SDL2-2.0.12/lib/x86/SDL2.lib")
#pragma comment(lib, "../libs/SDL2-2.0.12/lib/x86/SDL2main.lib")
#pragma comment(lib, "../libs/SDL2_image-2.0.5/lib/x86/SDL2_image.lib")
#pragma comment(lib, "../libs/SDL2_ttf-2.0.15/lib/x86/SDL2_ttf.lib")
#endif // _WIN64

bool CompElementLayer(Element* elementA, Element* elementB);

#endif // !_MAIN_H_

#ifndef _VALUE_H_
#define _VALUE_H_

#include "../libs/SDL2-2.0.12/include/SDL.h"
#include "../libs/pugixml-1.11.4/pugixml.hpp"
using namespace pugi;

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void Split(const string& str, const string& pattern, vector<string>& ret);

void Strip(string& str);

bool ConvertStringToColor(string str, SDL_Color& color);

bool GetBooleanValue(xml_node root, string name, bool& value);

bool GetStringValue(xml_node root, string name, string& value);

bool GetIntegerValue(xml_node root, string name, int& value);

bool GetDoubleValue(xml_node root, string name, double& value);

bool GetColorValue(xml_node root, string name, SDL_Color& color);

#endif // !_VALUE_H_

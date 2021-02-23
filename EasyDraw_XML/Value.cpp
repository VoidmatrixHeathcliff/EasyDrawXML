#include "Value.h"

#include <iostream>
using namespace std;

void Split(const string& str, const string& pattern, vector<string>& ret)
{
	if (pattern.empty()) return;
	size_t start = 0, index = str.find_first_of(pattern, 0);
	while (index != str.npos)
	{
		if (start != index)
			ret.push_back(str.substr(start, index - start));
		start = index + 1;
		index = str.find_first_of(pattern, start);
	}
	if (!str.substr(start).empty())
		ret.push_back(str.substr(start));
}

void Strip(string& str)
{
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	str.erase(0, str.find_first_not_of(" "));
	str.erase(str.find_last_not_of(" ") + 1);
}

bool ConvertStringToColor(string str, SDL_Color& color)
{
	if (str.erase(0, str.find_first_not_of(" ")).empty())
		return true;
	else
	{
		if (str[0] == '#')
		{
			str.erase(0, str.find_first_not_of("#"));
			int hex = 0;
			if (!sscanf(str.c_str(), "%x", &hex))
				return true;
			color.r = (hex >> 16) & 0x00ff;
			color.g = (hex >> 8) & 0x0000ff;
			color.b = hex & 0x000000ff;
			color.a = 255;
		}
		else
		{
			vector<string> strlist;
			Split(str, ",", strlist);
			color.r = strlist.size() > 0 ? atoi(strlist[0].c_str()) : 0;
			color.g = strlist.size() > 1 ? atoi(strlist[1].c_str()) : 0;
			color.b = strlist.size() > 2 ? atoi(strlist[2].c_str()) : 0;
			color.a = strlist.size() > 3 ? atoi(strlist[3].c_str()) : 255;
		}
		return false;
	}
}

bool GetBooleanValue(xml_node root, string name, bool& value)
{
	xml_attribute attribute_root = root.attribute(name.c_str());

	if (attribute_root.empty())
	{
		xml_node node_child = root.child(name.c_str());

		if (node_child.empty())
			return true;
		else
		{
			xml_attribute attribute_child = node_child.attribute("Value");
			if (attribute_child.empty())
			{
				string strChildValue = node_child.child_value();
				Strip(strChildValue);
				if (strChildValue.empty())
				{
					xml_node node_value = node_child.child("Value");
					if (node_value.empty())
						return true;
					else
					{
						string strGrandValue = node_value.child_value();
						Strip(strGrandValue);
						transform(strGrandValue.begin(), strGrandValue.end(), strGrandValue.begin(), ::toupper);
						value = "TRUE" == strGrandValue ? true : false;
					}
				}
				else
				{
					transform(strChildValue.begin(), strChildValue.end(), strChildValue.begin(), ::toupper);
					value = "TRUE" == strChildValue ? true : false;
				}
			}
			else
				value = attribute_child.as_bool();
		}
	}
	else
		value = attribute_root.as_bool();

	return false;
}

bool GetStringValue(xml_node root, string name, string& value)
{
	xml_attribute attribute_root = root.attribute(name.c_str());

	if (attribute_root.empty())
	{
		xml_node node_child = root.child(name.c_str());

		if (node_child.empty())
			return true;
		else
		{
			xml_attribute attribute_child = node_child.attribute("Value");
			if (attribute_child.empty())
			{
				string strChildValue = node_child.child_value();
				Strip(strChildValue);
				if (strChildValue.empty())
				{
					xml_node node_value = node_child.child("Value");
					if (node_value.empty())
						return true;
					else
					{
						string strGrandValue = node_value.child_value();
						Strip(strGrandValue);
						value = strGrandValue;
					}
				}
				else
					value = strChildValue;				
			}
			else
				value = attribute_child.as_string();
		}
	}
	else
		value = attribute_root.as_string();
	
	return false;
}

bool GetIntegerValue(xml_node root, string name, int& value)
{
	xml_attribute attribute_root = root.attribute(name.c_str());

	if (attribute_root.empty())
	{
		xml_node node_child = root.child(name.c_str());

		if (node_child.empty())
			return true;
		else
		{
			xml_attribute attribute_child = node_child.attribute("Value");
			if (attribute_child.empty())
			{
				string strChildValue = node_child.child_value();
				Strip(strChildValue);
				if (strChildValue.empty())
				{
					xml_node node_value = node_child.child("Value");
					if (node_value.empty())
						return true;
					else
					{
						string strGrandValue = node_value.child_value();
						Strip(strGrandValue);
						value = atoi(strGrandValue.c_str());
					}
				}
				else
					value = atoi(strChildValue.c_str());
			}
			else
				value = attribute_child.as_int();
		}
	}
	else
		value = attribute_root.as_int();

	return false;
}

bool GetDoubleValue(xml_node root, string name, double& value)
{
	xml_attribute attribute_root = root.attribute(name.c_str());

	if (attribute_root.empty())
	{
		xml_node node_child = root.child(name.c_str());

		if (node_child.empty())
			return true;
		else
		{
			xml_attribute attribute_child = node_child.attribute("Value");
			if (attribute_child.empty())
			{
				string strChildValue = node_child.child_value();
				Strip(strChildValue);
				if (strChildValue.empty())
				{
					xml_node node_value = node_child.child("Value");
					if (node_value.empty())
						return true;
					else
					{
						string strGrandValue = node_value.child_value();
						Strip(strGrandValue);
						value = atof(strGrandValue.c_str());
					}
				}
				else
					value = atof(strChildValue.c_str());				
			}
			else
				value = attribute_child.as_double();
		}
	}
	else
		value = attribute_root.as_double();

	return false;
}

bool GetColorValue(xml_node root, string name, SDL_Color& value)
{
	xml_attribute attribute_root = root.attribute(name.c_str());

	if (attribute_root.empty())
	{
		xml_node node_child = root.child(name.c_str());

		if (node_child.empty())
			return true;
		else
		{
			xml_attribute attribute_child = node_child.attribute("Value");
			if (attribute_child.empty())
			{
				string strChildValue = node_child.child_value();
				Strip(strChildValue);
				if (strChildValue.empty())
				{
					xml_node node_value = node_child.child("Value");
					if (node_value.empty())
						return true;
					else
					{
						string strGrandValue = node_value.child_value();
						Strip(strGrandValue);
						return ConvertStringToColor(strGrandValue, value);
					}
				}
				else
					return ConvertStringToColor(strChildValue, value);
			}
			else
				return ConvertStringToColor(attribute_child.as_string(), value);
		}
	}
	else
		return ConvertStringToColor(attribute_root.as_string(), value);
}

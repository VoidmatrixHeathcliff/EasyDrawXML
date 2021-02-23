#ifndef _ELEMENT_H_
#define _ELEMENT_H_

class Element
{
public:
	Element(int layer) : _iLayer(layer) {}
	~Element() {}
	virtual void Update() {}
	int GetLayer();

private:
	int _iLayer;
};

#endif // !_ELEMENT_H_

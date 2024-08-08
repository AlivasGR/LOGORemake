#pragma once
#include "NumberType.h"
#include "graphics_api\hy352_gui.h"
class SetXY {
	double cx, cy;
public:
	SetXY(LogoType&);
	SetXY(Object& o);
	bool operator,(LogoType&);
	bool operator,(Object&);
};
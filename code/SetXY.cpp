#include "SetXY.h"
#include <iostream>

SetXY::SetXY(LogoType& x) : cy(0) {
	try {
		cx = (double) dynamic_cast<NumberType&>(x);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATION ARGUMENT ERROR: Only NUMBER arguments allowed - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
}

bool SetXY::operator,(LogoType& y) {
	try {
		this->cy = (double) dynamic_cast<NumberType&>(y);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATION ARGUMENT ERROR: Only NUMBER arguments allowed - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	if (cx != -1) turtle_go_to_position((int)cx, (int)cy); 
	return true;
}

SetXY::SetXY(Object& o) : SetXY((LogoType&)o) {

}

bool SetXY::operator,(Object& o) {
	return (*this, (LogoType&) o);
}
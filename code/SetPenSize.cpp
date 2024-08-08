#include "SetPenSize.h"
#include <iostream>

SetPenSize::SetPenSize() {
	
}

void SetPenSize::operator=(LogoType& width) {
	try {
		dynamic_cast<NumberType&>(width);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATION ARGUMENT ERROR: Only NUMBER arguments allowed - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	NumberType stp = dynamic_cast<NumberType&>(width);
	if (stp.isInteger()) {
		if (stp.getValue() != -1)set_pen_thickness((float)stp.getValue());
	}
	else {
		if (stp.getFValue() != -1)set_pen_thickness((float)stp.getFValue());
	}
}

void SetPenSize::operator=(Object width) {
	operator=((LogoType&)width);
}
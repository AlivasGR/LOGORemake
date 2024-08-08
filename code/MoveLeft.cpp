#include "MoveLeft.h"
#include <iostream>

MoveLeft::MoveLeft() {
	
}

void MoveLeft::operator=(LogoType& angle) {
	try {
		dynamic_cast<NumberType&>(angle);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATION ARGUMENT ERROR: Only NUMBER arguments allowed - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	NumberType stp = dynamic_cast<NumberType&>(angle);
	if (stp.isInteger()) {
		turtle_rotate(-stp.getValue());
	}
	else {
		turtle_rotate((int)(-stp.getFValue()));
	}
}

void MoveLeft::operator=(Object angle) {
	operator=((LogoType&)angle);
}
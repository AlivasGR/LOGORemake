#include "MoveForward.h"
#include <iostream>

MoveForward::MoveForward() {

}

void MoveForward::operator=(LogoType& steps) {
	try {
		dynamic_cast<NumberType&>(steps);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATION ARGUMENT ERROR: Only NUMBER arguments allowed - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	NumberType stp = dynamic_cast<NumberType&>(steps);
	if (stp.isInteger()) {
		turtle_mv_forward((float)(stp.getValue()));
	}
	else {
		turtle_mv_forward((float)stp.getFValue());
	}
}

void MoveForward::operator=(Object steps) {
	operator=((LogoType&)steps);
}
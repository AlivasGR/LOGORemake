#include "MoveBackward.h"
#include <iostream>

MoveBackward::MoveBackward() {
	
}

void MoveBackward::operator=(LogoType& steps) {
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
		turtle_mv_backward((float)stp.getValue());
	}
	else {
		turtle_mv_backward((float)stp.getFValue());
	}
}

void MoveBackward::operator=(Object steps) {
	operator=((LogoType&)steps);
}
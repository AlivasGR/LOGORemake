#include "MakeCircle.h"
#include <iostream>


MakeCircle::MakeCircle() {

}

void MakeCircle::operator=(LogoType& radius) {
	try {
		dynamic_cast<NumberType&>(radius);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATION ARGUMENT ERROR: Only NUMBER arguments allowed - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	NumberType r = dynamic_cast<NumberType&>(radius);
	if (r.isInteger()) {
		turtle_draw_circle(r.getValue());
	}
	else {
		turtle_draw_circle((unsigned)r.getFValue());
	}
}

void MakeCircle::operator=(Object radius) {
	operator=((LogoType&)radius);
}


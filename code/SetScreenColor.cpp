#include "SetScreenColor.h"
#include <iostream>

SetScreenColor::SetScreenColor() {
	
}

void SetScreenColor::operator=(LogoType& r) {
	try {
		dynamic_cast<ListType&>(r);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATION ARGUMENT ERROR: Only LIST argument allowed - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	ListType stp = dynamic_cast<ListType&>(r);
	unsigned rc = 0, gc = 0, bc = 0;
	try {
		if (stp.getSize() != 3) throw std::invalid_argument("Incorrect list size");
		rc = (int)dynamic_cast<NumberType&>(stp.getAt(0));
		if (rc < 0 || rc > 255) throw std::invalid_argument("Incorrect value for red");
		gc = (int)dynamic_cast<NumberType&>(stp.getAt(1));
		if (gc < 0 || gc > 255) throw std::invalid_argument("Incorrect value for green");
		bc = (int)dynamic_cast<NumberType&>(stp.getAt(2));
		if (rc < 0 || rc > 255) throw std::invalid_argument("Incorrect value for blue");
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATION ARGUMENT ERROR: Only NUMBER arguments allowed - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	catch (std::invalid_argument &e) {
		std::cout << "OPERATION ARGUMENT ERROR: " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	set_screen_color(rc, gc, bc);
}

void SetScreenColor::operator=(Object r) {
	operator=((LogoType&)r);
}
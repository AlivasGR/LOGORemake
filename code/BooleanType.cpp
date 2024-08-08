#include "BooleanType.h"
#include <iostream>

BooleanType::BooleanType(bool v) : value(v) {

}

bool BooleanType::getValue() const {
	return value;
}

void BooleanType::setValue(bool v) {
	value = v;
}

LogoType * BooleanType::clone() {
	BooleanType * temp = new BooleanType(this->getValue());
	return temp;
}

bool BooleanType::operator==(const LogoType& r) {
	try {
		dynamic_cast<const BooleanType&>(r);
	}
	catch (std::bad_cast) {
		return false;
	}
	BooleanType right = dynamic_cast<const BooleanType&>(r);
	if (this->getValue() == right.getValue()) {
		return true;
	}
	else return false;
}

bool BooleanType::operator!=(const LogoType& r) {
	if (!(*(this) == r)) {
		return true;
	}
	else return false;
}

bool BooleanType::operator>(const LogoType& other) {
	try {
		dynamic_cast<const BooleanType&>(other);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATOR ARGUMENT ERROR: Cannot compare BOOLEAN to other types - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	return value > dynamic_cast<const BooleanType&>(other).getValue();
}

bool BooleanType::operator<(const LogoType& other) {
	return (!(*this > other) && !(*this == other));
}

bool BooleanType::operator>=(const LogoType& other) {
	return !(*this < other);
}

bool BooleanType::operator<=(const LogoType& other) {
	return !(*this > other);
}

std::string BooleanType::toString() {
	return getValue() ? std::string("true") : std::string("false");
}
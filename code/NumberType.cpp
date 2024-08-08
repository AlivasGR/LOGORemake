#include "NumberType.h"
#include <typeinfo>
#include <string>
#include <iostream>

NumberType::NumberType(int v) : value(v), isInt(true) {
	fvalue = 404;
}

NumberType::NumberType(double v) : fvalue(v), isInt(false) {
	value = 404;
}

NumberType::NumberType(const NumberType& c) : isInt(c.isInteger()) {
	this->value = c.getValue();
	this->fvalue = c.getFValue();
}

int NumberType::getValue() const {
	return value;
}

void NumberType::setValue(int v) {
	value = v;
}

double NumberType::getFValue() const {
	return fvalue;
}

void NumberType::setFValue(double v) {
	fvalue = v;
}

bool NumberType::isInteger() const {
	return isInt;
}

LogoType* NumberType::clone(){
	NumberType *ret = (this->isInt == true)?(new NumberType(this->value)):(new NumberType(this->fvalue) );
	return ret;
}

NumberType::operator double() {
	return this->isInteger() ? this->getValue() : this->getFValue();
}

NumberType::operator int() {
	return this->isInteger() ? this->getValue() : (int)(this->getFValue());
}

NumberType::operator unsigned() {
	return this->isInteger() ? (unsigned)(this->getValue()): (unsigned)(this->getFValue());
}

NumberType& NumberType::operator=(const NumberType& v) {
	this->setFValue(v.getFValue());
	this->setValue(v.getValue());
	this->isInt = v.isInteger();
	return *this;
}

NumberType NumberType::operator+(NumberType& r) {
	if (this->isInteger()) {
		if (r.isInteger()) {
			return NumberType(this->getValue() + r.getValue());
		}
		else {
			return NumberType(this->getValue() + r.getFValue());
		}
	}
	else {
		if (r.isInteger()) {
			return NumberType(this->getFValue() + r.getValue());
		}
		else {
			return NumberType(this->getFValue() + r.getFValue());
		}
	}
}

NumberType NumberType::operator*(NumberType& r) {
	if (this->isInteger()) {
		if (r.isInteger()) {
			return NumberType(this->getValue() * r.getValue());
		}
		else {
			return NumberType(this->getValue() * r.getFValue());
		}
	}
	else {
		if (r.isInteger()) {
			return NumberType(this->getFValue() * r.getValue());
		}
		else {
			return NumberType(this->getFValue() * r.getFValue());
		}
	}
}

bool NumberType::operator==(const LogoType& r) {
	try {
		dynamic_cast<const NumberType&>(r);
	}
	catch (std::bad_cast) {
		return false;
	}
	NumberType right = dynamic_cast<const NumberType&>(r);
	if (this->isInteger()) {
		if (right.isInteger()) {
			if (this->getValue() == right.getValue()) {
				return true;
			}
			else return false;
		}
		else {
			if (this->getValue() == right.getFValue()) {
				return true;
			}
			else return false;
		}
	}
	else {
		if (right.isInteger()) {
			if (this->getFValue() == right.getValue()) {
				return true;
			}
			else return false;
		}
		else {
			if (this->getFValue() == right.getFValue()) {
				return true;
			}
			else return false;
		}
	}
}

bool NumberType::operator!=(const LogoType& r) {
	if (*(this) == r) return false;
	else return true;
}

bool NumberType::operator>(const LogoType& r) {
	try {
		dynamic_cast<const NumberType&>(r);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATOR ARGUMENT ERROR: Cannot compare NUMBER to other types - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	NumberType right = dynamic_cast<const NumberType&>(r);
	if (this->isInteger()) {
		if (right.isInteger()) {
			if (this->getValue() > right.getValue()) {
				return true;
			}
			else return false;
		}
		else {
			if (this->getValue() > right.getFValue()) {
				return true;
			}
			else return false;
		}
	}
	else {
		if (right.isInteger()) {
			if (this->getFValue() > right.getValue()) {
				return true;
			}
			else return false;
		}
		else {
			if (this->getFValue() > right.getFValue()) {
				return true;
			}
			else return false;
		}
	}
}

bool NumberType::operator<(const LogoType& r) {
	return (!(*(this) > r) && !(*(this) == r));
}

bool NumberType::operator>=(const LogoType& r) {
	return !(*(this) < r);
}

bool NumberType::operator<=(const LogoType& r) {
	return !(*(this) > r);
}

std::string NumberType::toString() {
	return (isInteger() ? std::to_string(getValue()) : std::to_string(getFValue()));
}
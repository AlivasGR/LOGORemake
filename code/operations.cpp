#include "operations.h"
#include <iostream>

const NumberType& getNumberFromType(const LogoType& r) {
	try {
		dynamic_cast<const NumberType&>(r);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATION ARGUMENT ERROR: All arguments in arithmetic operation must be NUMBERS - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	return dynamic_cast<const NumberType&>(r);
}

const BooleanType& getBooleanFromType(const LogoType& r) {
	try {
		dynamic_cast<const BooleanType&>(r);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATION ARGUMENT ERROR: All arguments in boolean operation must be BOOLEANS - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	return dynamic_cast<const BooleanType&>(r);
}

NumberType difference(const LogoType& a, const LogoType& b) {
	const NumberType& ar = getNumberFromType(a);
	const NumberType& br = getNumberFromType(b);
	if (ar.isInteger()) {
		if (br.isInteger()) {
			return NumberType(ar.getValue() - br.getValue());
		}
		else {
			return NumberType(ar.getValue() - br.getFValue());
		}
	}
	else {
		if (br.isInteger()) {
			return NumberType(ar.getFValue() - br.getValue());
		}
		else {
			return NumberType(ar.getFValue() - br.getFValue());
		}
	}
}

NumberType minusOperation(const LogoType& a) {
	const NumberType& ar = getNumberFromType(a);
	if (ar.isInteger()) return -ar.getValue();
	else return -ar.getFValue();
}

NumberType quotient(const LogoType& al, const LogoType& bl) {
	const NumberType& a = getNumberFromType(al);
	const NumberType& b = getNumberFromType(bl);
	if (a.isInteger()) {
		if (b.isInteger()) {
			return NumberType(a.getValue() / b.getValue());
		}
		else {
			return NumberType(a.getValue() / b.getFValue());
		}
	}
	else {
		if (b.isInteger()) {
			return NumberType(a.getFValue() / b.getValue());
		}
		else {
			return NumberType(a.getFValue() / b.getFValue());
		}
	}
}

NumberType modulo(const LogoType& al, const LogoType& bl) {
	const NumberType& a = getNumberFromType(al);
	const NumberType& b = getNumberFromType(bl);
	if (a.isInteger() && b.isInteger()) {
		return NumberType(a.getValue() % b.getValue());
	}
	else {
		std::cout << "OPERATION ARGUMENT ERROR: All arguments in MODULO operation must be INTEGERS" << std::endl;
		system("pause");
		exit(-1);
	}
}

BooleanType not(LogoType &a) {
	const BooleanType& al = getBooleanFromType(a);
	return BooleanType(!(al.getValue()));
}

bool getAndOfVector(std::vector<LogoType *>& r) {
	bool sum = true;
	for (LogoType * l : r) {
		try {
			BooleanType * temp = dynamic_cast<BooleanType *>(l);
			if (temp == nullptr) throw(std::bad_cast());
		}
		catch (std::bad_cast &e) {
			std::cout << "TYPE ERROR: " << e.what() << std::endl;
			system("pause");
			exit(-1);
		}
		BooleanType temp = *(dynamic_cast<BooleanType *>(l));
		sum = sum && temp.getValue();
	}
	return sum;
}

bool getOrOfVector(std::vector<LogoType *>& r) {
	bool sum = false;
	for (LogoType * l : r) {
		try {
			BooleanType * temp = dynamic_cast<BooleanType *>(l);
			if (temp == nullptr) throw(std::bad_cast());
		}
		catch (std::bad_cast &e) {
			std::cout << "TYPE ERROR: " << e.what() << std::endl;
			system("pause");
			exit(-1);
		}
		BooleanType temp = *(dynamic_cast<BooleanType *>(l));
		sum = sum || temp.getValue();
	}
	return sum;
}

NumberType getProductOfVector(std::vector<LogoType *>& r) {
	double sum = 1;
	int isum = 1;
	bool isInteger = true;
	for (LogoType * l : r) {
		try {
			NumberType * temp = dynamic_cast<NumberType *>(l);
			if (temp == nullptr) throw(std::bad_cast());
		}
		catch (std::bad_cast &e) {
			std::cout << "TYPE ERROR: " << e.what() << std::endl;
			system("pause");
			exit(-1);
		}
		NumberType temp = *(dynamic_cast<NumberType *>(l));
		if (isInteger) isInteger = temp.isInteger();
		sum *= temp.isInteger() ? temp.getValue() : temp.getFValue();
		isum *= (int)(temp.isInteger() ? temp.getValue() : temp.getFValue());
	}
	if (isInteger) return NumberType(isum);
	else return NumberType(sum);
}

NumberType getSumOfVector(std::vector<LogoType *>& r) {
	double sum = 0;
	int isum = 0;
	bool isInteger = true;
	for (LogoType * l : r) {
		try {
			NumberType * temp = dynamic_cast<NumberType *>(l);
			if (temp == nullptr) throw(std::bad_cast());
		}
		catch (std::bad_cast &e) {
			std::cout << "TYPE ERROR: " << e.what() << std::endl;
			system("pause");
			exit(-1);
		}
		NumberType temp = *(dynamic_cast<NumberType *>(l));
		if (isInteger) isInteger = temp.isInteger();
		sum += temp.isInteger() ? temp.getValue() : temp.getFValue();
		isum += (int)(temp.isInteger() ? temp.getValue() : temp.getFValue());
	}
	if (isInteger) return NumberType(isum);
	else return NumberType(sum);
}

And::And(LogoType& r) : value(getBooleanFromType(r)) {

}

And::And(std::vector<LogoType *>& r) : value(BooleanType(getAndOfVector(r))) {

}

BooleanType& And::getValue() {
	return And::value;
}

And::operator BooleanType&() {
	return And::getValue();
}

Or::Or(LogoType& r) : value(getBooleanFromType(r)) {

}

Or::Or(std::vector<LogoType *>& r) : value(BooleanType(getOrOfVector(r))) {

}

BooleanType& Or::getValue() {
	return Or::value;
}

Or::operator BooleanType&() {
	return Or::getValue();
}

Product::Product(LogoType& r) : value(getNumberFromType(r)) {

}

Product::Product(std::vector<LogoType *>& r) : value(getProductOfVector(r)) {

}

NumberType Product::getValue() {
	return Product::value;
}

Product::operator NumberType() {
	return Product::getValue();
}

Sum::Sum(LogoType& r) : value(getNumberFromType(r)) {

}

Sum::Sum(std::vector<LogoType *>& r) : value(getSumOfVector(r)) {

}

NumberType Sum::getValue() {
	return Sum::value;
}

Sum::operator NumberType() {
	return Sum::getValue();
}






#include "WordType.h"
#include <iostream>

WordType::WordType(const char * v) : value(v) {

}

std::string WordType::getValue() {
	return value;
}

void WordType::setValue(std::string v) {
	value = v;
}

LogoType * WordType::clone() {
	std::string s = this->getValue();
	WordType * temp = new WordType(s.c_str());
	return temp;
}

bool WordType::operator==(const LogoType& r) {
	try {
		dynamic_cast<const WordType&>(r);
	}
	catch (std::bad_cast) {
		return false;
	}
	WordType right = dynamic_cast<const WordType&>(r);
	if (this->getValue() == right.getValue()) {
		return true;
	}
	else return false;
}

bool WordType::operator==(const char * r) {
	return (*this)==((WordType)r);
}

bool WordType::operator!=(const LogoType& r) {
	if (!(*(this) == r)) {
		return true;
	}
	else return false;
}

bool WordType::operator!=(const char * r) {
	return !((*this) == ((WordType)r));
}

bool WordType::operator>(const LogoType& r) {
	try {
		dynamic_cast<const WordType&>(r);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATOR ARGUMENT ERROR: Cannot compare WORD to other types - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	WordType right = dynamic_cast<const WordType&>(r);
	if ((this->getValue().compare(right.getValue())) < 0) {
		return true;
	}
	else return false;
}

bool WordType::operator>(const char * r) {
	if ((this->getValue().compare(std::string(r))) < 0) {
		return true;
	}
	else return false;
}

bool WordType::operator<(const LogoType& r) {
	if (!(*(this) > r) && !(*(this) == r)) {
		return true;
	}
	else return false;
}

bool WordType::operator<(const char * r) {
	if ((this->getValue().compare(std::string(r))) > 0) {
		return true;
	}
	else return false;
}

bool WordType::operator>=(const LogoType& r) {
	if (!(*(this) < r)) {
		return true;
	}
	else return false;
}

bool WordType::operator>=(const char * r) {
	return (!((*this) < r));
}

bool WordType::operator<=(const LogoType& r) {
	if (!(*(this) > r)) {
	return true;
	}
	else return false;
}

bool WordType::operator<=(const char * r) {
	return (!((*this) > r));
}

std::string WordType::toString() {
	return value;
}
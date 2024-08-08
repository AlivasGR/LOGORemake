#include "LogoType.h"

LogoType::~LogoType() {

}
LogoType* LogoType::clone() {
	return nullptr;
}

LogoVector::LogoVector() {

}

LogoVector::LogoVector(unsigned int size) : std::vector<LogoType*>(size) {
	for (unsigned int i = 0; i < size; i++)
		this->operator[](i) = nullptr;
}

std::vector<LogoType*>& operator,(std::vector<LogoType*>& leftOfComma, LogoType &rightOfComma) {
	leftOfComma.push_back(&rightOfComma);
	return leftOfComma;
}

std::vector<LogoType*> operator,(LogoType& leftOfComma, Object &rightOfComma) {
	std::vector<LogoType*> result = std::vector<LogoType*>();
	result.push_back(&leftOfComma);
	result.push_back((LogoType*)rightOfComma);
	return result;
}

LogoVector::~LogoVector() {
	size_type sz = this->size();
	for (unsigned int i = 0; i < sz; i++) {
		if( (*this)[i] != nullptr )
			delete (*this)[i];
	}
}

LogoType::operator Object() {
	Object temp;
	temp.setData(clone());
	return temp;
}
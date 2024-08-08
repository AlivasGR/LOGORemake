#pragma once
#include "ArrayType.h"
#include <iostream>

/*
=====================ARRAY ITERATOR IMPLEMENTATION=================================
bool ArrayIter::operator!= (const ContIter& other) const {
	const ArrayIter& otherSentenceIter = dynamic_cast<const ArrayIter&>(other);
	return _pos != otherSentenceIter._pos;
}

LogoType& ArrayIter::operator*() const {
	return _p_list->getAt(_pos);
}

const ArrayIter& ArrayIter::operator++() {
	++_pos;
	return *this;
}
===================================================================================
*/

ArrayType::ArrayType() {
	list = LogoVector();
}

ArrayType::ArrayType(const ArrayType& other) {
	for (unsigned int i = 0; i < other.list.size(); i++) {
		if (other.list[i] != nullptr) list.push_back(other.list[i]->clone());
		else list.push_back(nullptr);
	}
}

ArrayType::ArrayType(unsigned int size) {
	list = LogoVector(size);
}

ArrayType::ArrayType(std::vector<LogoType*> initializer) {
	for (unsigned int i = 0; i < initializer.size(); i++) {
		list.push_back(initializer[i]->clone());
	}
}

ArrayType::~ArrayType() {

}

LogoType* ArrayType::clone() {
	ArrayType* tmp = new ArrayType();
	LogoVector::size_type sz = list.size();
	for (unsigned int i = 0; i < sz; i++) {
		if (list[i] != nullptr) 
			tmp->list.push_back( list[i]->clone() );
		else {
			tmp->list.push_back(nullptr);
		}
	}
	return tmp;
}

ArrayType& ArrayType::operator=(std::initializer_list<LogoType*> initializer) {
	for (LogoType* p : initializer) {
		list.push_back(p->clone());
	}
	return *this;
}

ArrayType& ArrayType::operator=(unsigned r) {
	this->list = LogoVector(r);
	return *this;
}

bool ArrayType::operator==(const LogoType& other){
	LogoVector::size_type sz = list.size();
	try {
		dynamic_cast<const ArrayType&>(other);
	}
	catch (std::bad_cast) {
		return false;
	}
	const ArrayType& right = dynamic_cast<const ArrayType&>(other);
	if (sz != right.getSize()) return false;
	for (unsigned int i = 0; i < sz; i++) {
		if (*list[i] != right.getAt(i))
			return false;
	}
	return true;
}

bool ArrayType::operator!=(const LogoType& other) {
	return !(*this == other);
}

bool ArrayType::operator>(const LogoType& other) {
	try {
		dynamic_cast<const ArrayType&>(other);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATOR ARGUMENT ERROR: Cannot compare ARRAY to other types - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	return (list.size() > dynamic_cast<const ArrayType&>(other).getSize());
}

bool ArrayType::operator<(const LogoType& other) {
	return (!(*this > other) && !(*this == other));
}

bool ArrayType::operator>=(const LogoType& other) {
	return !(*this < other);
}

bool ArrayType::operator<=(const LogoType& other) {
	return !(*this > other);
}

LogoType& ArrayType::getAt(unsigned int i) const {
	if (i >= list.size()) {
		std::cout << "ERROR:  Array index out of bounds in ITEM\n";
		system("pause");
		exit(-1);
	}
	if (list[i] == nullptr) {
		std::cout << "ERROR:  Attempted to access empty array element\n";
		system("pause");
		exit(-1);
	}
	return *list[i];
}

void ArrayType::setAt(unsigned int i, LogoType& newVal) {
	if (i >= list.size()) {
		std::cout << "ERROR:  Array index out of bounds in SETITEM\n";
		system("pause");
		exit(-1);
	}
	if(list[i] != nullptr)
		delete list[i];
	list[i] = newVal.clone();
}

unsigned ArrayType::getSize() const {
	return list.size();
}

std::string ArrayType::toString() {
	std::string s = "{";
	for (LogoType * t : list) {
		if (t != nullptr) {
			s.append(t->toString());
			s.append(", ");
		}
		else {
			s.append("<EMPTY>");
			s.append(", ");
		}
	}
	s = s.substr(0, s.size() - 2);
	s.append("}");
	return s;
}

ArrayType::operator std::vector<LogoType*>() {
	std::vector<LogoType *> returnedVector;
	for (LogoType* elem : list)
		returnedVector.push_back(elem);
	return list;
}
/*
=============ARRAY ITERATOR IMPLEMENTATION===============
ArrayIter ArrayType::begin(){
return ArrayIter(this, 0);
}

ArrayIter ArrayType::end() {
return ArrayIter(this, list.size());
}
=========================================================
*/
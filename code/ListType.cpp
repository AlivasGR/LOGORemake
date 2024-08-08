#include "ListType.h"
#include <iostream>

/* 
================ITERATOR IMPLEMENTATION FOR LIST===========================
bool ListIter::operator!= (const ContIter& other) const {
	const ListIter& otherListIter = dynamic_cast<const ListIter&>(other);
	return _pos != otherListIter._pos;
}

LogoType& ListIter::operator*() const {
	return _p_list->getAt(_pos);
}

const ListIter& ListIter::operator++() {
	++_pos;
	return *this;
}
===========================================================================
*/

ListType::ListType() {
	list = LogoVector();
}


ListType::~ListType() {
}

ListType::ListType(const ListType& other) {
	LogoVector::size_type sz = other.list.size();
	for (unsigned int i = 0; i < sz; i++) {
		if (other.list[i] != nullptr)
			list.push_back(other.list[i]->clone());
		else {
			list.push_back(nullptr);
		}
	}
}

LogoType* ListType::clone() {
	ListType* tmp = new ListType();
	LogoVector::size_type sz = list.size();
	for (unsigned int i = 0; i < sz; i++) {
		if (list[i] != nullptr)
			tmp->list.push_back(list[i]->clone() );
		else {
			tmp->list.push_back(nullptr);
		}
	}
	return tmp;
}

ListType& ListType::operator[](LogoType* toInsert){
	LogoType* temp = toInsert->clone();
	list.push_back(temp);
	return *this;
}

ListType& ListType::operator[](std::vector<LogoType*>& elementsToInsert){
	LogoVector::size_type sz = elementsToInsert.size();
	for (unsigned int i = 0; i < sz; i++) {
		LogoType* temp = elementsToInsert[i]->clone();
		list.push_back(temp);
	}
	return *this;
}

bool ListType::operator==(const LogoType& other){
	LogoVector::size_type sz = list.size();
	try {
		dynamic_cast<const ListType&>(other);
	}
	catch (std::bad_cast) {
		return false;
	}
	const ListType& right = dynamic_cast<const ListType&>(other);
	if (sz != right.getSize()) return false;
	for (unsigned int i = 0; i < sz; i++) {
		if (*list[i] != right.getAt(i))
			return false;
	}
	return true;
}

bool ListType::operator!=(const LogoType& other) {
	return !(*this == other);
}

bool ListType::operator>(const LogoType& other) {
	try {
		dynamic_cast<const ListType&>(other);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATOR ARGUMENT ERROR: Cannot compare LIST to other types - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	return (list.size() > dynamic_cast<const ListType&>(other).getSize());
}

bool ListType::operator<(const LogoType& other) {
	return (!(*this > other) && !(*this == other));
}

bool ListType::operator>=(const LogoType& other) {
	return !(*this < other);
}

bool ListType::operator<=(const LogoType& other) {
	return !(*this > other);
}

LogoType& ListType::getAt(unsigned int i) const {
	if (i >= list.size()) {
		std::cout << "ERROR:  List index out of bounds in ITEM\n";
		system("pause");
		exit(-1);
	}
	if (list[i] == nullptr) {
		std::cout << "ERROR:  Attempted to access empty list element\n";
		system("pause");
		exit(-1);
	}
	return *list[i];
}

LogoType& ListType::getAtDummy(unsigned int i) const {
	return getAt(i - 1);
}

void ListType::setAt(unsigned int i, LogoType& newVal) {
	if (i >= list.size()) {
		std::cout << "ERROR:  List index out of bounds in SETITEM\n";
		system("pause");
		exit(-1);
	}
	if( list[i] != nullptr)
		delete list[i];
	list[i] = newVal.clone();
}

std::string ListType::toString() {
	std::string s = "[";
	for (LogoType * t : list) {
		s.append(t->toString());
		s.append(", ");
	}
	s = s.substr(0, s.size() - 2);
	s.append("]");
	return s;
}

ListType::operator std::vector<LogoType*>() {
	std::vector<LogoType *> returnedVector;
	for (LogoType* elem : list)
		returnedVector.push_back(elem);
	return list;
}

/*
============ITERATOR IMPLEMENTATION FOR LIST==============
ListIter ListType::begin(){
	return ListIter(this, 0);
}

ListIter ListType::end(){
	return ListIter(this, list.size());
}
==========================================================
*/
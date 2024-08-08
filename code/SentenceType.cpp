#include "SentenceType.h"
#include <iostream>

/*
==========================SENTENCE ITERATOR IMPLEMENTATION================================
bool SentenceIter::operator!= (const ContIter& other) const {
	const SentenceIter& otherSentenceIter = dynamic_cast<const SentenceIter&>(other);
	return _pos != otherSentenceIter._pos;
}

LogoType& SentenceIter::operator*() const {
	return _p_list->getAt(_pos);
}

const SentenceIter& SentenceIter::operator++() {
	++_pos;
	return *this;
}
==========================================================================================
*/

SentenceType::SentenceType() {
	list = LogoVector();
}

SentenceType::SentenceType(LogoType &x) {
	try {
		dynamic_cast<WordType&>(x);
	}
	catch (std::bad_cast) {
		std::cout << "ARGUMENT ERROR: SENTENCE expects WORDS as arguments " << std::endl;
		system("pause");
		exit(-1);
	}
	list = LogoVector();
	list.push_back(x.clone());
}

SentenceType::SentenceType(std::vector<LogoType*> &v) {
	LogoVector::size_type sz = v.size();
	for (unsigned int i = 0; i < sz; i++) {
		WordType * temp = dynamic_cast<WordType *>(v[i]);
		if (temp == nullptr) {
			std::cout << "ARGUMENT ERROR: SENTENCE expects WORDS as arguments "<< std::endl;
			system("pause");
			exit(-1);
		}
		list.push_back(v[i]->clone());
	}
}

LogoType * SentenceType::clone() {
	LogoVector temp = LogoVector();
	for (LogoType * w : this->list) {
		if (w != nullptr) 
			temp.push_back(w->clone());
		else {
			temp.push_back(nullptr);
		}
	}
	return new SentenceType(temp);
}

bool SentenceType::operator==(const LogoType& other) {
	LogoVector::size_type sz = list.size();
	try {
		dynamic_cast<const SentenceType&>(other);
	}
	catch (std::bad_cast) {
		return false;
	}
	const SentenceType& right = dynamic_cast<const SentenceType&>(other);
	if (sz != right.getSize()) return false;
	for (unsigned int i = 0; i < sz; i++) {
		if (*list[i] != right.getAt(i))
			return false;
	}
	return true;
}

bool SentenceType::operator!=(const LogoType&other) {
	return !(*this == other);
}

bool SentenceType::operator>(const LogoType& other) {
	try {
		dynamic_cast<const SentenceType&>(other);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATOR ARGUMENT ERROR: Cannot compare SENTENCE to other types - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	return (list.size() > dynamic_cast<const SentenceType&>(other).getSize());
}

bool SentenceType::operator<(const LogoType& other) {
	return (!(*this > other) && !(*this == other));
}

bool SentenceType::operator>=(const LogoType& other) {
	return !(*this < other);
}

bool SentenceType::operator<=(const LogoType& other) {
	return !(*this > other);
}

unsigned SentenceType::getSize() const {
	return list.size();
}

LogoType& SentenceType::getAt(unsigned int i) const {
	if (i >= list.size()) {
		std::cout << "INDEX ERROR: SENTENCE index out of bounds" << std::endl;
		system("pause");
		exit(-1);
	}
	else {
		return *list[i];
	}
}

void SentenceType::setAt(unsigned int i, LogoType& newVal) {
	if (i >= list.size()) {
		std::cout << "INDEX ERROR: SENTENCE index out of bounds" << std::endl;
		system("pause");
		exit(-1);
	}
	try {
		dynamic_cast<WordType&>(newVal);
	}
	catch (std::bad_cast &e) {
		std::cout << "ERROR: Attempted to insert non-word in Sentence - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	if (list[i] != nullptr)
		delete list[i];
	list[i] = newVal.clone();
}

std::string SentenceType::toString() {
	std::string s = "SENTENCE: ";
	for (LogoType * t : list) {
		s.append(t->toString());
		s.append(" ");
	}
	s = s.substr(0, s.size() - 1);
	s.append(".");
	return s;
}

WordType* getWordFromTypeP(LogoType* r) {
	try {
		dynamic_cast<WordType*>(r);
	}
	catch (std::bad_cast &e) {
		std::cout << "TYPE ERROR: SENTENCE requires WORDS as arguments - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	return dynamic_cast<WordType*>(r);
}

SentenceType::operator std::vector<LogoType*>() {
	std::vector<LogoType *> returnedVector;
	for (LogoType* elem : list)
		returnedVector.push_back(elem);
	return list;
}

/*
==============SENTENCE ITERATOR IMPLEMENTATION=============
SentenceIter& SentenceType::begin() {
	return SentenceIter(this, 0);
}

SentenceIter& SentenceType::end() {
	return SentenceIter(this, list.size());
}
===========================================================
*/
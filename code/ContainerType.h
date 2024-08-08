#pragma once
#include "LogoType.h"

/*
====================CONTAINER ITERATOR DECLERATION=========================
class ContainerType;
class ContIterActual {
public:

	virtual bool operator!= (const ContIterActual& other) const = 0;

	virtual LogoType& operator* () const = 0;

	virtual const ContIterActual& operator++() = 0;
};

class ContIter {
private:
	ContIterActual* actualIterator;
};
===========================================================================
*/

class ContainerType : public LogoType {
public:
	virtual LogoType& getAt(unsigned int i) const = 0;

	virtual void setAt(unsigned int i, LogoType& newVal) = 0;

	virtual operator std::vector<LogoType*>() = 0;

	/*
	=========CONTAINER ITERATOR DECLERATION============
	virtual ContIter begin() = 0;

	virtual ContIter end() = 0;
	===================================================
	*/

};

LogoType& item(std::vector<unsigned int> indexes, LogoType& list);

void setItem(std::vector<unsigned int>indexes, LogoType& container, LogoType&newVal);
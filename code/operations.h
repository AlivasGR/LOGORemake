#pragma once
#include "NumberType.h"
#include "BooleanType.h"

const NumberType& getNumberFromType(const LogoType&);

const BooleanType& getBooleanFromType(const LogoType&);

NumberType difference(const LogoType&, const LogoType&);

NumberType minusOperation(const LogoType&);

NumberType quotient(const LogoType&, const LogoType&);

NumberType modulo(const LogoType&, const LogoType&);

BooleanType not(LogoType&);

bool getAndOfVector(std::vector<LogoType *>& r);

bool getOrOfVector(std::vector<LogoType *>& r);

NumberType getProductOfVector(std::vector<LogoType *>& r);

NumberType getSumOfVector(std::vector<LogoType *>& r);

class And {
	BooleanType value;
public:

	And(LogoType&);

	And(std::vector<LogoType *>&);

	BooleanType& getValue();

	operator BooleanType&();
};

class Or {
	BooleanType value;
public:

	Or(LogoType&);

	Or(std::vector<LogoType *>&);

	BooleanType& getValue();

	operator BooleanType&();
};

class Product {
	NumberType value;
public:

	Product(LogoType&);

	Product(std::vector<LogoType *>&);

	NumberType getValue();

	operator NumberType();
};

class Sum {
	NumberType value;
public:
	Sum(LogoType&);
	Sum(std::vector<LogoType *>&);
	NumberType getValue();
	operator NumberType();
};
#pragma once
#include<vector>
#include <typeinfo>
#include "Object.h"

class LogoVector;
class Object;

class LogoType {
public:

	LogoType() {

	}

	virtual ~LogoType();

	virtual LogoType * clone() = 0;

	friend std::vector<LogoType*> operator,(LogoType& leftOfComma, LogoType &rightOfComma) {
		std::vector<LogoType*> result = std::vector<LogoType*>();
		result.push_back(&leftOfComma);
		result.push_back(&rightOfComma);
		return result;
	}

	friend std::vector<LogoType*> operator,(LogoType& leftOfComma, Object &rightOfComma);
	
	friend std::vector<LogoType*>& operator,(std::vector<LogoType*>& leftOfComma, LogoType &rightOfComma);

	LogoType& operator+(LogoType& r) {
		return *this;
	}

	virtual bool operator==(const LogoType& other) = 0;

	virtual bool operator!=(const LogoType& other) = 0;

	virtual bool operator>(const LogoType& other) = 0;

	virtual bool operator<(const LogoType& other) = 0;

	virtual bool operator>=(const LogoType& other) = 0;

	virtual bool operator<=(const LogoType& other) = 0;

	operator LogoType*() {
		return this;
	}

	virtual std::string toString() = 0;

	virtual operator Object();
};


class LogoVector : public std::vector<LogoType*> {
public:

	LogoVector();

	LogoVector(unsigned int);

	~LogoVector();
};
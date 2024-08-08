#pragma once
#include"LogoType.h"

class LogoType;
class NumberType;
class BooleanType;
class Object {
private:
	LogoType* data;
public:
	Object();

	Object(Object&& other);

	Object(const Object& other);

	Object& operator=(Object&& other);

	Object& operator=(const Object& other);

	~Object();

	operator LogoType*();

	operator LogoType&();

	operator int();

	operator unsigned();

	operator bool();

	bool operator==(Object& other);

	bool operator!=(Object& other);

	bool operator>(Object& other);

	bool operator<(Object& other);

	bool operator>=(Object& other);

	bool operator<=(Object& other);

	bool operator==(const LogoType& other);

	bool operator!=(const LogoType& other);

	bool operator>(const LogoType& other);

	bool operator<(const LogoType& other);

	bool operator>=(const LogoType& other);

	bool operator<=(const LogoType& other);
	
	void setData(LogoType* newData);
};
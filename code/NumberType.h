#pragma once
#include "LogoType.h"
class NumberType : public LogoType {
	int value;
	double fvalue;
	bool isInt;
public:

	NumberType(int v);

	NumberType(double v);

	NumberType(const NumberType&);

	virtual LogoType* clone() override;

	int getValue() const;

	double getFValue() const;

	void setValue(int v);

	void setFValue(double v);

	bool isInteger() const;

	operator double();

	operator int();

	operator unsigned();

	bool operator==(const LogoType&) override;
	
	NumberType operator+(NumberType&);

	NumberType operator*(NumberType&);

	NumberType& operator=(const NumberType&);

	bool operator!=(const LogoType&) override;

	bool operator>(const LogoType&) override;

	bool operator<(const LogoType&) override;

	bool operator>=(const LogoType&) override;

	bool operator<=(const LogoType&) override;

	std::string toString() override;
};
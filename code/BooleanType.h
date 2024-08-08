#pragma once
#include "LogoType.h"
class BooleanType : public LogoType {
	bool value;
public:
	BooleanType(bool v);
	bool getValue() const;

	void setValue(bool v);

	virtual LogoType * clone();

	operator bool() {
		return value;
	}

	bool operator==(const LogoType&) override;

	bool operator!=(const LogoType&);

	bool operator>(const LogoType& other) override;

	bool operator<(const LogoType& other) override;

	bool operator>=(const LogoType& other) override;

	bool operator<=(const LogoType& other) override;

	std::string toString() override;

};
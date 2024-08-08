#pragma once
#include "LogoType.h"
#include <string>

class WordType : public LogoType {
	std::string value;
public:
	WordType(const char * v);

	std::string getValue();

	void setValue(std::string v);
	virtual ~WordType() {
		
	}
	virtual LogoType * clone() override;

	bool operator==(const LogoType&) override;

	bool operator==(const char *);

	bool operator!=(const LogoType&);

	bool operator!=(const char *);

	bool operator>(const LogoType&);

	bool operator>(const char *);

	bool operator<(const LogoType&);

	bool operator<(const char *);

	bool operator>=(const LogoType&);

	bool operator>=(const char *);

	bool operator<=(const LogoType&);

	bool operator<=(const char *);

	std::string toString() override;
};
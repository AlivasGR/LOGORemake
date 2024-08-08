#pragma once
#include <vector>
#include "ContainerType.h"
#include "WordType.h"

/*
===================SENTENCE ITERATOR DECLERATION===========================================
class SentenceType;
class BooleanType;
class SentenceIter : public ContIterActual {
public:
	SentenceIter(const SentenceType* p_list, int pos) : _pos(pos), _p_list(p_list) {

	}

	bool operator!= (const ContIterActual& other) const override;

	LogoType& operator* () const override;

	const SentenceIter& operator++() override;

private:
	int _pos;
	const SentenceType *_p_list;
};
============================================================================================
*/

WordType* getWordFromTypeP(LogoType* r);

class SentenceType : public ContainerType {
	LogoVector list;
public:
	SentenceType();

	SentenceType(LogoType &x);

	SentenceType(std::vector<LogoType*> &v);

	~SentenceType() {

	}

	/*
	========SENTENCE ITERATOR DECLERATION=======
	SentenceIter begin() override;

	SentenceIter end() override;
	============================================
	*/

	virtual LogoType * clone() override;

	bool operator==(const LogoType&) override;

	bool operator!=(const LogoType&) override;

	bool operator>(const LogoType&) override;

	bool operator<(const LogoType&) override;

	bool operator>=(const LogoType&) override;

	bool operator<=(const LogoType&) override;

	unsigned getSize() const;

	std::string toString() override;

	LogoType& getAt(unsigned int i) const override;

	void setAt(unsigned int i, LogoType& newVal) override;

	virtual operator std::vector<LogoType*>() override;
};
#pragma once
#include "LogoType.h"
#include "ContainerType.h"
#include<vector>
#include <iostream>

/*
===================LIST ITERATOR DECLERATION======================================
class ListType;
class BooleanType;
class ListIter : public ContIter {
public:
	ListIter(const ListType* p_list, int pos) : _pos(pos), _p_list(p_list){
	
	}
	
	bool operator!= (const ContIter& other) const override;

	LogoType& operator* () const override;

	const ListIter& operator++() override;

private:
	int _pos;
	const ListType *_p_list;
};
===================================================================================
*/

class ListType : public ContainerType {
private:
	LogoVector list;
public:
	ListType();
	ListType(const ListType& other);
	~ListType();

	virtual LogoType* clone() override;

	/*
	=======LIST ITERATOR DECLERATION=========
	ListIter begin() override;

	ListIter end() override;
	=========================================
	*/

	bool operator==(const LogoType& other) override;

	bool operator!=(const LogoType& other) override;

	ListType& operator=(ListType& v) {
		std::cout << "Hey" << std::endl;
		return *((ListType*)v.clone());
	}

	bool operator>(const LogoType&) override;

	bool operator<(const LogoType&) override;

	bool operator>=(const LogoType&) override;

	bool operator<=(const LogoType&) override;

	ListType& operator[](LogoType* toInsert);

	ListType& operator[](std::vector<LogoType*>& elementsToInsert);

	unsigned int getSize() const {
		return list.size();
	}

	LogoType& getAt(unsigned int i) const override;

	LogoType& getAtDummy(unsigned int i) const;

	void setAt(unsigned int i, LogoType& newVal) override;

	std::string toString() override;

	virtual operator std::vector<LogoType*>() override;
};
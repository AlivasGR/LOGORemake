#pragma once
#include "ContainerType.h"
#include<vector>
#include "NumberType.h"
#include <iostream>

/*
=====================ARRAY ITERATOR DECLERATION=====================================
class ArrayType;
class BooleanType;
class ArrayIter : public ContIter {
public:
	ArrayIter(const ArrayType* p_list, int pos) : _pos(pos), _p_list(p_list) {

	}

	bool operator!= (const ContIter& other) const override;

	LogoType& operator* () const override;

	const ArrayIter& operator++() override;

private:
	int _pos;
	const ArrayType *_p_list;
};
===================================================================================
*/

class ArrayType : public ContainerType {
private:
	LogoVector list;
public:
	ArrayType();
	ArrayType(unsigned int size);
	ArrayType(std::vector<LogoType*> initializer);
	ArrayType(const ArrayType& other);

	~ArrayType();

	virtual LogoType* clone() override;

	/*
	=============ARRAY ITERATOR DECLERATION===============
	ArrayIter begin() override;

	ArrayIter end() override;
	======================================================
	*/

	ArrayType& operator=(std::initializer_list<LogoType*>);

	ArrayType& operator=(unsigned);

	bool operator==(const LogoType& other) override;

	bool operator!=(const LogoType& other) override;

	bool operator>(const LogoType& other) override;

	bool operator<(const LogoType& other) override;

	bool operator>=(const LogoType& other) override;

	bool operator<=(const LogoType& other) override;

	LogoType& getAt(unsigned int i) const override;

	void setAt(unsigned int i, LogoType& newVal) override;

	virtual operator std::vector<LogoType*>() override; //return type?

	unsigned getSize() const;

	std::string toString() override;
	
};
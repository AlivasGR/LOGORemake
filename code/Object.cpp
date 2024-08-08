#pragma once
#include"Object.h"
#include "NumberType.h"
#include "BooleanType.h"
#include<iostream>

Object::Object() {
	data = nullptr;
}

Object::Object(Object&& other) {
	data = other.data;
	other.data = nullptr;
}

Object::Object(const Object& other) {
	if (other.data != nullptr)
		data = other.data->clone();
	else
		data = nullptr;
}

Object& Object::operator=(Object&& other) {
	if (&other != this) {
		if (data != nullptr)
			delete data;
		data = other.data;
		other.data = nullptr;
	}
	return *this;
}

Object& Object::operator=(const Object& other) {
	if (&other != this){
		if (data != nullptr)
			delete data;
		if (other.data != nullptr)
			data = other.data->clone();
		else
			data = nullptr;
	}
	return *this;
	
}

Object::~Object() {
	if(data != nullptr)
		delete data;
}

Object::operator LogoType*() {
	if (data == nullptr) {
		std::cout << "ERROR:  Trying to access data of unset variable\n";
		system("pause");
		exit(-1);
	}
	return data;
}

Object::operator LogoType&() {
	if (data == nullptr) {
		std::cout << "ERROR:  Trying to access data of unset variable\n";
		system("pause");
		exit(-1);
	}
	return *data;
}

Object::operator int() {
	try {
		dynamic_cast<NumberType&>(*data);
	}
	catch (std::bad_cast &e) {
		std::cout << "ERROR: bad cast from Object to int - " << e.what();
		system("pause");
		exit(-1);
	}
	return (dynamic_cast<NumberType&>(*data));
}

Object::operator unsigned() {
	try {
		dynamic_cast<NumberType&>(*data);
	}
	catch (std::bad_cast &e) {
		std::cout << "ERROR: bad cast from Object to unsigned int - " << e.what();
		system("pause");
		exit(-1);
	}
	return (dynamic_cast<NumberType&>(*data));
}

Object::operator bool() {
	try {
		dynamic_cast<BooleanType&>(*data);
	}
	catch (std::bad_cast &e) {
		std::cout << "ERROR: bad cast from Object to bool - " << e.what();
		system("pause");
		exit(-1);
	}
	return (dynamic_cast<BooleanType&>(*data));
}

bool Object::operator==(Object& other) {
	return *data == *other.data;
}

bool Object::operator!=(Object& other) {
	return *data != *other.data;
}

bool Object::operator>(Object& other) {
	return *data > *other.data;
}

bool Object::operator<(Object& other) {
	return *data < *other.data;
}

bool Object::operator>=(Object& other) {
	return *data >= *other.data;
}

bool Object::operator<=(Object& other) {
	return *data <= *other.data;
}


bool Object::operator==(const LogoType& other) {
	return *data == other;
}

bool Object::operator!=(const LogoType& other) {
	return *data != other;
}

bool Object::operator>(const LogoType& other) {
	return *data > other;
}

bool Object::operator<(const LogoType& other) {
	return *data < other;
}

bool Object::operator>=(const LogoType& other) {
	return *data >= other;
}

bool Object::operator<=(const LogoType& other) {
	return *data <= other;
}

void Object::setData(LogoType* newData) {
	if (data != nullptr)
		delete data;
	data = newData;
}
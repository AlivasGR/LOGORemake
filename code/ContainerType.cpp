#pragma once
#include "ContainerType.h"
#include <iostream>

LogoType& item(std::vector<unsigned int>indexes, LogoType& list) {
	std::vector<unsigned int>::size_type sz = indexes.size();
	try {
		dynamic_cast<ContainerType&>(list);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATOR ARGUMENT ERROR: Accessing something that is not a container - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	ContainerType& cont = dynamic_cast<ContainerType&>(list);
	if (sz == 1)
		return cont.getAt(indexes[0] - 1);
	std::vector<unsigned int> subIndexes;
	for (unsigned int i = 1; i < sz; i++) {
		subIndexes.push_back(indexes[i]);
	}
	LogoType& subList = dynamic_cast<LogoType&>(cont.getAt(indexes[0] - 1));
	return item(subIndexes, subList);
}

void setItem(std::vector<unsigned int>indexes, LogoType& container, LogoType&newVal) {
	std::vector<unsigned int>::size_type sz = indexes.size();
	try {
		dynamic_cast<ContainerType&>(container);
	}
	catch (std::bad_cast &e) {
		std::cout << "OPERATOR ARGUMENT ERROR: Accessing somehting that isn't a container - " << e.what() << std::endl;
		system("pause");
		exit(-1);
	}
	ContainerType& cont = dynamic_cast<ContainerType&>(container);
	if (sz == 1) {
		cont.setAt(indexes[0] - 1, newVal);
		return;
	}
	std::vector<unsigned int> subIndexes;
	for (unsigned int i = 1; i < sz; i++) {
		subIndexes.push_back(indexes[i]);
	}
	LogoType& subList = dynamic_cast<LogoType&>(cont.getAt(indexes[0] - 1));
	setItem(subIndexes, subList, newVal);
}
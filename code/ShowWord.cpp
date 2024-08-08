#include "ShowWord.h"

ShowWord::ShowWord() {

}

void ShowWord::operator=(Object r) {
	std::cout << ((LogoType&)(r)).toString() << std::endl;
}
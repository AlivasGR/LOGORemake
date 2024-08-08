#include "PrintWord.h"

PrintWord::PrintWord() {
	
}

void PrintWord::operator=(LogoType& r) {
	turtle_draw_label((r.toString()).c_str());
}

void PrintWord::operator=(Object r) {
	operator=((LogoType&)r);
}
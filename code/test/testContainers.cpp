#include  <iostream>
#include "../LOGO.h"
#ifdef TESTCONTAINERS

START_PROGRAM
MAKE y = WORD : "SECRET"
MAKE x = LIST[
	NUMBER:21,
		WORD : "Hello",
		ARRAY{
			BOOLEAN: TRUE,
			SENTENCE(WORD : "Foo",  WORD : "Bar"),
			NUMBER : 22,
			y
	}
]
SHOW: ITEM({ 3,2 }, x)
SETITEM({ 3, 2, 1 }, x, ITEM({ 3,2,2 }, x))
SETITEM({ 3, 2, 2 }, x, WORD: "Foo")
SHOW : ITEM({ 3,2 }, x)
SHOW : x
SETITEM({ 3, 4 }, x, ARRAY SIZE : 5)
SETITEM({ 3, 4, 2 }, x, WORD: "Dust in the wind")
SHOW : x
MAKE yy = ITEM({ 3, 3 }, x)
SHOW : yy
ASSIGN yy = x
SHOW : yy
SHOW : x
SETITEM({ 1 }, x, yy)
SHOW : x
ASSIGN x = LIST[ITEM({ 1 }, yy), ITEM({3}, yy)]
SHOW: x
ASSIGN x = LIST[ITEM({ 1 }, yy), ITEM({ 3, 1 }, yy), ITEM({ 3,2 }, yy), ITEM({ 3,3 }, yy), ITEM({ 3,4 }, yy)]
SHOW: x
; system("pause")
END_PROGRAM

#endif
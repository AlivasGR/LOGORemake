#include "../LOGO.h"

#ifdef TURTLETEST
START_PROGRAM
MAKE L = LIST[NUMBER:0, NUMBER : 0, NUMBER : 0]
SETSCREENCOLOR L
SETPENCOLOR LIST[NUMBER: 255, NUMBER: 255, NUMBER: 255]
SETPENSIZE NUMBER: 20
PENUP
FORWARD NUMBER: 800
LEFT NUMBER: 90
FORWARD NUMBER: 1600
RIGHT NUMBER: 180
PENDOWN
FORWARD NUMBER: 400
SETPENCOLOR LIST[NUMBER: 255, NUMBER: 0, NUMBER: 0]
MAKE x = NUMBER: 400
FORWARD x
SETPENCOLOR LIST[NUMBER: 0, NUMBER: 255, NUMBER: 0]
MAKE l = LIST[NUMBER:400]
FORWARD ITEM({ 1 }, l)
SETPENCOLOR LIST[NUMBER: 0, NUMBER: 0, NUMBER: 255]
MAKE a = ARRAY{ NUMBER:400 }
FORWARD ITEM({ 1 }, a)
RIGHT NUMBER: 180
SETPENCOLOR LIST[NUMBER:255, NUMBER : 255, NUMBER : 255]
BACK NUMBER : 400
SETPENCOLOR LIST[NUMBER:255, NUMBER : 0, NUMBER : 0]
BACK x
SETPENCOLOR LIST[NUMBER:0, NUMBER : 255, NUMBER : 0]
BACK ITEM({ 1 }, l)
SETPENCOLOR LIST[NUMBER:0, NUMBER : 0, NUMBER : 255]
BACK ITEM({ 1 }, a)
PENUP
CENTER
FORWARD NUMBER: 1000
PENDOWN
SETPENCOLOR LIST[NUMBER: 200, NUMBER: 150, NUMBER: 0]
REPEAT 90 TIMES DO
	FORWARD NUMBER: 10
	RIGHT NUMBER: 2
END
RIGHT NUMBER: 90
PENUP
FORWARD NUMBER: 280
LEFT NUMBER: 90
REPEAT 2 TIMES DO
	PENUP
	FORWARD NUMBER: 400
	PENDOWN
	REPEAT 4 TIMES DO
		FORWARD NUMBER: 150
		RIGHT NUMBER: 180
		FORWARD NUMBER: 150
		RIGHT NUMBER: 90
	END
END
PENUP
FORWARD NUMBER: 1000
PENDOWN
SETPENCOLOR LIST[NUMBER: 147, NUMBER: 215, NUMBER: 255]
PRINT WORD: "C++ can do this. Java can't. Deal with it O:)"
PENUP
CENTER
ASSIGN L = LIST[NUMBER:1000, NUMBER : 2000, ARRAY{ NUMBER: 800, NUMBER : 4000 }]
SETXY  ITEM({ 1 }, L), NUMBER: 800
CIRCLE NUMBER: 150
; system("pause")
END_PROGRAM
#endif
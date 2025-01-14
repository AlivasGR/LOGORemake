#include "../LOGO.h"
#ifdef POLYGONTEST

TO drawPolygon WITH arg FSTART
PENUP
IF ARG(1) < (NUMBER:3) DO
	SHOW : WORD:"Invalid argument for polygon!!"
	RETURN
	END
	MAKE side = ARG(2)
	MAKE angle = QUOTIENT(NUMBER : 360, ARG(1))

	MAKE counter = NUMBER : 0
	PENDOWN
	REPEAT WHILE counter < ARG(1) DO
		FORWARD side
		RIGHT DIFFERENCE(NUMBER : 180, DIFFERENCE(NUMBER : 180, angle))
		ASSIGN counter = SUM(counter, NUMBER:1)
	END
	PENUP
FEND

START_PROGRAM
	PENUP
	SETXY NUMBER : 1000, NUMBER : 700
	CALL drawPolygon(LIST[NUMBER:3, NUMBER : 300])
	SETXY NUMBER : 300, NUMBER : 300
	CALL drawPolygon(LIST[NUMBER:4, NUMBER : 300])
	SETXY NUMBER : 300, NUMBER : 700
	CALL drawPolygon(LIST[NUMBER:6, NUMBER : 300])
	SETXY NUMBER : 900, NUMBER : 400
	CALL drawPolygon(LIST[NUMBER:8, NUMBER : 300])
	REPEAT 8 TIMES DO
		FORWARD NUMBER : 300
		RIGHT NUMBER : 120
		CALL drawPolygon(LIST[NUMBER:3, NUMBER : 300])
		LEFT NUMBER:75
	END
	;system("pause")
END_PROGRAM
#endif
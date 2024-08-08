#include "../LOGO.h"

#ifdef FUNCTIONTEST

TO showArgsFuncton WITH fargs FSTART
	SHOW : WORD: "ENTERED FUNCTION"
	SHOW : fargs
	SHOW : ARG(1)
	SHOW : WORD : "EXITING FUNCTION"
FEND

TO powerFunction WITH f4args FSTART
	MAKE base = ARG(1)
	MAKE exp = ARG(2)
	MAKE I = 
	NUMBER: 1
	MAKE res = NUMBER: 1
	REPEAT WHILE I <= exp DO
		ASSIGN res = PRODUCT(res, base)
		ASSIGN I = SUM(I, NUMBER: 1)
	END
	ASSIGN I = NUMBER: 1
	REPEAT WHILE I <= res DO 
		PRINTOUT "="
		ASSIGN I = SUM(I, NUMBER: 1)
	END
FEND

TO printerFunction WITH f3args FSTART
	MAKE I = NUMBER : 1
	PRINTOUT "*"
	CALL powerFunction(LIST[NUMBER: 2, DIFFERENCE(ARG(1), NUMBER: 1)])
	PRINTOUT ARG(2).toString() << ARG(1).toString() << BR
FEND

TO recursiveFunction WITH f2args FSTART
	MAKE end = ARG(1)
	CALL printerFunction(LIST[ARG(1), WORD: "CALL: "])
	IF ARG(1) == ARG(2) DO
		CALL printerFunction(LIST[ARG(1), WORD:"RETURN: "])
		RETURN
	ELSE
		MAKE N1 = SUM(ARG(1), NUMBER: 1)
		MAKE N2 = SUM(ARG(2), NUMBER: 0)
		MAKE L = LIST[N1, N2]
		CALL recursiveFunction(L)
		CALL printerFunction(LIST[ARG(1), WORD:"RETURN: "])
	END
FEND

START_PROGRAM
CALL recursiveFunction(LIST[NUMBER:1, NUMBER: 8])
; system("pause")
END_PROGRAM
#endif
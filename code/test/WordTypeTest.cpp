#include "../LOGO.h"
#ifdef WORDTYPETEST
START_PROGRAM
MAKE x = WORD: "HELLO"
MAKE y = WORD:"WORLD"
MAKE z = WORD:"HELLO"
PRINTOUT "x = "
SHOW: x
PRINTOUT "y = "
SHOW : y
PRINTOUT "z = "
SHOW : z

IF x == z DO
	SHOW: WORD:"PASSED"
ELSE
	SHOW : WORD:"FAILED"
END

IF x != y DO
	SHOW: WORD:"PASSED"
ELSE
	SHOW : WORD:"FAILED"
END

MAKE sent = SENTENCE(WORD:"HELLO", WORD:"WORLD")

IF x == ITEM({ 1 }, sent) DO
	SHOW : WORD:"PASSED"
ELSE
	SHOW : WORD:"FAILED"
END

IF ITEM({ 2 }, sent) == (WORD:"WORLD") DO
	SHOW : WORD:"PASSED"
ELSE
	SHOW : WORD:"FAILED"
END



PRINT x
RIGHT NUMBER:90
PENUP
FORWARD NUMBER:200
PRINT y
RIGHT NUMBER:90
FORWARD NUMBER:200
PRINT sent
;system("pause")
END_PROGRAM
#endif
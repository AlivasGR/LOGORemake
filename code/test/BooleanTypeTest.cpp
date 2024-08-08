#include "../LOGO.h"
#ifdef BOOLEANTYPETEST
START_PROGRAM
SHOW : WORD:"=================================================="
MAKE L = LIST[BOOLEAN:FALSE, BOOLEAN : FALSE]
MAKE x1 = BOOLEAN : TRUE
SETITEM({ 1 }, L, x1)
SHOW : WORD : "TEST 1 - Decleration:"
SHOW : WORD : "--Expected:"
SHOW : WORD : "true"
SHOW : WORD : "--Actual: "
SHOW : x1
SHOW : WORD:"------------"
ASSIGN x1 = BOOLEAN : FALSE
SHOW : WORD:"TEST 2 - Assignment:"
SHOW : WORD : "--Expected:"
SHOW : WORD : "false"
SHOW : WORD : "--Actual"
SHOW : x1
SHOW : WORD: "TEST 3 - Operations:"
SHOW : WORD : "TEST 3.1 - NOT:"
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : TRUE
SHOW : WORD: "--Actual"
SHOW : NOT(BOOLEAN : FALSE)
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : TRUE
SHOW : WORD: "--Actual"
SHOW : NOT(x1)
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : FALSE
SHOW : WORD: "--Actual"
SHOW : ITEM({ 2 }, L)
SHOW : WORD : "TEST 3.2 - AND:"
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : TRUE
SHOW : WORD: "--Actual"
SHOW : AND(BOOLEAN : TRUE)
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : FALSE
SHOW : WORD: "--Actual"
SHOW : AND(BOOLEAN : FALSE, BOOLEAN : TRUE)
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : FALSE
SHOW : WORD: "--Actual"
SHOW : AND(BOOLEAN : FALSE, BOOLEAN : TRUE, BOOLEAN : FALSE)
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : TRUE
SHOW : WORD: "--Actual"
SHOW : AND(NOT(x1))
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : FALSE
SHOW : WORD: "--Actual"
MAKE x2 = AND(ITEM({ 2 }, L), ITEM({ 1 }, L))
SHOW : x2
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : FALSE
SHOW : WORD: "--Actual"
SHOW : AND(x2, NOT(x1), BOOLEAN : TRUE, ITEM({ 2 }, L))
SHOW : WORD : "TEST 3.3 - OR:"
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : TRUE
SHOW : WORD: "--Actual"
SHOW : OR(BOOLEAN : TRUE)
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : FALSE
SHOW : WORD: "--Actual"
SHOW : OR(BOOLEAN : FALSE, BOOLEAN : FALSE)
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : TRUE
SHOW : WORD: "--Actual"
SHOW : OR(BOOLEAN : FALSE, BOOLEAN : TRUE, BOOLEAN : FALSE)
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : TRUE
SHOW : WORD: "--Actual"
SHOW : OR(NOT(x1))
SHOW : WORD : "--Expected: "
SHOW : BOOLEAN : TRUE
SHOW : WORD: "--Actual"
ASSIGN x2 = OR(ITEM({ 2 }, L), ITEM({ 1 }, L))
SHOW : x2
MAKE x3 = OR(ITEM({ 2 }, L), NOT(ITEM({ 1 }, L)))
SHOW : WORD: "--Expected: "
SHOW : BOOLEAN : FALSE
SHOW : WORD: "--Actual"
SHOW : OR(x3, NOT(NOT(x1)), BOOLEAN : FALSE, ITEM({ 2 }, L))
SHOW : WORD : "=================================================="
;system("pause")
END_PROGRAM
#endif
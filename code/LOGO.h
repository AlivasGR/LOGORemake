#pragma once
#include "LogoType.h"
#include "Object.h"
#include "ContainerType.h"
#include "NumberType.h"
#include "BooleanType.h"
#include "WordType.h"
#include "SentenceType.h"
#include "ListType.h"
#include "ArrayType.h"
#include "operations.h"
#include "ShowWord.h"
#include "MoveForward.h"
#include "MoveBackward.h"
#include "MoveRight.h"
#include "MoveLeft.h"
#include "MakeCircle.h"
#include "SetPenSize.h"
#include "SetXY.h"
#include "SetPenColor.h"
#include "SetScreenColor.h"
#include "PrintWord.h"
#include "graphics_api/hy352_gui.h"
#include <iostream>

#define TESTCONTAINERS

#define START_PROGRAM int main() { \
	init_GUI();\
	set_screen_color(255, 255, 255);\
	set_pen_color(0, 0, 0);\
	set_pen_thickness(0.1f);\
	try {

#define END_PROGRAM ;} catch(std::bad_cast &e) {\
	std::cout << "ARGUMENT ERROR: Expected LIST - " << e.what() << std::endl;\
	}\
	destroy_GUI();\
	return 0;} 

#define TRUE true
#define FALSE false
#define NUMBER (false)?(NumberType)0
#define WORD (false)?(WordType)""
#define BOOLEAN (false)?(BooleanType)false

#define SENTENCE (SentenceType)
#define LIST ListType()
#define ARRAY ArrayType() =
#define SIZE (false)?0
#define ITEM item
#define SETITEM ;setItem
#define MAKE ;Object
#define ASSIGN ;

#define NOT not
#define AND (Object)(BooleanType&)(And)
#define OR (Object)(BooleanType&)(Or)

#define SUM (Object)(NumberType)(Sum)
#define PRODUCT (Object)(NumberType)(Product)

#define DIFFERENCE (Object)difference
#define MINUS (Object)minusOperation
#define QUOTIENT (Object)quotient
#define MODULO (Object)modulo

#define IF ;{if((
#define DO )) {
#define END ;}}
#define ELIF ;} else if ((
#define ELSE ;} else {

#define REPEAT ;{int iterVar = 0; while((iterVar++ != iterVar-1 &&
#define TIMES != iterVar-1
#define WHILE
#define REPCOUNT NumberType(iterVar)
#define FOREACH ;{for (LogoType * iterVar : (std::vector<LogoType*>) dynamic_cast<ContainerType&>((LogoType&)
#define ELEM (LogoType&) *iterVar

#define SHOW ;ShowWord() = (false)?Object()
#define PRINTOUT ;std::cout << 
#define BR std::endl
#define SRAND(S) ;srand(S)
#define RAND rand()
#define DRAND (double)rand()

#define TO ;void 
#define WITH (LogoType& argsList) { \
	try { \
		dynamic_cast<ListType&>(argsList); \
	} catch(std::bad_cast &e) { \
		std::cout << "FUNCTION ARGUMENT ERROR: FUNCTION arguments must be in a LIST - " << e.what() << std::endl;\
	    system("pause"); \
		exit(-1); \
	}\
	ListType
#define FSTART = dynamic_cast<ListType&>(argsList);
#define FEND ;}
#define RETURN ;return;
#define ARG (dynamic_cast<ListType&>(argsList)).getAtDummy
#define CALL ; 

#define PENUP ;pen_up()
#define PENDOWN ;pen_down()
#define CENTER ;turtle_go_to_center()
#define FORWARD ;MoveForward() = 
#define BACK ;MoveBackward() = 
#define RIGHT ;MoveRight() = 
#define LEFT ;MoveLeft() = 
#define CIRCLE ;MakeCircle() = 
#define SETPENSIZE ;SetPenSize() = 
#define PRINT ;PrintWord() = 
#define SETXY ;SetXY(NumberType(-1)) = 
#define SETPENCOLOR ;SetPenColor() =  
#define SETSCREENCOLOR ;SetScreenColor() = 
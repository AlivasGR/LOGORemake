#include "../LOGO.h"
#ifdef NUMBERTYPETEST
START_PROGRAM
SHOW : WORD:"=================================================="
SRAND(0)
;int REPS = 1000
MAKE x
MAKE y
REPEAT REPS TIMES DO
	;int rnd = RAND
	;double drnd = DRAND
	;int temp0 = rnd % REPS
	;int temp = (NumberType&)(LogoType&)MODULO(NUMBER: rnd, NUMBER : REPS)
	;if (temp != temp0) std::cout << "FAIL AT MODULO " << iterVar << " Expected: " << temp0 << " Actual: " << temp << std::endl
	;double fr = (NumberType&)(LogoType&)QUOTIENT(NUMBER: drnd, NUMBER : RAND_MAX)
	;double fr0 = drnd / RAND_MAX
	IF fr != fr0 DO 
		PRINTOUT "FAIL AT QUOTIENT " << iterVar << " Expected: " << fr0 << " Actual: " << fr << BR
	END
	ASSIGN x = NUMBER:temp
	IF (dynamic_cast<NumberType&>(*x)).getValue() != temp DO
		PRINTOUT "FAIL AT POSITIVE " << iterVar << " Expected: " << temp << " Actual: " << (dynamic_cast<NumberType&>(*x)).getValue() << BR
	END
	MINUS(x) 
	ASSIGN x = NUMBER:-temp
	IF (dynamic_cast<NumberType&>(*x)).getValue() != -temp DO
		PRINTOUT "FAIL AT NEGATIVE " << iterVar << " Expected: " << -temp << " Actual: " << (dynamic_cast<NumberType&>(*x)).getValue() << BR
	END
	ASSIGN y = SUM(NUMBER: temp, NUMBER : fr)
	ASSIGN x = NUMBER: temp + fr
	IF (*x) != (*y) DO
		PRINTOUT "FAIL AT SUM OR OPERATOR != " << iterVar << " Expected: " << temp + fr << " Actual: " << ((LogoType&)(SUM(NUMBER: temp, NUMBER : fr))).toString() << BR
	END
	IF (dynamic_cast<NumberType&>(*x)).getFValue() != (temp + fr) DO
		PRINTOUT "FAIL AT POSITIVE FLOATING POINT " << iterVar << " Expected: " << temp << " Actual: " << (dynamic_cast<NumberType&>(*x)).getFValue() << BR
	END
	ASSIGN y = DIFFERENCE(NUMBER: -temp, NUMBER : fr)
	ASSIGN x = NUMBER: -temp - fr
	IF (*x) != (*y) DO 
		PRINTOUT "FAIL AT DIFFERENCE OR OPERATOR != " << iterVar << " Expected: " << -temp - fr << " Actual: " << ((LogoType&)(DIFFERENCE(NUMBER: -temp, NUMBER : fr))).toString() << BR
	END
	IF (dynamic_cast<NumberType&>(*x)).getFValue() != (-temp - fr) DO
		PRINTOUT "FAIL AT NEGATIVE FLOATING POINT " << iterVar << " Expected: " << temp << " Actual: " << (dynamic_cast<NumberType&>(*x)).getFValue() << BR
	END
	MAKE XX = NUMBER: temp
	MAKE SXX = SUM(XX, NUMBER: temp, NUMBER: -temp)
	IF SXX != XX DO
		PRINTOUT "FAIL AT TRIPLE ARGUMENT SUM " << iterVar << " Expected: " << (int)XX << "Actual: " << (dynamic_cast<NumberType&>(*SXX)).getValue() << BR
	END
	ASSIGN SXX = PRODUCT(XX, NUMBER: temp, x)
	IF (dynamic_cast<NumberType&>(*SXX)).getFValue() != (temp*temp*(-temp - fr)) DO
		PRINTOUT "FAIL AT TRIPLE ARGUMENT PRODUCT (very low chance of false negative) " << iterVar << " Expected: " << (temp*temp*(-temp - fr)) << "Actual: " << (dynamic_cast<NumberType&>(*SXX)).getFValue() << BR
	END
	ASSIGN SXX = PRODUCT(XX, QUOTIENT(NUMBER: temp+1, NUMBER: temp+1))
	IF SXX != XX DO
		PRINTOUT "FAIL AT QUOTIENT-IN-PRODUCT " << iterVar << " Expected: " << temp << "Actual: " << (dynamic_cast<NumberType&>(*SXX)).getValue() << BR
	END
END
SHOW : WORD:"=================================================="
; system("pause")
END_PROGRAM
#endif
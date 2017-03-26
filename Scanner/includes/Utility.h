/*
 * Utility.h
 *
 *  Created on: 11.03.2017
 *      Author: nik0
 */

#ifndef SCANNER_INCLUDES_UTILITY_H_
#define SCANNER_INCLUDES_UTILITY_H_

#include <stddef.h>

class Utility{

public:

static int getLexemSize(char* lexem){

	int size = 0;
	while(lexem[size] != '\0'){
		size++;
	}
	return size+1;
}


static char* getEnumName(int enumType) {

		switch (enumType) {

		case 0:
			return "Integer";
			break;

		case 1:
			return "Identifier";
			break;

		case 2:
			return "If";
			break;

		case 3:
			return "While";
			break;

		case 4:
			return "PlusSign";
			break;

		case 5:
			return "AndSign";
			break;

		case 6:
			return "MinusSign";
			break;

		case 7:
			return "DividedSign";
			break;

		case 8:
			return "AsteriskSign";
			break;

		case 9:
			return "LesserSign";
			break;

		case 10:
			return "BiggerSign";
			break;

		case 11:
			return "EqualsSign";
			break;

		case 12:
			return "EqualsExmarkEqualsSign";
			break;

		case 13:
			return "ExmarkSign";
			break;

		case 14:
			return "DoubleAndSign";
			break;

		case 15:
			return "SemicolonSign";
			break;

		case 16:
			return "RoundBracketOpenSign";
			break;

		case 17:
			return "RoundBracketCloseSign";
			break;

		case 18:
			return "SquareBracketOpenSign";
			break;

		case 19:
			return "SquareBracketCloseSign";
			break;

		case 20:
			return "CurlyBracketOpenSign";
			break;

		case 21:
			return "CurlyBracketCloseSign";
			break;

		case 22:
			return "Commentary";
			break;
		case 23:
			return "UnknownSign";
			break;

		case 24:
			return "EquealsEquals";
			break;

		default:
			return NULL;

		}

	}

};

#endif /* SCANNER_INCLUDES_UTILITY_H_ */

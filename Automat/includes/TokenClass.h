/*
 * TokenClass.h
 *
 *  Created on: 10.01.2017
 *      Author: nik0
 */
//#include "Information.h"
#include "TokenType.h"
#include <iostream>
#ifndef AUTOMAT_INCLUDES_TOKENCLASS_H_
#define AUTOMAT_INCLUDES_TOKENCLASS_H_

class Token {

protected:

	int line;
	int column;
	TokenType::TType type;

public:

	Token() {

	//std::cout << "TOKEN CREATED!!:" << std::endl;
}

virtual ~Token() {};

int getLine() {
	return line;
}

int getColumn() {
	return column;
}

TokenType::TType getType() {
	return type;
}

};

class IdentifierToken : public Token{

    int key;

public:
	IdentifierToken(TokenType::TType t, int tokenLine, int tokenColumn, int key){
		this->line = tokenLine;
		this->column = tokenColumn;
		this->type = t;
		this->key = key;
	}

	int getKey() {
		return key;
	}



};

class IntegerToken : public Token{

	int integerValue;

public:
	IntegerToken(TokenType::TType t, int tokenLine, int tokenColumn, int value){
		this->line = tokenLine;
		this->column = tokenColumn;
		this->type = t;
		this->integerValue = value;
	}

	int getIntegerValue() {
		if (integerValue == NULL) {
			return NULL;
		}
		return integerValue;
	}

};

class SignToken : public Token{

public:
	SignToken(TokenType::TType t, int tokenLine, int tokenColumn){
		this->line = tokenLine;
		this->column = tokenColumn;
		this->type = t;
	}

};

class UnknownSignToken : public Token{

	UnknownSignToken(TokenType::TType t, int tokenLine, int tokenColumn){
		this->line = tokenLine;
		this->column = tokenColumn;
		this->type = t;
	}

};
#endif /* AUTOMAT_INCLUDES_TOKENCLASS_H_ */

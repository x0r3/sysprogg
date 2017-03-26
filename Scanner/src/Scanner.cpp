/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"
#include "../../Automat/includes/Automat.h"

#include "../includes/Utility.h"
#include "../../Automat/includes/TokenClass.h"

#include "../../Symboltable/includes/Symtable.h"

#include <stdio.h>
#include <stdlib.h>
//#include <error.h>
#include <errno.h>

#include <stddef.h>

Scanner::Scanner(const char* file) {
	// TODO Auto-generated constructor stub
	this->buffer = new Buffer(file);
	this->automat = new Automat(this);
	this->symtable = new Symtable();
	tokenLine = 0;
	tokenColumn = 0;
	makeTokenSwitch = false;
	value = new char[1024];
	position = 0;

}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

void Scanner::makeToken(TokenType::TType t, int line, int column) {
	makeTokenSwitch = true;
	this->t = t;
	tokenLine = line;
	tokenColumn = column;

}

Token* Scanner::nextToken() {

	Token* nextToken;
	position = 0;
	while (true) {
		char currentChar = buffer->getChar();
		if (currentChar == NULL) {
			return NULL;
		}
		value[position++] = currentChar;
		automat->readChar(currentChar);
		if (makeTokenSwitch == true) {
			makeTokenSwitch = false;
			break;
		}
	}
	if (t == TokenType::Identifier) {
		value[position] = '\0';
		Key key = symtable->insert(value, t);
		TokenType::TType type = symtable->lookup(key)->type;
		if(type == TokenType::If || type == TokenType::While){
			nextToken = new IdentifierToken(type, tokenLine, tokenColumn, key);
		}else{
		//set value to end of String

		nextToken = new IdentifierToken(t, tokenLine, tokenColumn, key);
		}

	} else if (t == TokenType::Integer) {

		value[position] = '\0';
		long int integerValue = 0;
		integerValue = strtol(value, NULL, 10);
		if(errno == ERANGE){
			// Fehlertoken
		}
		nextToken = new IntegerToken(t, tokenLine, tokenColumn, integerValue);
		//nextToken = IntegerToken;

	}else {

		value[position] = '\0';
		nextToken = new SignToken(t, tokenLine, tokenColumn);
		//nextToken = IdentifierToken;
	}

	if (nextToken->getType() == TokenType::Integer) {
		IntegerToken* integerToken = (IntegerToken*) nextToken;
		std::cout << "Token " << Utility::getEnumName(nextToken->getType())
				<< " Line: " << nextToken->getLine() << " Column: "
				<< nextToken->getColumn() << " Lexem: "
				<< integerToken->getIntegerValue() << "!" << std::endl;
	} else if ((nextToken->getType() == TokenType::Identifier) || (nextToken->getType() == TokenType::If) || (nextToken->getType() == TokenType::While)) {
		IdentifierToken* identifierToken = (IdentifierToken*) nextToken;
		std::cout << "Token " << Utility::getEnumName(nextToken->getType())
				<< " Line: " << nextToken->getLine() << " Column: "
				<< nextToken->getColumn() << " Lexem: "
				<< symtable->lookup(identifierToken->getKey())->lexem << "!" << std::endl;
	} else {
		std::cout << "Token " << Utility::getEnumName(nextToken->getType())
				<< " Line: " << nextToken->getLine() << " Column: "
				<< nextToken->getColumn() << std::endl;
	}
	//give the array free, to clear content
	free(value);
	value = new char[1024];
	return nextToken;

}

//cut end of value array.
void Scanner::cutEnd() {
	value[--position] = '\0';
}

void Scanner::ungetChar() {
	buffer->ungetChar();
	value[--position] = '\0';

}

void Scanner::resetLength() {

}


/*
 * State.cpp
 *
 *  Created on: 07.11.2016
 *      Author: nik0
 */

#include "../includes/State.h"
#include "../includes/TokenType.h"
#include "../includes/Automat.h"
#include <iostream>

InitialState* InitialState::stateAddress = 0;
IdentifierState* IdentifierState::stateAddress = 0;
IntegerState* IntegerState::stateAddress = 0;
AssignCheckState* AssignCheckState::stateAddress = 0;
CommentaryOpenCheckState* CommentaryOpenCheckState::stateAddress = 0;
CommentaryCloseCheckState* CommentaryCloseCheckState::stateAddress = 0;
CommentaryState* CommentaryState::stateAddress = 0;
KeywordWhileState* KeywordWhileState::stateAddress = 0;
KeywordIfState* KeywordIfState::stateAddress = 0;
IfCheckState* IfCheckState::stateAddress = 0;
SpecialSignCheckState* SpecialSignCheckState::stateAddress = 0;
WhileCheckState* WhileCheckState::stateAddress = 0;


//angefangen von Andras, auch wenn der Zigeuner Niko das pushen wird...(!!!)
/////////////////////////////////////////////////////////
////////////////INITIALSTATE/////////////////////////////

void InitialState::read(char c, Automat* automat) {

	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
		automat->setTokenPosition();
		automat->setState(IdentifierState::makeState());
		automat->increaseColumnCounter();
	} else if (c >= '0' && c <= '9') {
		automat->setTokenPosition();
		automat->setState(IntegerState::makeState());
		automat->increaseColumnCounter();
	} else if (c == '=') {
		automat->setTokenPosition();
		automat->setState(AssignCheckState::makeState());
		automat->increaseColumnCounter();
	} else if (c == '/') {
		automat->setTokenPosition();
		automat->setState(CommentaryOpenCheckState::makeState());
		automat->increaseColumnCounter();
	} else if (c == '+') {
		automat->scanner->makeToken(TokenType::PlusSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == '-') {
		automat->scanner->makeToken(TokenType::MinusSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == '*') {
		automat->scanner->makeToken(TokenType::AsteriskSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == '<') {
		automat->scanner->makeToken(TokenType::LesserSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == '>') {
		automat->scanner->makeToken(TokenType::BiggerSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == '!') {
		automat->scanner->makeToken(TokenType::ExmarkSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == '&') {
		automat->scanner->makeToken(TokenType::AndSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == ';') {
		automat->scanner->makeToken(TokenType::SemicolonSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == '(') {
		automat->scanner->makeToken(TokenType::RoundBracketOpenSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == ')') {
		automat->scanner->makeToken(TokenType::RoundBracketCloseSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == '{') {
		automat->scanner->makeToken(TokenType::CurlyBracketOpenSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == '}') {
		automat->scanner->makeToken(TokenType::CurlyBracketCloseSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == '[') {
		automat->scanner->makeToken(TokenType::SquareBracketOpenSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == ']') {
		automat->scanner->makeToken(TokenType::SquareBracketCloseSign,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
	} else if (c == ' ') {
		automat->increaseColumnCounter();
		automat->scanner->cutEnd();

	} else if (c == '\n') {
		automat->increaseLineCounter();
		automat->scanner->cutEnd();

	} else if (c == 'i') {

	}
}

InitialState* InitialState::makeState() {
	if (stateAddress == 0) {
		stateAddress = new InitialState();
		return stateAddress;
	} else {
		return stateAddress;
	}
}

void IntegerState::read(char c, Automat* automat) {

	if (c == ' ') {
		automat->scanner->makeToken(TokenType::Integer,
		automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
		automat->scanner->cutEnd();
		automat->setState(InitialState::makeState());
	} else if (c == '\n') {
		automat->scanner->makeToken(TokenType::Integer,
		automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseLineCounter();
		automat->scanner->cutEnd();
		automat->setState(InitialState::makeState());

	} else if ((c >= '0' && c <= '9')) {
		automat->increaseColumnCounter();
	} else {

	}
}

IntegerState* IntegerState::makeState() {
	if (stateAddress == 0) {
		stateAddress = new IntegerState();
		return stateAddress;
	} else {
		return stateAddress;
	}
}

void IdentifierState::read(char c, Automat* automat) {

	if (c == ' ') {
		automat->scanner->makeToken(TokenType::Identifier,
		automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseColumnCounter();
		automat->scanner->cutEnd();
		automat->setState(InitialState::makeState());
	} else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')|| (c >= '0' && c <= '9')) {

		automat->increaseColumnCounter();

	} else if (c == '\n') { //Zeilenumbruch?

		automat->scanner->makeToken(TokenType::Identifier,
		automat->getLineCounter(), automat->getColumnCounter());
		automat->increaseLineCounter();
		automat->scanner->cutEnd();
		automat->setState(InitialState::makeState());
	} else {
		std::cout << "Kein passendes Zeichen gefunden" << std::endl;
	}
}

IdentifierState* IdentifierState::makeState() {
	if (stateAddress == 0) {
		stateAddress = new IdentifierState();
		return stateAddress;
	} else {
		return stateAddress;
	}
}

void AssignCheckState::read(char c, Automat* automat) {

	if (c == ' ' || c == '\n') {
		automat->scanner->makeToken(TokenType::EqualsSign,
				automat->getLineCounter(), automat->getTokenColumn());
		automat->setState(InitialState::makeState());
	} else if (c == '!') {
		automat->setState(SpecialSignCheckState::makeState());
	} else if (c == '=') {
		automat->scanner->makeToken(TokenType::EqualsEquals,
				automat->getLineCounter(), automat->getTokenColumn());
		automat->setState(InitialState::makeState());
	}
}

AssignCheckState* AssignCheckState::makeState() {
	if (stateAddress == 0) {
		stateAddress = new AssignCheckState();
		return stateAddress;
	} else {
		return stateAddress;
	}
}

SpecialSignCheckState* SpecialSignCheckState::makeState() {
	if (stateAddress == 0) {
		stateAddress = new SpecialSignCheckState();
		return stateAddress;
	} else {
		return stateAddress;
	}
}

void SpecialSignCheckState::read(char c, Automat* automat) {

	if (c != '=') {
		//Error Token
		automat->scanner->makeToken(TokenType::UnknownSign,
				automat->getLineCounter(), automat->getColumnCounter());
	} else {

		automat->scanner->makeToken(TokenType::EqualsExmarkEqualsSign,
				automat->getLineCounter(), automat->getTokenColumn());
	}

	automat->setState(InitialState::makeState());

}

void CommentaryOpenCheckState::read(char c, Automat* automat) {

	if (c == '*') {
		//automat->scanner->makeToken(TokenType::Commentary, automat->getLineCounter(), automat->getTokenColumn());
		automat->setState(CommentaryState::makeState());
	} else {
		automat->scanner->makeToken(TokenType::DividedSign,
				automat->getLineCounter(), automat->getTokenColumn());
		automat->setState(InitialState::makeState());
	}

}

CommentaryOpenCheckState* CommentaryOpenCheckState::makeState() {
	if (stateAddress == 0) {
		stateAddress = new CommentaryOpenCheckState();
		return stateAddress;
	} else {
		return stateAddress;
	}
}

void CommentaryState::read(char c, Automat* automat) {

	if (c == '*') {
		automat->setState(CommentaryCloseCheckState::makeState());
	}

}

CommentaryCloseCheckState* CommentaryCloseCheckState::makeState() {
	if (stateAddress == 0) {
		stateAddress = new CommentaryCloseCheckState();
		return stateAddress;
	} else {
		return stateAddress;
	}
}

void CommentaryCloseCheckState::read(char c, Automat* automat) {

	if (c == '/') {
		automat->scanner->makeToken(TokenType::Commentary,
				automat->getLineCounter(), automat->getColumnCounter());
		automat->setState(InitialState::makeState());
	} else {
		automat->setState(CommentaryState::makeState());
	}

}

CommentaryState* CommentaryState::makeState() {
	if (stateAddress == 0) {
		stateAddress = new CommentaryState();
		return stateAddress;
	} else {
		return stateAddress;
	}
}


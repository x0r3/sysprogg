/*
 * Automat.cpp
 *
 */

#include "../includes/Automat.h"
#include "../includes/State.h"
#include "../../Scanner/includes/IScanner.h"


Automat::Automat(IScanner* scannerPointer) {
	currentState = InitialState::makeState();
	scanner = scannerPointer;
	lineCounter = 1;
	columnCounter = 0;
	tokenLine = 0;
	tokenColumn = 0;

	// TODO Auto-generated constructor stub

}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}

void Automat::ungetChar(int number){

}

void Automat::readChar(char c){
	currentState->read(c, this);
}

void Automat::setTokenPosition(){
	tokenLine = lineCounter;
	tokenColumn = columnCounter;
}

void Automat::setState(State* state){
	// Problematisch?
	 currentState = state;
}

void Automat::increaseColumnCounter(){
	columnCounter++;

}

void Automat::increaseLineCounter(){
	lineCounter++;
	columnCounter = 0;
}

void Automat::resetLineCounter(){
	lineCounter = 1;
}

int Automat::getColumnCounter()const{
	return columnCounter;
}

int Automat::getLineCounter()const{
	return lineCounter;
}

int Automat::getTokenLine()const{
	return tokenLine;
}

int Automat::getTokenColumn()const{
	return tokenColumn;
}

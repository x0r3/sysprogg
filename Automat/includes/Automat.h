/*
 * Automat.h
 *
 *  Created on: Jul 5, 2012
 *      Author: knad0001
 */

#include "../includes/State.h"
#include "../../Scanner/includes/IScanner.h"
#include "../../Automat/includes/TokenType.h"


#ifndef Automat_H_
#define Automat_H_

class State;
class Scanner;

class Automat {
	int columnCounter;
	int lineCounter;
	int tokenLine;
	int tokenColumn;
public:
	IScanner* scanner;
	State* currentState;
	Automat(IScanner* scannerPointer);
	void readChar(char c);
	int getColumnCounter() const;
	int getLineCounter() const;
    ~Automat();
	void resetLineCounter();
	void ungetChar(int);
	void setTokenPosition();
	void setState(State* s);
	void increaseColumnCounter();
	void increaseLineCounter();
	int getTokenLine() const;
	int getTokenColumn() const;
};

#endif /* Automat_H_ */

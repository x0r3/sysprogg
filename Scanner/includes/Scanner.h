/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_
#include "../../Buffer/includes/Buffer.h"
#include "../../Automat/includes/Automat.h"
#include "../../Automat/includes/TokenClass.h"
#include "../../Symboltable/includes/Symtable.h"
#include "IScanner.h"


class Automat;

class Scanner : public IScanner{

public:
	Scanner(const char* file);
	char* value;
	Buffer* buffer;
	Automat* automat;
	Symtable* symtable;
	int tokenLine;
	int position;
	int tokenColumn;
	TokenType::TType t;
	bool makeTokenSwitch;
	~Scanner();
	virtual void ungetChar();
	Token* nextToken();
	virtual void cutEnd();
	virtual void resetLength();
	virtual void makeToken(TokenType::TType t, int line, int column);
};



#endif /* SCANNER_H_ */

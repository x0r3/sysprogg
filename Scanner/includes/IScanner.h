/*
 * IScanner.h
 *
 *  Created on: 10.01.2017
 *      Author: nik0
 */

#include "../../Automat/includes/TokenType.h"

#ifndef SCANNER_SRC_ISCANNER_H_
#define SCANNER_SRC_ISCANNER_H_

class IScanner {
public:

	virtual void makeToken(TokenType::TType type, int line, int column) = 0;
	virtual void ungetChar() = 0;
	virtual void resetLength() = 0;
	virtual void cutEnd() = 0;
	virtual ~IScanner(){};
};



#endif /* SCANNER_SRC_ISCANNER_H_ */

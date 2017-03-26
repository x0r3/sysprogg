/*
 * TokenType.h
 *
 *  Created on: 07.11.2016
 *      Author: nik0
 */

#ifndef AUTOMAT_INCLUDES_TOKENTYPE_H_
#define AUTOMAT_INCLUDES_TOKENTYPE_H_

class TokenType{
public: /*Hier
 	 	 sind
 	 	 noch
 	 	 die
 	 	 TTypes anzupassen*/
	enum TType { Integer, Identifier, If, While, PlusSign, AndSign, MinusSign, DividedSign, AsteriskSign, LesserSign,
		BiggerSign, EqualsSign, EqualsExmarkEqualsSign, ExmarkSign, DoubleAndSign, SemicolonSign,
		RoundBracketOpenSign, RoundBracketCloseSign, SquareBracketOpenSign, SquareBracketCloseSign,
		CurlyBracketOpenSign, CurlyBracketCloseSign, Commentary, UnknownSign, EqualsEquals};
};

#endif /* AUTOMAT_INCLUDES_TOKENTYPE_H_ */


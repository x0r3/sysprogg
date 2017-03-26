#ifndef _INFORMATION_H_
#define _INFORMATION_H_
#include "../../Automat/includes/TokenType.h"


/*
 * Eine Information mit einem Pointer auf ein Lexem und einem Tokentyp.
 */

class Information {
public:

	char* lexem;					// Pointer auf das Lexem
	TokenType::TType type;			// Typ des Tokens
	bool declared;					// Wurde die Variable bereits deklariert?
	bool arrayType;					// Bezeichnet die Variable ein Array?



	/*
	 * Konstruktor der Information-Klasse
	 *
	 * @param lexemPtr 	Pointer auf das Lexem
	 * @param type		Typ des Tokens
	 *
	 */

	Information(char* lexemPtr, TokenType::TType type);


	/*
	 * Gibt zur�ck, ob die Variable bereits deklariert wurde.
	 *
	 * @return		bool-Wert, ob die Variable bereits deklariert wurde 
	 *
	 */

	bool isDeclared() const;


	/*
	 * Gibt zur�ck, ob die Variable als Array deklariert wurde.
	 *
	 * @return		bool-Wert, ob die Variable als Array deklariert wurde 
	 *
	 */

	bool isArray() const;


	/*
	* Hinterlegt die Information, dass die Variable deklariert wurde.
	*/

	void setDeclared();


	/*
	* Hinterlegt die Information, dass die Variable ein Array ist.
	*/

	void setArray();

};

#endif // _INFORMATION_H_

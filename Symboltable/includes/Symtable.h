#ifndef _SYMTABLE_H_
#define _SYMTABLE_H_

#include "Symtable.h"
#include "List.h"
#include "StringTab.h"
#include "../../Automat/includes/TokenType.h"
#include "InformationPtrContainer.h"

/*
 * Eine Symtable mit einer verketteten Liste, einer StringTab und einem
 * InformationPointerContainer.
 */

class Symtable {

	List** table;								// Liste mit List-Pointern
	Key currentRightKey;						// Zwischenspeicher für den aktuell richtigen Key
	StringTab* stringtab;						// Pointer auf den Stringtab
	InformationPtrContainer* infoContainer;		// Pointer auf den Information-Pointer-Container


	/*
	 * Trägt die Schlüsselwörter in die Symtable ein.
	 */

	void initSymbols();


   /*
	* Berechnet den Hashwert des übergebenen Lexems.
	*
	* @param lexem		Pointer auf die erste Position des Lexems.
	* @return			Errechneter Hashwert
	*/

	int hashcode(char* lexem);


public:


	/*
	 * Konstruktor der Symtable.
	 */

	Symtable();


   /*
	* Destruktor der Symtable.
	*/

	~Symtable();


   /*
	* Gibt zurück, ob sich das übergebene Lexem in der Stringtable
	* befindet oder nicht.
	*
	* @param lexem  	Pointer auf die erste Position des Lexems
	* @return			true, falls das Lexem schon vorhanden ist
	*		  			false, falls nicht
	*
	*/

	bool contains(char* lexem);


	/*
	 * Gibt den InformationPointer zum übergebenen Key zurück.
	 *
	 * @param key	Key des gewünschten InformationPointers
	 */

	Information* lookup (Key key) const;


	/*
	 * Fügt das übergebene Lexem mit seiner ebenfalls übergebene Länge
	 * ein.
	 *
	 * @param lexem		CharPointer auf das einzutragende Lexem
	 * @param type		Typ des Tokens
	 * @return			Schlüssel des SymtabEntrys
	 */

	Key insert (char* lexem, TokenType::TType type);


};

#endif // _SYMTABLE_H_

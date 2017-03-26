#ifndef _SYMTABENTRY_H_
#define _SYMTABENTRY_H_
#include "Information.h"
#include "../../Automat/includes/TokenType.h"

typedef int Key;

// Vorwärtsdeklarationen
class List;
class Symtable;

/*
 * Ein SymtabEntry mit einem Key und Zeigern auf den jeweils vorherigen
 * und den nachfolgenden Eintrag, auf ein Informations-Objekt, sowie auf
 * das Lexem in der StringTab.
 */

class SymtabEntry {

	friend class List;				// Die Klasse "List" darf auf die Attribute zugreifen
	friend class Symtable;			// Die Klasse "Symtable" darf auf die Attribute zugreifen
	SymtabEntry* next;				// Zeiger auf den nächsten SymtabEntry in der Liste
	SymtabEntry* prev;				// Zeiger auf den vorherigen SymtabEntry in der Liste
	Information* info;				// Zeiger auf das zugehörige Informations-Objekt
	Key key;						// Key des SymtabEntrys
	char* lexem;					// Zeiger auf das Lexem

public:
	

	/*
	 * Konstruktor der SymtabEntry-Klasse.
	 *
	 * @param lexemPtr	CharPointer auf das Lexem
	 * @param type		Typ des Tokens
	 * @param prev		Pointer auf den vorherigen SymtabEntry in der Liste
	 * @param next 		Pointer auf den nächsten SymtabEntry in der Liste
	 */

	SymtabEntry(char* lexemPtr, TokenType::TType type, SymtabEntry* prev, SymtabEntry* next = 0);


	/*
	 * Gibt den Pointer auf das Information-Objekt des SymtabEntrys
	 * zurück.
	 *
	 * @return	Pointer auf das Information-Objekt
	 */

	Information* getInfo() const;


	/*
	 * Setzt den Key des SymtabEntrys auf den übergebenen Wert.
	 *
	 * @param newKey	Zu setzender Key
	 */

	void setKey(Key newKey);


	/*
	 * Gibt den Key des SymtabEntrys zurück.
	 *
	 * @return	Key des SymtabEntrys
	 */

	Key getKey() const;


	/*
	 * Gibt den Zeiger auf das Lexem zurück.
	 */

	char* getLexemPtr() const;

};


#endif /*_SYMTABENTRY_H_ */

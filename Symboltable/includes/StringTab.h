#ifndef _STRINGTAB_H_
#define _STRINGTAB_H_

// Vorwärtsdeklaration
class StringTabNode;


/*
 * Eine StringTab mit einem Pointer auf die nächste freie Stelle, einer
 * Größe und einem Pointer auf den ersten StringTabNode.
 */

class StringTab {
	char* freeP;				// Zeiger auf den nächsten freien Speicherplatz
	int freeSpace;				// Anzahl freier Plätze
	StringTabNode* first;		// Zeiger auf den ersten StringTabNode


	/*
	 * Erstellt einen StringTabNode und lässt den Zeiger "freeP"
	 * darauf verweisen.
	 *
	 */

	void setNewNode();

public:


	/*
	 * Konstruktor der StringTab-Klasse.
	 */

	StringTab();


	/*
	 * Destruktor der StringTab-Klasse.
	 */

	~StringTab();


	/*
	 * Fügt das übergebene Lexem in die StringTab ein.
	 *
	 * @param lexem		Pointer auf das einzutragende Lexem
	 * @return			Pointer auf das eingetragene Lexem
	 * 					in der StringTab
	 */

	char* insert(char* lexem);

};


/*
 * Ein StringTabNode mit einem Zeiger auf den nächsten StringTabNode und
 * einem Zeiger auf ein Char-Array.
 */

class StringTabNode {
	friend class StringTab;			// StringTab darf auf die Attribute zugreifen
	StringTabNode* next;			// Zeiger auf den nächsten StringTabNode
	char* vector;					// Zeiger auf ein char-Array, in welchem die Buchstaben gespeichert werden

public:


	/*
     * Konstruktor der Klasse StringTabNode.
	 */

	StringTabNode();


	/*
	 * Destruktor der Klasse StringTabNode
	 */

	~StringTabNode();

};

#endif // _STRINGTAB_H_

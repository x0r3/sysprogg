#ifndef LIST_H_
#define LIST_H_

#include "SymtabEntry.h"
#include "../../Automat/includes/TokenType.h"

/*
 * Eine verkettete Liste mit einer Größe, einem Zeiger auf das erste und einem
 * Zeiger auf das letzte Listenelement.
 */

class List {

	SymtabEntry* first;				// Erstes Listenelement
	SymtabEntry* last;				// Letztes Listenelement
	int size;						// Größe


   /*
	* Entfernt alle Listenelemente.
	*/

	void removeAll();

public:


   /*
	* Standardkonstruktor der Liste.
	*/

	List();


   /*
	* Destruktor der List-Klasse.
	*/

	~List();


	/*
	* Erzeugt aus dem übergebenen Pointer auf das Lexem und dem
	* übergebenen Tokentyp einen SymtabEntry und hängt ihn an
	* die hinterste Position der Liste an.
	*
	* @param lexemPtr	Pointer auf das zu übergebende Lexem
	* @param type		Tokentyp
	* @return			Pointer auf den erzeugten SymtabEntry
	*/

	SymtabEntry* append(char* lexemPtr, TokenType::TType type);


	/*
	* Gibt die Anzahl der Listenelemente zurück.
	*
	* @return Anzahl der Listenelemente
	*/

	int getSize() const;


   /*
	* Gibt einen Pointer auf den SymtabEntry an der übergebenen
	* Position zurück.
    *
	* @param index   Index des gewünschten Elementes
	* @return  Element an der übergebenen Position
	*/

	SymtabEntry* get(int index) const;

};
#endif /* LIST_H_ */

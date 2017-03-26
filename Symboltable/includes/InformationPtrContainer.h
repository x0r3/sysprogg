#ifndef _INFORMATIONPTRCONTAINER_H_
#define _INFORMATIONPTRCONTAINER_H_
#include "Information.h"
#define CONTAINER_SIZE 500000

typedef int Key;

/*
 * Ein InformationPointerContainer mit einem Array für InformationPointer und
 * einer Größe.
 */

class InformationPtrContainer {
	int freeSpace;							// Anzahl freier Plätze
	Information** informationArray;         // Array für die Informationpointer
	int freePosition;						// Nummer des nächsten freien Platzes
public:


	/*
	 * Konstruktor des Information-Pointer-Containers.
	 *
	 * @param size	Anzahl der Speicherplätze im Container
	 *
	 */

	InformationPtrContainer(int size = CONTAINER_SIZE);


	/*
	 * Destruktor der Information-Pointer-Container-Klasse.
	 */

	~InformationPtrContainer();


	/*
	 * Fügt den übergebenen Information-Pointer in den Container ein
	 * und gibt einen Schlüssel aus, mit welchem der Pointer wieder in
	 * der Tabelle gefunden werden kann.
	 *
	 * @param infobox	Pointer des Information-Objektes, das gespeichert
	 * 					werden soll
	 * @return			Key, mit welchem der Pointer wieder gefunden werden
	 * 					kann
	 */

	Key insert (Information* infobox);


	/*
	 * Gibt den passenden Information-Pointer zum übergebenen Key aus.
	 *
	 * @param key	Schlüssel des Information-Pointers
	 * @return		Information-Pointer des übergebenen Keys
	 */

	Information* get (Key index) const;

};

#endif // _INFORMATIONPTRCONTAINER_H_

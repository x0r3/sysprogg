//für Util class

//ende für util class


#include "../includes/Symtable.h"
#include "../includes/List.h"
#include "../includes/StringTab.h"
#include "../../Automat/includes/TokenType.h"
#include "../includes/InformationPtrContainer.h"
#include "../../Scanner/includes/Utility.h"
#include <iostream>

#define SYMTABLE_SIZE 15000				// Größe der Symtable


	void Symtable::initSymbols () {

	  insert((char*)"if", TokenType::If);
	  insert((char*)"If", TokenType::If); // Schlüsselwort "if"
	  insert((char*)"iF", TokenType::If);
	  insert((char*)"IF", TokenType::If);
	  insert((char*)"while", TokenType::While);          // Schlüsselwort "while"

	}



	int Symtable::hashcode(char* lexem) {
		int length = Utility::getLexemSize(lexem);
		return (256 * *lexem + 16 * lexem[length - 1] + length);
	}


	Symtable::Symtable() {
		infoContainer = new InformationPtrContainer();
		stringtab = new StringTab();
		table = new List* [SYMTABLE_SIZE];
		List* ptr;
		for (int i = 0; i < SYMTABLE_SIZE; i++) {			// Liste mit List-Objekten füllen
			ptr = new List();
			table[i] = ptr;
		}
		initSymbols();
	}


	Symtable::~Symtable() {
		delete[] table;
	}


	bool Symtable::contains(char* lexem) {
		int length = Utility::getLexemSize(lexem);
		int hashKey = hashcode(lexem) % SYMTABLE_SIZE;
		List* currentList = table[hashKey];
		if (currentList->getSize() == 0) {						// Liste leer?
			return false;
		}
		char* currentLexem;
		SymtabEntry* currentNode = currentList->get(0);
		int counter = 0;
		for (int i = 0; i < currentList->getSize(); i++) {		// Prüfe die komplette Liste
			currentLexem = currentNode->getLexemPtr();
			counter = 0;

			while ((lexem[counter] == currentLexem[counter]) && (counter < length)) {	// Vergleiche die Lexeme
				counter++;
			}
			if ((counter == length) && (currentLexem[length-1] == '\0')) {// Lexeme gleich?

				currentRightKey = currentNode->getKey();
				return true;
			}
			currentNode = currentNode->next;					// hole nächstes Listenelement
		}
		return false;
	}


	Information* Symtable::lookup(Key key) const {
		return infoContainer->get(key);
	}


	Key Symtable::insert (char* lexem, TokenType::TType type) {
		if (contains(lexem)) {							// Lexem schon vorhanden?
			return currentRightKey;
		} else {
			int hashKey = hashcode(lexem) % SYMTABLE_SIZE;
			List* currentList = table[hashKey];
			char* lexemPtr = stringtab->insert(lexem);
			SymtabEntry* currentSymtabEntry = currentList->append(lexemPtr, type);
			Key key = (infoContainer->insert(currentSymtabEntry->getInfo()));
			currentSymtabEntry->setKey(key);
			return key;
		}
	}

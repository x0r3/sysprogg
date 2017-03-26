#include "../includes/Information.h"
#include "../../Automat/includes/TokenType.h"
#include "../includes/SymtabEntry.h"

// Vorwärtsdeklarationen
class List;
class Symtable;

typedef int Key;



	SymtabEntry::SymtabEntry(char* lexemPtr, TokenType::TType type, SymtabEntry* prev, SymtabEntry* next) {
		this->lexem = lexemPtr;
		this->prev = prev;
		this->next = next;
		info = new Information (lexem, type);
		key = -1L;
	}



	Information* SymtabEntry::getInfo() const {
		return info;
	}



	void SymtabEntry::setKey(Key newKey) {
		key = newKey;
	}



	Key SymtabEntry::getKey() const {
		return key;
	}


	char* SymtabEntry::getLexemPtr() const {
		return lexem;
	}


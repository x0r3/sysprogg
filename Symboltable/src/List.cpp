#include "../includes/List.h"
#include "../includes/SymtabEntry.h"
#include "../../Automat/includes/TokenType.h"


	void List::removeAll() {
		while (first != 0) {
			SymtabEntry* next = first->next;
			delete first;
			first = next;
		}
	}



	List::List() {
		first = 0;
		last = 0;
		size = 0;
	}



	List::~List() {
		removeAll();
	}


	SymtabEntry* List::append(char* lexemPtr, TokenType::TType type) {

		SymtabEntry* nle = new SymtabEntry(lexemPtr, type, last);

		// 1. Leere Liste?
		if (first == 0) {
			first = nle;
		}
		// 2. Liste nicht leer?
		else {
			last->next = nle;
		}
		last = nle;
		++size;
		return nle;
	}


	int List::getSize() const {
		return size;
	}



	SymtabEntry* List::get(int index) const {
		int count = 0;
		SymtabEntry* current = first;
		while (count < index) {
			current = current->next;
			++count;
		}
		return current;
	}

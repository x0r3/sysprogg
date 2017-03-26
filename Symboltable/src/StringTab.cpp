#include "../includes/StringTab.h"
#include "../../Scanner/includes/Utility.h"
#include <string.h>

#define NODE_SIZE 15000								// Größe der StringTabNodes


///////////////////////////////////////////////////////////////////////////////////
//////////////////////// METHODEN DER KLASSE STRINGTAB ////////////////////////////
///////////////////////////////////////////////////////////////////////////////////



	void StringTab::setNewNode() {
		StringTabNode* newNode = new StringTabNode();
		StringTabNode* currentNode = first;
		while (currentNode->next != 0) {				// finde den letzten StringTabNode
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
		freeP = newNode->vector;
		freeSpace = NODE_SIZE;
	}



	StringTab::StringTab() {
		first = new StringTabNode();
		freeSpace = NODE_SIZE;
		freeP = first->vector;
	}


	StringTab::~StringTab() {
		while (first != 0) {
			StringTabNode* next = first->next;
			delete first;
			first = next;
		}
	}



	char* StringTab::insert(char* lexem) {
		int length = Utility::getLexemSize(lexem);
		if (length > freeSpace) {					// falls kein Platz mehr frei: erstelle neuen Node
			setNewNode();
		}
		char* tmp = freeP;
		memcpy(freeP, lexem, length);				// kopiert das Lexem
		freeP += length;
		freeSpace -= length;
		return tmp;
	}



	///////////////////////////////////////////////////////////////////////////////////
	////////////////////// METHODEN DER KLASSE STRINGTABNODE //////////////////////////
	///////////////////////////////////////////////////////////////////////////////////





	StringTabNode::StringTabNode() {
		vector = new char[NODE_SIZE];
		next = 0;
	}



	StringTabNode::~StringTabNode() {
		delete vector;
	}

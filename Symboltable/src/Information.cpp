#include "../includes/Information.h"
#include "../../Automat/includes/TokenType.h"


	Information::Information(char* lexemPtr, TokenType::TType type) {
		this->lexem = lexemPtr;
		this->type = type;
		this->declared = false;
		this->arrayType = false;
	}

	
	bool Information::isDeclared() const {
		return declared;
	}



	bool Information::isArray() const {
		return arrayType;
	}


	void Information::setDeclared() {
		declared = true;
	}


	void Information::setArray() {
		arrayType = true;
	}


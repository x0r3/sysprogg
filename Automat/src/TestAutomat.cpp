#include "../includes/Automat.h"
#include "../../Scanner/includes/Scanner.h"
#include <iostream>


int main (int argc, char* argv[]){


	Automat* automat;

	char* path = "../../scanner-test3.txt";
	Scanner* scanner = new Scanner(path);
	automat = new Automat(scanner);

	while(true){
		char c = scanner->buffer->getChar();
		if(c == '\0'){
					break;
				}
		std::cout << c << std::endl;
		automat->readChar(c);

	}
	/*
	int out1 = automat->getColumnCounter();
	std::cout << out1 << std::endl;

	automat->readChar(scanner->buffer->getChar());

	out1 = automat->getColumnCounter();
	std::cout << out1 << std::endl;

	automat->readChar(scanner->buffer->getChar());

	out1 = automat->getColumnCounter();

	std::cout << out1 << std::endl;
	std::cout << "End of program" << std::endl;
	*/


}

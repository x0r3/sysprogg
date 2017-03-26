#include "../includes/Scanner.h"
#include <iostream>

int main(int argc, char **argv) {

	Scanner* scanner;
	char* path = "scanner-test.txt";
	Token* ptr;
	scanner = new Scanner(path);

	while(true){
		ptr = scanner->nextToken();
		if(ptr == NULL){
			break;
		}

	}
	std::cout << "Testscanner done." << std::endl;

}


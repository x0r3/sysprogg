#include <iostream>
#include "../includes/Buffer.h"



int main(int argc, char **argv) {



	Buffer*  buffer;
	char* testpath;
	testpath = "../../scanner-test3.txt";

	buffer = new Buffer(testpath);



	int temp = 0;

	while(temp < 10){
			char tmp = buffer->getChar();

			std::cout << tmp << std::endl;
			temp++;
		}

	/*

	while(temp < 4100){
		char tmp = buffer->getChar();

		std::cout << tmp << std::endl;
		temp++;
	}
	std::cout << "getChar() beendet." << std::endl;
	temp = 0;
	while(temp < 8){
			char tmp = buffer->ungetChar();

			std::cout << tmp << std::endl;
			temp++;
		}
	std::cout << "ungetChar() beendet." << std::endl;
	temp = 0;
	while(temp < 8){
			char tmp = buffer->getChar();

			std::cout << tmp << std::endl;
			temp++;
		}
	std::cout << "getChar() beendet." << std::endl;


	std::cout << "-----------------------------------" << std::endl;
	std::cout << buffer->getByteCount() << std::endl;



	std::cout << "End of program."<< std::endl;

	*/





	/*
	char temp;

	temp = buffer->getChar();
	if(temp != NULL){
		std::cout << temp << std::endl;
	}else{
		std::cout << "NULL" << std::endl;
	}
	temp = buffer->getChar();
	if(temp != NULL){
			std::cout << temp << std::endl;
	}else{
		std::cout << "NULL" << std::endl;
		}
	temp = buffer->getChar();
	if(temp != NULL){
			std::cout << temp << std::endl;
	}else{

	std::cout << "NULL" << std::endl;
	}


	temp = buffer->ungetChar();
	if(temp != NULL){
			std::cout << temp << std::endl;
		}else{
			std::cout << "NULL" << std::endl;
		}
	temp = buffer->ungetChar();
	if(temp != NULL){
			std::cout << temp << std::endl;
		}else{
			std::cout << "NULL" << std::endl;
		}
	temp = buffer->ungetChar();
	if(temp != NULL){
			std::cout << temp << std::endl;
		}else{
			std::cout << "NULL" << std::endl;
		}
	temp = buffer->ungetChar();
	if(temp != NULL){
			std::cout << temp << std::endl;
		}else{
			std::cout << "NULL" << std::endl;
		}
	temp = buffer->ungetChar();
	if(temp != NULL){
			std::cout << temp << std::endl;
		}else{
			std::cout << "NULL" << std::endl;
		}
	*/


}

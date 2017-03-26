/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Buffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <string>
#include <stddef.h>

char* pufferCollection[2];
char* currentPointer;
char  currentChar;
int byte_count;
int fileDescriptor;
bool Buffer1Loaded = false;
bool Buffer2Loaded = false;

#define BYTE_BUFFERSIZE 4096


Buffer::Buffer(const char* filepath) {
	// ES GEEEEHT
//nikos first branch commit numberTwoTHOUSANAD AND 400
	//Hello World
	posix_memalign(((void**) &pufferCollection[0]), getpagesize(), getpagesize());
	posix_memalign(((void**) &pufferCollection[1]), getpagesize(), getpagesize());

	fileDescriptor = open(filepath, O_RDONLY | O_DIRECT | S_IROTH);

	byte_count = read(fileDescriptor, pufferCollection[0], getpagesize());



	pufferCollection[0][BYTE_BUFFERSIZE] = NULL;
	//byte_count = read(fileDescriptor, pufferCollection[1], getpagesize());
	pufferCollection[1][BYTE_BUFFERSIZE];

//test
	currentPointer = pufferCollection[0];
	currentChar = *currentPointer;


}

Buffer::~Buffer() {
	// TODO Auto-generated destructor stub
//ich arbeite jetzt hier auch mit
}// test

//Es handelt sich hierbei um das einfache Pufferschema welches in der Vorlesungsfolie behandelt wird
char Buffer::getChar(){

	//currentPointer++; Sorgt für Probleme da das erste Zeichen sonst geschluckt wird

	if(*currentPointer == NULL){
		std::cout << "NULL-pointer detected!" << std::endl;
		//Wenn am Ende des ersten Puffers
		if(currentPointer == &pufferCollection[0][BYTE_BUFFERSIZE]){
			std::cout << "Switching Buffer to Buffer No.: 2" << std::endl;
			if(!Buffer2Loaded){
				byte_count = read(fileDescriptor, pufferCollection[1], getpagesize());
				Buffer1Loaded = false;
				pufferCollection[1][byte_count] = NULL;
			}
			currentPointer = pufferCollection[1];
			return *currentPointer;
		}
		else if(currentPointer  == &pufferCollection[1][BYTE_BUFFERSIZE]){
			std::cout << "Switching Buffer to Buffer No.: 1" << std::endl;
			if(!Buffer1Loaded){
				byte_count = read(fileDescriptor, pufferCollection[0], getpagesize());
				Buffer2Loaded = false;
				pufferCollection[0][byte_count] = NULL;
			}
			currentPointer = pufferCollection[0];
			return *currentPointer;
		}else {
			// lexikalische Analyse beenden + Ein Schritt zurück.
			std::cout << "No end-of-buffer detected. This means its end-of-file. Analysis should stop now" << std::endl;

			return NULL;
		}

	}

		currentChar = *currentPointer;
		currentPointer++;		// Stattdessen mal hier hin gepackt - Hoffentlich keine Seiteneffekte
		return currentChar;
}

// ungetChar liefert das char welches zuvor durch getChar() geliefert wurde. Es muss dabei den Spezialfall abdecken falls
// ein bereits geladener Puffer wieder nach hinten hin verlassen und erneut betreten wird. In diesem Fall darf die
// Pufferhälfte nicht erneut geladen werden da dies zu einem Datenverlust führen würde

char Buffer::ungetChar(){

	if(currentPointer == &pufferCollection[0][0]){
		std::cout << "Currently at beginning of first buffer" << std::endl;

		currentPointer = &pufferCollection[1][BYTE_BUFFERSIZE-1];
		currentChar = *currentPointer;
		Buffer1Loaded = true;
		return currentChar;
	}
	if(currentPointer == &pufferCollection[1][0]){
		std::cout << "Currently at beginning of second buffer" << std::endl;

		currentPointer = &pufferCollection[0][BYTE_BUFFERSIZE-1];
		currentChar = *currentPointer;
		Buffer2Loaded = true;
		return currentChar;

	}
	currentPointer--;
	currentChar = *currentPointer;


	return currentChar;

}


int Buffer::getByteCount(){

	return byte_count;
}





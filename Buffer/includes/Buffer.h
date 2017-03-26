/*
 * Buffer.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef BUFFER_H_
#define BUFFER_H_

class Buffer {
private:

public:
	Buffer();
	Buffer(const char*);
	virtual ~Buffer();
	char getChar();
	char ungetChar();
	void reloadBuffer();
	int getByteCount();
};

#endif /* BUFFER_H_ */

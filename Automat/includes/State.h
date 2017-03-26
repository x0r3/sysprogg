/*
 * State.h
 *
 *  Created on: 07.11.2016
 *      Author: nik0
 */


#ifndef AUTOMAT_SRC_STATE_H_
#define AUTOMAT_SRC_STATE_H_

class Automat;

class State {
public:
	//virtual void read (char c, Automat* automat) = 0;
	State(){};
	virtual ~State(){};
	virtual void read(char c, Automat* automat) = 0;

};

class InitialState : public State {
	static InitialState* stateAddress;
public:
	virtual void read (char c, Automat* automat);

	static InitialState* makeState();
};

class IdentifierState : public State {
	static IdentifierState* stateAddress;
public:
	virtual void read (char c, Automat* automat);

	static IdentifierState* makeState();
};

class IntegerState : public State {
	static IntegerState* stateAddress;
public:
	virtual void read (char c, Automat* automat);

	static IntegerState* makeState();
};

class SpecialSignCheckState : public State {
	static SpecialSignCheckState* stateAddress;
public:
	virtual void read (char c, Automat* automat);

	static SpecialSignCheckState* makeState();
};

class AssignCheckState : public State {
	static AssignCheckState* stateAddress;
public:
	virtual void read (char c, Automat* automat);

	static AssignCheckState* makeState();
};

class CommentaryOpenCheckState : public State {
	static CommentaryOpenCheckState* stateAddress;
public:
	virtual void read (char c, Automat* automat);

	static CommentaryOpenCheckState* makeState();
};

class CommentaryState : public State {
	static CommentaryState* stateAddress;
public:
	virtual void read (char c, Automat* automat);

	static CommentaryState* makeState();
};

class CommentaryCloseCheckState : public State {
	static CommentaryCloseCheckState* stateAddress;
public:
	virtual void read (char c, Automat* automat);

	static CommentaryCloseCheckState* makeState();
};

class KeywordIfState : public State {
	static KeywordIfState* stateAddress;
public:
	virtual void read (char c, Automat* automat);

	static KeywordIfState* makeState();
};

class IfCheckState : public State {
	static IfCheckState* stateAddress;

public:
	virtual void read (char c, Automat* automat);


	static IfCheckState* makeState();
};


class KeywordWhileState : public State {

	static KeywordWhileState* stateAddress;
	char array[4] = {'h','i','l','e'};
	int i = 0;
public:

	virtual void read (char c, Automat* automat);

	static KeywordWhileState* makeState();
};

class WhileCheckState : public State {

	static WhileCheckState* stateAddress;

public:
	virtual void read (char c, Automat* automat);


	static WhileCheckState* makeState();
};

#endif /* AUTOMAT_SRC_STATE_H_ */

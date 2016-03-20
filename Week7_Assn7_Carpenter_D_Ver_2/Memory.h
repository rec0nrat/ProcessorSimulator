#include "Include.h"

struct myAddress{
	short address;
	int contents = 0;
	myAddress *nextAddress;
};

class Memory{

private:

	myAddress * head;

	int length;


public:

	Memory(int mySize = 100);

	int returnSize();

	void printMemContent(short  addressRef);

	void printAllMemory();

	void store(short addressRef, int * data);

	~Memory();
};

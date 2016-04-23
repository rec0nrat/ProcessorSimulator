#include "Memory.h"

using namespace memory;

Memory::Memory(int mySize){

	int sizeAcctual = mySize > 50 ? mySize : 50;

	head = new myAddress;
	head->nextAddress = NULL; 
	head->address = 0;
	
	for (int i = 0; i < sizeAcctual; i++){
		myAddress * p = head;
		myAddress * q = head;

		while (q){
			p = q;
			q = p->nextAddress;
		}

		p->nextAddress = new myAddress;
		p->nextAddress->nextAddress = NULL;
		p->address = i;

		length++;
	}
	
}

int Memory::returnSize(){
	return length;
}

void Memory::printMemContent(short addressRef){
	myAddress * p = head;
	myAddress * q = head;
	bool found = false;
	while (q){
		p = q;
		q = p->nextAddress;
		if (p->address == addressRef){
			found = true;
			cout << bitset<32>(p->contents) << endl;
		}
	}

	if (!found) cout << "Address not found" << endl;
}

void Memory::printAllMemory(){
	myAddress * p = head;
	myAddress * q = head;
	while (q->nextAddress){
		p = q;
		q = p->nextAddress;
		
		cout << p->address << "	" << bitset<32>(p->contents) << endl;
	}
}

void Memory::store(short addressRef, int * data){
	myAddress * p = head;
	myAddress * q = head;
	bool found = false;
	while (q && !found){
		p = q;
		q = p->nextAddress;
		if (p->address == addressRef){
			p->contents = *data;
			found = true;
		}
	}
	if (!found) cout << "Address not found" << endl;
}

Memory::~Memory(){
	myAddress * p = head;
	myAddress * q = head;
	while (q){
		p = q;
		q = p->nextAddress;;
		if (q) delete p;
	}
}
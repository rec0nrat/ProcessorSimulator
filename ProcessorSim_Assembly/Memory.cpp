#include "Memory.h"

using namespace memory;
Memory::Memory() {}
Memory::Memory(int capacity) {
	capacity = 50;
	memory = new bitset<32>[capacity];
	this->capacity = capacity;
	sp = capacity;
	hp = capacity / 2;
}

void Memory::push(bitset<32> data) {

	sp--;
	if (sp == hp)
		throw string("Overflow");
	else {
		memory[sp] = data;
	}
}

bitset<32> Memory::pop() {
	if (sp == capacity)
		throw string("Stack is empty.");
	else {
		bitset<32> temp = memory[sp];
		memory[sp] = 0;
		sp++;
		return temp;
	}
}

void Memory::printMemContent(short addressRef) {
	myAddress 
}

void Memory::printAllMemory() {

}

void Memory::store(short addressRef, int * data) {

}

Memory::~Memory() {
	delete[] memory;
}

	

/*


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
	*/
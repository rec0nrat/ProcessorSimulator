#include "Memory.h"

using namespace memory;

Memory::Memory() {
	//array of memory
	this->capacity = 50;
	this->memory = new bitset<32>[capacity];
	this->sp = capacity;
	this->hp = 7;
}

//creates variable for heap with register name and data being stored
void Memory::createVariable(std::string name, bitset<32> data) {

	hp++;

	if (hp == sp) {
		cout << "*** Memory Overflow! **" << endl;
		hp--;
	}
	else {
		MemLoc variable;
		variable.address = hp;
		variable.name = name;
		variables.push_back(variable);
		memory[hp] = data;
	}

}

//push onto stack
void Memory::push(bitset<32> data) {

	sp--;
	if (sp == hp) {
		cout << "*** Stack Overflow! **" << endl;
		sp++;
	}
	else {
		memory[sp] = data;
	}
}

//pop off of stack LIFO
bitset<32> Memory::pop() {

	if (sp == capacity) {
		cout << "*** Stack Empty! ***" << endl;
		return bitset<32>(0);
	}
	else {
		bitset<32> temp = memory[sp];
		memory[sp] = 0;
		sp++;
		return temp;
	}
}

//prints out everything stored in memory
void Memory::printAllMemory() {

	for (int i = 0; i < capacity; i++) {

		cout << "[" << i << "]";

		if (i / 1000 > 0) cout << " ";
		else if (i / 100 > 0) cout << "  ";
		else if (i / 10 > 0) cout << "   ";
		else cout << "    ";

		cout << memory[i];

		switch (i) {
		case 0:
			cout << " <=RAX";
			break;
		case 1:
			cout << " <=RBX";
			break;
		case 2:
			cout << " <=RCX";
			break;
		case 3:
			cout << " <=RDX";
			break;
		case 4:
			cout << " <=RSI";
			break;
		case 5:
			cout << " <=RDI";
			break;
		case 6:
			cout << " <=RBP";
			break;
		case 7:
			cout << " <=RSP";
			break;
		default:
			break;
		}

		for (int index = 0; index < variables.size(); index++) {
			if (variables[index].address.to_ullong() == i) {
				cout << " <=" << variables[index].name;
			}
		}

		if (sp == i) {
			cout << " <=SP";
		}
		if (hp == i) {
			cout << " <=HP";
		}
		if (i == capacity - 1 && sp == capacity) {
			cout << " <=SP";
		}

		cout << endl;
	}
}

//stores registers and data in memory heap 
void Memory::store(bitset<32> address, bitset<32> data, bool * error) {
	if (address.to_ullong() >= capacity) {
		*error = true;
	}
	memory[address.to_ullong()] = data;
}

void Memory::store(bitset<32> address, bitset<32> data) {
	
	memory[address.to_ullong()] = data;
}

//loads register address and data in memory heap
bitset<32> Memory::load(bitset<32> address, bool * error) {
	if (address.to_ullong() >= capacity) {
		*error = true;
		return 0;
	}
	return memory[address.to_ullong()];
}

bitset<32> Memory::load(bitset<32> address) {

	return memory[address.to_ullong()];
}

//deletes memory array
Memory::~Memory() {
	delete[] memory;
}





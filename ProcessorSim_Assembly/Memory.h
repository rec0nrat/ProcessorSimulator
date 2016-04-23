#include "Include.h"

namespace memory {

	struct myAddress {
		short address;
		int contents = 0;
		myAddress *nextAddress;
	};

	class Memory {

	private:
		int sp;
		int hp;
		int capacity;
		bitset<32> *memory;

	public:
		Memory();
		Memory(int capacity);
		void push(bitset<32> data);
		bitset<32> pop();
		void printMemContent(short  addressRef);
		void printAllMemory();
		void store(short addressRef, int * data);
		~Memory();
	};


}
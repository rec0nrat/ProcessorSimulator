#include "Include.h"

namespace memory {
	//struct that has address and register name
	struct MemLoc {
		bitset<32> address;
		std::string name;
	};

	class Memory {

	private:
		int sp;	//stack pointer
		int hp; //heap pointer
		int capacity;
		bitset<32> *memory;
		std::vector<MemLoc> variables; //vector of variables in memory location

	public:
		Memory();
		void createVariable(std::string name, bitset<32> data);	//creates a variable and stores it in vector of memory locations
		std::vector<MemLoc> getVariables() {
			return variables;
		}
		void push(bitset<32> data);	//push onto stack
		bitset<32> pop();			//pop off of stack
		void printAllMemory();		//print everything in heap and stack
		void store(bitset<32> address, bitset<32> data);	//store address and data
		void store(bitset<32> address, bitset<32> data, bool * error);	//store address and data and checks for error
		bitset<32> load(bitset<32> address, bool * error); //load address of register and checks for error
		bitset<32> load(bitset<32> address);		//loads address of register
		~Memory();
	};


}
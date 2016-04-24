#include "Include.h"

namespace memory {

	struct MemLoc {
		bitset<32> address;
		std::string name;
	};

	class Memory {

	private:
		int sp;
		int hp;
		int capacity;
		bitset<32> *memory;
		std::vector<MemLoc> variables;

	public:
		Memory();
		void createVariable(std::string name, bitset<32> data);
		std::vector<MemLoc> getVariables() {
			return variables;
		}
		void push(bitset<32> data);
		bitset<32> pop();
		void printAllMemory();
		void store(bitset<32> address, bitset<32> data);
		void store(bitset<32> address, bitset<32> data, bool * error);
		bitset<32> load(bitset<32> address, bool * error);
		bitset<32> load(bitset<32> address);
		~Memory();
	};


}
//#include "Include.h"
#include "Opcode.h"
#include "Register.h"
#include "Memory.h"
#include "ALU.h"
#include <sstream>

namespace processor_sim {
	
	class Control {

	private:
		//Registers
		const std::string array64[8] = { "RAX", "RBX",  "RCX",  "RDX",  "RSI",  "RDI",  "RSI",  "RBP" };
		const std::string array32[8] = { "EAX", "EBX",  "ECX",  "EDX",  "ESI",  "RDI",  "RSI",  "RBP" };
		const std::string array16[8] = { "AX",  "BX",  "CX",  "DX",  "SI",  "DI",  "BP", "SP" };
		const std::string array8[16] = { "AH", "BH", "CH", "DH", "SIH", "DIH", "DPH", "SH", "AL",  "BL",  "CL",  "DL",  "SIL",  "DIL",  "BPL", "SL" };
		const std::string othercmds[1] = { "MAX" };

		//update memory into heap
		void updateMemory();

		//display header message
		void DisplayHeader() {

			cout << "Processor Simulation \n"
				<< "(Using MASM Instruction Set) \n"
				<< "Version 1.2 \n"
				<< endl;
		}

		//display error message
		void DisplayError() {
			cout << "Invalid Command!!! Type 'help' for list of commands." << endl;
		}
	
		friend class Memory;

		friend class Register;

		friend class ALU;

		//Register, Memoru and ALU objects
		reg::Register m_Register;

		memory::Memory m_Memory;

		alu::ALU m_ALU;
	
	public:

		//Assembly commands
		void MOV(std::string destination, std::string source);
		void ADD(std::string destination, std::string value);
		void SUB(std::string destination, std::string value);
		void NOT(std::string destination, std::string value);
		void OR (std::string destination, std::string value);
		void AND(std::string destination, std::string value);
		void XOR(std::string destination, std::string value);
		void LEA(std::string destination, std::string source);
		void WORD(std::string destination, std::string source);
	
		//get value function to add value to a DWORD variable
		DWORD64 getValue(std::string destination, std::string value, bool * error);
		bitset<32> getValue(std::string source, bool * error);

		//help menu function
		void help();

		//user command function
		bool enterCommand();

		Control();
		~Control();
	};

}


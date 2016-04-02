//#include "Include.h"
#include "Opcode.h"
#include "Register.h"
#include "Memory.h"
#include "ALU.h"

namespace processor_sim {
	
	class Control {

	private:

		

		const std::string array64[8] = { "RAX", "RBX",  "RCX",  "RDX",  "RSI",  "RDI",  "RSI",  "RBP" };
		const std::string array32[8] = { "EAX", "EBX",  "ECX",  "EDX",  "ESI",  "RDI",  "RSI",  "RBP" };
		const std::string array16[8] = { "AX",  "BX",  "CX",  "DX",  "SI",  "DI",  "BP", "SP" };
		const std::string array8[16] = { "AH", "BH", "CH", "DH", "SIH", "DIH", "DPH", "SH", "AL",  "BL",  "CL",  "DL",  "SIL",  "DIL",  "BPL", "SL" };
		const std::string othercmds[1] = { "MAX" };
	
		friend class Memory;

		friend class Register;

		friend class ALU;

		reg::Register myRegister;

		memory::Memory myMemory;

		alu::ALU m_ALU;
	
	public:

		void MOV(std::string destination, std::string source);
		void ADD(std::string destination, std::string value);
		void SUB(std::string destination, std::string value);
		void NOT(std::string destination, std::string value);
		void OR (std::string destination, std::string value);
		void AND(std::string destination, std::string value);
		void XOR(std::string destination, std::string value);
	
		DWORD64 getValue(std::string destination, std::string value, bool * error);

		void help();

		bool enterCommand();

		Control();
		~Control();
	};

}


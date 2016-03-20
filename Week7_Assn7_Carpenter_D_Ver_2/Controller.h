#include "Include.h"
#include "Opcode.h"
#include "Register.h"
#include "Memory.h"
#include "ALU.h"

class Control {

private:

	std::string array64[8] = { "RAX", "RBX",  "RCX",  "RDX",  "RSI",  "RDI",  "RSI",  "RBP" };
	std::string array32[8] = { "EAX", "EBX",  "ECX",  "EDX",  "ESI",  "RDI",  "RSI",  "RBP" };
	std::string array16[8] = { "AX",  "BX",  "CX",  "DX",  "SI",  "DI",  "BP", "SP" };
	std::string array8[16] = { "AH", "BH", "CH", "DH", "SIH", "DIH", "DPH", "SH", "AL",  "BL",  "CL",  "DL",  "SIL",  "DIL",  "BPL", "SL" };
	std::string othercmds[1] = { "MAX" };


	friend class Memory;

	friend class Register;

	friend class ALU;

	Register myRegister;

	Memory myMemory;

	ALU myALU;

public:

	Control();

	void mov(std::string destination, std::string source);
	void add(std::string destination, std::string value);
	void sub(std::string destination, std::string value);
	void not(std::string destination, std::string value);
	void or(std::string destination, std::string value);
	void and(std::string destination, std::string value);
	void xor(std::string destination, std::string value);

	DWORD64 getValue(std::string destination, std::string value, bool * error);

	void help();

	bool enterCommand();

	~Control();

};


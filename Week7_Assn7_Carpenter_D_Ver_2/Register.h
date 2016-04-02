#include "Include.h"

/*
Register layout

|__64__|__56__|__48__|__40__|__32__|__24__|__16__|__8___|
|__________________________RAX__________________________|
|xxxxxxxxxxxxxxxxxxxxxxxxxxx|____________EAX____________|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|_____AX______|
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|__AH__|__AL__|
*/


namespace reg {

	class Register {

	private:
		const int bits[32] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };

		std::string Areg[5] = { "RAX", "EAX", "AX", "AH", "AL" };
		std::string Breg[5] = { "RBX", "EBX", "BX", "BH", "BL" };
		std::string Creg[5] = { "RCX", "ECX", "CX", "CH", "CL" };
		std::string Dreg[5] = { "RDX", "EDX", "DX", "DH", "DL" };
		std::string Sindex[5] = { "RSI", "ESI", "SI", "SIH", "SIL" };
		std::string Dindex[5] = { "RDI", "EDI", "DI", "DIH", "DIL" };
		std::string Bptr[5] = { "RBP", "EBP", "BP", "BPH", "BPL" };
		std::string Sptr[5] = { "RSP", "ESP", "SP", "SH", "SL" };

		bitset<64> mem;

		bitset<64> RAX;
		bitset<64> RBX;
		bitset<64> RCX;
		bitset<64> RDX;
		bitset<64> RSI;
		bitset<64> RDI;
		bitset<64> RBP;
		bitset<64> RSP;

	public:

		Register();

		DWORD64 getRegister(std::string request);
		DWORD64 getRegister(std::string request, bool * error);

		DWORD64 getRAX();
		DWORD64 getRBX();
		DWORD64 getRCX();
		DWORD64 getRDX();
		DWORD64 getRSI();
		DWORD64 getRDI();
		DWORD64 getRBP();
		DWORD64 getRSP();

		void DumpRegs64();
		void DumpRegs32();
		void DumpRegs16();
		void DumpRegs8();
		void DumpRegsDec();

		void changeRegister(std::string reg, DWORD64 value);

		~Register();

	};
}
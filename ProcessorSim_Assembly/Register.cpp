#include "Register.h"

using namespace reg;

Register::Register() {
	//64 bit registers
	for (int i = 63; i >= 32; i--) {
		RAX[i] = bitset<32>(0)[i-32];
	}
	for (int i = 63; i >= 32; i--) {
		RBX[i] = bitset<32>(1)[i-32];
	}
	for (int i = 63; i >= 32; i--) {
		RCX[i] = bitset<32>(2)[i-32];
	}
	for (int i = 63; i >= 32; i--) {
		RDX[i] = bitset<32>(3)[i-32];
	}
	for (int i = 63; i >= 32; i--) {
		RSI[i] = bitset<32>(4)[i-32];
	}
	for (int i = 63; i >= 32; i--) {
		RDI[i] = bitset<32>(5)[i-32];
	}
	for (int i = 63; i >= 32; i--) {
		RBP[i] = bitset<32>(6)[i-32];
	}
	for (int i = 63; i >= 32; i--) {
		RSP[i] = bitset<32>(7)[i-32];
	}
}

//getting address of registers
bitset<32> Register::getRegisterAddress(std::string request, bool * error) {

	for (int i = 0; i < 6; i++) {

		if (request == Areg[i]) {
			return bitset<32>(0);
		}
		if (request == Breg[i]) {
			return bitset<32>(1);
		}
		if (request == Creg[i]) {
			return bitset<32>(2);
		}
		if (request == Dreg[i]) {
			return bitset<32>(3);
		}
		if (request == Sindex[i]) {
			return bitset<32>(4);
		}
		if (request == Dindex[i]) {
			return bitset<32>(5);
		}
		if (request == Bptr[i]) {
			return bitset<32>(6);
		}
		if (request == Sptr[i]) {
			return bitset<32>(7);
		}
	}

	*error = true;
	return 0;
}

//
DWORD64 Register::getRegister(std::string request)
{
	
	for (int i = 0; i < 6; i++) {
		
		if (request == Areg[i]) {
			return RAX.to_ullong();
		}
		if (request == Breg[i]) {
			return RBX.to_ullong();
		}
		if (request == Creg[i]) {
			return RCX.to_ullong();
		}
		if (request == Dreg[i]) {
			return RDX.to_ullong();
		}
		if (request == Sindex[i]) {
			return getRSI();
		}
		if (request == Dindex[i]) {
			return getRDI();
		}
		if (request == Bptr[i]) {
			return getRBP();
		}
		if (request == Sptr[i]) {
			return getRSP();
		}
	}

	return 0;	
}

DWORD64 Register::getRegister(std::string request, bool * error)
{
	
	for (int i = 0; i < 6; i++) {
		
		if (request == Areg[i]) {
			return RAX.to_ullong();
		}
		if (request == Breg[i]) {
			return RBX.to_ullong();
		}
		if (request == Creg[i]) {
			return RCX.to_ullong();
		}
		if (request == Dreg[i]) {
			return RDX.to_ullong();
		}
		if (request == Sindex[i]) {
			return getRSI();
		}
		if (request == Dindex[i]) {
			return getRDI();
		}
		if (request == Bptr[i]) {
			return getRBP();
		}
		if (request == Sptr[i]) {
			return getRSP();
		}
	}
	*error = true;
	return 0;
}

//getting specific registers RAX, RBX, RCX etc... and returning lower 32 bit registers
DWORD64 Register::getRAX()
{
	return RAX.to_ullong();
	//return EAX;
}

DWORD64 Register::getRBX()
{
	return RBX.to_ullong();
	//return EBX;
}

DWORD64 Register::getRCX()
{
	return RCX.to_ullong();
	//return ECX;
}

DWORD64 Register::getRDX()
{
	return RDX.to_ullong();
	//return EDX;
}

DWORD64 Register::getRSI()
{
	return RSI.to_ullong();
	//return ESI;
}

DWORD64 Register::getRDI()
{
	return RDI.to_ullong();
	//return EDI;
}

DWORD64 Register::getRBP()
{
	return RBP.to_ullong();
	//return EDI;
}

DWORD64 Register::getRSP()
{
	return RSP.to_ullong();
	//return EDI;
}

//Register dump registers in decimal
void Register::DumpRegsDec() {
	cout << "Current Decimal Register Data" << endl;
	cout << "EAX: " << RAX.to_ullong() << endl;
	cout << "EBX: " << RBX.to_ullong() << endl;
	cout << "ECX: " << RCX.to_ullong() << endl;
	cout << "EDX: " << RDX.to_ullong() << endl;
	cout << "ESI: " << RSI.to_ullong() << endl;
	cout << "EDI: " << RDI.to_ullong() << endl;
}

//Register dump of 64 bit registers
void Register::DumpRegs64() {
	cout << "Current 64-bit Register Data" << endl;
	cout << "EAX: " << RAX << endl;
	cout << "EBX: " << RBX << endl;
	cout << "ECX: " << RCX << endl;
	cout << "EDX: " << RDX << endl;
	cout << "ESI: " << RSI << endl;
	cout << "EDI: " << RDI << endl;
}

//Register dump of 32 bit registers
void Register::DumpRegs32() {
	cout << "Current 32-bit Register Data" << endl;

	cout << "EAX: ";
	for (int i = 31; i >= 0; i--) {
		cout << RAX[i];
	}
	cout << "\nEBX: ";
	for (int i = 31; i >= 0; i--) {
		cout << RBX[i];
	}
	cout << "\nECX: ";
	for (int i = 31; i >= 0; i--) {
		cout << RCX[i];
	}
	cout << "\nEDX: ";
	for (int i = 31; i >= 0; i--) {
		cout << RDX[i];
	}
	cout << "\nESI: ";
	for (int i = 31; i >= 0; i--) {
		cout << RSI[i];
	}
	cout << "\nEDI: ";
	for (int i = 31; i >= 0; i--) {
		cout << RDI[i];
	}
	cout << endl;
}

//Register dump of 16 bit registers
void Register::DumpRegs16() {

	cout << "Current 16-bit Register Data" << endl;
	
	cout << "AX: ";
	for (int i = 15; i >= 0; i--) {
		cout << RAX[i];
	}
	cout << "\nBX: ";
	for (int i = 15; i >= 0; i--) {
		cout << RBX[i];
	}
	cout << "\nCX: ";
	for (int i = 15; i >= 0; i--) {
		cout << RCX[i];
	}
	cout << "\nDX: ";
	for (int i = 15; i >= 0; i--) {
		cout << RDX[i];
	}
	cout << "\nSI: ";
	for (int i = 15; i >= 0; i--) {
		cout << RSI[i];
	}
	cout << "\nDI: ";
	for (int i = 15; i >= 0; i--) {
		cout << RDI[i];
	}
	cout << endl;
}

//Register dump of 8 bit register
void Register::DumpRegs8() {
	cout << "Current 8-bit Register Data" << endl;

	cout << "AL:  ";
	for (int i = 7; i >= 0; i--) {
		cout <<RAX[i];	//dumps RAX
	}
	cout << "\nBL:  ";
	for (int i = 7; i >= 0; i--) {
		cout << RBX[i];	//dumps RBX
	}
	cout << "\nCL:  ";
	for (int i = 7; i >= 0; i--) {
		cout << RCX[i];	//dumps RCX
	}
	cout << "\nDL:  ";
	for (int i = 7; i >= 0; i--) {
		cout << RDX[i];	//dumps RDX
	}
	cout << "\nSIL: ";
	for (int i = 7; i >= 0; i--) {
		cout << RSI[i];	//dumps RSI
	}
	cout << "\nDIL: ";
	for (int i = 7; i >= 0; i--) {
		cout << RDI[i];	//dumps RDI
	}
	cout << endl;
}

//checks register and then
//checks if value is 32, 16 or 8 bits and stores in appropriate register
void Register::changeRegister(std::string reg, DWORD64 value, bool * error) {
	getRegister(reg, error);
	// A register
	if (reg == "RAX") RAX = value;	//stores value in RAX
	if (reg == "EAX") {				//stores value in EAX
		for (int i = 31; i >= 0; i--) {
			RAX[i] = bitset<32>(value)[i];	
		}
	}
	if (reg == "AX") {				//stores value in AX
		for (int i = 15; i >= 0; i--) {
			RAX[i] = bitset<16>(value)[i]; 
		}
	}
	if (reg == "AH") {				//stores value in AH
		for (int i = 15; i >= 8; i--) {
			RAX[i] = bitset<8>(value)[i - 8];
		}
	}
	if (reg == "AL") {				//stores value in AL
		for (int i = 7; i >= 0; i--) {
			RAX[i] = bitset<8>(value)[i];
		}
	}

	// B register
	if (reg == "RBX") RBX = value;	//stores value in RBX
	if (reg == "EBX") {				//stores value in EBX
		for (int i = 31; i >= 0; i--) {
			RBX[i] = bitset<32>(value)[i];
		}
	}
	if (reg == "BX") {				//stores value in BX
		for (int i = 15; i >= 0; i--) {
			RBX[i] = bitset<16>(value)[i];
		}
	}
	if (reg == "BH") {				//stores value in BH
		for (int i = 15; i >= 8; i--) {
			RBX[i] = bitset<8>(value)[i - 8];
		}
	}
	if (reg == "BL") {				//stores value in BL
		for (int i = 7; i >= 0; i--) {
			RBX[i] = bitset<8>(value)[i];
		}
	}

	//C register
	if (reg == "RCX") RCX = value;	//stores value in RCX
	if (reg == "ECX") {				//stores value in ECX
		for (int i = 31; i >= 0; i--) {
			RCX[i] = bitset<32>(value)[i];
		}
	}
	if (reg == "CX") {				//stores value in CX
		for (int i = 15; i >= 0; i--) {
			RCX[i] = bitset<16>(value)[i];
		}
	}
	if (reg == "CH") {				//stores value in CH
		for (int i = 15; i >= 8; i--) {
			RCX[i] = bitset<8>(value)[i - 8];
		}
	}
	if (reg == "CL") {				//stores value in CL
		for (int i = 7; i >= 0; i--) {
			RCX[i] = bitset<8>(value)[i];
		}
	}

	// D register
	if (reg == "RDX") RDX = value;	//stores value in RDX
	if (reg == "EDX") {				//stores value in EDX
		for (int i = 31; i >= 0; i--) {
			RDX[i] = bitset<32>(value)[i];
		}
	}
	if (reg == "DX") {				//stores value in DX
		for (int i = 15; i >= 0; i--) {
			RDX[i] = bitset<16>(value)[i];
		}
	}
	if (reg == "DH") {				//stores value in DH
		for (int i = 15; i >= 8; i--) {
			RDX[i] = bitset<8>(value)[i - 8];
		}
	}
	if (reg == "DL") {				//stores value in DL
		for (int i = 7; i >= 0; i--) {
			RDX[i] = bitset<8>(value)[i];
		}
	}

	// Source index register
	if (reg == "RSI") RSI = value;	//stores value in RSI
	if (reg == "ESI") {				//stores value in ESI
		for (int i = 31; i >= 0; i--) {
			RSI[i] = bitset<32>(value)[i];
		}
	}
	if (reg == "SI") {				//stores value in SI
		for (int i = 15; i >= 0; i--) {
			RSI[i] = bitset<16>(value)[i];
		}
	}
	if (reg == "SIH") {				//stores value in SIH
		for (int i = 15; i >= 8; i--) {
			RSI[i] = bitset<8>(value)[i - 8];
		}
	}
	if (reg == "SIL") {				//stores value in SIL
		for (int i = 7; i >= 0; i--) {
			RSI[i] = bitset<8>(value)[i];
		}
	}

	// Destination index register
	if (reg == "RDI") RDI = value;	//stores value in RDI
	if (reg == "EDI") {				//stores value in EDI
		for (int i = 31; i >= 0; i--) {
			RDI[i] = bitset<32>(value)[i];
		}
	}
	if (reg == "DI") {				//stores value in DI
		for (int i = 15; i >= 0; i--) {
			RDI[i] = bitset<16>(value)[i];
		}
	}
	if (reg == "DIH") {				//stores value in DIH
		for (int i = 15; i >= 8; i--) {
			RDI[i] = bitset<8>(value)[i - 8];
		}
	}
	if (reg == "DL") {				//stores value in DL
		for (int i = 7; i >= 0; i--) {
			RDI[i] = bitset<8>(value)[i];
		}
	}

}

//changes register and stores value according to its bits
void Register::changeRegister(std::string reg, DWORD64 value){

	// A registers
	if (reg == "RAX") RAX = value;
	if (reg == "EAX") {
		for (int i = 31; i >= 0; i--) {
			RAX[i] = bitset<32>(value)[i];
		}
	}
	if (reg == "AX") {
		for (int i = 15; i >= 0; i--) {
			RAX[i] = bitset<16>(value)[i];
		}
	}
	if (reg == "AH") {
		for (int i = 15; i >= 8; i--) {
			RAX[i] = bitset<8>(value)[i-8];
		}
	}
	if (reg == "AL") {
		for (int i = 7; i >= 0; i--) {
			RAX[i] = bitset<8>(value)[i];
		}
	}

	// B registers
	if (reg == "RBX") RBX = value;
	if (reg == "EBX") {
		for (int i = 31; i >= 0; i--) {
			RBX[i] = bitset<32>(value)[i];
		}
	}
	if (reg == "BX") {
		for (int i = 15; i >= 0; i--) {
			RBX[i] = bitset<16>(value)[i];
		}
	}
	if (reg == "BH") {
		for (int i = 15; i >= 8; i--) {
			RBX[i] = bitset<8>(value)[i-8];
		}
	}
	if (reg == "BL") {
		for (int i = 7; i >= 0; i--) {
			RBX[i] = bitset<8>(value)[i];
		}
	}

	//C registers
	if (reg == "RCX") RCX = value;
	if (reg == "ECX") {
		for (int i = 31; i >= 0; i--) {
			RCX[i] = bitset<32>(value)[i];
		}
	}
	if (reg == "CX") {
		for (int i = 15; i >= 0; i--) {
			RCX[i] = bitset<16>(value)[i];
		}
	}
	if (reg == "CH") {
		for (int i = 15; i >= 8; i--) {
			RCX[i] = bitset<8>(value)[i-8];
		}
	}
	if (reg == "CL") {
		for (int i = 7; i >= 0; i--) {
			RCX[i] = bitset<8>(value)[i];
		}
	}

	// D registers
	if (reg == "RDX") RDX = value;
	if (reg == "EDX") {
		for (int i = 31; i >= 0; i--) {
			RDX[i] = bitset<32>(value)[i];
		}
	}
	if (reg == "DX") {
		for (int i = 15; i >= 0; i--) {
			RDX[i] = bitset<16>(value)[i];
		}
	}
	if (reg == "DH") {
		for (int i = 15; i >= 8; i--) {
			RDX[i] = bitset<8>(value)[i - 8];
		}
	}
	if (reg == "DL") {
		for (int i = 7; i >= 0; i--) {
			RDX[i] = bitset<8>(value)[i];
		}
	}

	// Source index register
	if (reg == "RSI") RSI = value;
	if (reg == "ESI") {
		for (int i = 31; i >= 0; i--) {
			RSI[i] = bitset<32>(value)[i];
		}
	}
	if (reg == "SI") {
		for (int i = 15; i >= 0; i--) {
			RSI[i] = bitset<16>(value)[i];
		}
	}
	if (reg == "SIH") {
		for (int i = 15; i >= 8; i--) {
			RSI[i] = bitset<8>(value)[i - 8];
		}
	}
	if (reg == "SIL") {
		for (int i = 7; i >= 0; i--) {
			RSI[i] = bitset<8>(value)[i];
		}
	}

	// Destination index register
	if (reg == "RDI") RDI = value;
	if (reg == "EDI") {
		for (int i = 31; i >= 0; i--) {
			RDI[i] = bitset<32>(value)[i];
		}
	}
	if (reg == "DI") {
		for (int i = 15; i >= 0; i--) {
			RDI[i] = bitset<16>(value)[i];
		}
	}
	if (reg == "DIH") {
		for (int i = 15; i >= 8; i--) {
			RDI[i] = bitset<8>(value)[i - 8];
		}
	}
	if (reg == "DL") {
		for (int i = 7; i >= 0; i--) {
			RDI[i] = bitset<8>(value)[i];
		}
	}
}

Register::~Register() {

}
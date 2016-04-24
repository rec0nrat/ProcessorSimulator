#include "Controller.h"

using namespace processor_sim;

Control::Control() {
	updateMemory();
}

Control::~Control() {}

bitset<32> Control::getValue(std::string source, bool * error) {

	bitset<32> returnVal;

	for (int i = 0; i < 8; i++) {

		if (source == array32[i] || source == array16[i]) {
			return m_Register.getRegister(source);
		}
	}

	for (int i = 0; i < 16; i++) {

		if (source == array8[i]) {
			return m_Register.getRegister(source);
		}
	}

	for (int i = 0; i < m_Memory.getVariables().size(); i++) {
		if (source == m_Memory.getVariables()[i].name) {
			return m_Memory.load(m_Memory.getVariables()[i].address);
		}
	}

	try {
		returnVal = stoi(source);
	}
	catch (const std::exception& e) {
		*error = true;
	}

	return bitset<32>(returnVal);

}

DWORD64 Control::getValue(std::string destination ,std::string source, bool * error) {

	DWORD returnVal = 0;
	
	for (int i = 0; i < 8; i++) {

		if (source == array64[i] || source == array32[i] || source == array16[i]) 
			return m_Register.getRegister(source);
	}

	for (int i = 0; i < 16; i++){
		if (source == array8[i]) {
			return m_Register.getRegister(source);
		}
	}

	for (int i = 0; i < m_Memory.getVariables().size(); i++) {
		if (source == m_Memory.getVariables()[i].name) {
			return m_Memory.load(m_Memory.getVariables()[i].address).to_ullong();
		}
	}

	if (source == "MAX") {
		if (destination[0] == 'R') {
			return MAXDWORD64;
		}
		else if (destination[0] == 'E') {
			return MAXUINT32;
		}
		else if (destination == "AX" || destination == "BX" || destination == "CX" || destination == "DX" || destination == "SI" || destination == "DI" || destination == "BP" || destination == "SP") {
			return MAXUINT16;
		}
		else {
			return MAXBYTE;
		}
	}
	else {
		try {
			returnVal = stoi(source);
		}
		catch (const std::exception& e) {
			*error = true;
		}
		return returnVal;
	}
}

void Control::help() {
	bool listCmds = false;
	//cout << "Commands should look like:\ncommand (space) destination (comma), source (or another register)" << endl;
	//cout << "\nThe commands supported are:\n"
	cout << "MOV - Moves a value to a register\n"
		<< "ADD - Adds a value to a register\n"
		<< "AND - Bitwise AND's a register by a value\n"
		<< "OR  - Bitwise or's a register by a value\n"
		<< "XOR - Bitwise exclusive or a register by a value\n"
		<< "NOT - Bitwise not a register\n"
		<< "SUB - Subtract a value from a register\n"
		<< "Type 'MEMDUMP' to display memory\n"
		<< "LEA - Loads effective address to a register\n"
		<< "Type 'clear' to clear the screen.\n"
		<< "Type 'reg64' 'reg32' 'reg16' 'reg8' to view registers\n"
		<< "Type 'EXIT' to leave the program\n"
		<< endl;
}

void Control::updateMemory() {
	bitset<64> tempReg = m_Register.getRAX();
	bitset<32> tempLoc;
	bitset<32> tempData;

	for (int i = 63; i >= 32; i-- ){
		tempLoc[i - 32] = tempReg[i];
	}
	for (int i = 31; i >= 0; i--) {
		tempData[i] = tempReg[i];
	}
	m_Memory.store(tempLoc, tempData);

	tempReg = m_Register.getRBX();

	for (int i = 63; i >= 32; i--) {
		tempLoc[i - 32] = tempReg[i];
	}
	for (int i = 31; i >= 0; i--) {
		tempData[i] = tempReg[i];
	}
	m_Memory.store(tempLoc, tempData);

	tempReg = m_Register.getRCX();

	for (int i = 63; i >= 32; i--) {
		tempLoc[i - 32] = tempReg[i];
	}
	for (int i = 31; i >= 0; i--) {
		tempData[i] = tempReg[i];
	}
	m_Memory.store(tempLoc, tempData);

	tempReg = m_Register.getRDX();

	for (int i = 63; i >= 32; i--) {
		tempLoc[i - 32] = tempReg[i];
	}
	for (int i = 31; i >= 0; i--) {
		tempData[i] = tempReg[i];
	}
	m_Memory.store(tempLoc, tempData);

	tempReg = m_Register.getRSI();

	for (int i = 63; i >= 32; i--) {
		tempLoc[i - 32] = tempReg[i];
	}
	for (int i = 31; i >= 0; i--) {
		tempData[i] = tempReg[i];
	}
	m_Memory.store(tempLoc, tempData);

	tempReg = m_Register.getRDI();

	for (int i = 63; i >= 32; i--) {
		tempLoc[i - 32] = tempReg[i];
	}
	for (int i = 31; i >= 0; i--) {
		tempData[i] = tempReg[i];
	}
	m_Memory.store(tempLoc, tempData);

	tempReg = m_Register.getRBP();

	for (int i = 63; i >= 32; i--) {
		tempLoc[i - 32] = tempReg[i];
	}
	for (int i = 31; i >= 0; i--) {
		tempData[i] = tempReg[i];
	}
	m_Memory.store(tempLoc, tempData);

	tempReg = m_Register.getRSP();

	for (int i = 63; i >= 32; i--) {
		tempLoc[i - 32] = tempReg[i];
	}
	for (int i = 31; i >= 0; i--) {
		tempData[i] = tempReg[i];
	}
	m_Memory.store(tempLoc, tempData);
}

void Control::WORD(std::string destination, std::string source) {
	bool error = false;
	bitset<32> tempData = getValue(source, &error);
	if (!error) m_Memory.createVariable(destination, tempData);
	if (error) DisplayError();
}

void Control::MOV(std::string destination, std::string source) {
	bool error = false;
	DWORD64 temp2 = getValue(destination, source, &error);
	bitset<32> varAddress = bitset<32>(0);
	if (!error) {
		for (int i = 0; i < m_Memory.getVariables().size(); i++) {
			if (destination == m_Memory.getVariables()[i].name) {
				varAddress = m_Memory.load(m_Memory.getVariables()[i].address, &error);
				m_Memory.store(m_Memory.getVariables()[i].address, temp2, &error);
			}
		}
		if (varAddress == 0) {
			m_Register.changeRegister(destination, temp2, &error);
		}
		
	}
	if (error) DisplayError();
	updateMemory();
}

void Control::ADD(std::string destination, std::string source){
	bool error = false;
	DWORD64 temp2 = getValue(destination, source, &error);	
	DWORD64 temp1 = m_Register.getRegister(destination, &error);
	DWORD64 result = m_ALU.ADD(temp1, temp2);
	if(!error) m_Register.changeRegister(destination, result, &error);
	if (error) DisplayError();
	updateMemory();
}

void Control::SUB(std::string destination, std::string source) {
	bool pass = false;
	bool error = false;
	DWORD64 temp2 = getValue(destination, source, &error);
	DWORD64 temp1 = m_Register.getRegister(destination, &error);
	DWORD64 result = m_ALU.SUB(temp1, temp2);
	if(!error) m_Register.changeRegister(destination, result, &error);
	if (error) DisplayError();
	updateMemory();
}

void Control::NOT(std::string destination, std::string source){
	bool error = false;
	DWORD64 temp2 = getValue(destination, source, &error);
	DWORD64 temp1 = m_Register.getRegister(destination, &error);
	DWORD64 result = m_ALU.NOT(temp1, temp2);
	if (!error) m_Register.changeRegister(destination, result, &error);
	if (error) DisplayError();
	updateMemory();
}

void Control::OR(std::string destination, std::string source){
	bool error = false;
	DWORD64 temp2 = getValue(destination, source, &error);
	DWORD64 temp1 = m_Register.getRegister(destination, &error);
	DWORD64 result = m_ALU.OR(temp1, temp2);
	if (!error) m_Register.changeRegister(destination, result, &error);
	if (error) DisplayError();
	updateMemory();
}

void Control:: AND (std::string destination, std::string source){
	bool error = false;
	DWORD64 temp2 = getValue(destination, source, &error);
	DWORD64 temp1 = m_Register.getRegister(destination, &error);
	DWORD64 result = m_ALU.AND(temp1, temp2);
	if (!error) m_Register.changeRegister(destination, result, &error);
	if (error) DisplayError();
	updateMemory();
}

void Control:: XOR (std::string destination, std::string source) {
	bool error = false;
	DWORD64 temp2 = getValue(destination, source, &error);
	DWORD64 temp1 = m_Register.getRegister(destination, &error);
	DWORD64 result = m_ALU.XOR(temp1, temp2);
	if (!error) m_Register.changeRegister(destination, result, &error);
	if (error) DisplayError();
	updateMemory();
}

void Control:: LEA (std::string destination, std::string source) {
	bool error = false;
	DWORD64 temp2 = 0;
	bitset<32> varAddress = bitset<32>(0);
	for (int i = 0; i < m_Memory.getVariables().size(); i++) {
		if (source == m_Memory.getVariables()[i].name) {
			temp2 = m_Memory.getVariables()[i].address.to_ullong();
		}
	}

	if(temp2 == 0) temp2 = m_Register.getRegisterAddress(source, &error).to_ullong();

	
	if (!error) {
		for (int i = 0; i < m_Memory.getVariables().size(); i++) {
			if (destination == m_Memory.getVariables()[i].name) {
				varAddress = m_Memory.load(m_Memory.getVariables()[i].address, &error);
				m_Memory.store(m_Memory.getVariables()[i].address, temp2, &error);
			}
		}
		if (varAddress == 0) {
			m_Register.changeRegister(destination, temp2);
		}

	}
	if(error) DisplayError();
	updateMemory();
}

bool Control::enterCommand() {

	bool Found = false;
	std::string readData = "";
	std::vector<std::string> parsedCMDs;
	std::string cmd = "";
	std::string location = "";
	std::string source = "";
	int value1 = 0;

	cout << "inline.processor@> ";

	std::getline(cin, readData);

	istringstream strstream(readData);

	char chars[] = " ,";

	for (std::string next; std::getline(strstream, next, ' '); parsedCMDs.push_back(next));

	for (int i = 0; i < strlen(chars); i++) {
		for (int k = 0; k < parsedCMDs.size(); k++) {
			parsedCMDs[k].erase(std::remove(parsedCMDs[k].begin(), parsedCMDs[k].end(), chars[i]), parsedCMDs[k].end());
			for (int index = 0; index < parsedCMDs[k].size(); index++)
			{
				parsedCMDs[k][index] = toupper(parsedCMDs[k][index]);
			}
		}
	}
	if (readData != "") cmd = parsedCMDs[0];
	if (parsedCMDs.size() > 1) location = parsedCMDs[1];
	if (parsedCMDs.size() > 2) source = parsedCMDs[2];

	if (cmd == "WORD") {
		WORD(location, source);
		Found = true;
	}

	if (cmd == "MOV") {
		MOV(location, source);
		Found = true;
	}

	if (cmd == "ADD") {
		ADD(location, source);
		Found = true;
	}

	if (cmd == "SUB") {
		
		SUB(location, source);
		Found = true;
	}

	if (cmd == "AND") {
		AND(location, source);
		Found = true;
	}

	if (cmd == "OR") {
		OR (location, source);
		Found = true;
	}

	if (cmd == "NOT") {
		NOT (location, source);
		Found = true;
	}

	if (cmd == "XOR") {
		XOR (location, source);
		Found = true;
	}

	if (cmd == "CLEAR") {
		system("cls");
		DisplayHeader();
		Found = true;
	}

	if (cmd == "HELP") {
		help();
		Found = true;
	}

	if (cmd == "REG64") {
		m_Register.DumpRegs64();
		Found = true;
	}

	if (cmd == "REG32") {
		m_Register.DumpRegs32();
		Found = true;
	}

	if (cmd == "REG16") {
		m_Register.DumpRegs16();
		Found = true;
	}

	if (cmd == "REG8") {
		m_Register.DumpRegs8();
		Found = true;
	}

	if (cmd == "REGD") {
		m_Register.DumpRegsDec();
		Found = true;
	}

	if (cmd == "EXIT") {
		return false;
	}

	if (cmd == "MEMDUMP") {
		cout << "Initiate memory dump!" << endl;
		m_Memory.printAllMemory();
		Found = true;
	}

	if (cmd == "LEA") {		//load effective address command
		LEA(location, source);
		Found = true;
	}

	if (cmd == "PUSH") {	//push a value on to stack
		bitset<64> tempReg = m_Register.getRegister(location);
		bitset<32> tempData;
		for (int i = 31; i >= 0; i--) {
			tempData[i] = tempReg[i];
		}
		m_Memory.push(tempData);
		Found = true;
	}

	if (cmd == "POP") {		//pop a value off of stack
		bitset<64> tempReg = bitset<64>(0);
		bitset<32> tempData = m_Memory.pop();

		for (int i = 31; i >= 0; i--) {
			tempReg[i] = tempData[i];
		}

		m_Register.changeRegister(location, tempReg.to_ullong());
		Found = true;
	}

	if (!Found && readData != "") {
		DisplayError();
	}

	return true;
}


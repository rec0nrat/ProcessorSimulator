#include "Controller.h"

using namespace processor_sim;

Control::Control() {}

Control::~Control() {}

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
		<< "Type 'clear' to clear the screen.\n"
		<< "Type 'reg64' 'reg32' 'reg16' 'reg8' to view registers\n"
		<< "Type 'EXIT' to leave the program\n"
		<< endl;
}

void Control::MOV(std::string destination, std::string source) {
	bool error = false;
	DWORD64 temp2;
	temp2 = getValue(destination, source, &error);
	//cout << "Error flag = " << error << endl;
	if(!error) m_Register.changeRegister(destination,temp2); 
}

void Control::ADD(std::string destination, std::string source){
	bool error = false;
	DWORD64 temp2 = getValue(destination, source, &error);	
	DWORD64 temp1 = m_Register.getRegister(destination, &error);
	DWORD64 result = m_ALU.ADD(temp1, temp2);
	//cout << "Result = " << result << endl;
	//cout << "Error = " << error << endl;
	if(!error) m_Register.changeRegister(destination, result);
}

void Control::SUB(std::string destination, std::string source) {
	bool pass = false;
	bool error = false;
	DWORD64 temp2 = getValue(destination, source, &error);
	DWORD64 temp1 = m_Register.getRegister(destination, &error);
	DWORD64 result = m_ALU.SUB(temp1, temp2);
	if(!error) m_Register.changeRegister(destination, result);
}

void Control::NOT(std::string destination, std::string source){
	bool error = false;
	DWORD64 temp2 = getValue(destination, source, &error);
	DWORD64 temp1 = m_Register.getRegister(destination);
	DWORD64 result = m_ALU.NOT(temp1, temp2);
	if (!error) m_Register.changeRegister(destination, result);
}

void Control::OR(std::string destination, std::string source){
	bool error = false;
	DWORD64 temp2 = getValue(destination, source, &error);
	DWORD64 temp1 = m_Register.getRegister(destination, &error);
	DWORD64 result = m_ALU.OR(temp1, temp2);
	if (!error) m_Register.changeRegister(destination, result);
}

void Control:: AND (std::string destination, std::string source){
	bool error = false;
	DWORD64 temp2 = getValue(destination, source, &error);
	DWORD64 temp1 = m_Register.getRegister(destination, &error);
	DWORD64 result = m_ALU.AND(temp1, temp2);
	if (!error) m_Register.changeRegister(destination, result);
}

void Control:: XOR (std::string destination, std::string source) {
	bool error = false;
	DWORD64 temp2 = getValue(destination, source, &error);
	DWORD64 temp1 = m_Register.getRegister(destination, &error);
	DWORD64 result = m_ALU.XOR(temp1, temp2);
	if (!error) m_Register.changeRegister(destination, result);
}

bool Control::enterCommand() {

	char space = ' ';
	char comma = ',';
	bool space1 = false;
	bool comma1 = false;
	bool Found = false;
	std::string readData = "";
	std::string cmd = "";
	std::string location = "";
	std::string source = "";
	int value1 = 0;
	cout << "$: ";

	getline(cin, readData);

	for (int i = 0; i < readData.length(); i++) {

		if (bitset<8>(readData[i]) == bitset<8>(space)) space1 = true;
		if (bitset<8>(readData[i]) == bitset<8>(comma)) comma1 = true;
		if (bitset<8>(readData[i]) != bitset<8>(space) && bitset<8>(readData[i]) != bitset<8>(comma)) {
			if (space1 == false && comma1 == false) {
				cmd += toupper(readData[i]);
				
			}
			if (space1 == true && comma1 == false) {
				location += toupper(readData[i]);
			}
			if (space1 == true && comma1 == true) {
				source += toupper(readData[i]);
			}
		}
	}	

	if (cmd == SHOW(MOV)) {
		//cout << "You entered a 'Move' command" << endl;
		MOV(location, source);
		Found = true;
	}

	if (cmd == SHOW(ADD)) {
		//cout << "You entered an 'Addition' command" << endl;
		ADD(location, source);
		Found = true;
	}

	if (cmd == SHOW(SUB)) {
		
		SUB(location, source);
		Found = true;
	}

	if (cmd == SHOW(AND)) {
		AND(location, source);
		Found = true;
	}

	if (cmd == SHOW(OR)) {
		OR (location, source);
		Found = true;
	}

	if (cmd == SHOW(NOT)) {
		NOT (location, source);
		Found = true;
	}

	if (cmd == SHOW(XOR)) {
		XOR (location, source);
		Found = true;
	}

	if (cmd == "CLEAR") {
		system("cls");
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
		enterCommand();
	}

	if (!Found) {
		cout << "Not a valid command!!!!!\nType 'help' for assistance or 'exit' to leave the program..." << endl;
		enterCommand();
	}

	return true;
}


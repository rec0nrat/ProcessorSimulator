#include "Controller.h"

using namespace processor_sim;

Control::Control() {}

Control::~Control() {}

DWORD64 Control::getValue(std::string destination ,std::string value, bool * error) {
	//cout << "Error flag before error = " << *error << endl;
	DWORD returnVal = 0;
	
	for (int i = 0; i < 8; i++) {
		if (value == array64[i] || value == array32[i] || value == array16[i]) return myRegister.getRegister(value);
	}
	for (int i = 0; i < 16; i++) if (value == array8[i]) return myRegister.getRegister(value);

	if (value == "MAX") {
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
			returnVal = stoi(value);
		}
		catch (const std::exception& e) {
			*error = true;
		}
		return returnVal;
	}
}

void Control::help() {
	bool listCmds = false;
	cout << "Commands should look like:\ncommand (space) destination (comma), value (or another register)" << endl;
	cout << "\nThe commands supported are:\n"
		<< "MOV - Moves a value to a register\n"
		<< "ADD - Adds a value to a register\n"
		<< "AND - Bitwise AND's a register by a value\n"
		<< "OR  - Bitwise or's a register by a value\n"
		<< "XOR - Bitwise exclusive or a register by a value\n"
		<< "NOT - Bitwise not a register\n"
		<< "SUB - Subtract a value from a register\n"
		<< "Type 'clear' to clear the screen.\n"
		<< "Type 'reg64' for 64-bit registers\n'reg32' for 32-bit registers\n'reg16' for 16bit registers\n'reg8' for 8 bit registers\n'regd' for decimal of 64 bit registers\n"
		<< "Type 'EXIT' to leave the program at any point...\n"
		<< endl;
}

void Control::mov(std::string destination, std::string source) {
	bool error = false;
	DWORD64 temp2;
	temp2 = getValue(destination, source, &error);
	//cout << "Error flag = " << error << endl;
	if(!error) myRegister.changeRegister(destination,temp2); 
}

void Control::add(std::string destination, std::string value){
	bool error = false;
	DWORD64 temp2 = getValue(destination, value, &error);	
	DWORD64 temp1 = myRegister.getRegister(destination, &error);
	DWORD64 result = m_ALU.add(temp1, temp2);
	cout << "Result = " << result << endl;
	cout << "Error = " << error << endl;
	if(!error) myRegister.changeRegister(destination, result);
}

void Control::sub(std::string destination, std::string value) {
	bool pass = false;
	bool error = false;
	DWORD64 temp2 = getValue(destination, value, &error);
	DWORD64 temp1 = myRegister.getRegister(destination, &error);
	DWORD64 result = m_ALU.sub(temp1, temp2);
	if(!error) myRegister.changeRegister(destination, result);
}

void Control::not(std::string destination, std::string value){
	bool error = false;
	DWORD64 temp2 = getValue(destination, value, &error);
	DWORD64 temp1 = myRegister.getRegister(destination);
	DWORD64 result = m_ALU.not(temp1, temp2);
	if (!error) myRegister.changeRegister(destination, result);
}

void Control::or(std::string destination, std::string value){
	bool error = false;
	DWORD64 temp2 = getValue(destination, value, &error);
	DWORD64 temp1 = myRegister.getRegister(destination, &error);
	DWORD64 result = m_ALU.or(temp1, temp2);
	if (!error) myRegister.changeRegister(destination, result);
}

void Control:: AND (std::string destination, std::string value){
	bool error = false;
	DWORD64 temp2 = getValue(destination, value, &error);
	DWORD64 temp1 = myRegister.getRegister(destination, &error);
	DWORD64 result = m_ALU.AND(temp1, temp2);
	if (!error) myRegister.changeRegister(destination, result);
}

void Control:: xor (std::string destination, std::string value) {
	bool error = false;
	DWORD64 temp2 = getValue(destination, value, &error);
	DWORD64 temp1 = myRegister.getRegister(destination, &error);
	DWORD64 result = m_ALU.xor(temp1, temp2);
	if (!error) myRegister.changeRegister(destination, result);
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
	std::string value = "";
	int value1 = 0;
	cout << "$: ";
	getline(cin, readData);

	//cout << "You entered " << readData << endl;
	for (int i = 0; i < readData.length(); i++) {
		//cout << space1 << " " << comma1 << endl;

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
				value += toupper(readData[i]);
			}
		}
	}	

	if (cmd == SHOW(MOV)) {
		//cout << "You entered a 'Move' command" << endl;
		mov(location, value);
		Found = true;
	}

	if (cmd == SHOW(ADD)) {
		//cout << "You entered an 'Addition' command" << endl;
		add(location, value);
		Found = true;
	}

	if (cmd == SHOW(SUB)) {
		//cout << "You entered a 'Subtract' command" << endl;
		sub(location, value);
		Found = true;
	}

	if (cmd == SHOW(AND)) {
		//cout << "You entered an 'And' command" << endl;
		AND(location, value);
		Found = true;
	}

	if (cmd == SHOW(OR)) {
		//cout << "You entered an 'Or' command" << endl;
		or (location, value);
		Found = true;
	}

	if (cmd == SHOW(NOT)) {
		//cout << "You entered a 'Not' command" << endl;
		not (location, value);
		Found = true;
	}

	if (cmd == SHOW(XOR)) {
		//cout << "You entered an 'Xor' command" << endl;
		xor (location, value);
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
		myRegister.DumpRegs64();
		Found = true;
	}

	if (cmd == "REG32") {
		myRegister.DumpRegs32();
		Found = true;
	}

	if (cmd == "REG16") {
		myRegister.DumpRegs16();
		Found = true;
	}

	if (cmd == "REG8") {
		myRegister.DumpRegs8();
		Found = true;
	}

	if (cmd == "REGD") {
		myRegister.DumpRegsDec();
		Found = true;
	}

	if (cmd == "EXIT") {
		return false;
	}

	if (!Found) {
		cout << "Not a valid command!!!!!\nType 'help' for assistance or 'exit' to leave the program..." << endl;

		enterCommand();
	}

	return true;
}


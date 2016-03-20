/*

DJ Carpenter
Intro To Assembly
Building our own Assembler

*/



#include "Include.h"
//#include "ALU.h"
#include "Controller.h"

//template <typename Type>
//inline Type const& max(Type &a, Type &b){
//	return a > b ? a : b;
//}

void welcome();
void dataBits();

int main(){

	/*
	bitset<64> unob(MAXDWORD64);
	cout << unob << endl;
	DWORD64 unod = unob.to_ullong();
	cout << unod << endl;
	bitset<64> dunob = unod;
	cout << dunob << endl;
	
	bitset<8> two(2);
	while (1) {
		int temp = 0;
		cin >> temp;
		two = temp;
		for (int i = 7; i>= 0; i--) {
			cout << two[i];
		}
		cout << endl;
	}
	
	cout << "Bar-> " << bar << "\nFoo-> " << foo << "\nDecimal-> " << foo.to_ulong() << endl;

	for (int i = 0; i < 15; i++) {
		foo[array16[i]] = bar[array16[i]];
	}

	cout << "Bar-> " << bar[16] << "\nFoo-> " << foo << "\nDecimal-> "<< foo.to_ulong() << endl;

	foo = 10;

	cout << "Bar-> " << bar << "\nFoo-> " << foo << "\nDecimal-> " << foo.to_ulong() << endl;
	

	
	const char* Test = SHOW(MOV);
	
	cout << Test << ": "<<hex<< MOV << endl; 

	int x = 21;

	cout << x << " = " << bitset<32>(x) << endl;

	x = x >> 1;

	cout << x << " = " << bitset<32>(x) << endl;


	cout << "Enter a decimal value: ";
	std::string test;
	cin >> test;

	cout << "\n" << "MOV = "<< hex << MOV << " == " << bitset<16>(MOV) << endl;
	cout << "\n" << "ADD = " << ADD << ADD << " == " << bitset<16>(ADD) << endl;
	*/
	system("pause");
	welcome();
	cout << "Enter 'help' for a list of commands" << endl;
	Control newControl;

	while (newControl.enterCommand()) {

	}
	system("pause");
	return 0;
}

void welcome() {

	cout << "Welcome to my 'CPU' simulator!\n"
		<< "Author: Christina Bilbo\n"
		<< "Date: 2/28/2016\n"
		<< "Version: 1.01"
		<< endl;
}

void dataBits() {
	bitset<8> al;
	for (int i = 7; i >= 0; i--) {
		al[i] = 1;
	}
	cout << "8-bit Dec  = " << al.to_ulong() << endl;

	bitset<16> ax;
	for (int i = 15; i >= 0; i--) {
		ax[i] = 1;
	}
	cout << "16-bit Dec = " << ax.to_ulong() << endl;

	bitset<32> eax;
	for (int i = 31; i >= 0; i--) {
		eax[i] = 1;
	}
	cout << "32-bit Dec = " << eax.to_ulong() << endl;
	
	bitset<64> rax;
	for (int i = 0; i < rax.size(); i++) {
		rax[i] = 1;
	}
	cout << "64-bit Dec = " << rax.to_ullong() << endl;
	/*
	cout << "byte    = " << sizeof(byte) << " |  " << sizeof(byte) * 8 << " bits | Max Decimal = "<< MAXBYTE << endl;
	cout << "int16   = " << sizeof(INT16) << " or " << sizeof(INT16) * 8 << " bits | Max Decimal = "<< MAXINT16 << endl;
	cout << "dword   = " << sizeof(DWORD) << " or " << sizeof(DWORD) * 8 << " bits." << endl;
	cout << "dword64 = " << sizeof(DWORD64) << " or " << sizeof(DWORD64) * 8 << " bits." << endl;
	*/
	cout << "maxByte Dec   = " << MAXBYTE << endl;
	cout << "maxInt16 Dec = " << MAXUINT16 << endl;
	cout << "maxDWORD Dec   = " << MAXDWORD << endl;
	cout << "maxDWORD64 Dec = " << MAXDWORD64 << endl;

	cout << sizeof(short) << endl;
}
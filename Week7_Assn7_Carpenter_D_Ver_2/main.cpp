#include "Controller.h"	//Controller.h contains all sub components

using namespace processor_sim;	//namespace that defines all other components

void welcome();

int main(){

	Control Processor; //create an instance of a processor

	//Messing around with the bitsets
	bitset<8> b_set;
	int bits[8] = { 0,1,2,3,4,5,6,7 };
	for (int i = 0; i < 8; i++) {
		cout << b_set[bits[i]];
	}
	cout << endl;

	welcome();

	cout << endl << "** Enter 'help' for a list of commands **\n" << endl;

	while (Processor.enterCommand()) {} //loop while commands are being entered into UI

	system("pause");

	return 0;
}

void welcome() {

	cout << "Processor Simulation \n"
		<< "(Using MASM Instruction Set) \n"
		<< "Version 1.2 \n"
		<< endl;
}

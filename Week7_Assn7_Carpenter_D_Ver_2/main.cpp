#include "Controller.h"	//Controller.h contains all sub components

using namespace processor_sim;	// I got curous aboiut using namespaces so I'm pretty sure that this isn't necessary. I was just messing around with namespaces

void DisplayHeader();

int main(){

	Control Processor; //create an instance of a processor

	DisplayHeader();

	cout << endl << "** Enter 'help' for a list of commands **\n" << endl;

	while (Processor.enterCommand()) {} //loop while commands are being entered into UI

	system("pause");

	return 0;
}

void DisplayHeader() {

	cout << "Processor Simulation \n"
		<< "(Using MASM Instruction Set) \n"
		<< "Version 1.2 \n"
		<< endl;
}
